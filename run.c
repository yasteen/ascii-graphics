#include <ncurses.h>
#include "slep.h"
#include "ascii_graphics.h"

int ROW, COL;

int x = 0;

void run() {
	
}

// int turn = 10;
int main() {
	init_window();
	getmaxyx(stdscr, ROW, COL);
	while (1) {
		clear();
		run();
		x++;
		refresh();
		msleep(100);
	}
	getch();
	endwin();
	return 0;
}