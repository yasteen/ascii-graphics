#include <asciigraphics.h>
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
	triangle tris[12] = {
		// SOUTH
		{{ {0.0, 0.0, 0.0},    {0.0, 1.0, 0.0},    {1.0, 1.0, 0.0} }},
		{{ {0.0, 0.0, 0.0},    {1.0, 1.0, 0.0},    {1.0, 0.0, 0.0} }},

		// EAST                                                      
		{{ {1.0, 0.0, 0.0},    {1.0, 1.0, 0.0},    {1.0, 1.0, 1.0} }},
		{{ {1.0, 0.0, 0.0},    {1.0, 1.0, 1.0},    {1.0, 0.0, 1.0} }},

		// NORTH                                                     
		{{ {1.0, 0.0, 1.0},    {1.0, 1.0, 1.0},    {0.0, 1.0, 1.0} }},
		{{ {1.0, 0.0, 1.0},    {0.0, 1.0, 1.0},    {0.0, 0.0, 1.0} }},

		// WEST                                                      
		{{ {0.0, 0.0, 1.0},    {0.0, 1.0, 1.0},    {0.0, 1.0, 0.0} }},
		{{ {0.0, 0.0, 1.0},    {0.0, 1.0, 0.0},    {0.0, 0.0, 0.0} }},

		// TOP                                                       
		{{ {0.0, 1.0, 0.0},    {0.0, 1.0, 1.0},    {1.0, 1.0, 1.0} }},
		{{ {0.0, 1.0, 0.0},    {1.0, 1.0, 1.0},    {1.0, 1.0, 0.0} }},

		// BOTTOM                                                    
		{{ {1.0, 0.0, 1.0},    {0.0, 0.0, 1.0},    {0.0, 0.0, 0.0} }},
		{{ {1.0, 0.0, 1.0},    {0.0, 0.0, 0.0},    {1.0, 0.0, 0.0} }}
	};
	mesh m = {12, tris};
	drawMesh(m);
	// fillTriangle(
	// 	(int) (COL / 2 + r * cos(M_PI * x / 180)),
	// 	(int) (ROW + r * sin(M_PI * x / 180)) / 2,
	// 	(int) (COL / 2 + r * cos(M_PI * x / 180 + M_PI * 2 / 3)),
	// 	(int) (ROW + r * sin(M_PI * x / 180 + M_PI * 2 / 3)) / 2,
	// 	(int) (COL / 2 + r * cos(M_PI * x / 180 + M_PI * 4 / 3)),
	// 	(int) (ROW + r * sin(M_PI * x / 180 + M_PI * 4 / 3)) / 2,
	// 	'x');
	x++;
}

int main() {
	startEngine(40, init, run);
	return 0;
}
