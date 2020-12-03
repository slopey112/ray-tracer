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

void plane_destroy(Plane *self)
{
    free(self->normal);
    free(self->center);
    free(self);
}

Triangle *triangle_init(Vector *p1, Vector *p2, Vector *p3)
{
    Triangle *triangle = malloc(sizeof(Triangle));
    triangle->p1 = p1;
    triangle->p2 = p2;
    triangle->p3 = p3;
    return triangle;
}

void triangle_destroy(Triangle *self)
{
    free(self->p1);
    free(self->p2);
    free(self->p3);
    free(self);
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

int triangle_intersect_point(Triangle *self, Vector *P)
{
    Vector *v0 = vector_minus(self->p2, self->p1);
    Vector *v1 = vector_minus(self->p3, self->p1);
    Vector *v2 = vector_minus(P, self->p1);

    double d00 = vector_dot(v0, v0);
    double d01 = vector_dot(v0, v1);
    double d11 = vector_dot(v1, v1);
    double d20 = vector_dot(v2, v0);
    double d21 = vector_dot(v2, v1);
    double d22 = vector_dot(v2, v2);
    
    double inverse = 1 / (d00 * d11 - d01 * d01);
    double u = (d11 * d20 - d01 * d21) * inverse;
    double v = (d00 * d21 - d01 * d20) * inverse;

    free(v0);
    free(v1);
    free(v2);

    return (u >= 0) && (v >= 0) && (u + v < 1);
}
