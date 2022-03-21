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
	fill_rect(x, y, 5, 5, '#');
	draw_rect(x - 1, y - 1, 7, 7, '.');
	// fill_triangle(t / 2, 0, t / 3, 20, 10, 5, 'c');
	t += 0.2;
}

int main()
{
	start_engine(50, init, update);
}
