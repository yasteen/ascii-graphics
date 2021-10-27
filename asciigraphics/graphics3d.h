#ifndef ASCII3D_H
#define ASCII3D_H

#include "vecmath.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846 /* pi */
#endif
typedef struct triangle_t
{
    vec3 p[3];
} triangle;

typedef struct mesh_t
{
    size_t size;
    triangle *tris;
} mesh;

void drawMesh(mesh m);
mat4 createProjMat(float near, float far, float fov, float aspratio, float fovrad);

#endif
