#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>

void read(int* multiplier, int* upperBound);
void calcPrint(const int* multiplier, const int* upperBound);


int main(void) {
    int v1, v2;
    bool done = false;
    while (!done) {
        read(&v1, &v2);
        // if both inputs are 0, stop the code.
        if (v1 == 0 && v2 == 0) {
            printf("Thanks!");
            done = true;
        } else {
            calcPrint(&v1, &v2);
        }
    }
    return 0;
}

/**
 * Reads in two parameters and returns them by reference.
 * @param multiplier Multiplier to be read in
 * @param upperBound UpperBound to be read in
 */
void read(int* multiplier, int* upperBound) {
    printf("Enter the number you want to use for the table of multiplication:\n");
    scanf("%d%*c", multiplier);
    printf("Enter the limit:\n");
    scanf("%d%*c", upperBound);
}

/**
 * Calculates and then prints a multiplication table until upperBound is met.
 * @param multiplier Multiplier for the multiplication table.
 * @param upperBound Upper bound for the table
 */
void calcPrint(const int* multiplier, const int* upperBound) {
    bool boundHit = false;
    int i = 1;
    int res;
    int sumOdd = 0;
    int sumEven = 0;

    // While not at upperbound
    while (!boundHit) {
        // result = post-increment i times the dereference of multiplier adress
        res = i++ * *multiplier;

        // If the result is greater than upperbound
        if (res > *upperBound) {
            // Stop the loop
            boundHit = true;
        } else {
            // Else if number is even and then if uneven, add to respective totals.
            if (res % 2 == 0) {
                sumEven += res;
            } else {
                sumOdd += res;
            }

            printf("%d\n",res);
        }
    }
    printf("\nThe sum of the even numbers is %d.\n"
           "The sum of the odd numbers is %d.\n", sumEven, sumOdd);
}