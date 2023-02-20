#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <inttypes.h>
#include <stdlib.h>

typedef unsigned float_bits;

// compute 0.5 * f
float_bits float_half(float_bits f)
{
    // 1 + 8 + 23
    unsigned sign = f >> 31;
    unsigned exponent = (f >> 23) & 0xFF;
    unsigned fraction = f & 0x7FFFFF;
    unsigned exp_frac = f & (~(1 << 31)); 
    unsigned last_bit = f & 1;
    unsigned second_last_bit = (f >> 1) & 1;

    /**
     *  
        * round to even, we care about last 2 bits of frac
        *
        * 00 => 0 just >>1
        * 01 => 0 (round to even) just >>1
        * 10 => 1 just >>1
        * 11 => 1 + 1 (round to even) just >>1 and plus 1
   *
    */
    if (0 == exponent)
    {
        fraction >>= 1;
        if (1 == last_bit) {
            if (1 == second_last_bit) {
                fraction += 1;
            }
        }
        return (sign << 31) | (exponent << 23) | fraction;
    } else if (1 == exponent)
    {
        exp_frac >>= 1;

        if (1 == last_bit) {
            if (1 == second_last_bit) {
                exp_frac += 1;
            }
        }

        return (sign << 31) | exp_frac;
    } else if (exponent < 0xFF)
    {
        exponent -= 1;
        return (sign << 31) | (exponent << 23) | fraction;
    } else {
        return f;
    }
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
        u = float_half(i);
        f1 = *(float*)&u;
        
        f = *(float*)&i;
        f2 = 0.5 * f;
        if (isfinite(f1)) {
            if (f1 != f2) {
                printf("i=%X, f1=%X, f2=%X\n", i, *(unsigned *)&f1, *(unsigned *)&f2);
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
    // count_inf: 2, count_nan: 16777213
    printf("count_inf: %d, count_nan: %d\n", count_inf, count_nan);
}

int main(int argc, char const *argv[])
{
    test();

    return 0;
}
