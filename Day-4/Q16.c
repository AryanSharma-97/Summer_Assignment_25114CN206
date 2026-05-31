// WAP to print Armstrong no. into a range
#include <stdio.h>
#include <math.h>
int Arm(int n){
    int i, r, sum, digits, temp;
    
    for(i=0;i<=n;i++){
        temp=i;
        sum=0;
        digits=0;
        // calculate digits
        while(temp>0){
            digits++;
            temp/=10;
        }

        temp=i;
        if(digits == 0)
            digits = 1; // count 0 as 1 digit

        while(temp>0){
            r=temp%10;
            sum+=(int)(pow(r, digits)+0.5); // Adding 0.5 to round to nearest integer
            temp/=10;
        }
        if(sum==i)
            printf("%d ", i);
    }
}
int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Armstrong numbers between 0 and %d are: ", n);
    Arm(n);
    return 0;
}