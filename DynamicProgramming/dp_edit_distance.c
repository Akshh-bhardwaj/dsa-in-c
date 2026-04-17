/*
 * Edit Distance (Levenshtein Distance)  — LeetCode 72
 * =====================================================
 * Minimum operations (insert, delete, replace) to convert string s1 to s2.
 *
 * Recurrence:
 *   if s1[i] == s2[j]: dp[i][j] = dp[i-1][j-1]
 *   else: dp[i][j] = 1 + min(dp[i-1][j],    ← delete from s1
 *                             dp[i][j-1],    ← insert into s1
 *                             dp[i-1][j-1])  ← replace
 *
 * Time  Complexity: O(m * n)
 * Space Complexity: O(m * n) → O(n) optimised
 *
 * Related:
 *   - LeetCode 583 "Delete Operation for Two Strings" (delete only)
 *   - LeetCode 712 "Minimum ASCII Delete Sum"
 *   - Wildcard matching (LeetCode 44)
 */

#include <stdio.h>
#include <string.h>

#define MAXN 105

int dp[MAXN][MAXN];

int minOf3(int a, int b, int c) {
    int m = a < b ? a : b;
    return m < c ? m : c;
}

int editDistance(char *s1, char *s2) {
    int m = strlen(s1), n = strlen(s2);

    for (int i = 0; i <= m; i++) dp[i][0] = i; /* delete all of s1 */
    for (int j = 0; j <= n; j++) dp[0][j] = j; /* insert all of s2 */

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + minOf3(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
        }
    }
    return dp[m][n];
}

/* Print the operations performed */
void printOperations(char *s1, char *s2) {
    int m = strlen(s1), n = strlen(s2);
    int i = m, j = n;
    printf("Operations:\n");
    while (i > 0 || j > 0) {
        if (i > 0 && j > 0 && s1[i-1] == s2[j-1]) {
            i--; j--;
        } else if (j > 0 && (i == 0 || dp[i][j-1] < dp[i-1][j] && dp[i][j-1] < dp[i-1][j-1])) {
            printf("  Insert  '%c' at position %d\n", s2[j-1], i);
            j--;
        } else if (i > 0 && (j == 0 || dp[i-1][j] < dp[i][j-1] && dp[i-1][j] < dp[i-1][j-1])) {
            printf("  Delete  '%c' at position %d\n", s1[i-1], i-1);
            i--;
        } else {
            printf("  Replace '%c' → '%c' at position %d\n", s1[i-1], s2[j-1], i-1);
            i--; j--;
        }
    }
}

int main() {
    struct { char *s1, *s2; } tests[] = {
        {"horse", "ros"},
        {"intention", "execution"},
        {"kitten", "sitting"},
        {"", "abc"}
    };
    int n = 4;

    for (int t = 0; t < n; t++) {
        printf("s1=\"%s\"  s2=\"%s\"\n", tests[t].s1, tests[t].s2);
        int d = editDistance(tests[t].s1, tests[t].s2);
        printf("Edit Distance: %d\n", d);
        if (d <= 5) printOperations(tests[t].s1, tests[t].s2);
        printf("\n");
    }
    return 0;
}
