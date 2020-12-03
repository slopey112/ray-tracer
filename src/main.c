#include <stdlib.h>
#include <stdio.h>
#include "vector.h"
#include "types.h"

int main()
{
    Vector *a = vector_init(-6, 8, 0);
    Vector *b = vector_init(5, 12, 0);
    double dot = vector_dot(a, b);
    printf("%f\n", dot);
    free(a);
    free(b);

    Vector *normal = vector_init(0, 0, 1);
    Vector *center = vector_init(0, 0, 5);
    Plane *plane = plane_init(normal, center);

    Vector *origin = vector_init(0, 0, 10);
    Vector *v = vector_init(0, -1, -1);

    Vector *intersect = plane_ray_intersect(plane, origin, v);
    free(normal);
    free(center);
    free(plane);
    free(origin);
    free(v);

    printf("%f %f %f\n", intersect->x, intersect->y, intersect->z);
    return 0;
}
