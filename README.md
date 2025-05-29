# Packet Parser

packet_parser : 以c語言實作封包結構，可搭配 gdb 和 valgrind 檢查。<br>
packer_server: 使用Crow框架建立api，呼叫c file且輸出到demo的html頁面。

## 功能
- 解析模擬的封包 ex. TCP, UDP, ICMP
- 檢查封包長度，防止記憶體越界
- cross compile成mips file, 執行環境：MIPS Malta (QEMU)
## 專案架構

```
.
├── frontend
│       └── index.html
├── packet_parser
│   ├── include
│   │   ├── tcp_parser.h
│   │   ├── udp_parser.h
│   │   └── icmp_parser.h
│   ├──src
│   |   ├── main.c
│   |   ├── tcp_parser.c
│   |   ├── udp_parser.c
│   |   └── icmp_parser.c
│   └── Makefile
├── packet_server
│   ├── include
│   │   └── crow_all.h
│   ├── src
│   |   └── main.cpp
│   └── Makefile
├── .gitignore
└── README.md
```

## 執行網頁Demo
```bash
cd packet_server
make && ./build/packet_server
cd frontend
python3 -m http.server 8888
//open web browser
http://localhost:8888/index.html
```
