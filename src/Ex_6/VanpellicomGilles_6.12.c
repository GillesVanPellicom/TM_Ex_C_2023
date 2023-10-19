#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

void drawBar(int n, char c);

/*
 * Ik ben mij er van bewust dat deze relatief complexe implementatie niet nodig was,
 * maar om het voor mijzelf toch iets of wat leerlijk te maken heb ik dit iets minder triviaal geïmplementeerd.
 * De opdracht is volbracht volgens de gegeven opgave.
 */

int main(void) {
    // Define and initialize variables
    char symbol = '=';
    int *arr = NULL;
    int length = 0;
    int capacity = 1;

    // Ask and handle symbol input 
    printf("What symbol would you like to use? ");
    scanf("%c", &symbol);

    // Allocate memory for dynamic array
    arr = (int *) malloc(capacity * sizeof(int));

    // If allocation fails, exit with error
    if (arr == NULL) {
        fprintf(stderr, "Fatal: Memory allocation for 'arr' failed.\n");
        return 1;
    }

    // Ask for scores
    printf("Enter scores: ");
    // While loop not stopped
    while (true) {
        // If the length of the array equals the capacity, array full
        if (length == capacity) {
            // Double capacity and reallocate
            capacity *= 2;
            arr = (int *) realloc(arr, capacity * sizeof(int));
            // If reallocation fails, exit with error
            if (arr == NULL) {
                fprintf(stderr, "Fatal: Memory reallocation for 'arr' failed.\n");
                return 1;
            }
        }
        // Handle input
        scanf("%d%*c", &arr[length]);
        // If last input < 0, exit loop
        if (arr[length] < 0) {
            break;
        }
        // Increase array size
        length++;
    }
    // Newline after input handler
    printf("\n");

    // For all elements in arr, call drawBar()
    for (int i = 0; i < length; i++) {
        drawBar(arr[i], symbol);
    }

    // Free arr memory
    free(arr);

    return 0;
}

/**
 * Prints a score followed by a bar graph.
 * @param n Score
 * @param c Bar graph character
 */
void drawBar(int n, char c) {
    printf("score = %d\t", n);
    for (int i = 0; i < n; ++i) {
        printf("%c", c);
    }
    printf("\n");
}