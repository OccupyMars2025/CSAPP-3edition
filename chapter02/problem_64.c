#include <stdio.h>

int any_odd_bit_is_one(unsigned x)
{
    int odd_bit_pattern = 0x55555555;
    int result = x & odd_bit_pattern;

    return result == odd_bit_pattern;
}

int main(int argc, char const *argv[])
{
    printf("%d\n", any_odd_bit_is_one(0x55555555));
    printf("%d\n", any_odd_bit_is_one(0x5555555));
    return 0;
}
