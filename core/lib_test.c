#include <stdio.h>
#include <assert.h>

#include "test.h"

#include "lib.h"

int main()
{
    float a = 45;
    assert(roundp(map(a, 0, 100, 0, 1000), 2) == 450.00);
    assert(roundp(map(a, 1, 100, 0, 1000), 2) != 450.00);

    float b = 145;
    assert(roundp(map(b, 100, 200, 200, 300), 2) == 245.00);
    assert(roundp(map(b, 100, 200, 1000, 2000), 2) == 1450.00);

    passed();

    return 0;
}
