#include <stdio.h>
#include <assert.h>

unsigned f2u(float f)
{
    return *(unsigned*)&f;
}

int float_le(float x, float y) 
{
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);

    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;

    return ((ux << 1) == 0 && (uy << 1) == 0) ||  // x = y = 0
        (sx == 1 && sy == 0) ||   // x <=0 , y>=0
        (sx == 1 && sy == 1 && ux >= uy) || // x <= y <= 0
        (sx == 0 && sy == 0 && ux <= uy);  // 0<=x<=y
}

int main(int argc, char const *argv[])
{
    assert(float_le(-0, +0));
    assert(float_le(+0, -0));
    assert(float_le(0, 3));
    assert(float_le(-4, -0));
    assert(float_le(-4, 4));
    
    return 0;
}
