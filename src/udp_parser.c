#include "../include/udp_parser.h"
#include <stdio.h>
#include <stddef.h>

int parser_udp_packet(const uint8_t *packet, size_t len, udp_header_t *h){
    if (len < 8){
        fprintf(stderr, "Packet too short! Got %zu, Need 8 bytes.\n", len);
    return -1;
    }
    
    h->source_port = (packet[0] << 8) | packet[1];
    h->dest_port = (packet[2] << 8) | packet[3];
    h->length = (packet[4] << 8) | packet[5];
    h->checksum = (packet[6] << 8) | packet[7];

    return 0;
}

