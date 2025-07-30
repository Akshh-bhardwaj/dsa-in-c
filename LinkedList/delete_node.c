#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head, *prev = NULL;
    if (temp && temp->data == key) {
        *head = temp->next; free(temp); return;
    }
    while (temp && temp->data != key) {
        prev = temp; temp = temp->next;
    }
    if (!temp) return;
    prev->next = temp->next; free(temp);
}

void insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data; newNode->next = *head;
    *head = newNode;
}

void print(struct Node* head) {
    while (head) {
        printf("%d -> ", head->data); head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    print(head);
    deleteNode(&head, 20);
    print(head);
    return 0;
}
