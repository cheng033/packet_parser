#ifndef TCP_PARSER_H
#define TCP_PARSER_H

#include <stdint.h> 
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    uint16_t source_port;
    uint16_t dest_port;
    uint32_t seq_num;
    uint32_t ack_num;
    uint16_t offset_reserved_flags;
    uint16_t window_size;
    uint16_t checksum;
    uint16_t urgent_pointer;
} tcp_header_t;

int parser_tcp_packet(const uint8_t *packet, size_t len, tcp_header_t *h);

#ifdef __cplusplus
}
#endif

#endif    
