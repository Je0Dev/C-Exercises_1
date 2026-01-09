#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 5

// Function to calculate factorial
long factorial(int n) {
    if(n <= 1) return 1;
    return n * factorial(n-1);
}

int main() {
    int a[SIZE][SIZE], i, j;
    srand(time(NULL));
    
    // Initialize with random single-digit integers
    printf("Original 5x5 array:\n");
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            a[i][j] = rand() % 10; // 0-9
            printf("%2d ", a[i][j]);
        }
        printf("\n");
    }
    
    // Replace with factorial of sum of indices (except secondary diagonal)
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            if(j == SIZE-1-i) {
                a[i][j] = 0; // Secondary diagonal elements set to 0
            } else {
                a[i][j] = factorial(i+j);
            }
        }
    }
    
    // Print modified array
    printf("\nModified 5x5 array:\n");
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            printf("%10ld ", (long)a[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}