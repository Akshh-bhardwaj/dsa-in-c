#include <stdio.h>

void buildTree(int arr[], int tree[], int start, int end, int node) {
    if (start == end) {
        tree[node] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    buildTree(arr, tree, start, mid, 2 * node);
    buildTree(arr, tree, mid + 1, end, 2 * node + 1);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int query(int tree[], int start, int end, int l, int r, int node) {
    if (r < start || end < l) return 0;
    if (l <= start && end <= r) return tree[node];
    int mid = (start + end) / 2;
    int p1 = query(tree, start, mid, l, r, 2 * node);
    int p2 = query(tree, mid + 1, end, l, r, 2 * node + 1);
    return p1 + p2;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    int tree[4 * n];
    buildTree(arr, tree, 0, n - 1, 1);
    printf("Sum of values in range [1, 3] is %d\n", query(tree, 0, n - 1, 1, 3, 1));
    return 0;
}
