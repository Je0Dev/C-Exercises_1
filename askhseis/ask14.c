#include <stdio.h>

int main() {
    int N, sum = 0;
    
    do {
        printf("Enter a positive integer less than 20: ");
        scanf("%d", &N);
    } while(N <= 0 || N >= 20);
    
    for(int i = 1; i <= N; i++) {
        int term = 2 * i;
        sum += term * term;
    }
    
    printf("Result: %d\n", sum);
    return 0;
}