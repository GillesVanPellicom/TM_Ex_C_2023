#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void printNibble(short int x, short int nibbleIndex);
void printNibbles(short int x);

int main(void) {
    printf("Input a number [-2^15, 2^15]:");
    short int res;
    scanf("%hd", &res);
    printf("Input:\t%hd\n",res);
    printf("Output:\t");
    printNibbles(res);
    return 0;
}

/**
 * Print all nibbles of a 16 bit short, respecting MSB and LSB order.
 * @param x Short int to be read.
 */
void printNibbles(short int x) {
    for (int i = 3; i > -1; --i) {
        printNibble(x, (short int) i);
        printf(" ");
    }
    printf("\n");
}

/**
 * Prints out a single nibble of a 16 bit short int by index.
 * @param x Short int to be read.
 * @param nibbleIndex Nibble to be printed. nibbleIndex ∈ {0, 1, 2, 3}
 */
void printNibble(short int x, short int nibbleIndex) {
    x >>= nibbleIndex*(short int)4;
    x &= 0xF;
    printf("%x", x);
}