/*
 * Insert Node in Linked List
 * --------------------------
 * Support inserting at the beginning, end, and a given position.
 *
 * Approach: Pointer manipulation
 */

#include <stdio.h>
#include <stdlib.h>

/* Node definition */
typedef struct Node {
    int data;
    struct Node *next;
} Node;

/* Create a new node */
Node *newNode(int data) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = data;
    n->next = NULL;
    return n;
}

/* Insert at beginning */
Node *insertAtBegin(Node *head, int data) {
    Node *n = newNode(data);
    n->next = head;
    return n; /* new head */
}

/* Insert at end */
Node *insertAtEnd(Node *head, int data) {
    Node *n = newNode(data);
    if (head == NULL) return n;
    Node *temp = head;
    while (temp->next) temp = temp->next;
    temp->next = n;
    return head;
}

/* Insert after given position (1-indexed) */
void insertAtPos(Node *head, int pos, int data) {
    Node *temp = head;
    for (int i = 1; i < pos - 1 && temp; i++) temp = temp->next;
    if (!temp) { printf("Position out of range\n"); return; }
    Node *n = newNode(data);
    n->next = temp->next;
    temp->next = n;
}

/* Print the linked list */
void printList(Node *head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node *head = NULL;

    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    printf("Initial list      : "); printList(head);

    head = insertAtBegin(head, 5);
    printf("After insertBegin : "); printList(head);

    insertAtPos(head, 3, 15);
    printf("After insertPos(3): "); printList(head);

    return 0;
}
