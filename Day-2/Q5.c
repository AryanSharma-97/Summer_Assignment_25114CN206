// WAP to find the no. of digits of a number

#include<stdio.h>
int main(){
    int n =0, count=0;
    printf("Enter a number: ");
    scanf("%d", &n);
    if (n==0){
        count=1;
    }
    else{
        if(n<0){
            n=-n;
        }
        while(n!=0){
            n=n/10;
            count=count+1;
        }
    }
    printf("Number of digits = %d\n", count);
    return 0;
}