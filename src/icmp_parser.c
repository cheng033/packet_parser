#include "../include/icmp_parser.h"
#include <stdio.h>
#include <stddef.h>

int parser_icmp_packet(const uint8_t *packet, size_t len, icmp_header_t *h){
    if (len < 4){
        fprintf(stderr, "Packet too short! Got %zu, Need 4 bytes.\n", len);
        return -1;
    }

    h->type = packet[0];
    h->code = packet[1];
    h->checksum = (packet[2] << 8) | packet[3];

    return 0;
}
