// WAP to find the largest priime factor of a number
#include <stdio.h>
int largestPrimeFactor(int n) {
    int i, maxPrime = 1;
    //continously dividing with 2 until n is not even
    while (n % 2 == 0) {
        maxPrime = 2;
        n /= 2;
    }
    // for odd faactoers from 3 to sqrt(n)
    for (i = 3; i*i<= n; i += 2) {
        while (n % i == 0) {
            maxPrime = i;
            n /= i;
        }
    }
    // hanling if n is a prime number greater than 2
    if (n > 2)
        maxPrime = n;
    return maxPrime;
}
int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int result = largestPrimeFactor(n);
    if (result != 1)
        printf("The largest prime factor of %d is %d.\n", n, result);
    else
        printf("No prime factors found for %d.\n", n);
    return 0;
}