#ifndef PULSE_NETWORK_H
#define PULSE_NETWORK_H

#include "types.h"

int network_detect(PulseState *state);

int network_get_ipv4(PulseState *state);

int network_get_gateway(PulseState *state);

#endif
