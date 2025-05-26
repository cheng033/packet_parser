# Packet Parser

一個用 C 語言實作的封包解析器，適合初學者練習 struct 設計、bitwise 操作, gdb debug 與 valgrind 檢查記憶體。

## 功能
- 解析模擬的封包 ex. TCP, UDP, ICMP
- 檢查封包長度，防止記憶體越界

## 專案架構
```
packet_parser/
├── include/
│ ├── tcp_parser.h
│ └── udp_parser.h
│ └── icmp_parser.h 
├── src/
│ ├── tcp_parser.c
│ └── udp_parser.c
│ └── icmp_parser.c
│ └── main.c
├── Makefile
└── README.md
```

## 編譯與執行
```bash
make && ./build/packet_parser
```

