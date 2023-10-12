#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	// Define input arr
	double input[6];

	// Ask and handle input
	printf("Enter Ex_6 real numbers please: \n");
	for (int i = 0; i < 6; ++i) {
		scanf("%lf%*c", &input[i]);
	}

	// For input:
	for (int i = 0; i < 6; ++i) {
		// If new row, add seperator
		if (i%2 == 0) {
			printf("-----------------------------\n|");
		}

		// Print result i, right aligned 2dp format.
		printf("%10.2lf |", input[i]);

		// If current number is at end of row, newline
		if (i%2 != 0) {
			printf("\n");

			// Else, tab
		} else {
			printf("");
		}
	}

	// Closing seperator
	printf("-----------------------------\n");

}

void askAndPrintRealTable()
{
	
}