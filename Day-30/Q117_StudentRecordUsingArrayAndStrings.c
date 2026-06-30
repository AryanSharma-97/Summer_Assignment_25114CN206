#include <stdio.h>

int main() {
    int rollNo[100];
    char name[100][50];
    float marks[100];
    int n;

    printf("Enter number of students (max 100): ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > 100) {
        printf("Invalid number of students.\n");
        return 1;
    }

    // Input student details
    for (int i = 0; i < n; i++) {
        printf("\n--- Enter details for Student %d ---\n", i + 1);

        printf("Roll Number: ");
        if (scanf("%d", &rollNo[i]) != 1) {
            printf("Invalid roll number.\n");
            return 1;
        }

        printf("Name: ");
        scanf(" %[^\n]", name[i]); // Reads full name until Enter

        printf("Marks: ");
        if (scanf("%f", &marks[i]) != 1) {
            printf("Invalid marks.\n");
            return 1;
        }
    }
    printf("\n===== Student Records =====\n");
    printf("%-10s %-30s %-10s\n", "Roll No", "Name", "Marks");
    printf("----------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-10d %-30s %-10.2f\n", rollNo[i], name[i], marks[i]);
    }
    printf("----------------------------------------------------------");
    return 0;
}
