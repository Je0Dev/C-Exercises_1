#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 5

int main() {
    int matrix[SIZE][SIZE];
    int secondary_diag[SIZE];
    int min_diag = 1000, max_diag = -1000;
    srand(time(NULL));
    
    // Fill secondary diagonal with random values in [-10, 10]
    for(int i = 0; i < SIZE; i++) {
        secondary_diag[i] = rand() % 21 - 10; // -10 to 10
        matrix[i][SIZE-1-i] = secondary_diag[i];
        
        if(secondary_diag[i] < min_diag) min_diag = secondary_diag[i];
        if(secondary_diag[i] > max_diag) max_diag = secondary_diag[i];
    }
    
    // Fill elements above secondary diagonal with values > max_diag
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE-1-i; j++) {
            matrix[i][j] = max_diag + 1 + rand() % 20;
        }
    }
    
    // Fill elements below secondary diagonal with values < min_diag
    for(int i = 0; i < SIZE; i++) {
        for(int j = SIZE-i; j < SIZE; j++) {
            matrix[i][j] = min_diag - 1 - rand() % 20;
        }
    }
    
    // Print the matrix
    printf("\n");
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}