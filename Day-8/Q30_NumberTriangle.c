// WAP to print number triangle pattern
#include <stdio.h>
void NumberTriangle(int rows){
    for(int i=1; i<=rows; i++){
        for(int j=1; j<=i; j++){
            printf("%d ", j);
        }
    printf("\n");
    }
}
int main(){
    int rows;
    printf("Enter the no. of roes for number triangle pattern: ");
    scanf("%d", &rows);
    NumberTriangle(rows);
    return 0;
}