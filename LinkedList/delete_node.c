/*
 * Delete Node in Linked List
 * --------------------------
 * Delete a node by value from a singly linked list.
 *
 * Approach: Pointer traversal O(n)
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *newNode(int data) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = data;
    n->next = NULL;
    return n;
}

Node *insertAtEnd(Node *head, int data) {
    Node *n = newNode(data);
    if (!head) return n;
    Node *temp = head;
    while (temp->next) temp = temp->next;
    temp->next = n;
    return head;
}

Node *deleteNode(Node *head, int key) {
    if (!head) { printf("List is empty!\n"); return NULL; }

    /* If head itself holds the key */
    if (head->data == key) {
        Node *temp = head;
        head = head->next;
        free(temp);
        printf("Deleted %d\n", key);
        return head;
    }

    /* Search for the node */
    Node *prev = head, *curr = head->next;
    while (curr && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    if (!curr) { printf("%d not found in list\n", key); return head; }

    prev->next = curr->next;
    free(curr);
    printf("Deleted %d\n", key);
    return head;
}

void printList(Node *head) {
    while (head) { printf("%d -> ", head->data); head = head->next; }
    printf("NULL\n");
}

int main() {
    Node *head = NULL;
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);

    printf("Original : "); printList(head);

    head = deleteNode(head, 20);
    printf("After del: "); printList(head);

    head = deleteNode(head, 10); /* Delete head */
    printf("After del: "); printList(head);

    head = deleteNode(head, 99); /* Not found */

    return 0;
}
