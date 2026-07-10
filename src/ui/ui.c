#include <ncurses.h>

#include "../internal/ui.h"

int ui_init(void)
{
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);

    return 0;
}

void ui_draw(const PulseState *state)
{
    clear();

    if (state->initialized)
    {
    mvprintw(0, 0, "Pulse");
    mvprintw(2, 0, "Interface : %s", state->connected ? state->interface : "--");
    mvprintw(3, 0, "Status    : %s", state->connected ? "Connected" : "Disconnected");
    mvprintw(4, 0, "IPv4      : %s", state->connected ? state->ipv4 : "--");
    mvprintw(6, 0, "Press q to quit");
    }

//    if (state->initialized)
//        mvprintw(4, 0, "Core initialized");

    mvprintw(6, 0, "Press q to quit");

    refresh();
}

void ui_shutdown(void)
{
    endwin();
}
