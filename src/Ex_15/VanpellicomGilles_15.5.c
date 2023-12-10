#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 50

#define NUM_PERSONS 3

typedef struct Person {
    char name[MAX_LENGTH];
    char hometown[MAX_LENGTH];
} Person;

void readPerson(Person* person) {
    printf("Enter name: ");
    scanf("%49s", person->name); // Read name

    printf("Enter hometown for %s: ", person->name);
    scanf("%49s", person->hometown); // Read hometown
}

bool searchTown(Person* people, Person* p) {
    for (int i = 0; i < NUM_PERSONS; ++i) {

        if (strcmp(people[i].name, p->name) == 0) {
            // Found
            strcpy(p->hometown, people[i].hometown);
            return true;
        }
    }
    // Not found
    return false;
}

int main() {
    Person persons[NUM_PERSONS];

    for (int i = 0; i < NUM_PERSONS; ++i) {
        readPerson(&persons[i]);
    }

    printf("===========================================================\n"
           "Enter the name of the person you want to search for: ");
    Person toFind;
    scanf("%s", toFind.name);
    if (searchTown( persons, &toFind)) {
        printf("This person lives in %s", toFind.hometown);
    } else {
        printf("This person is unknown.");
    }

    return 0;
}