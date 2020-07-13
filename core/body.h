#ifndef BODY_H
#define BODY_H

#include <stdlib.h>

#include "vect.h"

typedef struct Body {
    Vect pos;
    Vect vel;
    Vect acc;
    float mass;
} Body;

Body *body_alloc()
{
    return (Body *) malloc(sizeof(Body));
}

void body_init(Body *body, Vect pos, float mass)
{
    body->pos = pos;
    body->vel = (Vect) {0.0, 0.0};
    body->acc = (Vect) {0.0, 0.0};
    body->mass = mass;
}

Body *body_create(Vect pos, float mass)
{
    // Can't have zero mass body
    if (mass==0)
        return NULL;

    Body *body = body_alloc();
    if (!body)
        return NULL;

    body_init(body, pos, mass);

    return body;
}

Body *body_create_xy(float x, float y, float mass)
{
    Vect pos = vect(x, y);
    return body_create(pos, mass);
}

void body_apply_force(Body *body, Vect force)
{
    force = vect_div(force, body->mass);
    body->acc = vect_add(body->acc, force);
}

void body_apply_gravity(Body *body, Vect force)
{
    body->acc = vect_add(body->acc, force);
}

void body_update(Body *body)
{
    body->vel = vect_add(body->vel, body->acc);
    body->pos = vect_add(body->pos, body->vel);

    body->acc = vectzero;
}

void body_destroy(Body *body)
{
    free(body);
}

#endif
