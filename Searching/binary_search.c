/*
 * Binary Search
 * -------------
 * Search for a target in a SORTED array by repeatedly halving
 * the search space.
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(1) iterative
 */

#include <stdio.h>

int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2; /* Avoids integer overflow */
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else                        high = mid - 1;
    }
    return -1; /* Not found */
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 23;

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\nSearching for: %d\n", target);

    int result = binarySearch(arr, n, target);
    if (result != -1)
        printf("Found at index: %d\n", result);
    else
        printf("Element not found!\n");

    return 0;
}
