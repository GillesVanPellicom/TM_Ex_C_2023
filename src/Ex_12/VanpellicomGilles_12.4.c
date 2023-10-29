#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

short int rotateNibbleLeft(short int x);

int main(void) {
    short int x = rotateNibbleLeft(31072);
    printf("%b", x);
    return 0;
}

/**
 * Rotates the nibbles in a short int left by one.
 * @param x Short int to be manipulated.
 * @return Rotated short int x.
 */
short int rotateNibbleLeft(short int x) {
    // Shift x left 4. This will create an overshoot of 4 bits.
    // OR this result with x >> 12. The first 4 bits will have data, the rest 0 so or is permitted.
    // Bitmask with 0xFFFF because there will be overshoot because of the first operation.
    // Cast to short int to avoid implementation-defined behavior.

    // Input value in binary
    // Expected: 0111 1001 0110 0000
    // Actual:    111 1001 0110 0000 (leading zero removed)
    printf("%b\n", 31072);

    // print rotate left (sanity check)
    // Expected: 1001 0110 0000 0111
    // Actual:   1001 0110 0000 0111
    printf("%b\n", (x << 4 | x >> 12) & 0xFFFF);
    // Return rotate left
    // Expected: 1001 0110 0000 0111
    // Actual:   1111 1111 1111 1111 1001 0110 0000 0111
    // Exact 16 bit more. Promotion from short int to int against explicit typecast to short int.
    return (short int) ((x << 4 | x >> 12) & 0xFFFF);
}


