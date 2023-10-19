#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>

// Prototypes
bool readIntegersInOrderAsc(int* arr, int n);

bool insertIntegerInSortedArray(int* arr, int x, int length);

bool insertInteger(int* arr, int x, int index, int length);

void printIntegerArray(int* arr, int length);


int main(void) {
    // Declare array
    int arr[10];

    // Set tail of array to 0 to negate compiler-specific behavior.
    // gcc initializes an empty array with 0's. MSVC just keeps whatever is in memory at the time of creation.
    // This caused false-positives in a dirty-check in insertInteger()
    arr[9] = 0;

    // Ask for base input
    printf("Please input 9 integers in ascending order:\n");
    if (!readIntegersInOrderAsc(arr, 9)) {
        // Error
        return 1;
    }
    // Ask for number to be inserted
    printf("Now input an integer to be inserted in the previous list: ");
    int x;
    scanf("%d%*c", &x);

    // Array length = size of the total array / size of the datatype for the array.
    int length = sizeof(arr) / sizeof(arr[0]);
    // Insert number
    if (!insertIntegerInSortedArray(arr, x, length)) {
        // Error
        return 1;
    }

    // Print result
    printIntegerArray(arr, length);


    return 0;
}

/**
 * Reads integers in ascending order
 * @param arr array to be populated
 * @param n amount of integers to be read in
 * @return true if success, false if fail
 */
bool readIntegersInOrderAsc(int* arr, int n) {
    int tmp;
    for (int i = 0; i < n; ++i) {
        printf("Integer %d: ", i + 1);
        scanf("%d%*c", &tmp);
        printf("\n");
        // If it's not the first iteration and the previous numbers are larger than tmp
        if (i != 0 && arr[i - 1] > tmp) {
            // Integers have not been given in order
            fprintf(stderr, "Error: readIntegersInOrderAsc(): input has to be given in ascending order.");
            return false;
        }
        arr[i] = tmp;
    }
    return true;
}

/**
 * Inserts an integer in the correct spot in a sorted array. O(n)
 * (I could have implemented something more efficient, E.g. a binary search derivative,
 * but that's a lot of work for arrays with n <= 10.)
 * @param arr array to be manipulated
 * @return true if success, false if fail.
 */
bool insertIntegerInSortedArray(int* arr, int x, int length) {
    for (int i = 0; i < length; ++i) {
        if (x <= arr[i]) {
            // Index found
            // Return result from insertInteger() in case that function throws an error.
            return insertInteger(arr, x, i, length);
        }
    }
    // No insertable location found (unreachable)
    return false;
}

/**
 * Inserts an integer into an array by index.
 * @param arr array to be manipulated
 * @param x integer to be inserted
 * @param index index of insertion
 * @param length length of the array
 * @return true if success, false if fail.
 */
bool insertInteger(int* arr, int x, int index, int length) {
    // Sketchy semi-secure check to see if insertion is possible.
    if (arr[length - 1] != 0) {
        // No space for shift right
        fprintf(stderr,
                "Error: insertInteger(): The given array does not have the required tail space for this operation");
        return false;
    }

    // reverse-iterative shift right until index is hit
    for (int i = length-1; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = x;
    return true;
}

/**
 * Prints an array of integers to stdout.
 * @param arr array to be read
 * @param length length of array
 */
void printIntegerArray(int* arr, int length) {
    for (int i = 0; i < length; ++i) {
        printf("%d\n", arr[i]);
    }
}