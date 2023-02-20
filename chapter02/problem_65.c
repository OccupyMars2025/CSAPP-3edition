#include <stdio.h>


int have_odd_number_of_ones(unsigned x)
{
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;
    x &= 1;
    return x;
}

int main(int argc, char const *argv[])
{
    printf("%d\n", have_odd_number_of_ones(0b101));
    printf("%d\n", have_odd_number_of_ones(0b1011));
    return 0;
}
