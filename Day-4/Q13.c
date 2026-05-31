// WAP to print the first n terms of the Fibonacci series
#include <stdio.h>

void printFibonacci(int n) {
    if (n <= 0) {
        printf("Invalid number of terms.\n");
        return;
    }

    int a = 0, b = 1;

    if (n >= 1)
        printf("%d ", a);
    if (n >= 2)
        printf("%d ", b);

    for (int i = 3; i <= n; i++) {
        int next = a + b;
        printf("%d ", next);
        a = b;
        b = next;
    }
}

int main() {
    int n;

    printf("Enter number of terms: ");
    scanf("%d", &n);
    printFibonacci(n);
    return 0;
}
