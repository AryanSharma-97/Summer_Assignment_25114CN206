// WAP to check whether a matrix is symmetric or not
#include <stdio.h>
int isSymmetric(int rows, int cols, int mat[rows][cols]) {
    if (rows != cols) {
        return 0; // A non-square matrix cannot be symmetric
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] != mat[j][i]) {
                return 0; // Not symmetric
            }
        }
    }
    return 1; // Symmetric
}
int main() {
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
    
    if (isSymmetric(rows, cols, mat)) {
        printf("The matrix is symmetric.\n");
    } else {
        printf("The matrix is not symmetric.\n");
    }
    
    return 0;
}