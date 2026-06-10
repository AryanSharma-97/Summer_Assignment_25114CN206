// WAP to Print Number pyramid pattern
#include <stdio.h>
void StarPyramid(int rows){
    for(int i=0; i<rows; i++){
        for(int k=1; k<rows-i; k++){
            printf("  ");
        }
        for(int j=0; j<=2*i; j++){
            // printf("%d ", j+1);
            if(j<i)
                printf("%d ", j+1);
            else
                printf("%d ", 2*i-j+1);
        }
    printf("\n");

    }
}
int main(){
    int rows;
    printf("Enter the no. of rows for star pyramid pattern: ");
    scanf("%d", &rows);
    StarPyramid(rows);
    return 0;
}