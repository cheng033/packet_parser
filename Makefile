CC = gcc
CFLAGS = -g -Wall -Iinclude

all: packet_parser
packet_parser: src/main.c src/tcp_parser.c
	$(CC) $(CFLAGS) -o build/packet_parser src/main.c src/tcp_parser.c

clean:
	rm -f build/packet_parser

