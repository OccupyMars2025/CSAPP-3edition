#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>


int threefourths(int x)
{
    // method 1:
    // int q = x >> 2;
    // int r = x & 0b11;
    // int result = (q << 1) + q + (((r << 1) + r) >> 2);
    // int is_negative = x & INT_MIN;
    // is_negative && (r != 0) && (result = result + 1);
    // return result;

    // method 2:
    int q = x >> 2;
    int r = x & 0b11;
    int result = x - q;
    // if ((x >= 0) && (r != 0))
    //     result = x - q - 1;
    !(x & INT_MIN) && (r != 0) && (result = result - 1);
    return result;
}

int threefourths_2(int x) {
    int y;
    if (x < 0)
        y = (int) ceil((double)x * 0.75);
    else 
        y = (int) floor((double)x * 0.75);
    return y;
}

int main(int argc, char const *argv[])
{
    int x;
    for (size_t i = 0; i < 1000; i++)
    {
        x = rand() % 10000 - 5000;
        printf("x = %d, (3/4)x = %d, %d\n", x, threefourths(x), threefourths_2(x));
        assert(threefourths(x) == threefourths_2(x));
    }

    assert(threefourths(8) == 6);
    assert(threefourths(9) == 6);
    assert(threefourths(10) == 7);
    assert(threefourths(11) == 8);
    assert(threefourths(12) == 9);

    assert(threefourths(-8) == -6);
    assert(threefourths(-9) == -6);
    assert(threefourths(-10) == -7);
    assert(threefourths(-11) == -8);
    assert(threefourths(-12) == -9);
    
    return 0;
}
