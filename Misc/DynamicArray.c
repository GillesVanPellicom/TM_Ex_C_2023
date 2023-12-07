#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>

int main(void) {
    printf("How many numbers do you wish to enter?");
    int n = 0;
    scanf("%d%*c", &n);
    int* arr = malloc(sizeof(int)*n);

    for (int i = 0; i < n; ++i) {
        printf("Enter number %d:", i+1);
        scanf("%d%*c", &arr[i]);
    }

    int sum = 0;
    printf("Front to back:\n");
    for (int i = n-1; i >= 0 ; --i) {
        printf("%d\n", arr[i]);
        sum += arr[i];
    }
    printf("Sum: %d\n", sum);
    printf("Average: %lf\n", (double) sum / (double) n);

    free(arr);


    return 0;
}