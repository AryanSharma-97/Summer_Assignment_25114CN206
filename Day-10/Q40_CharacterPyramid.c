// WAP to Print Character pyramid pattern
#include <stdio.h>
void CharPyramid(int rows){
    for(int i=0; i<rows; i++){
        char ch='A';
        for(int k=1; k<rows-i; k++){
            printf("  ");
        }
        for(int j=0; j<=2*i; j++){
            // printf("* ");
            if(j<i){
                printf("%c ", ch);
                ch++;
            }
            else{
                printf("%c ", ch);
                ch--;
            }
        }
    printf("\n");

    }
}
int main(){
    int rows;
    printf("Enter the no. of rows for Char pyramid pattern: ");
    scanf("%d", &rows);
    CharPyramid(rows);
    return 0;
}