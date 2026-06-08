// WAP to Print half pyramid pattern
#include <stdio.h>
void HalfPyramid(int rows){
    for(int i=0; i<rows; i++){
        for(int j=0; j<=i; j++){
            printf("* ");
        }
    printf("\n");

    }
}
int main(){
    int rows;
    printf("Enter the no. of roes for half pyramid pattern: ");
    scanf("%d", &rows);
    HalfPyramid(rows);
    return 0;
}