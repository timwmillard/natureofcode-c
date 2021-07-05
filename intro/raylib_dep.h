/**
 * @file raylib_dep.h
 * 
 * @author Tim Millard (timwmillard@gmail.com)
 * @brief To replace depricated function in raylib.
 * @version 0.1
 * @date 2021-07-05
 * 
 * @copyright Copyright (c) 2021
 * 
 * LoadImageEx
 * https://github.com/raysan5/raylib/commit/0db0e6acd8980d3790b96a17c407289e3e237371
 * 
 */

#ifndef RAYLIB_DEP_H
#define RAYLIB_DEP_H

#include <raylib.h>
#include <stdlib.h>

const int UNCOMPRESSED_R8G8B8A8 = 7;

// Load image from Color array data (RGBA - 32bit)
// NOTE: Creates a copy of pixels data array
Image LoadImageEx_DEP(Color *pixels, int width, int height)
{
    Image image = { 0 };
    image.data = NULL;
    image.width = width;
    image.height = height;
    image.mipmaps = 1;
    image.format = UNCOMPRESSED_R8G8B8A8;

    int k = 0;

    image.data = (unsigned char *)RL_MALLOC(image.width*image.height*4*sizeof(unsigned char));

    for (int i = 0; i < image.width*image.height*4; i += 4)
    {
        ((unsigned char *)image.data)[i] = pixels[k].r;
        ((unsigned char *)image.data)[i + 1] = pixels[k].g;
        ((unsigned char *)image.data)[i + 2] = pixels[k].b;
        ((unsigned char *)image.data)[i + 3] = pixels[k].a;
        k++;
    }

    return image;
}

#endif
