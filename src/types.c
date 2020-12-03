#include <stdlib.h>
#include "types.h"

Vector *plane_ray_intersect(Plane *self, Vector *origin, Vector *v)
{
    // origin - dot(w, normal) / dot(v, normal) * v = point
    // where w = origin - center

    Vector *w = vector_minus(origin, self->center);
    double product1 = vector_dot(w, self->normal);
    free(w);
    double product2 = vector_dot(v, self->normal);
    Vector *proj_v = vector_multiply(v, product1 / product2);
    Vector *P = vector_minus(origin, proj_v);
    free(proj_v);
    return P;
}

Plane *plane_init(Vector *normal, Vector *center)
{
    Plane *plane = malloc(sizeof(Plane));
    plane->normal = normal;
    plane->center = center;
    return plane;
}

Triangle *triangle_init(Vector *p1, Vector *p2, Vector *p3)
{
    Triangle *triangle = malloc(sizeof(Triangle));
    triangle->p1 = p1;
    triangle->p2 = p2;
    triangle->p3 = p3;
    return triangle;
}

Plane *triangle_to_plane(Triangle *triangle)
{
    Vector *U = vector_minus(triangle->p2, triangle->p1);
    Vector *V = vector_minus(triangle->p3, triangle->p1);
    Vector *cross = vector_cross(U, V);
    free(U);
    free(V);
    
    Plane *plane = plane_init(cross, triangle->p1);
    return plane;
}
