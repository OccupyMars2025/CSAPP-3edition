#include <iostream>
#define _GNU_SOURCE 1
#include <math.h>
#include <assert.h>

using namespace std;

int main(int argc, char const *argv[])
{
    // floating point addition:
    // 1. commutative
    // 2. NOT associative
    // float x = 2.14f;
    // float y = -8.97f;
    
    // if (x + y == y + x) {
    //     cout << "x + y = y + x = " << x + y << endl;
    // } 
    // x = (3.14f + 1e10) - 1e10;
    // y = 3.14f + (1e10 - 1e10);
    // if (x == y)
    //     cout << "Strange: x=" << x << ", y=" << y << endl;
    // else
    //     cout << "x != y, x="<< x << ", y=" << y << endl;

    // float temp = 3.14f + 1e10;
    // x = temp - 1e10;
    // temp = 1e10 - 1e10;
    // y = 3.14f + temp;
    // cout << "x=" << x<< ", y=" << y << endl;

    // float x = (1e20 * 1e20) * 1e-20;
    // float y = 1e20 * (1e20 * 1e-20);
    // cout << "x= "<< x << ", y="<< y << endl;

    // // Not associative
    // float temp = 1e20 * 1e20;
    // x = temp * 1e-20;
    // temp = 1e20 * 1e-20;
    // y = 1e20 * temp;
    // cout << "x= "<< x << ", y="<< y << endl;

    // float x = 1e20 * (1e20 - 1e20);
    // float y = 1e20 * 1e20 - 1e20 * 1e20;
    // cout << "x= "<< x << ", y="<< y << endl;

    // float temp = 1e20 * 1e20;
    // y = temp - temp;
    // cout << "x= "<< x << ", y="<< y << ", temp=" << temp <<endl;


    // int32_t x = (int32_t)+1e10;
    // cout << x << endl;
    // cout << (int64_t)pow(2, 31) - 1 << endl;

    // x = (int32_t)-1e10;
    // cout << x << endl;
    // cout << -(int64_t)pow(2, 31) << endl;

    // int32_t x1 = (int32_t)1.99;
    // int32_t x2 = (int32_t)-1.99;
    // cout << "x1="<< x1 << ", x2=" << x2 <<endl;

    float f = 1.0e20;
    double d = 1.0;
    cout << "(f + d) - f = " << (f + d) - f << endl;
    cout << "d = " << d << endl;
    // assert( (f + d) - f == d);

    return 0;
}
