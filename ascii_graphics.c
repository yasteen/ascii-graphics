#include <ncurses.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include "slep.h"
#include "ascii_graphics.h"


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

// NOTE the array is indexed starting from offset.
void populateLine(int x0, int y0, int x1, int y1, int startY, int * range[2]) {
	// int offset = y0 - startY;
	if (y0 == y1) {
		range[0][y0 - startY] = x0 < x1 ? x0 : x1;
		range[1][y0 - startY] = x0 > x1 ? x0 : x1;
		return;
	}
	int dx =  abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
	int dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
	int err = dx + dy, e2;
	while(1) {
		if (x0 < range[0][y0 - startY]) range[0][y0 - startY] = x0;
		if (x0 > range[1][y0 - startY]) range[1][y0 - startY] = x0;
		if (x0 == x1 && y0 == y1) break;
		e2 = 2 * err;
		if (e2 >= dy) { err += dy; x0 += sx; }
		if (e2 <= dx) { err += dx; y0 += sy; }
	}
}

void fillTriangle(int x0, int y0, int x1, int y1, int x2, int y2, char c) {
	// Get max height
	int height = y0>y1 ? y0-y1 : y1-y0; int h = y0>y2 ? y0-y2 : y2-y0;
	height = height>h ? height : h; h = y1>y2 ? y1-y2 : y2-y1;
	height = height>h ? height : h;

	// Sort x0 <= x1 <= x2
	int swap;
	if (x2 < x0 || x1 < x0) {
		if (x2 < x1) {
			swap = x0; x0 = x2; x2 = swap;
			swap = y0; y0 = y2; y2 = swap;
		} else {
			swap = x0; x0 = x1; x1 = swap;
			swap = y0; y0 = y1; y1 = swap;
		}
	}
	if (x2 < x1) {
		swap = x1; x1 = x2; x2 = swap;
		swap = y1; y1 = y2; y2 = swap;
	}
	int width = x2 - x0;
	int minY = y0 < y1 ? y0 : y1; minY = minY < y2 ? minY : y2;

	// +1 for endpoint
	int * range[2] = { malloc(sizeof(int) * (height + 1)),
					   malloc(sizeof(int) * (height + 1)) };
	for (int i = 0; i <= height; i++) {
		range[0][i] = INT_MAX;
		range[1][i] = INT_MIN;
	}
	populateLine(x0, y0, x1, y1, minY, range);
	populateLine(x1, y1, x2, y2, minY, range);
	populateLine(x0, y0, x2, y2, minY, range);
	// + 1 for null terminator + 1 for endpoint
	char * s = malloc(sizeof(char) * (width + 2));
	for (int i = 0; i < width + 1; i++) s[i] = c;
	s[width + 1] = '\0';
	for (int i = 0; i <= height; i++) {
		mvprintw(minY + i, range[0][i], "%.*s", range[1][i]-range[0][i] + 1, s);
	}
	free(range[0]); free(range[1]); free(s);

}