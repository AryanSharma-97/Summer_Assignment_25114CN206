// WAP to print prime no. in a range

#include<stdio.h>
int main(){
    int n=0, i=1 , j=1, count=0;
    printf("Enter the range t find prime: ");
    scanf("%d", &n);
    for(j=0;j<=n;j++){
        count=0;
        for(i=1;i<=j;i++){
            if(j%i==0){
                 count++;
            }
        }
        if(count==2)
                printf("%d ", j);

    }
    return 0;
}