#include <stdio.h>

// get the most significant byte
int get_msb(int x) {
    int shift_amount = (sizeof(x) - 1) << 3;
    int shifted_val = x >> shift_amount;
    return shifted_val & 0xFF;
}

int answer_to_A(int x) {
    return !(x + 1);
}

int answer_to_B(int x) {
    return !x;
}

int answer_to_C(int x) {
    return !((x & 0xFF) - 0xFF);
}

int answer_to_D(int x) {
    int shifted_amount = (sizeof(x) - 1) << 3;
    return !(x >> shifted_amount);
}




