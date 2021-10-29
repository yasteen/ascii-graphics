#include "include/asciigraphics.h"
#include "include/slep.h"
#include <ncurses.h>

int end_engine = 0;

// Starts the graphics engine
// Note that this function runs until endEngine();
void startEngine(int sleepms, void (*init)(), void (*update)()) {
    initscr();
    clear();
    cbreak();   // Input gets immediately sent
    // noecho();
    curs_set(0);
    init();
    while (!end_engine) {
        erase();
        update();
        refresh();
        msleep(sleepms);
    }
    getch();
    endwin();
}

// Ends the engine at the end of the current loop
void endEngine() {
    end_engine = 1;
}
