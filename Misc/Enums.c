#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

enum Months {January, February, March, April, May, June, July, August, September, October, November, December};

void printMonths(enum Months m);

int main(void) {
    printf("De maanden van het jaar zijn:\n"
           "nr.\t| maand\n"
           "-------------------\n");

    for (int i = January; i <= December; i++) {
        printf("%d\t| ", i);
        printMonths(i);
        printf("\n");
    }
    return 0;

}

void printMonths(enum Months m) {
    switch (m) {

        case January:
            printf("January");
            break;
        case February:
            printf("February");
            break;
        case March:
            printf("March");
            break;
        case April:
            printf("April");
            break;
        case May:
            printf("May");
            break;
        case June:
            printf("June");
            break;
        case July:
            printf("July");
            break;
        case August:
            printf("August");
            break;
        case September:
            printf("September");
            break;
        case October:
            printf("October");
            break;
        case November:
            printf("November");
            break;
        case December:
            printf("December");
            break;
    }
}