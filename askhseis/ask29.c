#include <stdio.h>
#define SIZE 10

int main() {
    int arr[SIZE];
    int found = 0;
    
    printf("Enter 10 positive integers:\n");
    for(int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("\n");
    for(int i = 0; i < SIZE-1; i += 2) { // Check odd positions (0, 2, 4, 6, 8)
        if(arr[i+1] % arr[i] == 0) { // Check if next element is multiple of current
            printf("TIMH STOIXEIOY:%d  STH 8ESH:%d\n", arr[i], i+1);
            found = 1;
        }
    }
    
    if(!found) {
        printf("DEN YPARXEI STOIXEIO POY NA PLHROI TΗ SYGKEKRIMENH SYN8HKH...\n");
    }
    
    return 0;
}