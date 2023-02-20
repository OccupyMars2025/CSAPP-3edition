#include <stdio.h>
#include <stdlib.h>

int leftmost_one(unsigned x)
{
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;

    return x - (x >> 1);
}

int rightmost_one(unsigned x)
{
    return ~((~x + 1) | x) + 1;
}


int main(int argc, char const *argv[])
{
    unsigned x = UINT_MAX;
    printf("%d\n", leftmost_one(x));
    printf("%d\n\n", rightmost_one(x));

    x = 1 << 31;
    printf("%d\n", leftmost_one(x));
    printf("%d\n\n", rightmost_one(x));

    x = 9;
    printf("%d\n", leftmost_one(x));
    printf("%d\n\n", rightmost_one(x));

    return 0;
}

