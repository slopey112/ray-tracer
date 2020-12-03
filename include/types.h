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

Triangle *triangle_init(Vector *p1, Vector *p2, Vector *p3);
Plane *triangle_to_plane(Triangle *triangle);
Plane *plane_init(Vector *normal, Vector *center);
Vector *plane_ray_intersect(Plane *self, Vector *origin, Vector *v);
