#include <stdio.h>

void matrixMultiply(int mat1[][100], int mat2[][100], int result[][100], int row1, int col1, int row2, int col2) {
    int i, j, k;

    for (i = 0; i < row1; i++) {
        for (j = 0; j < col2; j++) {
            result[i][j] = 0;
            for (k = 0; k < col1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void displayMatrix(int mat[][100], int row, int col) {
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int mat1[100][100], mat2[100][100], result[100][100];
    int row1, col1, row2, col2;
    int i, j;

    printf("Enter the number of rows and columns for matrix 1 (separated by a space): ");
    scanf("%d %d", &row1, &col1);

    printf("Enter elements of matrix 1:\n");
    for (i = 0; i < row1; i++) {
        for (j = 0; j < col1; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("Enter the number of rows and columns for matrix 2 (separated by a space): ");
    scanf("%d %d", &row2, &col2);

    if (col1 != row2) {
        printf("Matrices cannot be multiplied due to incompatible dimensions.\n");
        return 0;
    }

    printf("Enter elements of matrix 2:\n");
    for (i = 0; i < row2; i++) {
        for (j = 0; j < col2; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    matrixMultiply(mat1, mat2, result, row1, col1, row2, col2);

    printf("Matrix 1:\n");
    displayMatrix(mat1, row1, col1);

    printf("\nMatrix 2:\n");
    displayMatrix(mat2, row2, col2);

    printf("\nResultant Matrix:\n");
    displayMatrix(result, row1, col2);

    return 0;
}
