// WAP to find reverse of a number using recursion
#include <stdio.h>
#include <stdlib.h>

// Recursive helper function to reverse digits
int reverseRecursive(int num, int rev) {
    if (num == 0) {
        return rev;
    }
    return reverseRecursive(num / 10, rev * 10 + num % 10);
}
int reverseNumber(int num) {
    int isNegative = num < 0;
    if (isNegative) {
        num = -num; // Make the number positive for reversal
    }
    int reversed = reverseRecursive(num, 0);
    return isNegative ? -reversed : reversed;
}
int main() {
    int num;
    printf("Enter an integer: ");
    if (scanf("%d", &num) != 1) {
        printf("Invalid input! Please enter an integer.\n");
        return 1;
    }
    int reversed = reverseNumber(num);
    printf("Reversed number: %d\n", reversed);
    return 0;
}
