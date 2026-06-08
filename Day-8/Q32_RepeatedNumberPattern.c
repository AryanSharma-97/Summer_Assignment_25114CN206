// WAP to print repeated number pattern
#include <stdio.h>
void RepeatedNumberPattern(int rows){
    for(int i=1; i<=rows; i++){
        for(int j=1; j<=i; j++){
            printf("%d ", i);
        }
    printf("\n");
    }
}
int main(){
    int rows;
    printf("Enter the no. of roes for repeated number pattern: ");
    scanf("%d", &rows);
    RepeatedNumberPattern(rows);
    return 0;
}