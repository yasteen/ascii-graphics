#include "include/engine.h"
#include "include/slep.h"
#include <ncurses.h>

int is_engine_ended = 0;

// Starts the graphics engine
// Note that this function runs until end_engine();
void start_engine(int sleepms, void (*init)(), void (*update)())
{
    initscr();
    clear();
    cbreak(); // Input gets immediately sent
    // noecho();
    curs_set(0);
    init();
    while (!is_engine_ended)
    {
        erase();
        update();
        refresh();
        msleep(sleepms);
    }
    getch();
    endwin();
}

// Ends the engine at the end of the current loop
void end_engine()
{
    is_engine_ended = 1;
}
