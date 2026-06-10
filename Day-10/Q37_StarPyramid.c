// WAP to Print Star pyramid pattern
#include <stdio.h>
void StarPyramid(int rows){
    for(int i=0; i<rows; i++){
        for(int k=1; k<rows-i; k++){
            printf("  ");
        }
        for(int j=0; j<=2*i; j++){
            printf("* ");
        }
    printf("\n");

    }
}
int main(){
    int rows;
    printf("Enter the no. of roes for star pyramid pattern: ");
    scanf("%d", &rows);
    StarPyramid(rows);
    return 0;
}