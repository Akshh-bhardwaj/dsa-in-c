#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);  // Space for readability
        head = head->next;          // ✅ Move to next node
    }
    printf("\n");                   // ✅ Correct escape sequence
}

int main() {
    struct Node* head;
    struct Node* first = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;
    struct Node* forth = NULL;
    struct Node* newnode = NULL;

    // Allocate memory
    first = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    forth = (struct Node*)malloc(sizeof(struct Node));
    newnode = (struct Node*)malloc(sizeof(struct Node));

    // Assign data
    first->data = 100;
    second->data = 200;
    third->data = 300;
    forth->data = 463;
    newnode->data = 45;

    // Connect nodes
    first->next = third;
    third->next = second;
    second->next = newnode;
    newnode->next = forth;
    forth->next = NULL;

    head = first;

    printf("Before insertion:\n");
    printList(head);

    // Insert 454 after 200
    struct Node* temp = head;
    while (temp != NULL && temp->data != 200) {
        temp = temp->next;
    }

    if (temp != NULL) {
        struct Node* insertNode = (struct Node*)malloc(sizeof(struct Node));
        insertNode->data = 454;
        insertNode->next = temp->next;
        temp->next = insertNode;
    }

    printf("After inserting 454 after 200:\n");
    printList(head);

    return 0;
}
