#include "ascii3d.h"
#include "vecmath.h"
#include <math.h>
#include <ncurses.h>

void drawMesh(mesh m, mat4 projmat) {
	if (!projmat) {
		int r, c;
		getmaxyx(stdscr, r, c);
		projmat = createProjMat(0.1,1000.0,90.0,r/c,1.0f/tanf(fov*0.5/180.0*M_PI);
	}
	for (int i = 0; i < m.size; i++) {
		vec3 p0 = mv3norm(
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
}

