#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>

// Prototypes
void read(int* a, int* b);

int operandMenu();

int add(const int* a, const int* b);
int sub(const int* a, const int* b);
int mul(const int* a, const int* b);
int div(const int* a, const int* b);


int main(void) {

    int a, b;
    // Ask for integers a and b as input
    read(&a, &b);

    // Ask what operand is to be used
    int operandId = operandMenu();

    // Declare function pointer
    int (* fn)(const int* a, const int* b);

    // Switch over operandId to get correct function pointer
    switch (operandId) {
        case 1: {
            fn = &sub;
            break;
        }
        case 2: {
            fn = &mul;
            break;
        }
        case 3: {
            fn = &div;
            break;
        }
        default: {
            fn = &add;
            break;
        }
    }

    // Results will not always be correct since we are typecasting but the assignment said "use integers" so ¯\_(ツ)_/¯
    int res = fn(&a, &b);

    printf("The result of this operation is: %d", res);

    return 0;
}

/**
 * Asks for two numbers as input. Variables are mutated.
 * @param a int a by reference
 * @param b int b by reference
 */
void read(int* a, int* b) {
    printf("Please input two numbers:\n");
    scanf("%d%d", a, b);
}

/**
 * Shows a menu with operand options.
 * Keeps asking input until correct input is given.
 * @return operandId
 */
int operandMenu() {
    // Default is addition
    int res = 0;
    // While 0 <= res <= 3
    while (res >= 0 && res <= 3) {
        printf("Choose an operand:\n"
               "0\taddition\n"
               "1\tsubtraction\n"
               "2\tmultiplication\n"
               "3\tdivision\n");
        scanf("%d", &res);
        if (res < 0 || res > 3) {
            printf("That input is incorrect. Please choose one of the following:\n");
        } else {
            return res;
        }
    }
    return 0;
}

/**
 * Adds two numbers by reference.
 * @param a int a by reference
 * @param b int b by reference
 * @return a + b
 */
int add(const int* a, const int* b) {
    return *a + *b;
}

/**
 * Subtracts two numbers by reference.
 * @param a int a by reference
 * @param b int b by reference
 * @return a - b
 */
int sub(const int* a, const int* b) {
    return *a - *b;
}

/**
 * Multiplies two numbers by reference.
 * @param a int a by reference
 * @param b int b by reference
 * @return a * b
 */
int mul(const int* a, const int* b) {
    return *a * *b;
}

/**
 * Divides two numbers by reference.
 * @param a int a by reference
 * @param b int b by reference
 * @return a / b
 */
int div(const int* a, const int* b) {
    return *a / *b;
}

