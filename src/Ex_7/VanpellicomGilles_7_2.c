#define _CRT_SECURE_NO_WARNINGS



enum {
	DAYS = 2
};



#include <stdio.h>

void tempsHandler(void);
float calculateMean(int arr[]);

int main(void) {
	tempsHandler();

	return 0;
}

void tempsHandler(void) {
	printf("Please enter %d temperatures:\n", DAYS);

	int temps[DAYS];

	for (int i = 0; i < DAYS; ++i) {
		printf("Enter the temperature for day %d: ", i + 1);
		scanf("%d%*c", &temps[i]);
		printf("\n");
	}

	float result = calculateMean(temps);

	printf("Mean temperature is %f", result);

}

float calculateMean(int arr[]) {
	int total = 0;
	int len = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < len; ++i) {
		total += arr[i];
	}

	return (float)total / (float)len;
}
