// WAP to check prime using function
#include <stdio.h>
int isPrime(int num){
    if(num <= 1){
        return 0; // Not prime
    }
    for(int i = 2; i <= num/2; i++){
        if(num % i == 0){
            return 0; // Not prime
        }
    }
    return 1; // Prime
}
int main(){
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if(isPrime(num)){
        printf("%d is a prime number.\n", num);
    }
    else{
        printf("%d is not a prime number.\n", num);
    }
    return 0;
}