#ifndef PULSE_UI_H
#define PULSE_UI_H

#include "types.h"

int ui_init(void);
void ui_draw(const PulseState *state);

void ui_shutdown(void);

#endif
