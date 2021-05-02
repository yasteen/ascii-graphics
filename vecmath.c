#include "vecmath.h"
#include <stdlib.h>
#include <stdio.h>

const mat4 mat4z = {{
{0,0,0,0},
{0,0,0,0},
{0,0,0,0},
{0,0,0,0}}};

// Calculates the dot product of two vectors
float dotprod(vec v1, vec v2) {
	if (v1.size != v2.size) {
		fprintf(stderr, "Invalid vectors for dot product.\n");
		exit(1);
	}
	int product = 0;
	for (int i = 0; i < v1.size; i++) {
		product += v1.v[i] * v2.v[i];
	}
	return product;
}

// Multiplies a matrix with a vector
vec matvecprod(mat m, vec v) {
	if (m.cols != v.size) {
		fprintf(stderr, "Invalid matrix/vector size.\n");
		exit(1);
	}
	float * product = malloc(sizeof(float) * m.rows);
	for (int i = 0; i < m.rows; i++) {
		product[i] = 0;
		for (int j = 0; j < m.cols; j++) {
			product[i] += m.m[i][j] * v.v[j];
		}
	}
	vec result = {product, m.rows};
	return result;
}

// Calculates the product of two matrices
float mat4prod(mat4 m1, mat4 m2) {
	return 0; //!!!
}

vec3 mv3norm(mat4 m, vec3 v) {
	vec3 ans;
	ans.x    = v.x*m.m[0][0] + v.y*m.m[1][0] + v.z*m.m[2][0] + m.m[3][0];
	ans.y    = v.x*m.m[0][1] + v.y*m.m[1][1] + v.z*m.m[2][1] + m.m[3][1];
	ans.z    = v.x*m.m[0][2] + v.y*m.m[1][2] + v.z*m.m[2][2] + m.m[3][2];
	float w = v.x*m.m[0][3] + v.y*m.m[1][3] + v.z*m.m[2][3] + m.m[3][3];
	if (w != 0.0f) { ans.x /= w; ans.y /= w; ans.z /= w; }
	return ans;
}

