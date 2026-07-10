#include <ncurses.h>

#include <pulse/pulse.h>

int main(void)
{
    if (pulse_init() != 0)
        return 1;

    int ch;

    while ((ch = getch()) != 'q')
    {
        pulse_update();
        pulse_draw();
    }

    pulse_shutdown();

    return 0;
}
