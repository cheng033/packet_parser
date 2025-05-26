#include <stdio.h>
#include <stdint.h>
#include "tcp_parser.h"
#include "udp_parser.h"
#include "icmp_parser.h"

int main(){

    int protocol = 3;
    if(protocol == 1){

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
        fprintf(stderr, "Packet parser failed!\n");
        return 1;
    }

        printf("Source port: %u\n", h.source_port);
        printf("Dest port: %u\n", h.dest_port);
        printf("Seq num: %u\n", h.seq_num);
        printf("Ack num: %u\n", h.ack_num);
        printf("Offset and Flag: 0x%04x\n", h.offset_reserved_flags);
        printf("Window size: %u\n", h.window_size);
        printf("Checksum: %u\n", h.checksum);
        printf("Urgent pointer: %u\n", h.urgent_pointer);
        
    }
    
    else if(protocol == 2){
        uint8_t udp_packet[8] = {
            0x56, 0x33, //source_port
            0x83, 0xAE, //dest_port
            0x1F, 0x4D, //length
            0x66, 0xBF // checksum
        };
        udp_header_t h = {0};
        int ret = parser_udp_packet(udp_packet, sizeof(udp_packet), &h);
        if(ret < 0){
            fprintf(stderr, "UDP parser failed!\n");
            return 1;
    }

        printf("Source port: %u\n", h.source_port);
        printf("Dest port: %u\n", h.dest_port);
        printf("Length: %u\n", h.length);
        printf("Checksum: %u\n", h.checksum);        
    }
    
    else if(protocol == 3){
        uint8_t icmp_packet[4]={
            0x12, //type
            0x44, //code
            0x6F, 0xEA //checksum
        };
        icmp_header_t h ={0};
        int ret = parser_icmp_packet(icmp_packet, sizeof(icmp_packet), &h);
        if(ret < 0) {
            fprintf(stderr, "ICMP parser failed!\n");
            return 1;
        }
        
        printf("Type: %u\n", h.type);
        printf("Code: %u\n", h.code);
        printf("Checksum: %u\n", h.checksum);
    }

    else{
        printf("Unknown protocol.\n");    
    }
    
    return 0;
}
