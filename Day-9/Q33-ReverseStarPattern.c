// WAP to Print half pyramid pattern
#include <stdio.h>
void RevHalfPyramid(int rows){
    for(int i=rows; i>0; i--){
        for(int j=0; j<i; j++){
            printf("* ");
        }
    printf("\n");

    }
}
int main(){
    int rows;
    printf("Enter the no. of rows for Reverse Star pattern: ");
    scanf("%d", &rows);
    RevHalfPyramid(rows);
    return 0;
}