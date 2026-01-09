#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int a[2][3], b[3][2], c[2][2];
    int i, j, k;
    srand(time(NULL));
    
    // Initialize matrix a (2x3) with random values in [-9, 9]
    printf("Matrix A (2x3):\n");
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 3; j++) {
            a[i][j] = rand() % 19 - 9; // Generates -9 to 9
            printf("%3d ", a[i][j]);
        }
        printf("\n");
    }
    
    // Initialize matrix b (3x2) with random values in [-9, 9]
    printf("\nMatrix B (3x2):\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 2; j++) {
            b[i][j] = rand() % 19 - 9; // Generates -9 to 9
            printf("%3d ", b[i][j]);
        }
        printf("\n");
    }
    
    // Multiply matrices: c = a × b
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            c[i][j] = 0;
            for(k = 0; k < 3; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    
    // Print result matrix c (2x2)
    printf("\nMatrix C = A × B (2x2):\n");
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            printf("%5d ", c[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}