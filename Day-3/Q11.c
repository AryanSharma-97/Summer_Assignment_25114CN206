// WAP TO CALCULATE GCD OF TWO NUMBERS
#include<stdio.h>
int main(){
    int a=0,b=0,gcd=0;
    printf("Enter two numbers to find GCD: ");
    scanf("%d %d", &a, &b);
    if(a<=0 || b<=0){
        printf("Please enter positive integers only.");
        return 1;
    }
    while(b!=0){
        gcd = b;
        b = a % b;
        a = gcd;
    }
    printf("GCD of the two numbers is: %d", gcd);
    return 0;
}