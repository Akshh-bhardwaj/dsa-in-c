/*
 * Linear Search
 * -------------
 * Search for a target in an unsorted array by scanning each element.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <stdio.h>

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) return i;
    }
    return -1; /* Not found */
}

int main() {
    int arr[] = {4, 2, 9, 7, 3, 15, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    printf("Array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\nSearching for: %d\n", target);

    int result = linearSearch(arr, n, target);
    if (result != -1)
        printf("Found at index: %d\n", result);
    else
        printf("Element not found!\n");

    return 0;
}
