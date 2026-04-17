#include <stdio.h>

// Easiest Monotonic Stack without pointers or malloc
void nextGreater(int arr[], int n) {
    int stack[100]; // Fixed size array used as stack
    int top = -1;
    
    for (int i = 0; i < n; i++) {
        // While stack is not empty AND current element is greater than top of stack
        while (top != -1 && stack[top] < arr[i]) {
            printf("Next greater for %d is %d\n", stack[top], arr[i]);
            top--; // Pop element
        }
        
        // Push current element to stack
        stack[++top] = arr[i];
    }
    
    // Remaining elements have no greater element
    while (top != -1) {
        printf("Next greater for %d is -1\n", stack[top]);
        top--;
    }
}

int main() {
    int arr[] = {4, 5, 2, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    nextGreater(arr, n);
    return 0;
}
