#include "crow_all.h"
#include <sstream>
using namespace std;
extern "C" {
#include "../../packet_parser/include/tcp_parser.h"
#include "../../packet_parser/include/udp_parser.h"
#include "../../packet_parser/include/icmp_parser.h"
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
    
    crow::json::wvalue res;
    if (ret < 0){
        res["error"] = "Packet parser failed!";
        return res;
    }

    res["source_port"] = h.source_port;
    res["dest_port"] = h.dest_port;
    res["seq_num"] =  h.seq_num;
    res["ack_num"] = h.ack_num;
    res["offset_flag"] = h.offset_reserved_flags;
    res["window"] = h.window_size;
    res["checksum"] =  h.checksum;
    res["urgent_pointer"] = h.urgent_pointer;
    return res;
});


    //UDP
    CROW_ROUTE(app, "/parse/udp")([]() {
    uint8_t udp_packet[8] = {
        0x56, 0x33, // source_port
        0x83, 0xAE, // dest_port
        0x1F, 0x4D, // length
        0x66, 0xBF  // checksum
    };
    udp_header_t h = {0};
    int ret = parser_udp_packet(udp_packet, sizeof(udp_packet), &h);
    
    crow::json::wvalue res;
    if (ret < 0) {
        res["error"] = "UDP parser failed!";
        return res;
    }
    res["source_port"] = h.source_port;
    res["dest_port"] = h.dest_port;
    res["length"] = h.length;
    res["checksum"] = h.checksum;
    return res;
});



    //ICMP
    CROW_ROUTE(app, "/parse/icmp")([](){
        uint8_t icmp_packet[4]{
        0x12, //type
        0x44, //code
        0x6F, 0xEA //checksum
    };
    icmp_header_t h = {0};
    int ret = parser_icmp_packet(icmp_packet,sizeof(icmp_packet), &h);

    crow::json::wvalue res;
    if(ret < 0){
        res["error"] = "ICMP parser failed!";
        return res;
    }
    res["type"] = h.type;
    res["code"] = h.code;
    res["checksum"] = h.checksum;
    return res;
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


