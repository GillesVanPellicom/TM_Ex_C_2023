#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>


#define MAX 100


int readSize(int lowerBound, int upperBound);

int populateArray(int *arr);

void printArray(const int *arr, int size);

double calcArrayAverage(const int *arr, int size);

int calcArrayMax(const int *arr, int size);


int main(void) {
    int arr[MAX];
    int arrSize = populateArray(arr);
    printArray(arr, arrSize);
    double arrAvg = calcArrayAverage(arr, arrSize);
    int arrMax = calcArrayMax(arr, arrSize);
    printf("Array average: %lf\nArray max: %d", arrAvg, arrMax);

    return 0;
}

/**
 * Reads an integer as input.
 * Integer must be within interval [lowerBound; upperBound]
 * If not, retry until correct.
 * @param lowerBound lower interval bound
 * @param upperBound upper interval bound
 * @return int result
 */
int readSize(int lowerBound, int upperBound) {
    int res;
    while (true) {
        scanf("%d", &res);
        if (res >= lowerBound || res <= upperBound) {
            return res;
        }

        printf("Your input must be [%d; %d]", lowerBound, upperBound);
    }
}

/**
 * Reads integers and places them in provided array until '999' is written.
 * @param arr array of integers
 * @return size of array
 */
int populateArray(int *arr) {
    int size = 0;
    int res;
    printf("Please input numbers and end with 999");
    while (true) {
        scanf("%d", &res);

        if (res == 999) {
            break;
        }

        arr[size] = res;
        size++;
    }
    return size;
}

/**
 * Prints an array.
 * @param arr array of integers
 * @param size size of array
 */
void printArray(const int *arr, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d\n", arr[i]);
    }
}

/**
 * Calculates the average of an array of integers.
 * @param arr array of integers
 * @param size size of array
 * @return average of array
 */
double calcArrayAverage(const int *arr, int size) {
    int total = 0;
    for (int i = 0; i < size; ++i) {
        total += arr[i];
    }
    return (double) total / (double) 2;
}

/**
 * Finds the largest int in an array.
 * @param arr array of integers
 * @param size size of array
 * @return largest int in arr
 */
int calcArrayMax(const int *arr, int size) {
    int max = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}