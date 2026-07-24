/*
 * array_basics.c
 * --------------
 * A comprehensive guide to understanding and using Arrays in C.
 * Designed as a teaching tool for students to master core array concepts in C.
 * 
 * Topics Covered:
 * 1. Declaration, Initialization & Size Calculation
 * 2. Accessing & Modifying Elements
 * 3. Array Traversal
 * 4. Basic Operations (Search, Sum, Average, Min/Max)
 * 5. Shifting Elements (Insertion & Deletion simulation in fixed-size arrays)
 * 6. Multi-dimensional (2D) Arrays
 * 7. Dynamic Arrays using malloc & free
 */

#include <stdio.h>
#include <stdlib.h>

void demoDeclarationAndInitialization() {
    printf("--- 1. Declaration & Initialization ---\n");

    // Syntax A: Declare and define size (contains garbage values until initialized)
    int arr1[5] = {0}; // Initialized all to 0

    // Syntax B: Direct initialization with values (size inferred)
    int arr2[] = {10, 20, 30, 40, 50};

    // Calculate length of array
    // sizeof(arr2) gives total bytes occupied, sizeof(arr2[0]) gives bytes of one element
    int length = sizeof(arr2) / sizeof(arr2[0]);

    printf("arr1 size (elements): 5\n");
    printf("arr2 length (calculated): %d\n", length);
    printf("Total memory size of arr2: %lu bytes\n\n", sizeof(arr2));
}

void demoAccessAndModify() {
    printf("--- 2. Accessing & Modifying Elements ---\n");
    int numbers[] = {100, 200, 300};

    // Access (0-indexed)
    printf("Element at index 0: %d\n", numbers[0]);
    printf("Element at index 2: %d\n", numbers[2]);

    // Modify
    numbers[1] = 999;
    printf("Modified element at index 1: %d\n\n", numbers[1]);
}

void demoTraversal() {
    printf("--- 3. Array Traversal ---\n");
    int arr[] = {2, 4, 6, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Standard for loop traversal
    printf("Traversal using for loop: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}

void demoBasicOperations() {
    printf("--- 4. Basic Array Operations ---\n");
    int values[] = {12, 45, 2, 67, 34, 9, 23};
    int n = sizeof(values) / sizeof(values[0]);

    // Sum and Average
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += values[i];
    }
    double average = (double)sum / n;

    // Min and Max
    int min = values[0];
    int max = values[0];
    for (int i = 1; i < n; i++) {
        if (values[i] < min) min = values[i];
        if (values[i] > max) max = values[i];
    }

    // Linear Search
    int target = 67;
    int targetIndex = -1;
    for (int i = 0; i < n; i++) {
        if (values[i] == target) {
            targetIndex = i;
            break;
        }
    }

    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);
    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);
    printf("Target %d found at index: %d\n\n", target, targetIndex);
}

void demoInsertionAndDeletion() {
    printf("--- 5. Insertion & Deletion (Shifting Elements) ---\n");
    
    // Create an array with a larger capacity than its initial elements
    int arr[10] = {10, 20, 30, 40, 50};
    int size = 5; // current number of active elements
    int capacity = 10;

    printf("Initial array: ");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");

    // 1. INSERTION: Insert 99 at index 2
    int insertIndex = 2;
    int newElement = 99;

    if (size < capacity) {
        // Shift elements to the right to make space
        for (int i = size; i > insertIndex; i--) {
            arr[i] = arr[i - 1];
        }
        arr[insertIndex] = newElement;
        size++;
        
        printf("After insertion of %d at index %d: ", newElement, insertIndex);
        for (int i = 0; i < size; i++) printf("%d ", arr[i]);
        printf("\n");
    }

    // 2. DELETION: Delete element at index 3 (which is 30)
    int deleteIndex = 3;
    if (deleteIndex < size) {
        // Shift elements to the left to close the gap
        for (int i = deleteIndex; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;

        printf("After deletion at index %d: ", deleteIndex);
        for (int i = 0; i < size; i++) printf("%d ", arr[i]);
        printf("\n\n");
    }
}

void demoTwoDimensionalArrays() {
    printf("--- 6. Multi-dimensional (2D) Arrays ---\n");

    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printf("Matrix Traversal:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void demoDynamicArrays() {
    printf("--- 7. Dynamic Arrays (malloc/free) ---\n");
    int size = 5;

    // Allocate memory dynamically
    int *dynArr = (int *)malloc(size * sizeof(int));
    if (dynArr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    // Initialize values
    for (int i = 0; i < size; i++) {
        dynArr[i] = (i + 1) * 10;
    }

    printf("Dynamic array values: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", dynArr[i]);
    }
    printf("\n");

    // Free the allocated memory to avoid memory leaks
    free(dynArr);
    printf("Memory freed successfully.\n\n");
}

int main() {
    printf("==================================================\n");
    printf("            C ARRAYS COMPREHENSIVE GUIDE          \n");
    printf("==================================================\n\n");

    demoDeclarationAndInitialization();
    demoAccessAndModify();
    demoTraversal();
    demoBasicOperations();
    demoInsertionAndDeletion();
    demoTwoDimensionalArrays();
    demoDynamicArrays();

    return 0;
}
