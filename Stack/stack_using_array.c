// Problem: Implement stack using array

#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) {
    if(top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = val;
}

int pop() {
    if(top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

void display() {
    if(top == -1) {
        printf("Stack is empty\n");
        return;
    }
    for(int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    display();        // 30 20 10
    printf("Popped: %d\n", pop());
    display();        // 20 10
    return 0;
}
