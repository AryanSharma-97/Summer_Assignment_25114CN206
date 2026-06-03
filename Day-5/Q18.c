// WAP to cherk strong no.
#include <stdio.h>
// function to check strong number
int strong(int n){
    int i, fact,temp,sum=0,x=n;
    while(n!=0){
        temp=0;
        temp=n%10;
        fact=1;
        for(i=temp; i>0;i--)
        fact *= i;
        n=n/10;
        sum+=fact;
    }
    if (sum==x)
        printf("strong no.");
    else
        printf("not a strong no.");
}

int main(){
    int n;
    printf("Enter a strong number to be checked:");
    scanf("%d", &n);
    strong(n);
    return 0;
}