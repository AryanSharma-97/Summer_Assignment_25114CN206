// WAP to convert decimal to binary
#include <stdio.h>
int decimaltoBinary(int n){
    // int n;
    // printf("Enter a decimal number: ");
    // scanf("%d", &n);
    if (n < 0) {
        printf("Negative numbers cannot be converted to binary.\n");
        return 1;
    }
    if (n == 0) {
        printf("Binary representation: 0\n");
        return 0;
    }
    while (n > 0) {
        printf("%d", n % 2);
        n /= 2;
    }
    return 0;
}
int main(){
    int n;
    printf("Enter a decimal number: ");
    scanf("%d", &n);
    printf("Binary representation: ");
    decimaltoBinary(n);
    return 0;
}