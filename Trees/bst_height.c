/*
 * BST Height (& Diameter)
 * -----------------------
 * Height of a tree = number of edges on the longest path from root to leaf.
 * Diameter         = longest path between any two nodes.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(h) – call stack height
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
    if (!root) return newNode(data);
    if (data < root->data) root->left  = insert(root->left,  data);
    else if (data > root->data) root->right = insert(root->right, data);
    return root;
}

int max(int a, int b) { return a > b ? a : b; }

/* Height of BST */
int height(Node *root) {
    if (!root) return -1; /* -1 for edge-count height, 0 for level count */
    int leftH  = height(root->left);
    int rightH = height(root->right);
    return 1 + max(leftH, rightH);
}

/* Diameter of BST */
int diameter;

int heightForDiameter(Node *root) {
    if (!root) return 0;
    int leftH  = heightForDiameter(root->left);
    int rightH = heightForDiameter(root->right);
    int curr = leftH + rightH; /* Diameter through this node */
    if (curr > diameter) diameter = curr;
    return 1 + max(leftH, rightH);
}

int main() {
    Node *root = NULL;
    int values[] = {50, 30, 70, 20, 40, 60, 80, 10};
    int n = sizeof(values) / sizeof(values[0]);

    printf("Inserting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", values[i]);
        root = insert(root, values[i]);
    }
    printf("\n");

    printf("Height of BST   : %d\n", height(root));

    diameter = 0;
    heightForDiameter(root);
    printf("Diameter of BST : %d\n", diameter);

    return 0;
}
