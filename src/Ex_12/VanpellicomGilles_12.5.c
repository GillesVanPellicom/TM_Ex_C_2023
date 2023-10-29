#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// Prototypes
void printShortInBinary(short int x);
void scanAndPrintShortInBinary();

int main(void) {
    scanAndPrintShortInBinary();
    return 0;
}

/**
 * Asks a short int as input, then prints the given value and the value translated to binary.
 */
void scanAndPrintShortInBinary() {
    printf("Please input an integer smaller than 2^16: ");
    short int res;
    scanf("%hd*c", &res);
    printf("Input:\t%hd\n",res);
    printf("output:\t");
    printShortInBinary(res);
    printf("\n");
}

/**
 * Prints a short int as binary with a space every nibble.
 * @param x
 */
void printShortInBinary(short int x) {
    for (int i = 16-1; i >= 0; --i) {
        int curr = (x >> i) & 1;
        printf("%d",curr);
        if (i % 4 == 0) {
            printf(" ");
        }
    }
    printf("\n");
}

