/*
 * BST Insert
 * ----------
 * Insert nodes into a Binary Search Tree (BST).
 * BST property: left subtree < root < right subtree
 *
 * Time Complexity: O(h) where h is height of tree
 * Average: O(log n), Worst: O(n) for skewed tree
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *newNode(int data) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->data  = data;
    n->left  = NULL;
    n->right = NULL;
    return n;
}

Node *insert(Node *root, int data) {
    if (root == NULL) return newNode(data);
    if (data < root->data)
        root->left  = insert(root->left,  data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    /* Ignore duplicates */
    return root;
}

int search(Node *root, int key) {
    if (root == NULL)          return 0;
    if (root->data == key)     return 1;
    if (key < root->data)      return search(root->left,  key);
    return                            search(root->right, key);
}

/* Inorder traversal to verify BST ordering */
void inorder(Node *root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    Node *root = NULL;
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(values) / sizeof(values[0]);

    printf("Inserting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", values[i]);
        root = insert(root, values[i]);
    }
    printf("\n");

    printf("Inorder (should be sorted): ");
    inorder(root);
    printf("\n");

    printf("Search 40 : %s\n", search(root, 40) ? "Found ✓" : "Not Found ✗");
    printf("Search 99 : %s\n", search(root, 99) ? "Found ✓" : "Not Found ✗");

    return 0;
}
