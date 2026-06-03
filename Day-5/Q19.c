// WAP too print the factors of a number
#include <stdio.h>
int factors(int n){
    if(n==0){
        printf("0 has infinitely many factors.");//check if the number is zero,
    }
    else if(n<0){
        printf("Negative numbers are not considered for factorization.");
    }
    else{
        int i;
        printf("Factors of %d are: ", n);
        for(i=1;i<=n;i++){
            if(n%i==0)
                printf("%d ", i);
        }
    }
}
int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    factors(n); // Calling the function to print factors
    return 0;
}