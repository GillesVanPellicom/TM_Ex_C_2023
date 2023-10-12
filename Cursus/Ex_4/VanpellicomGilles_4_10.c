#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
    // Declarations and initializations where applicable
    int sec;
    int days = 0;
    int hours = 0;
    int mins = 0;

    // Ask and handle input

    printf("Please enter the number of seconds: ");
    scanf("%d%*c", &sec);

    // Calculate amount of days, hours and seconds.
    // Days
    if (sec >= 86400) {
        days = sec / 86400;
        sec %= 86400;
    }

    // Hours
    if (sec >= 3600) {
        hours = sec / 3600;
        sec %= 3600;
    }

    // Minutes
    if (sec >= 60) {
        mins = sec / 60;
        sec %= 60;
    }

    // Print result
    printf("That equals %d days, %d hours and %d minutes", days, hours, mins);

}