/*
 * Stack using Linked List
 * -----------------------
 * Dynamic stack – no size limit (bounded only by memory).
 * Includes Infix to Postfix conversion demo.
 *
 * Time Complexity: O(1) push/pop/peek
 * Space Complexity: O(n)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char data;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
    int size;
} Stack;

void initStack(Stack *s) { s->top = NULL; s->size = 0; }

int isEmpty(Stack *s) { return s->top == NULL; }

void push(Stack *s, char data) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = data;
    n->next = s->top;
    s->top = n;
    s->size++;
}

char pop(Stack *s) {
    if (isEmpty(s)) { printf("Stack Underflow!\n"); return '\0'; }
    Node *temp = s->top;
    char val = temp->data;
    s->top = temp->next;
    free(temp);
    s->size--;
    return val;
}

char peek(Stack *s) {
    if (isEmpty(s)) return '\0';
    return s->top->data;
}

/* ---- Infix to Postfix Conversion ---- */
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^')              return 3;
    return 0;
}

void infixToPostfix(char *infix, char *postfix) {
    Stack s;
    initStack(&s);
    int k = 0;

    for (int i = 0; infix[i]; i++) {
        char c = infix[i];

        if (isalnum(c)) {
            postfix[k++] = c; /* Operand goes directly to output */
        } else if (c == '(') {
            push(&s, c);
        } else if (c == ')') {
            while (!isEmpty(&s) && peek(&s) != '(')
                postfix[k++] = pop(&s);
            if (!isEmpty(&s)) pop(&s); /* Remove '(' */
        } else {
            /* Operator: pop higher or equal precedence operators first */
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(c))
                postfix[k++] = pop(&s);
            push(&s, c);
        }
    }
    while (!isEmpty(&s)) postfix[k++] = pop(&s);
    postfix[k] = '\0';
}

int main() {
    /* Demonstrate stack push/pop */
    Stack s;
    initStack(&s);
    push(&s, 'A');
    push(&s, 'B');
    push(&s, 'C');
    printf("Stack top: %c\n", peek(&s));
    printf("Popped: %c\n", pop(&s));
    printf("Popped: %c\n", pop(&s));

    /* Infix to Postfix */
    printf("\n--- Infix to Postfix ---\n");
    char *expressions[] = {
        "A+B*C",
        "(A+B)*C",
        "A+B*C-D/E",
        "(A+B)*(C-D)"
    };
    char result[100];
    for (int i = 0; i < 4; i++) {
        infixToPostfix(expressions[i], result);
        printf("Infix: %-15s => Postfix: %s\n", expressions[i], result);
    }

    return 0;
}
