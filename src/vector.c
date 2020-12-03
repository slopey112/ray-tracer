#include <stdlib.h>
#include "vector.h"

Vector *vector_init(double x, double y, double z)
{
    Vector *vector = malloc(sizeof(Vector));
    vector->x = x;
    vector->y = y;
    vector->z = z;
    return vector;
}

double vector_dot(Vector *self, Vector *other)
{
    return self->x * other->x + self->y * other->y + self->z * other->z;
}

Vector *vector_cross(Vector *self, Vector *other)
{
    Vector *cross = malloc(sizeof(Vector));
    cross->x = self->y * other->z - self->z * other->y;
    cross->y = self->z * other->x - self->x * other->z;
    cross->z = self->x * other->y - self->y * other->x;
    return cross;
}

Vector *vector_add(Vector *self, Vector *other)
{
    Vector *sum = malloc(sizeof(Vector));
    sum->x = self->x + other->x;
    sum->y = self->y + other->y;
    sum->z = self->z + other->z;
    return sum;
}

Vector *vector_minus(Vector *self, Vector *other)
{
    Vector *difference = malloc(sizeof(Vector));
    difference->x = self->x - other->x;
    difference->y = self->y - other->y;
    difference->z = self->z - other->z;
    return difference;
}

Vector *vector_multiply(Vector *self, double scalar)
{
    Vector *product = malloc(sizeof(Vector));
    product->x = self->x * scalar;
    product->y = self->y * scalar;
    product->z = self->z * scalar;
    return product;
}
