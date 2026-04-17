/*
 * Max and Min Element in an Array
 * --------------------------------
 * Find the maximum and minimum element in an array in a single pass.
 *
 * Approach: Linear scan O(n)
 */

#include <stdio.h>

void findMaxMin(int arr[], int n) {
    if (n == 0) {
        printf("Array is empty!\n");
        return;
    }
    int max = arr[0], min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }
    printf("Maximum element: %d\n", max);
    printf("Minimum element: %d\n", min);
}

int main() {
    int arr[] = {3, 5, 1, 9, 2, 8, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    findMaxMin(arr, n);

    return 0;
}
