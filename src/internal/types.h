#include <arpa/inet.h>

#ifndef PULSE_TYPES_H
#define PULSE_TYPES_H

#define PULSE_IFNAME_LEN 32
#define PULSE_IP_LEN INET_ADDRSTRLEN

#define PULSE_SSID_LEN 64

#define PULSE_GATEWAY_LEN 16

typedef struct
{
    int initialized;
    int connected;

    char interface[PULSE_IFNAME_LEN];
    char ipv4[PULSE_IP_LEN];
    char gateway[PULSE_GATEWAY_LEN];

    char ssid[PULSE_SSID_LEN];

    int signal_dbm;

    unsigned long long rx_bytes;
    unsigned long long tx_bytes;

    double down_speed;
    double up_speed;

    double ping_ms;
} PulseState;

#endif
