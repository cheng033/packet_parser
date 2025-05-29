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
├── packet_parser
│   ├── include
│   │   ├── tcp_parser.h
│   │   ├── udp_parser.h
│   │   └── icmp_parser.h
│   ├── Makefile
|   ├── packet_parser.mips
│   └── src
│       ├── main.c
│       ├── tcp_parser.c
│       ├── udp_parser.c
│       └── icmp_parser.c
├── packet_server
│   ├── include
│   │   └── crow_all.h
│   ├── Makefile
│   └── src
│       └── main.cpp
├── frontend
│       └── index.html
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
## 執行 MIPS
### 1. QEMU + Openwrt image 安裝 
### 2. Openwrt shell 設定ip
```
ifconfig br-lan down //如果bridge綁住lan要加
ifconfig eth0 0.0.0.0
udhcpc -i eth0
```
### 3. 原環境檔案傳輸
```
cd packet_parser
python3 -m http.server 8888
```
### 4. Openwrt shell 執行
```
wget http://10.0.2.2:8888/packet_parser.mips
chmod +x packet_parser.mips
./packet_parser.mips
```
