#include <stdio.h>

// int main(int argc, char const *argv[])
// {
//     unsigned int x = 0x89ABCDEF;
//     unsigned int y = 0x76543210;
    
//     unsigned int result = ((x << 24) >> 24) |((y >> 8) << 8);

//     printf("%X\n", result);

//     return 0;
// }

unsigned int combine_word(unsigned int x, unsigned int y) {
    return (x & 0xFF) | (y & ~0xFF);
}

int main(int argc, char const *argv[])
{
    unsigned int x = 0x89ABCDEF;
    unsigned int y = 0x76543210;
    
    unsigned int result = combine_word(x, y);

    printf("%X\n", result);

    return 0;
}