/*
 * Longest Increasing Subsequence (LIS)
 * ======================================
 * Find the length of the longest strictly increasing subsequence.
 *
 * Method 1: DP — O(n^2) — builds dp[i] = LIS ending at index i
 * Method 2: Binary Search (Patience Sorting) — O(n log n) ← optimal
 *
 * Print the actual LIS using parent[] array.
 *
 * Time  Complexity: O(n^2) DP, O(n log n) BS
 * Space Complexity: O(n)
 *
 * Interview note:
 *   - LeetCode 300 "Longest Increasing Subsequence" ← classic
 *   - LeetCode 354 "Russian Doll Envelopes" (2D LIS)
 *   - LeetCode 673 "Number of LIS"
 */

#include <stdio.h>
#include <string.h>

#define MAXN 1005

int dp[MAXN];
int parent[MAXN];

/* Method 1: O(n^2) DP */
int lisDP(int arr[], int n) {
    for (int i = 0; i < n; i++) { dp[i] = 1; parent[i] = -1; }

    int maxLen = 1, maxIdx = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }
        if (dp[i] > maxLen) { maxLen = dp[i]; maxIdx = i; }
    }

    /* Print actual LIS */
    int seq[MAXN], len = 0;
    for (int x = maxIdx; x != -1; x = parent[x]) seq[len++] = arr[x];
    printf("LIS (DP): length=%d, sequence: ", maxLen);
    for (int i = len-1; i >= 0; i--) printf("%d%s", seq[i], i ? " " : "\n");

    return maxLen;
}

/* Method 2: O(n log n) Binary Search (Patience Sorting) */
int binarySearch(int tails[], int lo, int hi, int target) {
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (tails[mid] < target) lo = mid + 1;
        else                     hi = mid;
    }
    return lo;
}

int lisBinarySearch(int arr[], int n) {
    int tails[MAXN]; /* tails[i] = smallest tail of IS with length i+1 */
    int size = 0;

    for (int i = 0; i < n; i++) {
        int pos = binarySearch(tails, 0, size, arr[i]);
        tails[pos] = arr[i];
        if (pos == size) size++;
    }
    printf("LIS (Binary Search): length=%d\n", size);
    return size;
}

int main() {
    int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n\n");

    lisDP(arr, n);
    lisBinarySearch(arr, n);

    printf("\n");
    int arr2[] = {0, 1, 0, 3, 2, 3};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("Array: ");
    for (int i = 0; i < n2; i++) printf("%d ", arr2[i]);
    printf("\n");
    lisDP(arr2, n2);
    lisBinarySearch(arr2, n2);

    return 0;
}
