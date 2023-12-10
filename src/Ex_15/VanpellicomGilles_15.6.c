#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PEOPLE 5

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    float salary;
} Person;

int main() {
    FILE *file;
    file = fopen("people_data.txt", "w");

    if (file == NULL) {
        printf("Error opening file");
        return 1;
    }

    Person people[MAX_PEOPLE];
    int numOfPeople;

    printf("Enter the number of people: ");
    scanf("%d", &numOfPeople);
    getchar(); // Clear the newline character from the input buffer

    if (numOfPeople > MAX_PEOPLE) {
        printf("Number of people exceeds the maximum limit.");
        return 1;
    }

    for (int i = 0; i < numOfPeople; ++i) {
        printf("\nEnter details for person %d:\n", i + 1);

        printf("Name: ");
        fgets(people[i].name, MAX_NAME_LENGTH, stdin);
        people[i].name[strcspn(people[i].name, "\n")] = '\0'; // Remove newline from fgets

        printf("Age: ");
        scanf("%d", &people[i].age);

        printf("Salary: ");
        scanf("%f", &people[i].salary);

        getchar(); // Clear the newline character from the input buffer

        // Write the structure to the file
        fprintf(file, "Person %d\n", i + 1);
        fprintf(file, "Name: %s\n", people[i].name);
        fprintf(file, "Age: %d\n", people[i].age);
        fprintf(file, "Salary: %.2f\n\n", people[i].salary);
    }

    fclose(file);
    printf("\nData written to file successfully.\n");

    return 0;
}