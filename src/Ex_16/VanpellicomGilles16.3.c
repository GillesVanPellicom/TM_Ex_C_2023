#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char name[50];
    Date dob;
} Person;

void read_person(FILE *file, Person *person) {
    fscanf(file, "%s", person->name);
    fscanf(file, "%d %d %d", &person->dob.day, &person->dob.month, &person->dob.year);
}

void calculate(Date current_date, Date dob, int *years, int *months, int *days) {
    if (current_date.month < dob.month || (current_date.month == dob.month && current_date.day < dob.day)) {
        *years = current_date.year - dob.year - 1;
    } else {
        *years = current_date.year - dob.year;
    }

    if (current_date.month < dob.month || (current_date.month == dob.month && current_date.day < dob.day)) {
        *months = (12 - dob.month) + current_date.month - 1;
    } else {
        *months = current_date.month - dob.month;
    }

    if (current_date.day < dob.day) {
        *days = current_date.day + 30 - dob.day; // Assuming each month has 30 days
    } else {
        *days = current_date.day - dob.day;
    }
}

int main() {
    char *filename = "../src/Ex_16/ages.txt"; // Hardcoded filename

    int day, month, year;
    printf("Enter current date (dd mm yyyy): ");
    scanf("%d %d %d", &day, &month, &year);

    Date current_date = {day, month, year};

    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file.\n");
        return 1;
    }

    Person people[100]; // Assuming a maximum of 100 people in the file
    int num_people = 0;
    while (!feof(file) && num_people < 100) {
        read_person(file, &people[num_people]);
        num_people++;
    }
    fclose(file);

    int oldest_age = -1;
    int longest_name_length = -1;
    char *oldest_name;
    char *longest_name;

    for (int i = 0; i < num_people; ++i) {
        int years, months, days;
        calculate(current_date, people[i].dob, &years, &months, &days);

        printf("%s is %d years old\n", people[i].name, years);

        if (years > oldest_age) {
            oldest_age = years;
            oldest_name = people[i].name;
        }

        int name_length = strlen(people[i].name);
        if (name_length > longest_name_length) {
            longest_name_length = name_length;
            longest_name = people[i].name;
        }
    }

    printf("The person with the longest name is: %s\n", longest_name);
    printf("The oldest person is: %s\n", oldest_name);

    return 0;
}
