#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int front, rear;
} Queue;

void initQueue(Queue* queue) {
    queue->front = 0;
    queue->rear = -1;
}

int isFull(Queue* queue) {
    return queue->rear == MAX - 1;
}

int isEmpty(Queue* queue) {
    return queue->front > queue->rear;
}

void enqueue(Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue Overflow\n");
        return;
    }
    queue->data[++(queue->rear)] = value;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow\n");
        return -1;
    }
    return queue->data[(queue->front)++];
}

int peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is Empty\n");
        return -1;
    }
    return queue->data[queue->front];
}
