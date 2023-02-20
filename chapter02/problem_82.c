/*
 * 2.82
 */
#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include <stdlib.h>
#include <inttypes.h>

/* broken when x is INT_MIN */
int A(int x, int y) {
  return ((x < y) == (-x > -y));
}

/*
 * right
 *
 * ((x + y) << 4) + y - x
 *   =>
 * x << 4 - x + y << 4 + y
 *   =>
 * x*16 - x + y*16 + y
 *   whether overflow or not, =>
 * x*15 + y*17
 */
int B(int x, int y) {
  return ((x + y) << 4) + y - x == 17 * y + 15 * x;
}

/*
 * right
 *
 * ~x + ~y + 1
 *   =>
 * ~x + 1 + ~y + 1 - 1
 *   =>
 * -x + -y - 1
 *   =>
 * -(x + y) - 1
 *   =>
 * ~(x + y) + 1 - 1
 *   =>
 * ~(x + y)
 */
int C(int x, int y) {
  return ~x + ~y + 1 == ~(x + y);
}

/*
 * right
 *
 * (ux - uy) == -(unsigned) (y - x)
 *   =>
 * -(ux - uy) == (unsigned) (y - x)
 *   =>
 * (ux - uy) == (unsigned) (x - y)
 */
int D(int x, int y) {
  unsigned ux = (unsigned) x;
  unsigned uy = (unsigned) y;

  return (ux - uy) == -(unsigned) (y - x);
}

/*
 * right
 *
 * x >> 2 << 2
 *   =>
 * x & ~0x3
 *   =>
 * x - num(00/01/10/11)
 *   =>
 * ((x >> 2) << 2) <= x
 */
int E(int x, int y) {
  return ((x >> 2) << 2) <= x;
}

int main(int argc, char* argv[]) {
    // int x, y;
    // x = INT32_MIN;
    // y = 0;
    // printf("%d\n", (x < y) == (-x > -y));
    // printf("%d < %d: %d\n", x, y, (x < y));
    // printf("%d > %d: %d\n", -x, -y, (-x > -y));
    // printf("%d\n", INT32_MIN > 0);
    // printf("%lld > 0 : %d\n", -INT32_MIN, -INT32_MIN > 0);
    printf("%d\n", A(INT32_MIN, 0));
    // The compiler is very intelligent.
    assert(A(INT32_MIN, 0) == 1);


    int x, y;

    srand(0);

    for (size_t i = 0; i < 1000; i++)
    {
        x = rand();
        y = rand();

        assert(B(x, y));
        assert(C(x, y));
        assert(D(x, y));
        assert(E(x, y));
    }
    
    return 0;
}


