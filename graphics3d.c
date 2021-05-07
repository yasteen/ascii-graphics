#include "asciigraphics/graphics3d.h"
#include "asciigraphics/graphics2d.h"
#include "asciigraphics/vecmath.h"
#include <math.h>
#include <ncurses.h>

void drawMesh(mesh m) {
		int r, c;
		getmaxyx(stdscr, r, c);
		mat4 matProj = createProjMat(0.1,1000.0,90.0,r/c,1.0f/tanf(90.0*0.5/180.0*M_PI));

	for (int i = 0; i < m.size; i++) {
		vec3 p0 = mv3norm(matProj, m.tris[i].p[0]);
		vec3 p1 = mv3norm(matProj, m.tris[i].p[1]);
		vec3 p2 = mv3norm(matProj, m.tris[i].p[2]);

		drawTriangle(p0.x, p0.y, p1.x, p1.y, p2.x, p2.y, 'X');
	}
}

mat4 createProjMat(float near, float far, float fov, float aspratio, float fovrad) {
	mat4 projmat = mat4z;
	projmat.m[0][0] = aspratio * fovrad;
	projmat.m[1][1] = fovrad;
	projmat.m[2][2] = far / (far - near);
	projmat.m[3][2] = (-far*near)/(far-near);
	projmat.m[2][3] = 1.0;
	projmat.m[3][3] = 0.0;
	return projmat;
}

