#include <ncurses.h>
#include "slep.h"
#include "ascii_graphics.h"


int ROW, COL;

int main() {
	init_window();
	getmaxyx(stdscr, ROW, COL);
	int width = 10;
	int height = 10;
	int x = 0;
	int y = (ROW - height) / 2;
	while (1) {
		clear();
		drawRect(x, y, width, height, 'f');
		drawTriangle(20, 0, 0, 10, 30, 11, 'f');
		x++;
		refresh();
		msleep(1000);
	}
	getch();
	endwin();
	return 0;
}
