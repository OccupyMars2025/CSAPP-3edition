#include <stdio.h>
#include <limits.h>

int saturating_add(int x, int y)
{
    /*
    int sum = x + y;
    if x >= 0 and y >= 0 and sum < 0, then positive overflow occurs;
    if x < 0 and y < 0 and sum >= 0, then negative overflow occurs

    x >= 0  <==> the most significant bit of x is 0  
    x < 0  <==> the most significant bit of x is 1
    */
    int sum = x + y;
    int mask = INT_MIN;

    // short circuit an assignment statement
    int positive_overflow = !(x & mask) && !(y & mask) && (sum & mask);
    int negative_overflow = (x & mask) && (y & mask) && !(sum & mask);

    (positive_overflow && (sum = INT_MAX)) || (negative_overflow && (sum = INT_MIN));

    return sum;
}

int main(int argc, char const *argv[])
{
    printf("%10X + %10X = %10X\n", 1, 2, saturating_add(1, 2));
    printf("%10X + %10X = %10X\n", INT_MAX, 2, saturating_add(INT_MAX, 2));
    printf("%10X + %10X = %10X\n", -1, INT_MIN, saturating_add(-1, INT_MIN));
    return 0;
}
