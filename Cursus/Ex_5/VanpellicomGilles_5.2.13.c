#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
    // Declare variables
    float getal1, getal2;
    float res;
    char operand;
    // Ask input
    printf("Enter an expression without spaces: \n");
    scanf("%f%c%f%*c", &getal1, &operand, &getal2);

    // Switch over operand and calculate result
    switch (operand) {
        case '+': {
            res = getal1 + getal2;
            break;
        }
        case '-': {
            res = getal1 - getal2;
            break;
        }
        case '*': {
            res = getal1 * getal2;
            break;
        }
        case '/': {
            res = getal1 / getal2;
            break;
        }
        default: {
            // If operand is invalid, end.
            printf("That option is not valid");
            return 0;
        }
    }
    // Print result
    printf("%f %c %f = %f", getal1, operand, getal2, res);

    return 0;
}
