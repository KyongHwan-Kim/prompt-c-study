#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertHeap(int value) {
    heap[++size] = value;
    int current = size;

    while (current > 1 && heap[current] < heap[current / 2]) {
        swap(&heap[current], &heap[current / 2]);
        current /= 2;
    }
}

int deleteHeap() {
    if (size == 0) {
        printf("Heap is Empty\n");
        return -1;
    }

    int root = heap[1];
    heap[1] = heap[size--];
    int current = 1;

    while (current * 2 <= size) {
        int child = current * 2;
        if (child + 1 <= size && heap[child + 1] < heap[child]) {
            child++;
        }
        if (heap[current] <= heap[child]) {
            break;
        }
        swap(&heap[current], &heap[child]);
        current = child;
    }

    return root;
}
