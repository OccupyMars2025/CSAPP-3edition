#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int divide_power2(int x, int k)
{
    int is_negative = x & INT_MIN;
    is_negative && (x = x + (1 << k) - 1);
    return x >> k;
}

int mul3div4(int x)
{
    x = (x << 1) + x;
    return divide_power2(x, 2);
}

int main(int argc, char const *argv[])
{
    int x;
    for (size_t i = 0; i < 500; i++)
    {
        x = rand() / 10000 - 5000;
        assert(mul3div4(x) == (3 * x) / 4);
    }
    
    x = 0x87654321;
    assert(mul3div4(x) == x * 3 / 4);
    
    return 0;
}
