// WAP to convert binary to decimal
#include <stdio.h>
int BinaryToDecimal(int n){
    int dec=0,rem;
    while(n!=0){
        rem=n%10;
        dec=dec*2+rem;
        n=n/10;
    }
    return dec;
}
int main(){
    int n;
    printf("Enter a decimal number to converted into binary:");
    scanf("%d",&n);
    int result=BinaryToDecimal(n);
    printf("Decimal reprresentation: %d\n", result);
    return 0;
}