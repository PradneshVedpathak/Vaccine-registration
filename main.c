#include <stdio.h>
#include <conio.h>
#include <stdbool.h>


#define MAX_REGISTRATIONS 100


typedef struct {
    char name[50];
    int age;
    char address[100];
} Registration;


void registerVaccine(Registration[], int*);
void displayRegistrations(Registration[], int);

int main() {
    clrscr();
    Registration registrations[MAX_REGISTRATIONS];
    int numRegistrations = 0;

    int choice;
    bool exitProgram = false;

    while (!exitProgram) {
        printf("\nVaccine Registration System\n");
        printf("1. Register for vaccine\n");
        printf("2. Display registrations\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerVaccine(registrations, &numRegistrations);
                break;
            case 2:
                displayRegistrations(registrations, numRegistrations);
                break;
            case 3:
                exitProgram = true;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    getch();
}

void registerVaccine(Registration registrations[], int *numRegistrations) {
    if (*numRegistrations == MAX_REGISTRATIONS) {
        printf("Registration full. Cannot accept more registrations.\n");
    } else {
        Registration newRegistration;
        printf("Enter name: ");
        scanf(" %[^\n]", newRegistration.name);
        printf("Enter age: ");
        scanf("%d", &newRegistration.age);
        printf("Enter address: ");
        scanf(" %[^\n]", newRegistration.address);

        registrations[*numRegistrations] = newRegistration;
        (*numRegistrations)++;
        printf("Registration successful.\n");
    }
}

void displayRegistrations(Registration registrations[], int numRegistrations) {
    if (numRegistrations == 0) {
        printf("No registrations found.\n");
    } else {
        printf("Registered users:\n");
        for (int i = 0; i < numRegistrations; i++) {
            printf("Registration %d:\n", i + 1);
            printf("Name: %s\n", registrations[i].name);
            printf("Age: %d\n", registrations[i].age);
            printf("Address: %s\n", registrations[i].address);
        }
    }
}

