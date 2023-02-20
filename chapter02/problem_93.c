#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <inttypes.h>

typedef unsigned float_bits;

float_bits float_absolute_value(float_bits f)
{
    // 1 + 8 + 23
    unsigned sign = f >> 31;
    unsigned exponent = (f >> 23) & 0xFF;
    unsigned fraction = f & 0x7FFFFF;

    if (0xFF == exponent && 0 != fraction) // NaN
    {
        return f;
    } else {
        return (f << 1) >> 1;
    }
}


void test()
{
    float f, f2;
    float_bits u;
    for (unsigned i = 0; i < UINT32_MAX; i++)
    {
        f = *(float*)&i;
        u = float_absolute_value(i);
        f2 = *(float*)&u;
        if (isfinite(f2))
        {
            assert(f2 == fabs(f));
        } else 
        {
            assert((isnan(f2) && isnan(f)) || (isinf(f2) && isinf(f)));
        } 
    }
}

int main(int argc, char const *argv[])
{
    test();

    return 0;
}
