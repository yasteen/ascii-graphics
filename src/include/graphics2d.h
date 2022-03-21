#ifndef GRAPHICS2D_H
#define GRAPHICS2D_H

void fill_rect(int x, int y, int width, int height, char c);
void draw_rect(int x, int y, int width, int height, char c);
void draw_line(int x0, int y0, int x1, int y1, char c);
void draw_triangle(int x0, int y0, int x1, int y1, int x2, int y2, char c);

void fill_triangle(int x0, int y0, int x1, int y1, int x2, int y2, char c);

#endif
