#include <stdio.h>
#include <stdlib.h>

struct Employee {
    int id;
    char name[100];
    char department[100];
};

struct Employee employees[100];
int count = 0;

void addEmployee() {
    if (count >= 100) {
        printf("Employee list is full!\n");
        return;
    }

    printf("Enter Employee ID: ");
    scanf("%d", &employees[count].id);

    printf("Enter Employee Name: ");
    scanf("%s", employees[count].name);

    printf("Enter Department: ");
    scanf("%s", employees[count].department);

    count++;
    printf("Employee added successfully!\n");
}

void listEmployees() {
    if (count == 0) {
        printf("No employees in the system.\n");
        return;
    }

    printf("\n--- Employee List ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Name: %s | Department: %s\n",
               employees[i].id, employees[i].name, employees[i].department);
    }
}

void removeEmployee() {
    if (count == 0) {
        printf("No employees to remove.\n");
        return;
    }

    int id, found = 0;
    printf("Enter Employee ID to remove: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (employees[i].id == id) {
            found = 1;
            for (int j = i; j < count - 1; j++) {
                employees[j] = employees[j + 1];
            }
            count--;
            printf("Employee removed successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Employee with ID %d not found.\n", id);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n===== Employee Management System =====\n");
        printf("1. Add Employee\n");
        printf("2. List Employees\n");
        printf("3. Remove Employee\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: listEmployees(); break;
            case 3: removeEmployee(); break;
            case 4: printf("Exiting...\n"); return 0;
            default: printf("Invalid choice! Try again.\n");
        }
    }
}
