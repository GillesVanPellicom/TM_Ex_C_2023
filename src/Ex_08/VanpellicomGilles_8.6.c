#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void tokenizeAndPrint(char* s) {
    char* token = strtok(s, " ,.?!");
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, " ,.?!");
    }
}

int main(void) {
    char s[] = "This is a string.";
    tokenizeAndPrint(s);
    return 0;
}