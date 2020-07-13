#ifndef LIB_H
#define LIB_H

#if defined(__GNUC__)
#   define    HUGE_VAL     __builtin_huge_val()
#   define    HUGE_VALF    __builtin_huge_valf()
#   define    HUGE_VALL    __builtin_huge_vall()
#   define    NAN          __builtin_nanf("0x7fc00000")
#else
#   define    HUGE_VAL     1e500
#   define    HUGE_VALF    1e50f
#   define    HUGE_VALL    1e5000L
#   define    NAN          __nan()
#endif

#define INFINITY    HUGE_VALF

float map(float value, float start1, float stop1, float start2, float stop2)
{
    return (value - start1) / (stop1 - start1) * (stop2 - start2) + start2;
}

int mapi(int value, int start1, int stop1, int start2, int stop2)
{
    return (value - start1) / (stop1 - start1) * (stop2 - start2) + start2;
}

// TODO

// float max(float a, float b)
// float min(float a, float b)

#endif