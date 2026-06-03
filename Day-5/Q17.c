// WAP to check perfect no.
#include <stdio.h>
int Perfect(int n){
    int i, sum=0;
    for(i=1;i<n;i++){
        if(n%i==0)
            sum+=i;
    }
    if(sum==n)
     printf("%d is a perfect number.", n);
    else
     printf("%d is not a perfect number.", n);
}
int main(){
    int n;
    printf("Enter a perfect number to be checked:");
    scanf("%d", &n);
    Perfect(n);
    return 0;
}