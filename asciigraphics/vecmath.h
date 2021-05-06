#ifndef VECMATH_H
#define VECMATH_H

#include <stdio.h>

// Type definitions

// Vectors
typedef struct vec_t {
	float * v;
	size_t size;
} vec;

typedef struct vec3_t {
	float x, y, z;
} vec3;


// Matrices
typedef struct mat_t {
	float ** m;
	float rows;
	float cols;
} mat;

typedef struct mat4_t {
	float m[4][4];
} mat4;

// Mat4 of zeros
extern const mat4 mat4z;

// Functions
float dotprod(vec v1, vec v2);
vec matvecprod(mat, vec v);
float mat4prod(mat4 m1, mat4 m2);
vec3 mv3norm(mat4 m, vec3 v);


#endif
