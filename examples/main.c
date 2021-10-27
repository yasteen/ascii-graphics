#include <asciigraphics.h>
#include <math.h>
#include <ncurses.h>

int ROW, COL;

int x = 0;
int r = 30;

void init()
{
	getmaxyx(stdscr, ROW, COL);
}

// Runs each iteration
void run()
{
	triangle tris[12] = {
		// SOUTH
		{{{0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {1.0, 1.0, 0.0}}},
		{{{0.0, 0.0, 0.0}, {1.0, 1.0, 0.0}, {1.0, 0.0, 0.0}}},

		// EAST
		{{{1.0, 0.0, 0.0}, {1.0, 1.0, 0.0}, {1.0, 1.0, 1.0}}},
		{{{1.0, 0.0, 0.0}, {1.0, 1.0, 1.0}, {1.0, 0.0, 1.0}}},

		// NORTH
		{{{1.0, 0.0, 1.0}, {1.0, 1.0, 1.0}, {0.0, 1.0, 1.0}}},
		{{{1.0, 0.0, 1.0}, {0.0, 1.0, 1.0}, {0.0, 0.0, 1.0}}},

		// WEST
		{{{0.0, 0.0, 1.0}, {0.0, 1.0, 1.0}, {0.0, 1.0, 0.0}}},
		{{{0.0, 0.0, 1.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 0.0}}},

		// TOP
		{{{0.0, 1.0, 0.0}, {0.0, 1.0, 1.0}, {1.0, 1.0, 1.0}}},
		{{{0.0, 1.0, 0.0}, {1.0, 1.0, 1.0}, {1.0, 1.0, 0.0}}},

		// BOTTOM
		{{{1.0, 0.0, 1.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, 0.0}}},
		{{{1.0, 0.0, 1.0}, {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}}}};
	mesh m = {12, tris};

	float fTheta = x * 0.1;
	mat4 matRotZ = mat4z;
	mat4 matRotX = mat4z;

	matRotZ.m[0][0] = cosf(fTheta);
	matRotZ.m[0][1] = sinf(fTheta);
	matRotZ.m[1][0] = -sinf(fTheta);
	matRotZ.m[1][1] = cosf(fTheta);
	matRotZ.m[2][2] = 1;
	matRotZ.m[3][3] = 1;

	matRotX.m[0][0] = 1;
	matRotX.m[1][1] = cosf(fTheta);
	matRotX.m[1][2] = sinf(fTheta);
	matRotX.m[2][1] = -sinf(fTheta);
	matRotX.m[2][2] = cosf(fTheta);
	matRotX.m[3][3] = 1;

	for (int i = 0; i < m.size; i++)
	{
		m.tris[i].p[0] = mv3norm(matRotZ, m.tris[i].p[0]);
		m.tris[i].p[1] = mv3norm(matRotZ, m.tris[i].p[1]);
		m.tris[i].p[2] = mv3norm(matRotZ, m.tris[i].p[2]);

		m.tris[i].p[0] = mv3norm(matRotX, m.tris[i].p[0]);
		m.tris[i].p[1] = mv3norm(matRotX, m.tris[i].p[1]);
		m.tris[i].p[2] = mv3norm(matRotX, m.tris[i].p[2]);
	}

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

int main()
{
	startEngine(50, init, run);
	return 0;
}
