#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

int main(void) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char* pattern = "brrr";

    // Open the file in read mode
    file = fopen("./Text.txt", "r");

    // Handle errors
    if (file == NULL) {
        perror("An unexpected I/O failure occurred");
        return 1;
    }

    int i = 0;
    // Read file line by line
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        if (strstr(line, pattern) != NULL) {
            // Match found
            printf("%d %s", i++, line);
        }
    }

    // Close the file
    fclose(file);

    return 0;
}