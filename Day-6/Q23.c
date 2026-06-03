// WAP to count no. of set bits in a number
#include <stdio.h>
int CountSetBits(int n){
    int count=0;
    if (n < 0) {
        printf("Negative numbers cannot be converted to binary.\n");
        return 1;
    }
    if (n == 0) {
        printf("Binary representation: 0\n");
        return 0;
    }
    printf("Binary representation: ");
    while (n > 0) {
        printf("%d", n % 2);
        if (n%2==1)
            count++;
        n /= 2;
    }
    return count;
}
int main(){
    int n;
    printf("Enter a decimal number: ");
    scanf("%d", &n);
    int result=CountSetBits(n);
    printf("\nNumber of set bits in %d is: %d\n", n, result);
    return 0;
}