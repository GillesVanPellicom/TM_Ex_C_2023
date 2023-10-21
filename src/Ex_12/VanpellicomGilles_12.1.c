#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// Custom datatypes
enum Months{January, February, March, April, May, June, July, August, September, October, November, December};

// Prototypes
enum Months lastMonth(enum Months currentMonth);
void printMonth(enum Months m);
void printAllMonths();

int main(void) {
    printAllMonths();
    return 0;
}

/**
 * Prints all months and all previous months in a quint 80s table.
 */
void printAllMonths() {
    printf("Current Month\t\t| Previous Month\n"
           "----------------------------------------\n");
    // For enum Months
    for (enum Months i = January; i <= December; i++ ) {
        // I really want to use some kind of table library or output as csv...
        printMonth(i);
        printf("\t\t| ");
        printMonth(lastMonth(i));
        printf("\n");
    }
}

/**
 * Gives the previous month for a specific month
 * @param currentMonth Current month
 * @return Previous month
 */
enum Months lastMonth(enum Months currentMonth) {
    switch (currentMonth) {
        case January:
            return December;
        case February:
            return January;
        case March:
            return February;
        case April:
            return March;
        case May:
            return April;
        case June:
            return May;
        case July:
            return June;
        case August:
            return July;
        case September:
            return August;
        case October:
            return September;
        case November:
            return October;
        case December:
            return November;
    }
}

/**
 * Translates Months enum to a string.
 * @param m Month to be translated.
 */
void printMonth(enum Months m) {
    switch (m) {

        case January:
            printf("January\t");
            break;
        case February:
            printf("February");
            break;
        case March:
            printf("March\t");
            break;
        case April:
            printf("April\t");
            break;
        case May:
            printf("May\t");
            break;
        case June:
            printf("June\t");
            break;
        case July:
            printf("July\t");
            break;
        case August:
            printf("August\t");
            break;
        case September:
            printf("September");
            break;
        case October:
            printf("October\t");
            break;
        case November:
            printf("November");
            break;
        case December:
            printf("December");
            break;
    }
}