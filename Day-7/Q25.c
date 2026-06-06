// WAP for recursive factorial of a number
#include <stdio.h>
// Recursive function to calculate factorial
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    // Recursive case: n * factorial(n - 1)
    return (unsigned long long)n * factorial(n - 1);
}

int main() {
    int num;
    printf("Enter a integer: ");
    scanf("%d", &num);
    if (num < 0) {
        printf("Factorial of a negative number is not defined.\n");
        return 1;
    }
    // Calculate factorial
    unsigned long long result = factorial(num);
    printf("Factorial of %d is %llu\n", num, result);
    return 0;
}
