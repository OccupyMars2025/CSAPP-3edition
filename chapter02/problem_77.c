#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int multiply_17(int x) 
{
    return (x << 4) + x;
}

int multiply_minus_7(int x) 
{
    return x - (x << 3);
}

int multiply_60(int x) 
{
    return (x << 6) - (x << 2);
}

int multiply_negative_112(int x) 
{
    return (x << 4) - (x << 7);
}

int main(int argc, char const *argv[])
{
    int x;
    for (size_t i = 0; i < 1000; i++)
    {
        x = rand() % 10000 - 5000;
        printf("%X, ", x);
        assert(multiply_17(x) == x * 17);
        assert(multiply_minus_7(x) == x * (-7));
        assert(multiply_60(x) == x * 60);
        assert(multiply_negative_112(x) == x * 112);
    }
    
    return 0;
}
