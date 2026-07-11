# Pulse

A lightweight terminal-based network monitoring panel written in C using **ncurses**.

Pulse provides a clean, real-time overview of your current network connection without requiring a full desktop environment. It is designed to be a small component of a larger terminal user interface ecosystem.

---

## Features

* Detect active network interface
* Display connection status
* Show IPv4 address
* Display default gateway
* Detect connected Wi-Fi SSID
* Display Wi-Fi signal strength with a visual bar
* Monitor total received (RX) and transmitted (TX) traffic
* Display live download and upload speeds
* Measure network latency (Ping)
* Lightweight ncurses interface
* Minimal dependencies

---

## Preview

```text
Pulse

Interface : wlo1
Status    : Connected
IPv4      : 10.33.56.179
Gateway   : 10.33.56.128

SSID      : ssh
Signal    : [########..] -62 dBm

RX        : 32.6 MB    Down : 70.5 KB/s
TX        : 37.6 MB    Up   : 63.6 KB/s

Ping      : 5.66 ms

Press q to quit
```

---

## Requirements

* Linux
* GCC
* GNU Make
* ncurses
* iw
* ping (iputils)

---

## Build

```bash
make
```

---

## Run

```bash
./pulse
```

---

## Project Structure

```text
include/
└── pulse/

src/
├── core/
│   ├── network.c
│   ├── ping.c
│   ├── pulse.c
│   ├── traffic.c
│   └── wifi.c
├── internal/
├── ui/
└── main.c
```

---

## Modules

### Network

* Active interface detection
* IPv4 detection
* Gateway detection

### Wi-Fi

* SSID detection
* Signal strength

### Traffic

* RX/TX counters
* Live bandwidth calculation

### Ping

* Gateway latency monitoring

### UI

* ncurses-based terminal interface

---

## Design Goals

* Lightweight
* Fast
* Simple
* Terminal-first
* Modular architecture
* Easy to extend

---

## Roadmap

### Version 1.0

* [x] Interface detection
* [x] Connection status
* [x] IPv4 address
* [x] Gateway detection
* [x] Wi-Fi information
* [x] Signal strength indicator
* [x] RX/TX statistics
* [x] Live bandwidth
* [x] Ping monitoring

### Future Ideas

* Multiple interfaces
* Historical traffic graphs
* Configurable refresh interval
* Themes
* IPv6 support
* Public IP detection
* Export metrics
* Plugin system

---

## License

This project is licensed under the MIT License.

---

Built with C, ncurses, and Linux system interfaces.
