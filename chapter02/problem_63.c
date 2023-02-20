#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>  

static int number_of_int_bits = sizeof(int) << 3;

unsigned srl(unsigned x, int k) 
{
    assert(k > 0);
    unsigned x_sra = ((int) x) >> k;
    // Caution: you cannot write as follows:
    // unsigned mask = 1 << (number_of_int_bits - k) - 1;
    unsigned mask = (1 << (number_of_int_bits - k)) - 1;
    return x_sra & mask;
}

int sra(int x, int k) 
{
    assert(k > 0);
    int x_srl = ((unsigned) x) >> k;

    // 0...0 or  0..010..0
    int sign = x_srl & (1 << (number_of_int_bits - k - 1));

    int mask = (1 << (number_of_int_bits - k)) - 1;
    // Caution: this makes use of overflow
    mask = (~mask) + ((sign << 1) ^ (1 << (number_of_int_bits -k)));

    return x_srl | mask;
}

int main(int argc, char const *argv[])
{
    unsigned x1, x1_srl;
    int x2, x2_sra;
    int shift_amount;

    /* initialize random seed: */
    srand (time(NULL));

    for (size_t i = 0; i < 100; i++)
    {
        x1 = rand();
        x2 = rand() + INT_MIN;

        for (shift_amount = 1; shift_amount < number_of_int_bits; ++shift_amount)
        {
            printf("=========shift amount = %d\n", shift_amount);

            x1_srl = x1 >> shift_amount;
            printf("x1=   %d\nx1_srl=%d\n", x1, x1_srl);
            assert(x1_srl == srl(x1, shift_amount));

            x2_sra = x2 >> shift_amount;
            printf("x2=   %d\nx2_sra=%d\n", x2, x2_sra);
            assert(x2_sra == sra(x2, shift_amount));

        }     
    }
    return 0;
}
