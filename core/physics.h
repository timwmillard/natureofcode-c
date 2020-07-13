#include "vect.h"

typedef struct Body {
    Vect pos;
    Vect vel;
    Vect acc;
    float mass;
} Body;