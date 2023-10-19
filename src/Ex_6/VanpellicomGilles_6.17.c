#define _CRT_SECURE_NO_WARNINGS

#include <stdbool.h>
#include <stdio.h>


void filled_square(int n);

void empty_square(int n);

int main(void) {
    int res;
    while (true) {
        printf("What do you choose?:\n\t1. Draw an empty square\n\t2. Draw a filled square\n\t3. Stop\n");
        scanf("%d%*c", &res);

        switch (res) {
            case 1: {
                empty_square(20);
                printf(" ");
                break;
            }
            case 2: {
                filled_square(20);
                printf(" ");
                break;
            }
            case 3: {
                printf("Thanks for playing with us!");
                return 0;
            }
            default: {
                printf("Please enter a valid choice.\n");
                continue;
            }
        }
    }
}

/**
 * Prints a solid square to the stdout
 * Dimensions n by n/2
 * @param n square length
 */
void filled_square(int n) {
    for (int i = 1; i <= n / 2; i++) {
        for (int j = 1; j <= n; j++) {
            printf("\xDB");
        }
        printf("\n");
    }
}

/**
 * Prints a square with an empty middle to the stdout
 * Dimensions n by n/2
 * @param n square length
 */
void empty_square(int n) {

    for (int i = 1; i <= n / 2; i++) {

        for (int j = 1; j <= n; j++) {

            if ((i != 1 || i != n / 2) && (j <= 2 || j > n - 2)) {
                printf("\xDB");
            } else if ((i == 1 || i == n / 2)) {
                printf("\xDB");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}