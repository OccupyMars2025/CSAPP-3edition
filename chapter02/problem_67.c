#include <stdio.h>


/*
https://www.open-std.org/jtc1/sc22/wg14/www/docs/n1570.pdf

In section 6.5.7 Bitwise shift operators of c11 standard, it said

If the value of the right operand is negative or is greater than or 
equal to the width of the promoted left operand, the behavior it undefined.
 */
// int int_size_is_32()
// {
//     // set_msb is not zero <==> word size >= 32
//     int set_msb = 1 << 31;

//     // beyond_msb is zero <==> word size <= 32
//     int beyond_msb = 1 << 32;

//     return set_msb && (!beyond_msb);
// }

int int_size_is_32()
{
    // set_msb is not zero <==> word size >= 32
    int set_msb = 1 << 31;

    // beyond_msb is zero <==> word size <= 32
    int beyond_msb = set_msb << 1;

    return set_msb && (!beyond_msb);
}

int int_size_is_at_least_32(void)
{
    // set_msb is not zero <==> word size >= 32
    int set_msb = 1 << 31;

    return set_msb != 0;
}

int int_size_is_at_least_16(void)
{
    // set_msb is not zero <==> word size >= 16
    int set_msb = 1 << 15;

    return set_msb != 0;
}

int main(int argc, char const *argv[])
{
    printf("%d\n", int_size_is_32());
    printf("%d\n", int_size_is_at_least_32());
    printf("%d\n", int_size_is_at_least_16());

    return 0;
}
