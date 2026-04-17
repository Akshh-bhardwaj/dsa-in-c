/*
 * Longest Common Subsequence (LCS)
 * =================================
 * Find the length of the longest subsequence common to two strings.
 * A subsequence does NOT need to be contiguous.
 *
 * Recurrence:
 *   if s1[i] == s2[j]:  dp[i][j] = 1 + dp[i-1][j-1]
 *   else:               dp[i][j] = max(dp[i-1][j], dp[i][j-1])
 *
 * Time  Complexity: O(m * n)
 * Space Complexity: O(m * n) → O(n) space-optimised
 *
 * Extensions:
 *   - Print the actual LCS (backtracking)
 *   - Shortest Common Supersequence (SCS)
 *   - Longest Common Substring (contiguous)
 *   - Edit Distance (LeetCode 72)
 *   - LCS (LeetCode 1143)
 */

#include <stdio.h>
#include <string.h>

#define MAXN 105

int dp[MAXN][MAXN];

int lcs(char *s1, char *s2) {
    int m = strlen(s1), n = strlen(s2);

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = dp[i-1][j] > dp[i][j-1] ? dp[i-1][j] : dp[i][j-1];
        }
    }
    return dp[m][n];
}

/* Backtrack to find the actual LCS string */
void printLCS(char *s1, char *s2) {
    int m = strlen(s1), n = strlen(s2);
    int len = dp[m][n];
    char result[MAXN];
    result[len] = '\0';

    int i = m, j = n, idx = len - 1;
    while (i > 0 && j > 0) {
        if (s1[i-1] == s2[j-1]) {
            result[idx--] = s1[i-1];
            i--; j--;
        } else if (dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }
    printf("LCS string : \"%s\"\n", result);
}

/* Longest Common Substring (contiguous) */
int longestCommonSubstring(char *s1, char *s2) {
    int m = strlen(s1), n = strlen(s2);
    int maxLen = 0;
    int dp2[MAXN][MAXN];
    memset(dp2, 0, sizeof(dp2));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp2[i][j] = 1 + dp2[i-1][j-1];
                if (dp2[i][j] > maxLen) maxLen = dp2[i][j];
            }
        }
    }
    return maxLen;
}

/* Shortest Common Supersequence length */
int shortestCommonSupersequence(char *s1, char *s2) {
    int m = strlen(s1), n = strlen(s2);
    return m + n - dp[m][n]; /* Uses LCS already computed */
}

int main() {
    char s1[] = "AGGTAB";
    char s2[] = "GXTXAYB";

    printf("s1 = \"%s\"\ns2 = \"%s\"\n\n", s1, s2);

    int len = lcs(s1, s2);
    printf("LCS length : %d\n", len);
    printLCS(s1, s2);
    printf("Longest Common Substring length : %d\n", longestCommonSubstring(s1, s2));
    printf("Shortest Common Supersequence   : %d\n", shortestCommonSupersequence(s1, s2));

    /* Another test */
    char a[] = "ABCBDAB", b[] = "BDCABA";
    printf("\ns1 = \"%s\"\ns2 = \"%s\"\n", a, b);
    printf("LCS length : %d\n", lcs(a, b));
    printLCS(a, b);

    return 0;
}
