#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

// Structure to store employee details
struct Employee {
    int id;
    char name[50];
    char doj[11]; // Date of Joining in format DD/MM/YYYY
    float salary;
};

int main() {
    struct Employee employees[MAX_EMPLOYEES];
    int count = 0; // number of employees
    int choice;

    while (1) {
        printf("\n=== Employee Management System ===\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Remove Employee\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (count >= MAX_EMPLOYEES) {
                printf("Cannot add more employees. Limit reached.\n");
                continue;
            }
            printf("Enter Employee ID: ");
            scanf("%d", &employees[count].id);
            printf("Enter Name: ");
            getchar(); // clear newline
            fgets(employees[count].name, sizeof(employees[count].name), stdin);
            employees[count].name[strcspn(employees[count].name, "\n")] = '\0';
            printf("Enter Date of Joining (DD/MM/YYYY): ");
            fgets(employees[count].doj, sizeof(employees[count].doj), stdin);
            employees[count].doj[strcspn(employees[count].doj, "\n")] = '\0';
            printf("Enter Salary: ");
            scanf("%f", &employees[count].salary);
            count++;
            printf("Employee added successfully!\n");

        } else if (choice == 2) {
            if (count == 0) {
                printf("No employees to display.\n");
            } else {
                printf("\n%-10s %-20s %-12s %-10s\n", "ID", "Name", "DOJ", "Salary");
                for (int i = 0; i < count; i++) {
                    printf("%-10d %-20s %-12s %-10.2f\n",
                           employees[i].id,
                           employees[i].name,
                           employees[i].doj,
                           employees[i].salary);
                }
            }

        } else if (choice == 3) {
            if (count == 0) {
                printf("No employees to remove.\n");
                continue;
            }
            int id, found = 0;
            printf("Enter Employee ID to remove: ");
            scanf("%d", &id);
            for (int i = 0; i < count; i++) {
                if (employees[i].id == id) {
                    // Shift remaining employees left
                    for (int j = i; j < count - 1; j++) {
                        employees[j] = employees[j + 1];
                    }
                    count--;
                    found = 1;
                    printf("Employee removed successfully!\n");
                    break;
                }
            }
            if (!found) {
                printf("Employee with ID %d not found.\n", id);
            }

        } else if (choice == 4) {
            printf("Exiting...\n");
            break;

        } else {
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
