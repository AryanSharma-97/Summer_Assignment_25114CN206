// WAP to print hollow square pattern
#include<stdio.h>
void HollowSquare(int rows){
    for(int i=1; i<=rows; i++){
        for(int j=1; j<=rows; j++){
            if(i==1 || i==rows || j==1 || j==rows){
                printf("* ");
            }
            else{
                printf("  ");
            }
        }
    printf("\n");
    }
}
int main(){
    int rows;
    printf("Enter the no. of rows for hollow square pattern: ");
    scanf("%d", &rows);
    HollowSquare(rows);
    return 0;
}