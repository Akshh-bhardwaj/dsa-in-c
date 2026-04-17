/*
 * Move Zeroes to the End
 * ----------------------
 * Move all zeroes in an array to the end while maintaining the
 * relative order of non-zero elements.
 *
 * Approach: Two-pointer in-place O(n)
 */

#include <stdio.h>

void moveZeroes(int arr[], int n) {
    int pos = 0; /* position to place next non-zero */
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arr[pos++] = arr[i];
        }
    }
    /* Fill remaining positions with 0 */
    while (pos < n) {
        arr[pos++] = 0;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {0, 1, 0, 3, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original : ");
    printArray(arr, n);

    moveZeroes(arr, n);

    printf("After    : ");
    printArray(arr, n);

    return 0;
}
