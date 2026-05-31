// WAP to check if entered number is armstrong number or not
#include <stdio.h>
#include <math.h>
int Arm(int n) {
    int temp = n, sum = 0, digits = 0;
    // Count digits
    while (temp>0) {
        digits++;
        temp/=10;
    }
    temp=n;
    while (temp > 0) {
        int r=temp%10;
        sum+=(int)(pow(r, digits)+0.5); // Adding 0.5 to round to nearest integer
        temp/= 10;
    }
    return sum==n;;
}
int main() {
    int num;

    printf("Enter a number: ");
    if (scanf("%d", &num) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (Arm(num)==1)
        printf("%d is an Armstrong number.\n", num);
    else
        printf("%d is not an Armstrong number.\n", num);

    return 0;
}
