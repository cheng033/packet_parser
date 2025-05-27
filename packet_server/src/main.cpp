#include "crow_all.h"
#include <sstream>
using namespace std;
extern "C" {
#include "../../packet_parser/include/tcp_parser.h"
}

int main(){
    crow::SimpleApp app;
    //固定的tcp packet    
    CROW_ROUTE(app, "/parse/tcp")([](){
        uint8_t tcp_packet[20] = {
            0x01, 0x02, //source
            0x00, 0x50, //dest
            0x12, 0x34, 0x56, 0x78, //seq
            0x87, 0x65, 0x43, 0x21, //ack
            0x50, 0x02, //ofset + flag
            0x20, 0x00, //window size
            0x12, 0x34, //checksum
            0x00, 0x00  //urgent pointer
    };

    tcp_header_t h = {0};
    int ret = parser_tcp_packet(tcp_packet, sizeof(tcp_packet), &h);

    if (ret < 0){
        return string("Packet parser failed!\n");
    }

    stringstream ss;
    ss << "Source port:" << h.source_port << "\n";
    ss << "Dest port: " << h.dest_port << "\n";
    ss<< "Seq num: " << h.seq_num << "\n";
    ss << "Ack num: " << h.ack_num << "\n";
    ss << "Offset+Flag: 0x" << hex << h.offset_reserved_flags << "\n";
    ss << "Window: " << dec << h.window_size << "\n";
    ss << "Checksum: " << h.checksum << "\n";
    ss << "Urgent pointer: " << h.urgent_pointer << "\n";
    return ss.str();
});

    //Others
    CROW_ROUTE(app, "/hello")([](){
        return "Hello, packet server!";
    });
    
    CROW_ROUTE(app, "/ping")([]{
        string response = "伺服器運作中";
        return response;
    });

    app.port(18080).multithreaded().run();
}


