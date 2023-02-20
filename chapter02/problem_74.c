#include <stdio.h>
#include <assert.h>
#include <limits.h>

int tsub_ok(int x, int y)
{
    /**
     * If x >= 0 and y < 0 and difference < 0, then positive overflow occurs.
     * If x < 0 and y >= 0 and difference >= 0, then negative overflow occurs.
     * 
     * x >= 0  <==> the most significant bit of x is 0  
       x < 0  <==> the most significant bit of x is 1
    */
    int difference = x - y;
    int mask = INT_MIN;

    // short circuit an assignment statement
    int positive_overflow = !(x & mask) && (y & mask) && (difference & mask);
    int negative_overflow = (x & mask) && !(y & mask) && !(difference & mask);

    (positive_overflow && (difference = INT_MAX)) || (negative_overflow && (difference = INT_MIN));

    return difference;
}

int main(int argc, char const *argv[])
{
    assert(tsub_ok(INT_MAX, -1) == INT_MAX);
    assert(tsub_ok(3, 2) == 1);
    assert(tsub_ok(INT_MIN + 3, 10) == INT_MIN);
    
    return 0;
}
