#include <stdio.h>
#include <stdlib.h>
int **matrix_allocate(int row, int column) {
    int **matrix = malloc(row * sizeof(*matrix));
    for (int i = 0; i < row; i++) {
        matrix[i] = calloc(column, sizeof(*matrix[i]));
    }
    return matrix;
}
int **matrix_add(int **a, int **b, int row) {
    int **c = matrix_allocate(row, row);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    return c;
}
int **matrix_multiply(int **A, int **B, int n) {
    int **C = matrix_allocate(n, n);
    if (n == 2) {
        C[0][0]=A[0][0]*B[0][0]+A[0][1]*B[1][0];
        C[0][1]=A[0][0]*B[0][1]+A[0][1]*B[1][1];
        C[1][0]=A[1][0]*B[0][0]+A[1][1]*B[1][0];
        C[1][1]=A[1][0]*B[0][1]+A[1][1]*B[1][1];
        return C;
    } else {
        int m = n / 2;
        int **a11 = matrix_allocate(m, m);
        int **a12 = matrix_allocate(m, m);
        int **a21 = matrix_allocate(m, m);
        int **a22 = matrix_allocate(m, m);
        int **b11 = matrix_allocate(m, m);
        int **b12 = matrix_allocate(m, m);
        int **b21 = matrix_allocate(m, m);
        int **b22 = matrix_allocate(m, m);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                a11[i][j] = A[i][j];
                a12[i][j] = A[i][j + m];
                a21[i][j] = A[i + m][j];
                a22[i][j] = A[i + m][j + m];
                b11[i][j] = B[i][j];
                b12[i][j] = B[i][j + m];
                b21[i][j] = B[i + m][j];
                b22[i][j] = B[i + m][j + m];
            }
        }

        int **c11 = matrix_add(matrix_multiply(a11, b11, m),
                               matrix_multiply(a12, b21, m), m);
        int **c12 = matrix_add(matrix_multiply(a11, b12, m),
                               matrix_multiply(a12, b22, m), m);
        int **c21 = matrix_add(matrix_multiply(a21, b11, m),
                               matrix_multiply(a22, b21, m), m);
        int **c22 = matrix_add(matrix_multiply(a21, b12, m),
                               matrix_multiply(a22, b22, m),m);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                C[i][j] = c11[i][j];
                C[i][j + m] = c12[i][j];
                C[i + m][j] = c21[i][j];
                C[i + m][j + m] = c22[i][j];
            }
        }
        
    }
    

    return C;
}


int main() {
    int x,n,z;
    printf("Enter order of 2:");
    scanf("%d",&x);
    for(z=0;z<x;z++){
        n*=2;
    }
    int **A = matrix_allocate(n, n);
    int **B = matrix_allocate(n, n);
    int i,j;
    printf("Enter elements of matrix A:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d",&A[i][j]);
        }
    }
    printf("Enter elements of matrix B:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d",&B[i][j]);
        }
    }
    printf("Matrix A:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf(" %d ",A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Matrix B:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf(" %d ",B[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    int **C = matrix_multiply(A, B, n);
    printf("Result matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf(" %d ",C[i][j]);
        }
        printf("\n");
    }

    return 0;
}