/*
 * Tree Traversals
 * ---------------
 * Inorder   (Left -> Root -> Right) : gives sorted output for BST
 * Preorder  (Root -> Left -> Right) : useful for copying a tree
 * Postorder (Left -> Right -> Root) : useful for deleting a tree
 * Level Order (BFS)                 : level-by-level traversal
 *
 * Time Complexity:  O(n) for all traversals
 * Space Complexity: O(h) recursive, O(n) level-order queue
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

/* DFS Traversals */
void inorder(Node *root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(Node *root) {
    if (!root) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

/* Level Order Traversal using a simple array-based queue */
void levelOrder(Node *root) {
    if (!root) return;
    Node *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        Node *curr = queue[front++];
        printf("%d ", curr->data);
        if (curr->left)  queue[rear++] = curr->left;
        if (curr->right) queue[rear++] = curr->right;
    }
}

int main() {
    Node *root = NULL;
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) root = insert(root, values[i]);

    printf("Inorder   : "); inorder(root);     printf("\n");
    printf("Preorder  : "); preorder(root);    printf("\n");
    printf("Postorder : "); postorder(root);   printf("\n");
    printf("LevelOrder: "); levelOrder(root);  printf("\n");

    return 0;
}
