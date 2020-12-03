#ifndef VECTOR_H
#define VECTOR_H

typedef struct
{
    double x;
    double y;
    double z;
} Vector;

Vector *vector_init(double x, double y, double z);
double vector_dot(Vector *self, Vector *other);
Vector *vector_cross(Vector *self, Vector *other);
Vector *vector_add(Vector *self, Vector *other);
Vector *vector_minus(Vector *self, Vector *other);
Vector *vector_multiply(Vector *self, double scalar);
#endif
