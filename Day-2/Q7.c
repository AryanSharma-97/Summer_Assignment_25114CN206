// WAP to find the product of digits of a number
#include<stdio.h>
int main(){
    int n=0, r=0, pro=1;
    printf("Enter a number: ");
    scanf("%d", &n);
    if(n==0){
        pro=0;
    }
    else{
        if(n<0)
            n=-n;
        while(n!=0){
            r=n%10;
            pro=pro*r;
            n=n/10;
        }
    }
    printf("Product of digits = %d\n", pro);
    return 0;
}