#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_SUBJECTS 10

// Structure to store student data
typedef struct {
    char name[50];
    char rollNo[20];
    int numSubjects;
    char subjectNames[MAX_SUBJECTS][30];
    float marks[MAX_SUBJECTS];
    float total;
    float percentage;
    char grade;
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

// Function to calculate grade
char calculateGrade(float percentage) {
    if (percentage >= 90) return 'A';
    else if (percentage >= 75) return 'B';
    else if (percentage >= 60) return 'C';
    else if (percentage >= 50) return 'D';
    else return 'F';
}

// Function to create a new marksheet
void createMarksheet() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Maximum student limit reached.\n");
        return;
    }

    Student s;
    s.total = 0;

    getchar(); // Clear input buffer
    printf("Enter Student Name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = '\0';

    printf("Enter Roll Number: ");
    fgets(s.rollNo, sizeof(s.rollNo), stdin);
    s.rollNo[strcspn(s.rollNo, "\n")] = '\0';

    printf("Enter number of subjects (max %d): ", MAX_SUBJECTS);
    if (scanf("%d", &s.numSubjects) != 1 || s.numSubjects <= 0 || s.numSubjects > MAX_SUBJECTS) {
        printf("Invalid number of subjects.\n");
        return;
    }

    for (int i = 0; i < s.numSubjects; i++) {
        printf("Enter name of subject %d: ", i + 1);
        scanf("%s", s.subjectNames[i]);

        printf("Enter marks for %s (0-100): ", s.subjectNames[i]);
        if (scanf("%f", &s.marks[i]) != 1 || s.marks[i] < 0 || s.marks[i] > 100) {
            printf("Invalid marks entered.\n");
            return;
        }
        s.total += s.marks[i];
    }

    s.percentage = s.total / s.numSubjects;
    s.grade = calculateGrade(s.percentage);

    students[studentCount++] = s;
    printf("Marksheet created successfully.\n");
}

// Function to display all marksheets
void displayMarksheets() {
    if (studentCount == 0) {
        printf("No marksheets available.\n");
        return;
    }

    for (int i = 0; i < studentCount; i++) {
        Student s = students[i];
        printf("\nStudent Name: %s\n", s.name);
        printf("Roll Number: %s\n", s.rollNo);
        printf("Subjects and Marks:\n");
        for (int j = 0; j < s.numSubjects; j++) {
            printf("%s: %.2f\n", s.subjectNames[j], s.marks[j]);
        }
        printf("Total Marks: %.2f / %.2f\n", s.total, s.numSubjects * 100.0);
        printf("Percentage: %.2f%%\n", s.percentage);
        printf("Grade: %c\n", s.grade);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Create New Marksheet\n");
        printf("2. Display All Marksheets\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            exit(1);
        }

        switch (choice) {
            case 1:
                createMarksheet();
                break;
            case 2:
                displayMarksheets();
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
