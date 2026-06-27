#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

// Structure to store student details
struct Student {
    int rollNo;
    char name[50];
    float marks;
};

int main() {
    struct Student students[MAX_STUDENTS];
    int count = 0; // number of students
    int choice;

    while (1) {
        printf("\n=== Student Management System ===\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (count >= MAX_STUDENTS) {
                printf("Cannot add more students. Limit reached.\n");
                continue;
            }
            printf("Enter Roll Number: ");
            scanf("%d", &students[count].rollNo);
            printf("Enter Name: ");
            getchar(); // clear newline
            fgets(students[count].name, sizeof(students[count].name), stdin);
            students[count].name[strcspn(students[count].name, "\n")] = '\0'; // remove newline
            printf("Enter Marks: ");
            scanf("%f", &students[count].marks);
            count++;
            printf("Student added successfully!\n");

        } else if (choice == 2) {
            if (count == 0) {
                printf("No students to display.\n");
            } else {
                printf("\n%-10s %-20s %-10s\n", "Roll No", "Name", "Marks");
                for (int i = 0; i < count; i++) {
                    printf("%-10d %-20s %-10.2f\n",
                           students[i].rollNo,
                           students[i].name,
                           students[i].marks);
                }
            }

        } else if (choice == 3) {
            printf("Exiting...\n");
            break;

        } else {
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
