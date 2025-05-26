#ifndef ICMP_HEADER_H
#define ICMP_HEADER_H
#include <stdint.h>
#include <stddef.h>

typedef struct {
    uint8_t type;
    uint8_t code;
    uint16_t checksum;
}icmp_header_t;

int parser_icmp_packet(const uint8_t *packet, size_t len, icmp_header_t *h);

#endif

