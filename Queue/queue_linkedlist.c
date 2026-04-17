/*
 * Queue using Linked List
 * -----------------------
 * Dynamic queue – no fixed size limit.
 * Also demonstrates implementing a Queue using two Stacks.
 *
 * Time Complexity: O(1) enqueue/dequeue (linked list version)
 * Space Complexity: O(n)
 */

#include <stdio.h>
#include <stdlib.h>

/* ============================
 * QUEUE USING LINKED LIST
 * ============================ */

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
    int size;
} Queue;

void initQueue(Queue *q) { q->front = q->rear = NULL; q->size = 0; }

int isEmpty(Queue *q) { return q->front == NULL; }

void enqueue(Queue *q, int data) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = data;
    n->next = NULL;
    if (isEmpty(q)) {
        q->front = q->rear = n;
    } else {
        q->rear->next = n;
        q->rear = n;
    }
    q->size++;
    printf("Enqueued: %d\n", data);
}

int dequeue(Queue *q) {
    if (isEmpty(q)) { printf("Queue Underflow!\n"); return -1; }
    Node *temp = q->front;
    int val = temp->data;
    q->front = temp->next;
    if (!q->front) q->rear = NULL;
    free(temp);
    q->size--;
    return val;
}

void printQueue(Queue *q) {
    Node *temp = q->front;
    printf("Queue: ");
    while (temp) { printf("%d -> ", temp->data); temp = temp->next; }
    printf("NULL\n");
}

/* ============================
 * QUEUE USING TWO STACKS
 * ============================ */

#define SMAX 100

typedef struct {
    int arr[SMAX];
    int top;
} Stack;

void initStack(Stack *s) { s->top = -1; }
int stackEmpty(Stack *s)  { return s->top == -1; }
void stackPush(Stack *s, int x) { s->arr[++(s->top)] = x; }
int  stackPop(Stack *s)         { return s->arr[(s->top)--]; }

typedef struct {
    Stack s1; /* for enqueue */
    Stack s2; /* for dequeue */
} TwoStackQueue;

void tsqInit(TwoStackQueue *q)  { initStack(&q->s1); initStack(&q->s2); }

void tsqEnqueue(TwoStackQueue *q, int x) {
    stackPush(&q->s1, x);
}

int tsqDequeue(TwoStackQueue *q) {
    if (stackEmpty(&q->s2)) {
        while (!stackEmpty(&q->s1))
            stackPush(&q->s2, stackPop(&q->s1));
    }
    if (stackEmpty(&q->s2)) { printf("Queue empty!\n"); return -1; }
    return stackPop(&q->s2);
}

int main() {
    printf("=== Queue using Linked List ===\n");
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    printQueue(&q);
    printf("Dequeued: %d\n", dequeue(&q));
    printQueue(&q);

    printf("\n=== Queue using Two Stacks ===\n");
    TwoStackQueue tsq;
    tsqInit(&tsq);
    tsqEnqueue(&tsq, 1);
    tsqEnqueue(&tsq, 2);
    tsqEnqueue(&tsq, 3);
    printf("Dequeued: %d\n", tsqDequeue(&tsq));
    printf("Dequeued: %d\n", tsqDequeue(&tsq));
    tsqEnqueue(&tsq, 4);
    printf("Dequeued: %d\n", tsqDequeue(&tsq));
    printf("Dequeued: %d\n", tsqDequeue(&tsq));

    return 0;
}
