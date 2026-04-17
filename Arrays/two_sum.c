/*
 * Two Sum
 * -------
 * Given an array of integers and a target,
 * return indices of the two numbers that add up to target.
 *
 * Approach: Brute Force O(n^2)
 */

#include <stdio.h>

void twoSum(int arr[], int n, int target) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                printf("Indices: [%d, %d] => arr[%d]=%d + arr[%d]=%d = %d\n",
                       i, j, i, arr[i], j, arr[j], target);
                found = 1;
            }
        }
    }
    if (!found) {
        printf("No pair found that adds up to %d\n", target);
    }
}

int main() {
    int arr[] = {2, 7, 11, 15};
    int target = 9;
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\nTarget: %d\n", target);

    twoSum(arr, n, target);

    return 0;
}
