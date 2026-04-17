#include <stdio.h>

// Easiest "Hashing" implementation using Direct Addressing (Array mapping)
// Note: This simple approach works only for small positive integers.
void twoSum(int arr[], int n, int target) {
    int hash[1000] = {0}; // Initialize all entries to 0 (empty)
    
    for (int i = 0; i < n; i++) {
        int complement = target - arr[i];
        
        // Check if complement exists in our "hash map"
        if (complement >= 0 && hash[complement] != 0) {
            // hash stores 1-based index to handle 0 as "empty"
            printf("Found numbers %d and %d!\n", arr[hash[complement] - 1], arr[i]);
            printf("At Indices: %d and %d\n", hash[complement] - 1, i);
            return;
        }
        
        // Save current number's index (1-based to avoid 0 collision)
        hash[arr[i]] = i + 1; 
    }
    printf("Not found\n");
}

int main() {
    int arr[] = {2, 7, 11, 15};
    int target = 9;
    int n = sizeof(arr) / sizeof(arr[0]);
    
    twoSum(arr, n, target);
    return 0;
}
