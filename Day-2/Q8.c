// WAP to check if a no.. os palindrome or not
#include<stdio.h>
int main(){
   int n=0, rev=0, r=0, temp=0;
   printf("Enter a number: ");
    scanf("%d", &n);
    temp=n;
    while(n!=0){
        r=n%10;
        rev=rev*10+r;
        n=n/10;
    }
    if(temp==rev){
        printf("The number is a palindrome.\n");
    }
    else{
        printf("The number is not a palindrome.\n");
    }
    return 0;
}