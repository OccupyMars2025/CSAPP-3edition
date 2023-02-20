/*
 * 2.89.c
 */
#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include <stdlib.h>

/*
 * most important thing is that all double number come from ints
 */

/* right */
int A(int x, double dx) {
  return (float)x == (float)dx;
}

/* wrong when y is INT_MIN */
int B(int x, double dx, int y, double dy) {
  return dx-dy == (double)(x-y);
}

/* right */
int C(double dx, double dy, double dz) {
  return (dx+dy)+dz == dx+(dy+dz);
}

/*
 * wrong
 *
 * FIXME I don't know what conditions cause false
 */
int D(double dx, double dy, double dz) {
  return (dx*dy)*dz == dx*(dy*dz);
}

/* wrong when dx != 0 and dz == 0 */
int E(double dx, double dz) {
  return dx/dx == dz/dz;
}

int main(int argc, char* argv[]) {
    srand(0);

    int x = rand();
    int y = rand();
    int z = rand();
    double dx = (double)x;
    double dy = (double)y;
    double dz = (double)z;

    printf("%x %x %x\n", x, y, z);

    assert(A(x, dx));
    assert(!B(0, (double)0, INT_MIN, (double)INT_MIN));
    assert(C(dx, dy, dz));
    /* magic number, brute force attack */
    assert(!D((double)(int)0x64e73387, (double)(int)0xd31cb264, (double)(int)0xd22f1fcd));
    assert(!E(dx, (double)(int)0));

    // test D
    double x1 = (double)(int)0x64e73387;  // 1692873607
    double x2 = (double)(int)0xd31cb264;  // -753094044
    double x3 = (double)(int)0xd22f1fcd;  // -768663603
    // x1 = (double) INT_MIN - 1;
    // x2 = (double) INT_MIN;
    // x3 = (double) INT_MIN + 2;
    printf("%f, %f, %f\n", x1, x2, x3); // 1692873607.000000, -753094044.000000, -768663603.000000
    printf("%f\n", (x1 * x2) * x3);  // 979963870399385375233540096.000000
    printf("%f\n", x1 * (x2 * x3));  // 979963870399385512672493568.000000

    // find cases for test D that yields 0
    int count = 0;
    double product_1, product_2;
    for (int i = 0; i < INT_MAX; i++)
    {
        for (int j = i; j < INT_MAX; j++)
        {
            for (int k = j; k < INT_MAX; k++)
            {
                x1 = (double) i;
                x2 = (double) j;
                x3 = (double) k;
                product_1 = (x1 * x2) * x3;
                product_2 = x1 * (x2 * x3);
                if (product_1 != product_2)
                {
                    printf("%f, %f, %f\n", x1, x2, x3);
                    printf("%f\n", product_1);  
                    printf("%f\n", product_2);
                    // exit(0);  
                    count++;
                    if (10 == count)
                    {
                        exit(0);
                    }
                }
            }
            
        }
        
    }
    

    return 0;
}