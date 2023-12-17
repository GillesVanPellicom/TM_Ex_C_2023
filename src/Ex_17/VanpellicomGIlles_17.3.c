#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 3 // Default size

struct CustomerName {
    int number;
    char name[50];
};

struct CustomerAddress {
    int number;
    char address[100];
};

void readCustomerData(struct CustomerName *names, struct CustomerAddress *addresses, int size) {
    printf("Enter customer data:\n");
    for (int i = 0; i < size; i++) {
        printf("Customer %d number: ", i + 1);
        scanf("%d", &names[i].number);
        while(getchar() != '\n');

        printf("Customer %d name: ", i + 1);
        scanf(" %[^\n]s", names[i].name);

        printf("Customer %d address number: ", i + 1);
        scanf("%d", &addresses[i].number);
        while(getchar() != '\n');

        printf("Customer %d address: ", i + 1);
        scanf(" %[^\n]s", addresses[i].address);
    }
}

void printCustomerData(struct CustomerName *names, struct CustomerAddress *addresses, int size) {
    printf("\nCustomer data:\n");
    for (int i = 0; i < size; i++) {
        printf("Customer %d\n", i + 1);
        printf("Number: %d\n", names[i].number);
        printf("Name: %s\n", names[i].name);
        printf("Address Number: %d\n", addresses[i].number);
        printf("Address: %s\n\n", addresses[i].address);
    }
}

int main() {
    struct CustomerName *names = (struct CustomerName *)malloc(SIZE * sizeof(struct CustomerName));
    struct CustomerAddress *addresses = (struct CustomerAddress *)malloc(SIZE * sizeof(struct CustomerAddress));

    if (names == NULL || addresses == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    FILE *file;
    file = fopen("../src/Ex_17/customer_data.txt", "r");

    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    readCustomerData(names, addresses, SIZE);
    printCustomerData(names, addresses, SIZE);

    free(names);
    free(addresses);

    fclose(file);

    return 0;
}
