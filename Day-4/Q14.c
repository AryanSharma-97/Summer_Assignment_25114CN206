// WAP to find nth term of the Fibonacci series
#include <stdio.h>

// Function to find the n-th Fibonacci term
int fibonacci(int n) {
    if (n == 0) return 0;   // First term
    if (n == 1) return 1;   // Second term

    int a = 0, b = 1, c;

    // Calculate next terms up to n
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("The %d-th Fibonacci term is: %d\n", n, fibonacci(n));

    return 0;
}
