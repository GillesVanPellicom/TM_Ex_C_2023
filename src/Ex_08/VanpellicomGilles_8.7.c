#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#define MAX 20

void readName(char* s) {
    printf("Input name: ");
    scanf("%19s%*c", s);
}

int main(void) {
    char s[10][MAX];
    for (int i = 0; i < 2; ++i) {
        readName(s[i]);
    }
    if (tolower(s[0][0]) <= tolower(s[1][1])) {
        // correct order
        printf("%s\n%s", s[0], s[1]);
    } else {
        printf("%s\n%s", s[1], s[0]);
    }
    return 0;
}