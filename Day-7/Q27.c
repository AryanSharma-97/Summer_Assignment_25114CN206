// WAP to find sum of digitals of a number using recursion
#include <stdio.h>
// Recursive function to calculate sum of digits
int sumOfDigits(int n) {
    if (n < 0) {
        n = -n; // for negative numbers
    }
    if (n == 0) {
        return 0;
    }
    //last digit + sum of remaining digits
    return (n % 10) + sumOfDigits(n / 10);
}
int main(){
    int num;
    printf(" Enter an integer: ");
    scanf("%d", &num);
    int result = sumOfDigits(num);
    printf("Sum of digits of %d is %d\n",num ,result);
    return 0;
}