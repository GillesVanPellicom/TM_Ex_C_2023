#define _CRT_SECURE_NO_WARNINGS
	
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	srand(time(NULL));
	int ran = rand()%100;
	int in;
	int guesses = 0;
	bool found = false;


	while (!found) {
		printf("Higher or lower: guess: ");
		scanf("%d%*c", &in);
		guesses++;
		if (in == ran) {
			// found
			found = true;
		} else if (in < ran) {
			printf("\nHigher\n");
		} else {
			printf("\nLower\n");
		}
	}

	printf("You found the number in %d guesses", guesses);

}
