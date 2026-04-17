/*
 * Factorial using Recursion
 * -------------------------
 * factorial(n) = n * factorial(n-1)
 * Base case: factorial(0) = 1
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n) call stack
 */

#include <stdio.h>

long long factorial(int n) {
    if (n < 0) { printf("Negative input!\n"); return -1; }
    if (n == 0 || n == 1) return 1;
    return (long long)n * factorial(n - 1);
}

int main() {
    int tests[] = {0, 1, 5, 10, 15};
    int n = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < n; i++) {
        printf("factorial(%2d) = %lld\n", tests[i], factorial(tests[i]));
    }

    return 0;
}
