#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <inttypes.h>

typedef unsigned float_bits;

// compute 2*f using bit-level manipulation
float_bits float_twice(float_bits f)
{
    // 1 + 8 + 23 : bits[0:32]
    unsigned sign = f >> 31;
    unsigned exponent = (f >> 23) & 0xFF;
    unsigned fraction = f & 0x7FFFFF;

    if (0 == exponent) {
        fraction <<= 1;
    } else if (exponent < 0xFF - 1)
    {
        exponent += 1;
    } else if (0xFF - 1 == exponent)
    {
        exponent = 0xFF;
        fraction = 0;
    } else
    {
        return f;
    } 

    return (sign << 31) | (exponent << 23) | fraction;
}

void test()
{
    float f, f1, f2;
    unsigned u;
    unsigned count_nan = 0, count_inf = 0;
    for (unsigned i = 0; i < UINT32_MAX; i++)
    {
        if (i % (1 << 27) == 0) {
            printf("========== i = %u ===========\n", i);
        }
        u = float_twice(i);
        f1 = *(float*)&u;
        
        f = *(float*)&i;
        f2 = 2 * f;
        if (isfinite(f1)) {
            if (f1 != f2) {
                printf("i=%X, f1=%f, f2=%f\n", i, f1, f2);
            }
            assert(f1 == f2);
        } else if (isnan(f1)) {
            if (!isnan(f2)) {
                printf("i=%X, f1=%f, f2=%f\n", i, f1, f2);
            }
            assert(isnan(f2));
            ++count_nan;
        } else if (isinf(f1))
        {
            if (!isinf(f2)) {
                printf("i=%X, f1=%f, f2=%f\n", i, f1, f2);
            }
            assert(isinf(f2));
            ++count_inf;
        } else
        {
            printf("Strange !!! i=%X, f1=%f, f2=%f\n", i, f1, f2);
        }
    }
    // count_inf: 16777218, count_nan: 16777213
    printf("count_inf: %d, count_nan: %d\n", count_inf, count_nan);
}

int main(int argc, char const *argv[])
{
    test();

    return 0;
}
