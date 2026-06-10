// WAP to Print Reverse Star pyramid pattern
#include <stdio.h>
void RevStarPyramid(int rows){
    for(int i=0; i<rows; i++){
        for(int k=0; k<i; k++){
            printf("  ");
        }
        for(int j=0; j<2*(rows-i)-1; j++){
            printf("* ");
        }
        printf("\n");
    }
}
int main(){
    int rows;
    printf("Enter the no. of roes for Reverse star pyramid pattern: ");
    scanf("%d", &rows);
    RevStarPyramid(rows);
    return 0;
}