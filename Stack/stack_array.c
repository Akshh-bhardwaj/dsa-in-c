/*
 * Stack using Array
 * -----------------
 * Implements a LIFO stack using a fixed-size array.
 * Operations: push, pop, peek, isEmpty, isFull
 *
 * Time Complexity: O(1) for all operations
 * Space Complexity: O(n)
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int top;
} Stack;

void initStack(Stack *s) { s->top = -1; }

int isEmpty(Stack *s) { return s->top == -1; }

int isFull(Stack *s) { return s->top == MAX - 1; }

void push(Stack *s, int data) {
    if (isFull(s)) { printf("Stack Overflow!\n"); return; }
    s->arr[++(s->top)] = data;
    printf("Pushed: %d\n", data);
}

int pop(Stack *s) {
    if (isEmpty(s)) { printf("Stack Underflow!\n"); return -1; }
    return s->arr[(s->top)--];
}

int peek(Stack *s) {
    if (isEmpty(s)) { printf("Stack is empty!\n"); return -1; }
    return s->arr[s->top];
}

void printStack(Stack *s) {
    if (isEmpty(s)) { printf("Stack is empty\n"); return; }
    printf("Stack (top -> bottom): ");
    for (int i = s->top; i >= 0; i--) printf("%d ", s->arr[i]);
    printf("\n");
}

/* ---- Valid Parentheses using Stack ---- */
int isValidParentheses(char *str) {
    Stack s;
    initStack(&s);
    for (int i = 0; str[i]; i++) {
        char c = str[i];
        if (c == '(' || c == '{' || c == '[') {
            push(&s, c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (isEmpty(&s)) return 0;
            char top = (char)pop(&s);
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) return 0;
        }
    }
    return isEmpty(&s);
}

int main() {
    Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    printStack(&s);
    printf("Top element : %d\n", peek(&s));
    printf("Popped      : %d\n", pop(&s));
    printStack(&s);

    printf("\n--- Valid Parentheses ---\n");
    char *tests[] = {"(())", "()[]{}", "(]", "([)]", "{[]}"};
    for (int i = 0; i < 5; i++) {
        printf("\"%s\" => %s\n", tests[i],
               isValidParentheses(tests[i]) ? "Valid ✓" : "Invalid ✗");
    }

    return 0;
}
