#ifndef GRAPHICS2D_H
#define GRAPHICS2D_H

void fillRect(int x, int y, int width, int height, char c);
void drawRect(int x, int y, int width, int height, char c);
void drawLine(int x0, int y0, int x1, int y1, char c);
void drawTriangle(int x0, int y0, int x1, int y1, int x2, int y2, char c);

void fillTriangle(int x0, int y0, int x1, int y1, int x2, int y2, char c);

#endif
