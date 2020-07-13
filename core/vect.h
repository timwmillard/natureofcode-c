#ifndef VECT_H
#define VECT_H

#include <math.h>

typedef struct Vect {
    float x;
    float y;
} Vect;

static const Vect vectzero = {0.0f, 0.0f};

static inline Vect vect(const float x, const float y)
{
    Vect vec = {x, y};
    return vec;
}

static inline Vect vect_add(const Vect a, const Vect b)
{
    return vect(a.x + b.x, a.y + b.y);
}

static inline Vect vect_sub(const Vect a, const Vect b)
{
    return vect(a.x - b.x, a.y - b.y);
}

static inline float vect_dot(const Vect a, const Vect b)
{
    return a.x * b.x + a.y * b.y;
}

static inline float vect_mag(const Vect v)
{
    return sqrtf(v.x * v.x + v.y * v.y);
}

static inline Vect vect_mult(const Vect v, float m)
{
    return vect(v.x * m, v.y * m);
}

static inline Vect vect_div(const Vect v, float m)
{
    return m == 0 ? vectzero : vect(v.x / m, v.y / m);
}

static inline Vect vect_normalize(const Vect v)
{
    float mag = vect_mag(v);
    return mag == 0 ? vectzero : vect(v.x/mag, v.y/mag);
}

static inline Vect vect_set_mag(const Vect v, float m)
{
    return vect_mult(vect_normalize(v), m);
}

static inline Vect vect_neg(const Vect v)
{
    return vect(-v.x, -v.y);
}

#endif
