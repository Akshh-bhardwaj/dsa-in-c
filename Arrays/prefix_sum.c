/*
 * Prefix Sum Array
 * ----------------
 * Build a prefix sum array where prefix[i] = sum of arr[0..i].
 * Then answer range sum queries in O(1).
 *
 * Approach: Prefix sum O(n) preprocessing, O(1) query
 */

#include <stdio.h>

#define MAX 100

void buildPrefixSum(int arr[], int prefix[], int n) {
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }
}

/* Sum of arr[l..r] inclusive */
int rangeSum(int prefix[], int l, int r) {
    if (l == 0) return prefix[r];
    return prefix[r] - prefix[l - 1];
}

int main() {
    int arr[] = {2, 4, 6, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int prefix[MAX];

    buildPrefixSum(arr, prefix, n);

    printf("Array  : ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\nPrefix : ");
    for (int i = 0; i < n; i++) printf("%d ", prefix[i]);
    printf("\n");

    printf("Sum of arr[1..3] = %d\n", rangeSum(prefix, 1, 3)); /* 4+6+8 = 18 */
    printf("Sum of arr[0..4] = %d\n", rangeSum(prefix, 0, 4)); /* 30 */

    return 0;
}
