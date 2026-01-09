#include <stdio.h>
#include <limits.h>

void find_max_min(int arr[3][4], int row, int col, int *row_max, int *col_min) {
    // Find max in the specified row
    *row_max = INT_MIN;
    for(int j = 0; j < 4; j++) {
        if(arr[row][j] > *row_max) {
            *row_max = arr[row][j];
        }
    }
    
    // Find min in the specified column
    *col_min = INT_MAX;
    for(int i = 0; i < 3; i++) {
        if(arr[i][col] < *col_min) {
            *col_min = arr[i][col];
        }
    }
}

int main() {
    int arr[3][4];
    int row, col, max_val, min_val;
    
    printf("Enter 12 integers:\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 4; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    
    printf("Enter row number (0-2): ");
    scanf("%d", &row);
    printf("Enter column number (0-3): ");
    scanf("%d", &col);
    
    find_max_min(arr, row, col, &max_val, &min_val);
    
    printf("Maximum in row %d: %d\n", row, max_val);
    printf("Minimum in column %d: %d\n", col, min_val);
    
    return 0;
}