// WAP to Print Inverser number triangle
#include <stdio.h>
void RevHalfPyramid(int rows){
    for(int i=rows; i>0; i--){
        for(int j=1; j<=i; j++){
            printf("%d",j);
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