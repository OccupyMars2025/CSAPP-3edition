#include <stdio.h>

int lower_one_mask(int n)
{
    // // 1 <= n <= w
    // int mask = 1 << (n - 1);
    // mask = (mask << 1) - 1;

    // return mask;

    int w = sizeof(int) << 3;
    return (unsigned) -1 >> (w - n);
}

int main(int argc, char const *argv[])
{
    printf("%X\n", lower_one_mask(6));
    printf("%X\n", lower_one_mask(1));
    printf("%X\n", lower_one_mask(32));
    
    return 0;
}
