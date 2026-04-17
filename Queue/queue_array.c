/*
 * Queue using Array (Circular Queue)
 * -----------------------------------
 * A circular queue avoids wasted space after dequeue operations.
 * Operations: enqueue, dequeue, peek, isEmpty, isFull
 *
 * Time Complexity: O(1) for all operations
 * Space Complexity: O(n)
 */

#include <stdio.h>

#define MAX 5

typedef struct {
    int arr[MAX];
    int front;
    int rear;
    int count;
} CircularQueue;

void initQueue(CircularQueue *q) {
    q->front = 0;
    q->rear  = -1;
    q->count = 0;
}

int isEmpty(CircularQueue *q) { return q->count == 0; }
int isFull(CircularQueue *q)  { return q->count == MAX; }

void enqueue(CircularQueue *q, int data) {
    if (isFull(q)) { printf("Queue is Full (Overflow)!\n"); return; }
    q->rear = (q->rear + 1) % MAX;
    q->arr[q->rear] = data;
    q->count++;
    printf("Enqueued: %d\n", data);
}

int dequeue(CircularQueue *q) {
    if (isEmpty(q)) { printf("Queue is Empty (Underflow)!\n"); return -1; }
    int val = q->arr[q->front];
    q->front = (q->front + 1) % MAX;
    q->count--;
    return val;
}

int peekFront(CircularQueue *q) {
    if (isEmpty(q)) { printf("Queue is empty!\n"); return -1; }
    return q->arr[q->front];
}

void printQueue(CircularQueue *q) {
    if (isEmpty(q)) { printf("Queue is empty\n"); return; }
    printf("Queue (front -> rear): ");
    for (int i = 0; i < q->count; i++) {
        printf("%d ", q->arr[(q->front + i) % MAX]);
    }
    printf("\n");
}

int main() {
    CircularQueue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    printQueue(&q);

    printf("Dequeued : %d\n", dequeue(&q));
    printQueue(&q);

    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60); /* Uses the freed spot – circular behavior */
    printQueue(&q);

    printf("Front    : %d\n", peekFront(&q));

    return 0;
}
