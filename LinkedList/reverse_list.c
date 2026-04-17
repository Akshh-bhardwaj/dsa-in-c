/*
 * Reverse a Linked List
 * ---------------------
 * Reverse a singly linked list in-place using three pointers.
 *
 * Approach: Iterative O(n), O(1) space
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

Node *reverseList(Node *head) {
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;

    while (curr) {
        next = curr->next; /* Save next */
        curr->next = prev; /* Reverse the link */
        prev = curr;       /* Move prev forward */
        curr = next;       /* Move curr forward */
    }
    return prev; /* New head */
}

void printList(Node *head) {
    while (head) { printf("%d -> ", head->data); head = head->next; }
    printf("NULL\n");
}

int main() {
    Node *head = NULL;
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 3);
    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 5);

    printf("Original : "); printList(head);

    head = reverseList(head);

    printf("Reversed : "); printList(head);

    return 0;
}
