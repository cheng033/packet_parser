#include "../include/tcp_parser.h"
#include <stdio.h>
#include <stddef.h>

int parser_tcp_packet(const uint8_t *packet, size_t len, tcp_header_t *h){
	if (len < 20){
		fprintf(stderr, "Packet too short! Got %zu , Need 20 bytes.\n", len);
		return -1;
	}

	h->source_port = (packet[0] << 8) | packet[1];
	h->dest_port = (packet[2] << 8 ) | packet[3];
	h->seq_num = (packet[4] << 24) | (packet[5] << 16) 					|(packet[6] << 8) | packet[7];
	h->ack_num = (packet[8] << 24) | (packet[9] << 16)                  |(packet[10] << 8) | packet[11];
	h->offset_reserved_flags =  (packet[12] << 8)                                        | packet[13]; 
	h->window_size =  (packet[14] << 8) | packet[15];
	h->checksum =  (packet[16] << 8) | packet[17];   
	h->urgent_pointer =  (packet[18] << 8)                                         | packet[19];  

	return 0;
}

