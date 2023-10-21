#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void readValues(const double* a, const double* b, const double* c);

int main(void) {
    double a = 1;
    double b = 2;
    double c = 3;
    readValues(&a, &b, &c);
    return 0;
}

void readValues(const double* a, const double* b, const double* c) {
    printf("%lf %lf %lf", *a, *b, *c);
}