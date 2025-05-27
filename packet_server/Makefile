.PHONY: all clean
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude -I../packet_parser/include

PARSER_SRC = ../packet_parser/src/tcp_parser.c

SRC = src/main.cpp
TARGET = build/packet_server

all: $(TARGET)

$(TARGET): $(SRC) $(PARSER_SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)


