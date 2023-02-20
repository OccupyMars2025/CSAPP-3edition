#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int divide_power2(int x, int k)
{   
    /**
     * rounding toward zero
    */
    // // method 1
    // if (x < 0) 
    // {
    //     return (x + (1 << k) - 1) >> k;
    // } else {
    //     return x >> k;
    // }

    // method 2
    int is_negative = x & INT_MIN;
    is_negative && (x = x + (1 << k) - 1);
    return x >> k;
}

int main(int argc, char const *argv[])
{
    int x;
    for (size_t i = 0; i < 100; i++)
    {
        x = rand() % 10000 - 5000;
        for (int k = 0; k < 31; k++)
        {
            printf("%d / %d = %d (%d)\n", x, (1 << k), divide_power2(x, k), x / (1 << k));
            assert(divide_power2(x, k) == x / (1 << k));
        }
    }

    x = 0x80000007;
    assert(divide_power2(x, 1) == x / 2);
    assert(divide_power2(x, 2) == x / 4);
    
    return 0;
}
