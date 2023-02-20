/*
 * 练习题 2.58
 *
 * 编写过程 is_little_endian，当在小端法机器上编译和运行时返回 1，在大端法机器上
 * 编译运行时返回 0。这个程序应该可以运行在任何机器上，无论机器的字长是多少。
 */

#include <stdio.h>

int is_little_endian() {
    int i = 1;
    unsigned char *p = (unsigned char *) &i;
    return p[0];
}

int main(int argc, char const *argv[])
{
    printf("is little endian: %d\n", is_little_endian());
    return 0;
}
