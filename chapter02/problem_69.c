#include <stdio.h>

static int number_of_unsigned_int_bits = sizeof(unsigned) << 3;

unsigned rotate_left(unsigned x, int n)
{
    // 0 <= n < w
    /* pay attention when n == 0 */
    return (x << n) | (x >> (number_of_unsigned_int_bits - n - 1) >> 1);
}

int main(int argc, char const *argv[])
{
    printf("%X\n", rotate_left(1, 1));
    printf("%X\n", rotate_left(3, 2));
    printf("%X\n", rotate_left(0xF00000F3, 8));

    return 0;
}
