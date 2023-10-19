#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool isPalindrome(char *s);

void strip(char *s, char c);

void toLowerCase(char *s);


int main(void) {

    char string[] = "Was it a car or a cat I saw?";

    bool res = isPalindrome(string);
    if (res) {
        printf("Palindrome");
    } else {
        printf("Not a palindrome");
    }
    return 0;
}

/**
 * Checks if a string is a palindrome
 * Also works for sentences
 * (spaces, punctuation and capitalization is ignored)
 * @param s string
 * @return boolean
 */
bool isPalindrome(char *s) {
    // Strip spaces and punctuation
    strip(s, ' ');
    strip(s, '.');
    strip(s, '?');
    strip(s, '!');
    // String to lower case
    toLowerCase(s);

    // Start and end of string counter
    int start = 0;
    int end = (int) strlen(s) - 1;

    // While start and end not the same number
    while (start < end) {
        // If char at start equals char at end
        if (s[start] == s[end]) {
            // Post-increment and decrement start and end respectively
            start++;
            end--;
            // Next iteration
            continue;
        }

        // Not a palindrome
        return false;
    }
    // Palindrome
    return true;
}

/**
 * Strips all occurrences of a specified character from a string
 * @param s string
 * @param c character
 */
void strip(char *s, char c) {
    // If string equals null, do nothing
    if (s == NULL) {
        return;
    }

    char *readPtr = s;
    char *writePtr = s;

    // While readPtr is not zero byte
    while (*readPtr) {
        if (*readPtr != c) {
            *writePtr = *readPtr;
            // Post-increment writePtr
            writePtr++;
        }
        // Post-increment readPtr
        readPtr++;
    }
    // Add null terminator
    *writePtr = '\0';
}

/**
 * Changes all uppercase to lowercase in a string
 * @param s string
 */
void toLowerCase(char *s) {
    // If string equals null, do nothing
    if (s == NULL) {
        return;
    }
    // While not at end of string
    while (*s) {
        // Set current character to lowercase version
        *s = (char) tolower(*s);
        // Increment pointer
        s++;
    }
}

