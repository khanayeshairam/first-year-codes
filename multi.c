
#include <stdio.h>
#include <stdlib.h>

// Function to multiply two matrices
void multiplyMatrices(int **A, int **B, int **C, int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            C[i][j] = 0; // Initialize result cell
            for (int k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Function to allocate a matrix dynamically
int **allocateMatrix(int rows, int cols) {
    int **matrix = malloc(rows * sizeof(int *));
    if (!matrix) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < rows; i++) {
        matrix[i] = malloc(cols * sizeof(int));
        if (!matrix[i]) {
            printf("Memory allocation failed!\n");
            exit(EXIT_FAILURE);
        }
    }
    return matrix;
}

// Function to free a matrix
void freeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int r1, c1, r2, c2;

    // Input dimensions
    printf("Enter rows and columns for first matrix: ");
    if (scanf("%d %d", &r1, &c1) != 2 || r1 <= 0 || c1 <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Enter rows and columns for second matrix: ");
    if (scanf("%d %d", &r2, &c2) != 2 || r2 <= 0 || c2 <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    // Check multiplication condition
    if (c1 != r2) {
        printf("Matrix multiplication not possible: columns of first != rows of second.\n");
        return 1;
    }

    // Allocate matrices
    int **A = allocateMatrix(r1, c1);
    int **B = allocateMatrix(r2, c2);
    int **C = allocateMatrix(r1, c2);

    // Input first matrix
    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            if (scanf("%d", &A[i][j]) != 1) {
                printf("Invalid input.\n");
                return 1;
            }
        }
    }

    // Input second matrix
    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            if (scanf("%d", &B[i][j]) != 1) {
                printf("Invalid input.\n");
                return 1;
            }
        }
    }

    // Multiply matrices
    multiplyMatrices(A, B, C, r1, c1, c2);

    // Output result
    printf("Resultant matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    // Free memory
    freeMatrix(A, r1);
    freeMatrix(B, r2);
    freeMatrix(C, r1);

    return 0;
}


