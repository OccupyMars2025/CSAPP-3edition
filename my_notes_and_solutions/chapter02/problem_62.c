#include <stdio.h>

int int_shifts_are_arithmetic()
{
    int i = -1;
    i = i >> 1;
    return i == -1;
}

int main(int argc, char const *argv[])
{
    printf("%d\n", int_shifts_are_arithmetic());
    return 0;
}
