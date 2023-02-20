#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <inttypes.h>
#include <stdlib.h>

typedef unsigned float_bits;

// compute (int)f
int32_t float_f2i(float_bits f)
{
    // 1 + 8 + 23
    unsigned sign = f >> 31;
    unsigned exponent = (f >> 23) & 0xFF;
    unsigned fraction = f & 0x7FFFFF;
    unsigned u;

    int32_t E = (int32_t) exponent - 127;
    if (E < 0) {
        return 0;
    } else if (E <= 23)  // 0 <= E <= 23
    {
        u = (1 << 23) | fraction;
        u >>= (23-E);
        if (0 == sign) {
            return u;
        } else
        {
            return ~u + 1;
        }
    } else if (E <= 30) // 23 < E <= 30
    {
        u = (1 << 23) | fraction;
        u <<= (E-23);
        if (0 == sign) {
            return u;
        } else
        {
            return ~u + 1;
        }
    } else
    {
        return INT32_MIN;
    }
}



void test()
{
    unsigned count_inf = 0, count_nan = 0;
    int32_t converted_integer_1, converted_integer_2;
    float f;
    // 
    // for (unsigned i = 0; i <= UINT32_MAX; i++)
    for (unsigned i = 0; i < UINT32_MAX; i++)
    {
        if (i % (1 << 27) == 0) {
            printf("========== i = %u ===========\n", i);
        }

        converted_integer_1 = float_f2i(i);

        f = *(float*)&i;
        converted_integer_2 = (int32_t) f;
        if (converted_integer_1 != converted_integer_2) {
            printf("bit pattern of float=%X, converted_1=%X, converted_2=%X\n", i, converted_integer_1, converted_integer_2);
        }
        assert(converted_integer_1 == converted_integer_2);
        if (isinf(f)) 
            ++count_inf;
        else if (isnan(f))
        {
            ++count_nan;
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
