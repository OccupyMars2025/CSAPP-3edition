#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <inttypes.h>
#include <stdlib.h>

typedef unsigned float_bits;

// compute (float) i
float_bits float_i2f(int32_t i)
{
    // float: 1 + 8 + 23
    unsigned sign = ((unsigned)i) >> 31;

}