#include <stdio.h>
#include <assert.h>

// The function on the textbook can’t extract negetive number from packet_t word.
typedef unsigned packed_t;

int xbyte(packed_t word, int bytenum)
{

    // 3, 2, 1, 0
    int result = ((int) word) << ((sizeof(word) - 1 - bytenum) << 3);
    result = result >> ((sizeof(word) - 1) << 3);

    return result;
}

int main(int argc, char const *argv[])
{   
    // packed_t word = 0x12345678;
    // assert(extract_byte(word, 0) == 0x78);
    // assert(extract_byte(word, 1) == 0x56);
    // assert(extract_byte(word, 2) == 0x34);
    // assert(extract_byte(word, 3) == 0x12);

    assert(xbyte(0xAABBCCDD, 0) == 0xFFFFFFDD);
    assert(xbyte(0xAABBCCDD, 1) == 0xFFFFFFCC);
    assert(xbyte(0xAABBCCDD, 2) == 0xFFFFFFBB);
    assert(xbyte(0xAABBCCDD, 3) == 0xFFFFFFAA);

    return 0;
}

