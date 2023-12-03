#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 100

int main(void) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char* pattern = "Jolie";

    printf("Enter the name of the person you want to find: ");
    scanf("%s", pattern);

    // Open the file in read mode
    file = fopen("./Text.txt", "r");

    // Handle errors
    if (file == NULL) {
        perror("An unexpected I/O failure occurred");
        return 1;
    }

    int age;
    bool ageFound = false;
    // Read file line by line
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        if (ageFound) {
            // Age on current line
            sscanf(line, "%*s %d", &age);

        }

        if (strstr(line, pattern) != NULL) {
            // Match found
            ageFound = true;
        }
    }

    // Close the file
    fclose(file);


    printf("\nname: %s\nage: %d", pattern, age);
    return 0;
}