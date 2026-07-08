# Pulse

> A lightweight, modular TUI network monitor for Linux.

Pulse is a terminal-based network monitoring application written in C using **ncurses**. It provides real-time information about your network connection in a compact, responsive interface designed for Linux systems.

The project is built with modularity in mind, making it easy to extend and integrate into larger terminal-based environments.

---

## Features

### Current

* Lightweight terminal interface
* Modular codebase
* ncurses-based UI
* Linux focused

### Planned

* Live network interface detection
* Wi-Fi SSID and signal strength
* RX/TX bandwidth monitoring
* Total uploaded/downloaded data
* IPv4 and gateway information
* Internet connectivity status
* Ping and latency monitoring
* Real-time traffic graphs
* Multiple interface support
* Configurable refresh rate
* Color themes
* Keyboard shortcuts
* Integration with custom TUI desktop environments

---

## Screenshot

*Coming soon.*

---

## Project Structure

```text
pulse/
├── .github/
├── assets/
├── docs/
├── include/
│   └── pulse/
├── src/
├── tests/
├── LICENSE
├── Makefile
└── README.md
```

---

## Building

```bash
make
```

---

## Running

```bash
./pulse
```

---

## Requirements

* Linux
* GCC
* Make
* ncurses

---

## Design Goals

* Lightweight
* Fast startup
* Low memory usage
* Minimal CPU usage
* Modular architecture
* No unnecessary dependencies
* Clean terminal interface

---

## Roadmap

* [ ] Project initialization
* [ ] Build system
* [ ] ncurses initialization
* [ ] Network interface detection
* [ ] Wi-Fi information
* [ ] RX/TX statistics
* [ ] Live bandwidth monitoring
* [ ] Ping monitoring
* [ ] Traffic graphs
* [ ] Network manager panel
* [ ] Theme support
* [ ] Configuration file
* [ ] Plugin support

---

## License

This project is licensed under the MIT License.

---

## Author

**Shashank Singh Patel**

GitHub: https://github.com/Github-Shashank
