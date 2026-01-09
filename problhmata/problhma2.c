#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Function to check if a number is prime
int is_prime(long long n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    
    // Check for factors up to sqrt(n)
    long long i = 5;
    while (i * i <= n) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return 0;
        }
        i += 6;
    }
    
    return 1;
}

// Function to check if a number is semiprime and find its prime factors
int is_semiprime(long long n, long long* factor1, long long* factor2) {
    if (n <= 3) return 0;
    
    // Check if n is prime - if it is, it can't be semiprime
    if (is_prime(n)) return 0;
    
    // Find the first prime factor
    long long limit = sqrt(n) + 1;
    for (long long i = 2; i <= limit; i++) {
        if (n % i == 0) {
            long long other_factor = n / i;
            
            // Check if both factors are prime
            if (is_prime(i) && is_prime(other_factor)) {
                *factor1 = i;
                *factor2 = other_factor;
                return 1;
            }
        }
    }
    
    return 0;
}

int main() {
    long long n;
    long long factor1, factor2;
    
    printf("Enter a natural number: ");
    scanf("%lld", &n);
    
    if (n <= 0) {
        printf("Please enter a positive natural number.\n");
        return 1;
    }
    
    clock_t start = clock();
    
    if (is_semiprime(n, &factor1, &factor2)) {
        printf("%lld is a semiprime number.\n", n);
        printf("Its prime factors are %lld and %lld.\n", factor1, factor2);
    } else {
        printf("%lld is not a semiprime number.\n", n);
    }
    
    clock_t end = clock();
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", cpu_time_used);
    
    /*
    Test cases:
    1. 46 should be semiprime with factors 2 and 23
    2. 1002616001 should be semiprime with factors 107 and 9370243
    3. 1002616003 should not be semiprime
    
    Performance note:
    For very large numbers, this implementation might be slow due to the trial division
    approach. More efficient algorithms like Pollard's rho algorithm would be better
    for extremely large numbers, but this solution works well for the test cases provided.
    */
    
    return 0;
}