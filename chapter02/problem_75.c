#include <stdio.h>
#include <assert.h>
#include <inttypes.h>
#include <stdlib.h>

int signed_high_prod(int x, int y)
{
    int64_t prod = ((int64_t) x) * ((int64_t) y);
    return (int) (prod >> 32);
}

unsigned unsigned_high_prod(unsigned x, unsigned y)
{
    int sign_of_x = x >> 31;
    int sign_of_y = y >> 31;
    int part1 = 0;
    int part2 = 0;
    (sign_of_x == 1) && (part1 = y);
    (sign_of_y == 1) && (part2 = x);

    return signed_high_prod(x, y) + part1 + part2;
}

unsigned standard_unsigned_high_prod(unsigned x, unsigned y)
{
    uint64_t prod = ((uint64_t) x) * ((uint64_t) y);
    return (unsigned) (prod >> 32);
}

int main(int argc, char const *argv[])
{
    unsigned x, y;

    for (size_t i = 0; i < 100; i++)
    {
        x = rand() % 2000 + UINT32_MAX - 1000;
        y = rand() + UINT32_MAX / 2;
        printf("high-order 32 bits of %10X + %10X = %10X\n", x, y, standard_unsigned_high_prod(x, y));
        assert(unsigned_high_prod(x, y) == standard_unsigned_high_prod(x, y));
    }
    
    return 0;
}
