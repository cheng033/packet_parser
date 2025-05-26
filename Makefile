.PHONY: all clean
CC = gcc
CFLAGS = -g -Wall -Iinclude

SRC = src/main.c src/tcp_parser.c src/udp_parser.c src/icmp_parser.c
TARGET = build/packet_parser

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f build/packet_parser

