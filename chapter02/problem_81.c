#include <stdio.h>
#include <assert.h>

int A(int k)
{
    return (-1) << k;
}

int B(int k, int j)
{
    return (~((-1) << k)) << j;
}

int main(int argc, char const *argv[])
{
    assert(A(8) == 0xFFFFFF00);
    assert(B(16, 8) == 0xFFFF00);
    return 0;
}
