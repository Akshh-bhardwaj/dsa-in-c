#include <stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void minHeapify(int heap[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] < heap[smallest])
        smallest = left;
    if (right < n && heap[right] < heap[smallest])
        smallest = right;
    
    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(heap, n, smallest);
    }
}

void buildMinHeap(int heap[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeapify(heap, n, i);
    }
}

void printHeap(int heap[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    int arr[] = {3, 9, 2, 1, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    buildMinHeap(arr, n);
    printf("Min Heap: ");
    printHeap(arr, n);
    return 0;
}
