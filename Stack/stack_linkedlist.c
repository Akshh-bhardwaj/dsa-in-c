#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = top;
    top = newNode;
    printf("%d pushed to stack\n", x);
}

int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    int x = top->data;
    struct Node* temp = top;
    top = top->next;
    free(temp);
    return x;
}

int peek() {
    if (top == NULL)
        return -1;
    return top->data;
}

void display() {
    struct Node* temp = top;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    display();
    printf("Top element is %d\n", peek());
    printf("Popped element is %d\n", pop());
    display();
    return 0;
}
