#ifndef VECMATH_H
#define VECMATH_H

#include <stdio.h>

// Type definitions

// Vectors
typedef struct vec_t {
	double * v;
	size_t size;
} vec;

typedef struct vec3_t {
	double x, y, z;
} vec3;


// Matrices
typedef struct mat_t {
	double ** m;
	double rows;
	double cols;
} mat;

typedef struct mat4_t {
	double m[4][4];
} mat4;

// Functions
double dotprod(vec v1, vec v2);
vec matvecprod(mat, vec v);
double mat4prod(mat4 m1, mat4 m2);
vec3 mv3norm(mat4 m, vec3 v);


#endif
