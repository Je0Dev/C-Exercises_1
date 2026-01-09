#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 50

int main() {
    int matrix[SIZE][SIZE];
    srand(time(NULL));
    
    // Fill elements above main diagonal with values in [-5, 0]
    for(int i = 0; i < SIZE; i++) {
        for(int j = i+1; j < SIZE; j++) {
            matrix[i][j] = rand() % 6 - 5; // -5 to 0
        }
    }
    
    // Fill elements below main diagonal with values in [0, 5]
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < i; j++) {
            matrix[i][j] = rand() % 6; // 0 to 5
        }
    }
    
    // Calculate and set main diagonal elements
    for(int i = 0; i < SIZE; i++) {
        int sum = 0, count = 0;
        
        // Sum elements in the same row (excluding diagonal)
        for(int j = 0; j < SIZE; j++) {
            if(j != i) {
                sum += matrix[i][j];
                count++;
            }
        }
        
        // Sum elements in the same column (excluding diagonal)
        for(int j = 0; j < SIZE; j++) {
            if(j != i) {
                sum += matrix[j][i];
                count++;
            }
        }
        
        // Calculate average and set diagonal element
        matrix[i][i] = (count > 0) ? sum / count : 0;
    }
    
    // Print a small portion of the matrix for verification
    printf("First 5x5 section of the matrix:\n");
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}