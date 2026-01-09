#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Iterative GCD using factorization
int gcd_iterative_factorization(int a, int b) {
    int smaller = (a < b) ? a : b;
    int gcd = 1;
    
    for (int i = 1; i <= smaller; i++) {
        if (a % i == 0 && b % i == 0) {
            gcd = i;
        }
    }
    
    return gcd;
}

// Recursive GCD using Euclidean algorithm
int gcd_recursive_euclidean(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd_recursive_euclidean(b, a % b);
}

int main() {
    int a, b;
    
    printf("Enter two positive integers: ");
    scanf("%d %d", &a, &b);
    
    if (a <= 0 || b <= 0) {
        printf("Please enter positive integers only.\n");
        return 1;
    }
    
    clock_t start, end;
    double cpu_time_used;
    
    // Iterative method (factorization)
    start = clock();
    int gcd_iter = gcd_iterative_factorization(a, b);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    printf("\nGCD using iterative method (factorization): %d\n", gcd_iter);
    printf("Time taken: %f seconds\n", cpu_time_used);
    
    // Recursive method (Euclidean)
    start = clock();
    int gcd_rec = gcd_recursive_euclidean(a, b);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    printf("\nGCD using recursive method (Euclidean algorithm): %d\n", gcd_rec);
    printf("Time taken: %f seconds\n", cpu_time_used);
    
    // Test with large numbers
    printf("\nTesting with large numbers (1234567 and 7654321):\n");
    
    int large_a = 1234567;
    int large_b = 7654321;
    
    start = clock();
    gcd_rec = gcd_recursive_euclidean(large_a, large_b);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    printf("GCD of %d and %d using recursive method: %d\n", large_a, large_b, gcd_rec);
    printf("Time taken: %f seconds\n", cpu_time_used);
    
    /*
    Observations:
    1. The iterative factorization method is extremely slow for large numbers.
       Its time complexity is O(min(a, b)), which becomes impractical for large inputs.
       
    2. The recursive Euclidean algorithm is much faster, with time complexity O(log(min(a, b))).
       It can handle very large numbers efficiently.
       
    3. For small numbers (less than 1000), the factorization method might be acceptable,
       but for numbers with 6-7 digits or more, the Euclidean algorithm is vastly superior.
       
    4. The Euclidean algorithm works by repeatedly applying the property:
       gcd(a, b) = gcd(b, a mod b) until b becomes 0.
       
    5. In practice, the Euclidean algorithm is the standard method for computing GCD
       due to its efficiency and simplicity.
    */
    
    return 0;
}