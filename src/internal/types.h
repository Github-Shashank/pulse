#ifndef PULSE_TYPES_H
#define PULSE_TYPES_H

#define PULSE_IFNAME_LEN 32
typedef struct
{
    int initialized;
    int connected;
    char interface[PULSE_IFNAME_LEN];
} PulseState;

#endif
