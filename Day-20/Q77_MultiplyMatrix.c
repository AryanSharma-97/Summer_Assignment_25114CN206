// WAP to multiply two matrices
#include <stdio.h>
void multiplyMatrices(int rows1, int cols1, int mat1[rows1][cols1], int rows2, int cols2, int mat2[rows2][cols2], int result[rows1][cols2]) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}
int main() {
    int rows1, cols1, rows2, cols2;
    printf("Enter the number of rows and columns for first matrix: ");
    scanf("%d %d", &rows1, &cols1);
    
    int mat1[rows1][cols1];
    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }
    
    printf("Enter the number of rows and columns for second matrix: ");
    scanf("%d %d", &rows2, &cols2);
    
    if (cols1 != rows2) {
        printf("Error: Number of columns in first matrix must be equal to number of rows in second matrix for multiplication.\n");
        return 1;
    }
    
    int mat2[rows2][cols2];
    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }
    
    int result[rows1][cols2];
    multiplyMatrices(rows1, cols1, mat1, rows2, cols2, mat2, result);
    
    printf("Resultant matrix after multiplication:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}