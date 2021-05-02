#ifndef ASCII3D_H
#define ASCII3D_H

#include "vecmath.h"

typedef struct triangle_t {
    vec3 p[3];
} triangle;

typedef struct mesh_t {
    triangle * tris;
    size_t size;
} mesh;

void drawMesh(mesh m, mat4 projmat);
mat4 createProjMat(float near, float far, float fov, float aspratio, float fovrad);

#endif
