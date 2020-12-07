#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <math.h>

#include "vector.h"
#include "types.h"
#include "canvas.h"
#include "parse.h"

#define EPSILON 0.00001

int main()
{
    // Dot Product Test
    Vector *a = vector_init(-6, 8, 0);
    Vector *b = vector_init(5, 12, 0);
    double dot = vector_dot(a, b);
    assert(dot == 66);
    free(a);
    free(b);

    // Ray-plane Intersection Test
    Vector *normal = vector_init(0, 0, 1);
    Vector *center = vector_init(0, 0, 5);
    Plane *plane = plane_init(normal, center);

    Vector *origin = vector_init(0, 0, 10);
    Vector *v = vector_init(0, -1, -1);

    Vector *intersect = plane_ray_intersect(plane, origin, v);
    plane_destroy(plane);
    free(origin);
    free(v);

    assert(fabs(intersect->x - 0) < EPSILON);
    assert(fabs(intersect->y + 5) < EPSILON);
    assert(fabs(intersect->z - 5) < EPSILON);
    free(intersect);

    // Ray-triangle Intersection Test
    Vector *p1 = vector_init(0, 0, 0);
    Vector *p2 = vector_init(10, 0, 0);
    Vector *p3 = vector_init(0, 10, 0);
    Triangle *triangle = triangle_init(p1, p2, p3);

    Vector *test1 = vector_init(50, 0, 0);
    Vector *test2 = vector_init(5, 0, 0);

    int val1 = triangle_intersect_point(triangle, test1);
    int val2 = triangle_intersect_point(triangle, test2);

    assert(val1 == 0);
    assert(val2 == 1);

    triangle_destroy(triangle);
    free(test1);
    free(test2);

    // Canvas Display Test
    // (you should see a thin red horizontal line on the top half of the window.
    Canvas *canvas = canvas_init(100, 100, 20, 20);
    for (int i = 0; i < 100; i++)
    {
        canvas_draw(canvas, i, 10, 255, 0, 0);
    }
    canvas_display(canvas);
    canvas_destroy(canvas);

    // Parse Test
    Triangle **triangles = parse_obj("../scene.obj");
    Vector *p = triangles[0]->p1;
    printf("%f %f %f\n", p->x, p->y, p->z);
    int ct = 42;

    // Visual Test
    Canvas *canvas2 = canvas_init(1000, 750, 5, 5);
    Vector *camera = vector_init(0, 0, 0);
    for (int i = 0; i < canvas2->height; i++)
    {
        for (int j = 0; j < canvas2->width; j++)
        {
            for (int k = 0; k < ct; k++)
            {

                Vector *viewport = canvas_to_viewport(canvas2, j, canvas2->height - i, 1);
                Triangle *triangle = triangles[k];
                Plane *plane = triangle_to_plane(triangle);
                Vector *intercept = plane_ray_intersect(plane, camera, viewport);
                if (triangle_intersect_point(triangle, intercept))
                {
                    canvas_draw(canvas2, j, i, 0, 255, 0);
                }
                free(viewport);
                free(intercept);
            }
        }
    }
    canvas_display(canvas2);
    sleep(60);
    canvas_destroy(canvas2);
}
