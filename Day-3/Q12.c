// WAP TO FIND LCM OF TWO NUMBERS
#include<stdio.h>
int main(){
    int a=0, b=0,lcm,gcd=0, num1, num2;
    printf("Enter two numbers to find LCM: ");
    scanf("%d %d", &a, &b);
    if(a<=0 || b<=0){
        printf("Please enter positive integers only.");
        return 1;
    }
    num1=a;
    num2=b;
    while(b!=0){
        gcd = b;
        b = a % b;
        a = gcd;
    }
    
    lcm = (num1*num2) / gcd;
    printf("LCM of the two numbers is: %d", lcm);
}