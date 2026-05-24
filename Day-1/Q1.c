#include <stdio.h>

int main() {
    int n;
    printf("Enter last no. n to find sum till : ");
    scanf("%d", &n);

    int sum = n * (n + 1) / 2;
    printf("Sum = %d\n", sum);

    return 0;
}
