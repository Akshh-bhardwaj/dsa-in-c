/*
 * Quick Sort
 * ----------
 * Divide-and-conquer: pick a pivot, partition around it, and
 * recursively sort the sub-arrays.
 *
 * Time Complexity: O(n log n) avg, O(n^2) worst
 * Space Complexity: O(log n) call stack
 */

#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Lomuto partition scheme – pivot is last element */
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1; /* index of smaller element */

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting: ");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("After  sorting: ");
    printArray(arr, n);

    return 0;
}
