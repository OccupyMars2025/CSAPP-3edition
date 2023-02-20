#include <stdio.h>

unsigned replace_byte(unsigned x, int i, unsigned char b)
{
    // i can only be 0, 1, 2, 3
    unsigned mask = 0xFF << (i*8);
    return (x & ~mask) | ((unsigned)b << (i*8));
}

int main(int argc, char const *argv[])
{
    unsigned x1 = replace_byte(0x12345678, 2, 0xAB);
    unsigned x2 = replace_byte(0x12345678, 0, 0xAB);

    printf("x1=%X \nx2=%X\n", x1, x2);   

    return 0;
}