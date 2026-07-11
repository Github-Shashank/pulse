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


static void signal_bar(int dbm, char *bar)
{
    int percent;

    if (dbm >= -50)
        percent = 100;
    else if (dbm <= -100)
        percent = 0;
    else
        percent = 2 * (dbm + 100);

    int blocks = (percent + 9) / 10;

    if (blocks > 10)
        blocks = 10;

    if (blocks < 0)
        blocks = 0;

    int i;

    for (i = 0; i < 10; i++)
    {
        bar[i] = (i < blocks) ?  '#' : '.' ; // '█' : '░';
    }

    bar[10] = '\0';
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
    mvprintw(6, 0, "SSID      : %s", state->connected ? state->ssid : "--");
    char bar[11];

    signal_bar(state->signal_dbm, bar);

    mvprintw(
        7,
        0,
        "Signal    : [%s] %d dBm",
        bar,
        state->signal_dbm
    );
    mvprintw(9, 0, "Press q to quit");
    }

//    if (state->initialized)
//        mvprintw(4, 0, "Core initialized");

//    mvprintw(6, 0, "Press q to quit");

    refresh();
}

void ui_shutdown(void)
{
    endwin();
}
