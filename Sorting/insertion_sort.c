/*
 * Insertion Sort
 * --------------
 * Build a sorted portion of the array one element at a time by
 * inserting each element into its correct position.
 *
 * Time Complexity: O(n^2) worst/avg, O(n) best
 * Space Complexity: O(1)
 */

#include <stdio.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        /* Shift elements greater than key one position ahead */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting: ");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("After  sorting: ");
    printArray(arr, n);

    return 0;
}
