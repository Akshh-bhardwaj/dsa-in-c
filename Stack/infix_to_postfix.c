// infix_to_postfix.c
// Converts an infix expression to postfix using a stack.
// Supports: + - * / ^ and parentheses. Assumes single-letter operands or digits.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack for characters
typedef struct {
    char data[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, char c) {
    if (!isFull(s)) {
        s->data[++(s->top)] = c;
    }
}

char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    }
    return '\0';
}

char peek(Stack *s) {
    if (!isEmpty(s)) return s->data[s->top];
    return '\0';
}

// precedence: higher value means higher precedence
int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

// Check if character is operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Convert infix to postfix
void infixToPostfix(const char *infix, char *postfix) {
    Stack s;
    init(&s);
    int k = 0;
    for (int i = 0; infix[i] != '\0'; ++i) {
        char c = infix[i];

        if (isspace(c)) continue; // skip spaces

        if (isalnum(c)) { // operand
            postfix[k++] = c;
        } else if (c == '(') {
            push(&s, c);
        } else if (c == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[k++] = pop(&s);
            }
            if (!isEmpty(&s) && peek(&s) == '(') pop(&s); // discard '('
        } else if (isOperator(c)) {
            while (!isEmpty(&s) && 
                  ((precedence(peek(&s)) > precedence(c)) ||
                   (precedence(peek(&s)) == precedence(c) && c != '^')) &&
                  peek(&s) != '(') {
                postfix[k++] = pop(&s);
            }
            push(&s, c);
        }
    }
    while (!isEmpty(&s)) {
        postfix[k++] = pop(&s);
    }
    postfix[k] = '\0';
}

int main() {
    char infix[256];
    char postfix[256];

    printf("Enter infix expression (e.g. a+b*(c^d-e)^(f+g*h)-i):\n");
    if (!fgets(infix, sizeof(infix), stdin)) return 0;

    // remove trailing newline if any
    infix[strcspn(infix, "\n")] = '\0';

    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);
    return 0;
}
