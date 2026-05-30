// WAP to check wether a no. is prime

#include<stdio.h>
int main(){
    int n=0, i=1, count=0;
    printf("Enter a number: ");
    scanf("%d", &n);
    if(n<=1)
        printf("Number is not prime");
    else{
        for(i=1;i<=n;i++){
            if(n%i==0){
                 count++;
            }
        }
        if(count==2)
            printf("The number is a prime number");
        else
            printf("the no. is not a prime number");
    }
    return 0;
}