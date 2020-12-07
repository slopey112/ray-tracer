#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vector.h"
#include "types.h"
#include "parse.h"

Triangle **parse_obj(char *fname)
{
    FILE *fp = fopen(fname, "r");
    if (fp == NULL)
    {
        printf("Cannot open file %s\n", fname);
        exit(1);
    }
    int vertex_ct = 0, face_ct = 0;
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), fp))
    {
        if (buffer[0] == 'v' && buffer[1] == ' ')
            vertex_ct++;
        if (buffer[0] == 'f')
            face_ct++;
    }
    fseek(fp, 0, SEEK_SET);
    Vector **vertices = malloc(sizeof(Vector *) * vertex_ct);
    Triangle **triangles = malloc(sizeof(Triangle *) * face_ct);
    vertex_ct = 0;
    face_ct = 0;
    while (fgets(buffer, sizeof(buffer), fp))
    {
        if (buffer[0] == 'v' && buffer[1] == ' ')
        {
            double x, y, z;
            sscanf(buffer, "v %lf %lf %lf", &x, &y, &z);
            vertices[vertex_ct] = vector_init(x, y, z);
            vertex_ct++;
        }
        else if (buffer[0] == 'f')
        {
            int a, b, c, g1, g2, g3, g4, g5, g6;
            sscanf(buffer, "f %d/%d/%d %d/%d/%d %d/%d/%d", &a, &g1, &g2, &b, &g3, &g4, &c, &g5, &g6);
            triangles[face_ct] = triangle_init(vertices[a-1], vertices[b-1], vertices[c-1]);
            face_ct++;
        }
    }
    return triangles;
}
