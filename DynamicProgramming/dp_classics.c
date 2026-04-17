/*
 * DP Classics — Climbing Stairs, House Robber, Subset Sum
 * ========================================================
 *
 * 1. Climbing Stairs (LeetCode 70)
 *    You can climb 1 or 2 steps. Ways to reach nth stair?
 *    → Fibonacci pattern
 *
 * 2. House Robber (LeetCode 198)
 *    Can't rob adjacent houses. Max money without alerting police.
 *    dp[i] = max(dp[i-1], dp[i-2] + arr[i])
 *
 * 3. House Robber II (LeetCode 213) — houses in a circle
 *
 * 4. Subset Sum
 *    Does any subset of array sum to target?
 *    → Foundation for Partition Equal Subset (LeetCode 416)
 *
 * 5. Matrix Chain Multiplication
 *    Minimum scalar multiplications to multiply a chain of matrices.
 */

#include <stdio.h>
#include <string.h>
#include <limits.h>

/* ============================================================
 * 1. Climbing Stairs
 * ============================================================ */
long long climbingStairs(int n) {
    if (n <= 2) return n;
    long long a = 1, b = 2, c;
    for (int i = 3; i <= n; i++) { c = a + b; a = b; b = c; }
    return b;
}

/* ============================================================
 * 2. House Robber (Linear)
 * ============================================================ */
int houseRobber(int arr[], int n) {
    if (n == 0) return 0;
    if (n == 1) return arr[0];
    int prev2 = arr[0];
    int prev1 = arr[0] > arr[1] ? arr[0] : arr[1];
    for (int i = 2; i < n; i++) {
        int curr = prev2 + arr[i];
        if (prev1 > curr) curr = prev1;
        prev2 = prev1; prev1 = curr;
    }
    return prev1;
}

/* Helper: rob houses from index lo..hi */
int robRange(int arr[], int lo, int hi) {
    if (lo > hi) return 0;
    int prev2 = 0, prev1 = 0;
    for (int i = lo; i <= hi; i++) {
        int curr = prev2 + arr[i];
        if (prev1 > curr) curr = prev1;
        prev2 = prev1; prev1 = curr;
    }
    return prev1;
}

/* ============================================================
 * 3. House Robber II (Circle)
 * ============================================================ */
int houseRobberII(int arr[], int n) {
    if (n == 1) return arr[0];
    /* Try excluding first house OR last house, take the max */
    int opt1 = robRange(arr, 0, n-2);
    int opt2 = robRange(arr, 1, n-1);
    return opt1 > opt2 ? opt1 : opt2;
}

/* ============================================================
 * 4. Subset Sum
 * ============================================================ */
int subsetSum(int arr[], int n, int target) {
    /* dp[j] = true if subset with sum j exists */
    int dp[10001] = {0};
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = target; j >= arr[i]; j--) {
            if (dp[j - arr[i]]) dp[j] = 1;
        }
    }
    return dp[target];
}

/* Partition Equal Subset Sum (LeetCode 416) */
int canPartition(int arr[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) total += arr[i];
    if (total % 2 != 0) return 0;
    return subsetSum(arr, n, total / 2);
}

/* ============================================================
 * 5. Matrix Chain Multiplication
 * ============================================================ */
#define MAXM 10
int mcm[MAXM][MAXM];

int matrixChain(int dims[], int n) {
    /* dims[] has n+1 values: matrix i has dims[i-1] x dims[i] */
    memset(mcm, 0, sizeof(mcm));
    /* l = chain length */
    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            mcm[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = mcm[i][k] + mcm[k+1][j] + dims[i-1]*dims[k]*dims[j];
                if (cost < mcm[i][j]) mcm[i][j] = cost;
            }
        }
    }
    return mcm[1][n];
}

int main() {
    printf("=== Climbing Stairs ===\n");
    for (int i = 1; i <= 10; i++)
        printf("n=%2d : %lld ways\n", i, climbingStairs(i));

    printf("\n=== House Robber ===\n");
    int h1[] = {2, 7, 9, 3, 1};
    printf("Houses {2,7,9,3,1} : max = %d\n", houseRobber(h1, 5));
    int h2[] = {2, 1, 1, 2};
    printf("Houses II {2,1,1,2} (circle) : max = %d\n", houseRobberII(h2, 4));

    printf("\n=== Subset Sum ===\n");
    int arr[] = {3, 34, 4, 12, 5, 2};
    printf("Arr {3,34,4,12,5,2}, target=9 : %s\n", subsetSum(arr,6,9) ? "YES ✓":"NO ✗");
    printf("Arr {3,34,4,12,5,2}, target=30: %s\n", subsetSum(arr,6,30)? "YES ✓":"NO ✗");

    int part[] = {1, 5, 11, 5};
    printf("Partition {1,5,11,5} : %s\n", canPartition(part,4) ? "YES ✓":"NO ✗");

    printf("\n=== Matrix Chain Multiplication ===\n");
    int dims[] = {10, 30, 5, 60};     /* 3 matrices: 10x30, 30x5, 5x60 */
    printf("Dims {10,30,5,60} : min ops = %d\n", matrixChain(dims, 3));

    return 0;
}
