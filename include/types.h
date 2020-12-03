#ifndef TYPES_H
#define TYPES_H

#include "vector.h"

typedef struct
{
    Vector *normal;
    Vector *center;
} Plane;

typedef struct
{
    Vector *p1;
    Vector *p2;
    Vector *p3;
} Triangle;

typedef struct
{
    Vector *p1;
    Vector *p2;
    Vector *p3;
    Vector *p4;
} Face;

typedef unsigned int uint;
typedef unsigned char byte;

Triangle *triangle_init(Vector *p1, Vector *p2, Vector *p3);
Plane *triangle_to_plane(Triangle *triangle);
Plane *plane_init(Vector *normal, Vector *center);
Vector *plane_ray_intersect(Plane *self, Vector *origin, Vector *v);
int triangle_intersect_point(Triangle *self, Vector *P);
void triangle_destroy(Triangle *self);
void plane_destroy(Plane *self);

#endif
