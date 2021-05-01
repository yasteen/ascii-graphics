#include "slep.h"
#include "ascii_graphics.h"
#include "engine.h"
#include <math.h>
#include <ncurses.h>

int ROW, COL;

int x = 0;
int r = 30;

void init() {
	getmaxyx(stdscr, ROW, COL);
}

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
	x++;
}

int main() {
	startEngine(40, init, run);
	return 0;
}
