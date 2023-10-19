#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void readNames(char (* strArr)[20]);

void printArray(char (* strArr)[20]);

int main(void) {
    char arr[10][20];
    readNames(arr);
    printArray(arr);

    return 0;
}

/**
 * Reads in a list of names
 * Max 10 names, max name length 20
 * @param strArr array to populate
 */
void readNames(char (* strArr)[20]) {
    for (int i = 0; i < 10; ++i) {
        printf("Name %d: ", i + 1);
        // Read in strings, max 19 chars since this string is max 20 chars.
        // One space reserved for null terminator, \0, making 20.
        scanf("%19s", strArr[i]);
        // Remove all newlines from buffer
        while (getchar() != '\n');
        printf("\n");
    }
}

/**
 * Prints out an array of strings
 * Static max length of 20 since I couldn't be bothered to write a nice nD-array length function.
 * @param strArr array to be read.
 */
void printArray(char (* strArr)[20]) {
    for (int i = 0; i < 10; ++i) {
        printf("Name %d is: %s \n", i + 1, strArr[i]);
    }
}