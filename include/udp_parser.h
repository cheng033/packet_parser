#ifndef UDP_PARSER_H
#define UDP_PARSER_H
#include <stdint.h>
#include <stddef.h>

typedef struct{
    uint16_t source_port;
    uint16_t dest_port;
    uint16_t length;
    uint16_t checksum;
}udp_header_t;

int parser_udp_packet(const uint8_t *packet, size_t len, udp_header_t *h);

#endif

