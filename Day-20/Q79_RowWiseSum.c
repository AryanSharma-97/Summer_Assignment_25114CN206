// WAP to find row wise sum of a matrix
#include <stdio.h>
void rowWiseSum(int rows, int cols, int mat[rows][cols], int rowSums[rows]) {
    for (int i = 0; i < rows; i++) {
        rowSums[i] = 0; // Initialize sum for the current row
        for (int j = 0; j < cols; j++) {
            rowSums[i] += mat[i][j]; // Add the current element to the row sum
        }
    }
}
int main() {
    int rows, cols;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);
    
    int mat[rows][cols], rowSums[rows];
    
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    
    rowWiseSum(rows, cols, mat, rowSums);
    
    printf("Row-wise sums:\n");
    for (int i = 0; i < rows; i++) {
        printf("Sum of row %d: %d\n", i + 1, rowSums[i]);
    }
    
    return 0;
}