#include <ncurses.h>

#include "../internal/ui.h"

static void format_speed(double bytes_per_second,
                         char *buffer,
                         size_t size)
{
    if (bytes_per_second < 1024.0)
    {
        snprintf(buffer, size, "%.0f B/s", bytes_per_second);
    }
    else if (bytes_per_second < 1024.0 * 1024.0)
    {
        snprintf(buffer,
                 size,
                 "%.1f KB/s",
                 bytes_per_second / 1024.0);
    }
    else
    {
        snprintf(buffer,
                 size,
                 "%.1f MB/s",
                 bytes_per_second / (1024.0 * 1024.0));
    }
}

int ui_init(void)
{
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);

    return 0;
}

static void format_bytes(
    unsigned long long bytes,
    char *buffer,
    size_t size)
{
    if (bytes < 1024)
    {
        snprintf(buffer, size, "%llu B", bytes);
    }
    else if (bytes < 1024ULL * 1024)
    {
        snprintf(buffer,
                 size,
                 "%.1f KB",
                 bytes / 1024.0);
    }
    else if (bytes < 1024ULL * 1024 * 1024)
    {
        snprintf(buffer,
                 size,
                 "%.1f MB",
                 bytes / (1024.0 * 1024.0));
    }
    else
    {
        snprintf(buffer,
                 size,
                 "%.1f GB",
                 bytes / (1024.0 * 1024.0 * 1024.0));
    }
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
    mvprintw(5, 0, "Gateway   : %s", state->connected ? state->gateway : "--");

    mvprintw(7, 0, "SSID      : %s", state->connected ? state->ssid : "--");
    char bar[11];
    signal_bar(state->signal_dbm, bar);
    mvprintw(8, 0, "Signal    : [%s] %d dBm", bar, state->signal_dbm);

    char rx[32];
    char tx[32];

    char down[32];
    char up[32];

    format_bytes(state->rx_bytes, rx, sizeof(rx));
    format_bytes(state->tx_bytes, tx, sizeof(tx));

    format_speed(state->down_speed, down, sizeof(down));
    format_speed(state->up_speed, up, sizeof(up));
    
    mvprintw(10, 0, "RX        : %-10s Down : %s", rx, down);
    mvprintw(11, 0, "TX        : %-10s Up   : %s", tx, up);

    mvprintw(13, 0, "Ping      : %.2f ms", state->ping_ms);

    mvprintw(15, 0, "Press q to quit");

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
