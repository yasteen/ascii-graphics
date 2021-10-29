
#include <math.h>
#include <ncurses.h>

#include "include/graphics3d.h"
#include "include/graphics2d.h"
#include "include/vecmath.h"

void drawMesh(mesh m)
{
	int row, col;
	getmaxyx(stdscr, row, col);
	float r = row;
	float c = col;

	float fov = 45.0;
	mat4 matProj = createProjMat(0.1, 1000.0, fov, r / c * 2, 1.0 / tanf(fov * 0.5 / 180.0 * M_PI));

	for (int i = 0; i < m.size; i++)
	{

		// Translate
		m.tris[i].p[0].z += 3.0;
		m.tris[i].p[1].z += 3.0;
		m.tris[i].p[2].z += 3.0;

		// Project
		vec3 p0 = mv3norm(matProj, m.tris[i].p[0]);
		vec3 p1 = mv3norm(matProj, m.tris[i].p[1]);
		vec3 p2 = mv3norm(matProj, m.tris[i].p[2]);

		// Scale into view
		p0.x = (p0.x + 1) * 0.5 * c;
		p0.y = (p0.y + 1) * 0.5 * r;
		p1.x = (p1.x + 1) * 0.5 * c;
		p1.y = (p1.y + 1) * 0.5 * r;
		p2.x = (p2.x + 1) * 0.5 * c;
		p2.y = (p2.y + 1) * 0.5 * r;

		drawTriangle(p0.x, p0.y, p1.x, p1.y, p2.x, p2.y, 'X');
	}
}

mat4 createProjMat(float near, float far, float fov, float aspratio, float fovrad)
{
	mvprintw(0, 0, "near: %f, far: %f, fov: %f, aspratio: %f, fovrad: %f", near, far, fov, aspratio, fovrad);
	mat4 projmat = mat4z;
	projmat.m[0][0] = aspratio * fovrad;
	projmat.m[1][1] = fovrad;
	projmat.m[2][2] = far / (far - near);
	projmat.m[3][2] = (-far * near) / (far - near);
	projmat.m[2][3] = 1.0;
	projmat.m[3][3] = 0.0;
	return projmat;
}
