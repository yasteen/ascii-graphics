#include <ncurses.h>
#include "slep.h"
#include "ascii_graphics.h"
#include <math.h>

int ROW, COL;

int x = 0;
int r = 20;

// Runs each iteration
void run() {
	fillTriangle(
		(int) (COL / 2 + r * cos(M_PI * x / 180)),
		(int) (ROW + r * sin(M_PI * x / 180)) / 2,
		(int) (COL / 2 + r * cos(M_PI * x / 180 + M_PI * 2 / 3)),
		(int) (ROW + r * sin(M_PI * x / 180 + M_PI * 2 / 3)) / 2,
		(int) (COL / 2 + r * cos(M_PI * x / 180 + M_PI * 4 / 3)),
		(int) (ROW + r * sin(M_PI * x / 180 + M_PI * 4 / 3)) / 2,
		'x');
}

int main() {
	init_window();	// Maybe remove from ascii_graphics.c
	getmaxyx(stdscr, ROW, COL);
	// int turn = 100;
	// while (turn--) {
	while (1) {
		erase();
		run();
		printw("Row: %d\n", ROW);
		x++;
		refresh();
		msleep(50);
	}
	getch();
	endwin();
	return 0;
}
