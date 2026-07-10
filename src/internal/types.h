#include <arpa/inet.h>

#ifndef PULSE_TYPES_H
#define PULSE_TYPES_H

#define PULSE_IFNAME_LEN 32
#define PULSE_IP_LEN INET_ADDRSTRLEN

typedef struct
{
    int initialized;
    int connected;

    char interface[PULSE_IFNAME_LEN];
    char ipv4[PULSE_IP_LEN];
} PulseState;

#endif
