#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <limits.h>

int main(void) {
    // Declare variables and init where applicable
    int min = INT_MAX;
    int max = INT_MIN;
    int tmp;

    printf("Enter 10 numbers:\n");

    // For 10
    for (int i = 0; i < 10; ++i) {
        // Scan number and store in tmp
        scanf("%d", &tmp);
        // If the new number (tmp) is smaller than the current smallest number, min := tmp
        if (tmp < min) {
            min = tmp;
            // If the new number (tmp) is larger than the current largest number, max := tmp
        } else if (tmp > max) {
            max = tmp;
        }
    }

    // Print results
    printf("Min: %d, max: %d", min, max);

    return 0;
}
