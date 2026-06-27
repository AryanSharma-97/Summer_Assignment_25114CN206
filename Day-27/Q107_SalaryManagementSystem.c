#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define NAME_LEN 50

// Structure to store employee details
typedef struct {
    int id;
    char name[NAME_LEN];
    float basicSalary;
    float hra;   // House Rent Allowance
    float da;    // Dearness Allowance
    float grossSalary;
} Employee;

// Function to calculate gross salary
void calculateGrossSalary(Employee empList[], int index) {
    empList[index].hra = empList[index].basicSalary * 0.20f; // 20% of basic
    empList[index].da  = empList[index].basicSalary * 0.10f; // 10% of basic
    empList[index].grossSalary = empList[index].basicSalary +
                                 empList[index].hra +
                                 empList[index].da;
}

// Function to add a new employee
void addEmployee(Employee empList[], int *count) {
    if (*count >= MAX_EMPLOYEES) {
        printf("Error: Employee limit reached.\n");
        return;
    }

    printf("\nEnter Employee ID: ");
    if (scanf("%d", &empList[*count].id) != 1) {
        printf("Invalid input. ID must be an integer.\n");
        while (getchar() != '\n'); // clear buffer
        return;
    }

    while (getchar() != '\n'); // clear buffer before reading string

    printf("Enter Employee Name: ");
    fgets(empList[*count].name, NAME_LEN, stdin);
    empList[*count].name[strcspn(empList[*count].name, "\n")] = '\0'; // remove newline

    printf("Enter Basic Salary: ");
    if (scanf("%f", &empList[*count].basicSalary) != 1 || empList[*count].basicSalary < 0) {
        printf("Invalid salary. Must be a positive number.\n");
        while (getchar() != '\n');
        return;
    }

    calculateGrossSalary(empList, *count);
    (*count)++;

    printf("Employee added successfully!\n");
}

// Function to display all employees
void displayEmployees(Employee empList[], int count) {
    if (count == 0) {
        printf("\nNo employee records found.\n");
        return;
    }

    printf("\n%-5s %-20s %-12s %-10s %-10s %-12s\n", 
           "ID", "Name", "Basic", "HRA", "DA", "Gross");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-5d %-20s %-12.2f %-10.2f %-10.2f %-12.2f\n",
               empList[i].id, empList[i].name, empList[i].basicSalary,
               empList[i].hra, empList[i].da, empList[i].grossSalary);
    }
}

int main() {
    Employee employees[MAX_EMPLOYEES];
    int count = 0;
    int choice;

    while (1) {
        printf("\n=== Salary Management System ===\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                addEmployee(employees, &count);
                break;
            case 2:
                displayEmployees(employees, count);
                break;
            case 3:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
