// WAp to print a Repeated Character triaangle pattern
#include <stdio.h>
void CharacterTriangle(int rows){
    char ch='A'; 
    for(int i=1; i<=rows; i++){
        for(int j=1; j<=i; j++){
            printf("%c",ch);
        }
        ch++;
    printf("\n");
    }
}
int main(){
    int rows;
    printf("Enter the no. of roes for character triangle pattern: ");
    scanf("%d", &rows);
    CharacterTriangle(rows);
    return 0;
}