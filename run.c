#include <ncurses.h>
#include "slep.h"
#include "ascii_graphics.h"
#include <math.h>

int ROW, COL;

int x = 0;
int r = 20;

void run() {
	fillTriangle(
		(int) (COL / 2 + r * cos(M_PI * x / 180)),
		(int) (ROW / 2 + 10 + r * sin(M_PI * x / 180)) / 2,
		(int) (COL / 2 + r * cos(M_PI * x / 180 + M_PI * 2 / 3)),
		(int) (ROW / 2 + 10 + r * sin(M_PI * x / 180 + M_PI * 2 / 3)) / 2,
		(int) (COL / 2 + r * cos(M_PI * x / 180 + M_PI * 4 / 3)),
		(int) (ROW / 2 + 10 + r * sin(M_PI * x / 180 + M_PI * 4 / 3)) / 2,
		'x');
}

int main() {
	init_window();
	getmaxyx(stdscr, ROW, COL);
	// int turn = 100;
	// while (turn--) {
	while (1) {
		clear();
		run();
		x++;
		refresh();
		msleep(50);
	}
	getch();
	endwin();
	return 0;
}