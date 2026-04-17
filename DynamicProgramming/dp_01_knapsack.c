/*
 * 0/1 Knapsack Problem
 * ====================
 * Given N items each with a weight and value, and a knapsack of capacity W,
 * find the maximum value you can put in the knapsack.
 * Each item can be taken AT MOST ONCE (0/1 choice).
 *
 * Recurrence:
 *   dp[i][w] = max(dp[i-1][w],  dp[i-1][w-wt[i]] + val[i])
 *              (skip item i)     (take item i)
 *
 * Time  Complexity: O(N * W)
 * Space Complexity: O(N * W) → optimised to O(W) with 1D DP
 *
 * Interview variants:
 *   - Unbounded Knapsack (items can repeat)
 *   - Subset Sum (val[i] = wt[i], target = W)
 *   - Partition Equal Subset Sum (LeetCode 416)
 *   - Coin Change (LeetCode 322)
 */

#include <stdio.h>
#include <string.h>

#define MAXN 100
#define MAXW 1000

int dp[MAXN+1][MAXW+1];

/* ---- 2D DP (easy to understand) ---- */
int knapsack2D(int wt[], int val[], int n, int W) {
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (wt[i-1] <= w) {
                int take   = val[i-1] + dp[i-1][w - wt[i-1]];
                int noTake = dp[i-1][w];
                dp[i][w] = take > noTake ? take : noTake;
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    return dp[n][W];
}

/* Backtrack to find which items were taken */
void printItems(int wt[], int val[], int n, int W) {
    printf("Items taken: ");
    int w = W;
    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i-1][w]) {
            printf("item%d(wt=%d,val=%d) ", i, wt[i-1], val[i-1]);
            w -= wt[i-1];
        }
    }
    printf("\n");
}

/* ---- 1D DP (space optimised) ---- */
int knapsack1D(int wt[], int val[], int n, int W) {
    int dp1D[MAXW+1];
    memset(dp1D, 0, sizeof(dp1D));
    for (int i = 0; i < n; i++) {
        /* Traverse RIGHT-TO-LEFT to prevent reusing same item */
        for (int w = W; w >= wt[i]; w--) {
            int take = val[i] + dp1D[w - wt[i]];
            if (take > dp1D[w]) dp1D[w] = take;
        }
    }
    return dp1D[W];
}

/* ---- Unbounded Knapsack (items can be used multiple times) ---- */
int unboundedKnapsack(int wt[], int val[], int n, int W) {
    int dp1D[MAXW+1];
    memset(dp1D, 0, sizeof(dp1D));
    for (int w = 1; w <= W; w++) {
        for (int i = 0; i < n; i++) {
            if (wt[i] <= w) {
                int take = val[i] + dp1D[w - wt[i]];
                if (take > dp1D[w]) dp1D[w] = take;
            }
        }
    }
    return dp1D[W];
}

int main() {
    int val[] = {60, 100, 120};
    int wt[]  = {10,  20,  30};
    int n = 3, W = 50;

    printf("Items: val={60,100,120}, wt={10,20,30}, Capacity=%d\n\n", W);

    int result = knapsack2D(wt, val, n, W);
    printf("0/1 Knapsack (2D DP)  : %d\n", result);
    printItems(wt, val, n, W);

    printf("0/1 Knapsack (1D DP)  : %d\n", knapsack1D(wt, val, n, W));
    printf("Unbounded Knapsack    : %d\n", unboundedKnapsack(wt, val, n, W));

    return 0;
}
