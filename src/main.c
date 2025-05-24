#include <stdio.h>
#include <stdint.h>
#include "tcp_parser.h"

int main(){
	uint8_t packet[20] = {
		0x01, 0x02, //source 
		0x00, 0x50, //dest 
		0x12, 0x34, 0x56, 0x78, //seq
		0x87, 0x65, 0x43, 0x21, //ack
		0x50, 0x02, //ofset + flag
		0x20, 0x00,	//window size
		0x12, 0x34,	//checksum
		0x00, 0x00  //urgent pointer
	};

    tcp_header_t h = {0};
	int ret = parser_tcp_packet(packet, sizeof(packet), &h);    
	
	if (ret < 0){
		fprintf(stderr, "Packet parse failed!\n");
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
    return 0;
}

