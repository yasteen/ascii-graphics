#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include "slep.h"

//static char scale[] = " .:-=+*#%@";	// size 10

void init_window() {
	initscr();
	clear();
	cbreak();		// Input gets immediately sent
	// noecho();
	curs_set(0);		// Set invisible cursor
}

void drawLine(int x0, int y0, int x1, int y1, char c) {
	int dx =  abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
	int dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
	int err = dx + dy, e2;

	while(1) {
		mvaddch(y0, x0, c);
		if (x0 == x1 && y0 == y1) break;
		e2 = 2 * err;
		if (e2 >= dy) { err += dy; x0 += sx; }
		if (e2 <= dx) { err += dx; y0 += sy; }
	}
}

void drawRect(int x, int y, int width, int height, char c) {
	drawLine(x, y, x, y + height, c);
	drawLine(x, y, x + width, y, c);
	drawLine(x + width, y, x + width, y + height, c);
	drawLine(x, y + height, x + width, y + height, c);
}
void fillRect(int x, int y, int width, int height, char c) {
	char * s = malloc(sizeof(char) * (width + 1));
	for (int i = 0; i < width; i++) s[i] = c;
	s[width] = '\0';
	for (int i = 0; i < height; i++) {
		mvaddstr(y + i, x, s);
	}
	free(s);
}


void drawTriangle(int x0, int y0, int x1, int y1, int x2, int y2, char c) {
	drawLine(x0, y0, x1, y1, c);
	drawLine(x1, y1, x2, y2, c);
	drawLine(x2, y2, x0, y0, c);
}

//int main() {
//	init_window();
//	int width = 10;
//	int height = 10;
//	int x = 0;
//	int y = (ROW - height) / 2;
//	while (1) {
//		clear();
//		drawRect(x, y, width, height, 'f');
//		drawTriangle(20, 0, 0, 10, 30, 11, 'f');
//		x++;
//		refresh();
//		msleep(1000);
//	}
//
//	// END PROGRAM
//	getch();
//	endwin();
//	return 0;
//}
