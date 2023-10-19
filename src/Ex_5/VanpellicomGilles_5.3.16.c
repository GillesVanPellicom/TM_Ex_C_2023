#define _CRT_SECURE_NO_WARNINGS

#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>


void drawSegment(int width, int length, int offset);

void drawTower(int n);

int main(void) {
    // Declare variables
    int res;
    char yesNo;

    // Loop until program is stopped
    while (true) {
        // Explain and ask input
        printf("This program builds a tower upside down!\n"
               "How wide should the tower be?\n"
               "(Enter an odd number between 3 and 15)\n");
        scanf("%d%*c", &res);

        // If the input is within constraints, draw the tower
        if (res <= 15 && res >= 3 && res % 2 != 0) {
            drawTower(res);
        } else {
            // Else, notify user input is invalid
            printf("That is not a valid input\n");
        }

        // Explain and ask for redo
        printf("Do you want to build another tower? (y/n)\n");
        scanf("%c%*c", &yesNo);

        // If anything but y is the answer, stop program
        if (tolower(yesNo) != 'y') {
            return 0;
        }
    }
    return 0;
}


/**
 * Draws upside-down tower recursively
 * @param width Desired starting width
 * @param length Desired starting length
 * @param offset Desired starting offset
 */
void drawSegment(int width, int length, int offset) {
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < width; ++j) {
            if (j < offset) {
                printf(" ");
            } else {
                printf("\xDB");
            }
        }
        printf("\n");
    }
    if (width - 4 > 0) {
        drawSegment(width - 2, length - 2, offset + 2);
    }
}

/**
 * Wrapper for drawSegment()
 * @param n Starting width of tower
 */
void drawTower(int n) {
    drawSegment(n * 2, n, 0);
}
