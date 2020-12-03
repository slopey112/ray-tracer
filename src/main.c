#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "vector.h"
#include "types.h"
#include "canvas.h"

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
    free(intersect);

    Canvas *canvas = canvas_init(100, 100, 20, 20);
    for (int i = 0; i < 100; i++)
    {
        canvas_draw(canvas, i, 10, 255, 0, 0);
    }
    canvas_display(canvas);
    sleep(5);
    canvas_destroy(canvas);
    return 0;
}
