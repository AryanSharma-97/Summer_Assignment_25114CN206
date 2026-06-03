// WAP to find x^n without using pow() function
#include <stdio.h>
int power(int x, int n){
    int i,res=1;
    for(i=1;i<=n;i++){
        res=res*x;
    }
    return res;
}
int main(){
    int x, n;
    printf("Enter a base number (x): ");
    scanf("%d", &x);
    printf("Enter an exponent (n): ");
    scanf("%d", &n);
    int result = power(x, n);
    printf("%d raised to the power of %d is: %d\n", x, n, result);
    return 0;
}