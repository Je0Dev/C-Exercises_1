#include <stdio.h>

int main() {
    unsigned int n;
    printf("Enter a positive integer: ");
    scanf("%u", &n);
    
    // Find the closest larger power of 2
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n++;
    
    printf("%u\n", n);
    printf("Kales giortes kai kalh xronia!!!\n");
    
    return 0;
}