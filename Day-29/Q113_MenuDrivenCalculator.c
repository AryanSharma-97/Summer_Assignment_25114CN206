#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void add();
void subtract();
void multiply();
void divide();
void modulus();

int main() {
    int choice;
    while (1) {
        //Menu
        printf("\n===== Simple Menu-Driven Calculator =====\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Modulus\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
    
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number between 1 and 6.\n");
            while (getchar() != '\n');
            continue;
        }
        switch (choice) {
            case 1: add(); break;
            case 2: subtract(); break;
            case 3: multiply(); break;
            case 4: divide(); break;
            case 5: modulus(); break;
            case 6: 
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select between 1 and 6.\n");
        }
    }
    return 0;
}

void add() {
    double a, b;
    printf("Enter two numbers: ");
    if (scanf("%lf %lf", &a, &b) != 2) {
        printf("Invalid input! Please enter numeric values.\n");
        while (getchar() != '\n');
        return;
    }
    printf("Result: %.2lf\n", a + b);
}
void subtract() {
    double a, b;
    printf("Enter two numbers: ");
    if (scanf("%lf %lf", &a, &b) != 2) {
        printf("Invalid input! Please enter numeric values.\n");
        while (getchar() != '\n');
        return;
    }
    printf("Result: %.2lf\n", a - b);
}
void multiply() {
    double a, b;
    printf("Enter two numbers: ");
    if (scanf("%lf %lf", &a, &b) != 2) {
        printf("Invalid input! Please enter numeric values.\n");
        while (getchar() != '\n');
        return;
    }
    printf("Result: %.2lf\n", a * b);
}
void divide() {
    double a, b;
    printf("Enter two numbers: ");
    if (scanf("%lf %lf", &a, &b) != 2) {
        printf("Invalid input! Please enter numeric values.\n");
        while (getchar() != '\n');
        return;
    }
    if (b == 0) {
        printf("Error: Division by zero is not allowed.\n");
        return;
    }
    printf("Result: %.2lf\n", a / b);
}
void modulus() {
    int a, b;
    printf("Enter two integers: ");
    if (scanf("%d %d", &a, &b) != 2) {
        printf("Invalid input! Please enter integer values.\n");
        while (getchar() != '\n');
        return;
    }
    if (b == 0) {
        printf("Error: Modulus by zero is not allowed.\n");
        return;
    }
    printf("Result: %d\n", a % b);
}
