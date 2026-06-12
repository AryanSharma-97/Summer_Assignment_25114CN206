// WAP to check armstrong numbers using function
#include <stdio.h>
#include <math.h>
int isArmstrong(int num) {
    int originalNum = num;
    int sum = 0;
    int n = 0;
    // counting no. of digits
    while (originalNum > 0) {
        originalNum /= 10;
        n++;
    }
    originalNum = num;
    while (originalNum > 0) {
        int digit = originalNum % 10;
        sum += (int)(pow(digit, n)+0.5); // Adding 0.5 to round to the nearest integer
        originalNum /= 10;
    }
    return sum == num;
}
int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (isArmstrong(num)) {
        printf("%d is an Armstrong number.\n", num);
    } else {
        printf("%d is not an Armstrong number.\n", num);
    }
    return 0;
}