#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5  // Matrix dimension
#define M 10 // Maximum random value

int main() {
    int r[N][N];
    int freq[M+1] = {0}; // Initialize frequency array to zero
    int i, j;
    
    srand(time(NULL));
    
    // Fill matrix with random values between 0 and M
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            r[i][j] = rand() % (M+1);
            freq[r[i][j]]++; // Increment frequency for this value
        }
    }
    
    // Print the matrix
    printf("Matrix (%dx%d):\n", N, N);
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            printf("%3d ", r[i][j]);
        }
        printf("\n");
    }
    
    // Print frequencies
    printf("\nFrequencies:\n");
    for(i = 0; i <= M; i++) {
        printf("Value %d appears %d times\n", i, freq[i]);
    }
    
    return 0;
}