// WAP to create a voting eligibility checker
#include <stdio.h>
#include <stdlib.h>

int main() {
    int age;

    printf("Enter your age: ");

    // Validate input
    if (scanf("%d", &age) != 1) {
        printf("Invalid input. Please enter a valid integer.\n");
        return 1; // Exit with error
    }

    // Check for negative or unrealistic ages
    if (age < 0 || age > 150) {
        printf("Invalid age entered. Please enter a realistic age.\n");
        return 1;
    }

    // Voting eligibility check
    if (age >= 18) {
        printf("✅ You are eligible to vote.\n");
    } else {
        printf("❌ You are NOT eligible to vote. You need %d more year(s).\n", 18 - age);
    }

    return 0;
}
