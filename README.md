# Packet Parser

一個用 C 語言實作的封包解析器，適合初學者練習 struct 設計、bitwise 操作, gdb debug 與 valgrind 檢查記憶體。

## 功能
- 解析模擬的封包 ex. TCP, UDP, ICMP
- 檢查封包長度，防止記憶體越界

## 專案架構

```
packet_project
├── packet_parser
│   ├── include
│   │   ├── icmp_parser.h
│   │   ├── tcp_parser.h
│   │   └── udp_parser.h
│   ├── Makefile
│   └── src
│       ├── icmp_parser.c
│       ├── main.c
│       ├── tcp_parser.c
│       └── udp_parser.c
├── packet_server
│   ├── include
│   │   └── crow_all.h
│   ├── Makefile
│   └── src
│       └── main.cpp
└── README.md
```

## 編譯與執行
```bash
cd packet_parser
make && ./build/packet_parser
```

