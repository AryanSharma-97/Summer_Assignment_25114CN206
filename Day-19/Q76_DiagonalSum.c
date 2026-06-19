// WAP to find diagonal sum of a matrix
#include <stdio.h>
void diagonalSum(int rows, int cols, int mat[rows][cols], int *primarySum, int *secondarySum) {
    *primarySum = 0;
    *secondarySum = 0;
    for (int i = 0; i < rows; i++) {
        *primarySum += mat[i][i]; // Primary diagonal
        *secondarySum += mat[i][cols - i - 1]; // Secondary diagonal
    }
}
int main(){
    int rows, cols;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);
    
    int mat[rows][cols];
    
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    
    int primarySum, secondarySum;
    diagonalSum(rows, cols, mat, &primarySum, &secondarySum);
    
    printf("Primary diagonal sum: %d\n", primarySum);
    printf("Secondary diagonal sum: %d\n", secondarySum);
    
    return 0;
}