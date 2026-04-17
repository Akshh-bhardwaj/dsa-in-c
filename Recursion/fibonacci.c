/*
 * Fibonacci using Recursion (+ Memoized version)
 * -----------------------------------------------
 * fib(n) = fib(n-1) + fib(n-2)
 * Base cases: fib(0) = 0, fib(1) = 1
 *
 * Naive recursion: O(2^n) time
 * Memoized:        O(n)   time, O(n) space
 */

#include <stdio.h>
#include <string.h>

#define MAX 100

long long memo[MAX];

long long fibMemo(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    if (memo[n] != -1) return memo[n];
    memo[n] = fibMemo(n - 1) + fibMemo(n - 2);
    return memo[n];
}

/* Simple recursive (only use for small n) */
long long fibSimple(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return fibSimple(n - 1) + fibSimple(n - 2);
}

int main() {
    memset(memo, -1, sizeof(memo));

    printf("=== Fibonacci (simple recursion, n <= 10) ===\n");
    for (int i = 0; i <= 10; i++) {
        printf("fib(%2d) = %lld\n", i, fibSimple(i));
    }

    printf("\n=== Fibonacci (memoized, n <= 30) ===\n");
    for (int i = 0; i <= 30; i += 5) {
        printf("fib(%2d) = %lld\n", i, fibMemo(i));
    }

    return 0;
}
