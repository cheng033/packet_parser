.PHONY: all clean
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude -I../packet_parser/include

SRC = src/main.cpp
PARSER_SRC = ../packet_parser/src/tcp_parser.c \
			 ../packet_parser/src/udp_parser.c \
			../packet_parser/src/icmp_parser.c 

TARGET = build/packet_server

all: $(TARGET)

$(TARGET): $(SRC) $(PARSER_SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)


