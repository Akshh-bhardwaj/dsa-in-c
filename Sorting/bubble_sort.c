/*
 * Bubble Sort
 * -----------
 * Repeatedly swap adjacent elements if they are in the wrong order.
 *
 * Time Complexity: O(n^2) worst/avg, O(n) best (already sorted with optimization)
 * Space Complexity: O(1)
 */

#include <stdio.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) break; /* Already sorted */
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting: ");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("After  sorting: ");
    printArray(arr, n);

    return 0;
}
