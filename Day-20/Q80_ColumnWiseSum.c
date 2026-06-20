// WAP to find Column wise sum of a matrix
#include <stdio.h>
void columnWiseSum(int rows, int cols, int mat[rows][cols], int colSums[cols]) {
    for (int j = 0; j < cols; j++) {
        colSums[j] = 0; // Initialize sum for the current column
        for (int i = 0; i < rows; i++) {
            colSums[j] += mat[i][j]; // Add the current element to the column sum
        }
    }
}
int main(){
    int rows, cols;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);
    
    int mat[rows][cols], colSums[cols];
    
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    
    columnWiseSum(rows, cols, mat, colSums);
    
    printf("Column-wise sums:\n");
    for (int j = 0; j < cols; j++) {
        printf("Sum of column %d: %d\n", j + 1, colSums[j]);
    }
    
    return 0;
}