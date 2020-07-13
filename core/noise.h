#ifndef NOISE_H
#define NOISE_H

#include "external/open-simplex-noise.h"

static struct osn_context *__osn_context__;

void noise_seed(int seed)
{
    open_simplex_noise(seed, &__osn_context__);
}

float noise(float x)
{
    return open_simplex_noise2(__osn_context__, x, 0.0);
}

float noise2(float x, float y)
{
    return open_simplex_noise2(__osn_context__, x, y);
}

float noise3(float x, float y, float z)
{
    return open_simplex_noise3(__osn_context__, x, y, z);
}

void destroy_noise()
{
    open_simplex_noise_free(__osn_context__);
}

#endif