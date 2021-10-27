#include <stdio.h>
#include <asciigraphics.h>

float t;

void init()
{
	t = 0;
}

void update()
{
	int x = 5 + 6 * t;
	int y = 30 - 10 * t + t * t;
	fillRect(x, y, 5, 5, '#');
	drawRect(x - 1, y - 1, 7, 7, '.');
	// fillTriangle(t / 2, 0, t / 3, 20, 10, 5, 'c');
	t += 0.2;
}

int main()
{
	startEngine(50, init, update);
}
