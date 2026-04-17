/*
 * Coin Change Problems
 * =====================
 * Problem 1: Minimum coins to make amount (LeetCode 322)
 *   dp[i] = min(dp[i], dp[i - coin] + 1)
 *
 * Problem 2: Count ways to make amount (LeetCode 518 - Coin Change II)
 *   dp[i] += dp[i - coin]
 *
 * Time  Complexity: O(amount * n)
 * Space Complexity: O(amount)
 */

#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAXAMT 10001

/* Minimum number of coins */
int coinChangeMin(int coins[], int n, int amount) {
    int dp[MAXAMT];
    for (int i = 0; i <= amount; i++) dp[i] = amount + 1; /* "infinity" */
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i && dp[i - coins[j]] + 1 < dp[i])
                dp[i] = dp[i - coins[j]] + 1;
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}

/* Number of ways to make amount (combinations, order doesn't matter) */
long long coinChangeWays(int coins[], int n, int amount) {
    long long dp[MAXAMT];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for (int i = 0; i < n; i++) {           /* Outer: coins (unbounded) */
        for (int j = coins[i]; j <= amount; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }
    return dp[amount];
}

/* Reconstruct which coins were used (min coins path) */
void printCoinsUsed(int coins[], int n, int amount) {
    int dp[MAXAMT], from[MAXAMT];
    for (int i = 0; i <= amount; i++) { dp[i] = amount + 1; from[i] = -1; }
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i && dp[i - coins[j]] + 1 < dp[i]) {
                dp[i] = dp[i - coins[j]] + 1;
                from[i] = coins[j];
            }
        }
    }
    if (dp[amount] > amount) { printf("Impossible\n"); return; }
    printf("Coins used (%d coins): ", dp[amount]);
    int rem = amount;
    while (rem > 0) { printf("%d ", from[rem]); rem -= from[rem]; }
    printf("\n");
}

int main() {
    int coins[] = {1, 5, 6, 9};
    int n = 4;
    int amount = 11;

    printf("Coins: {1,5,6,9}  Amount: %d\n\n", amount);
    printf("Min coins needed : %d\n", coinChangeMin(coins, n, amount));
    printCoinsUsed(coins, n, amount);
    printf("Number of ways   : %lld\n", coinChangeWays(coins, n, amount));

    printf("\nCoins: {1,2,5}  Amount: 5\n");
    int c2[] = {1,2,5};
    printf("Min coins : %d\n", coinChangeMin(c2, 3, 5));
    printf("Ways      : %lld\n", coinChangeWays(c2, 3, 5));

    return 0;
}
