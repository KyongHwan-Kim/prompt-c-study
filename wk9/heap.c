#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // 정적 힙의 최대 크기

typedef struct {
    int data[MAX_SIZE]; // 정적 배열
    int size;           // 현재 힙에 저장된 원소 개수
} MaxHeap;

// 힙 초기화
void initHeap(MaxHeap *heap) {
    heap->size = 0; // 초기 크기를 0으로 설정
}

// 부모와 자식의 인덱스 계산
int parent(int i) { return (i - 1) / 2; }
int leftChild(int i) { return 2 * i + 1; }
int rightChild(int i) { return 2 * i + 2; }

// 힙에 값 삽입 (삽입 후 최대 힙 유지)
void insert(MaxHeap *heap, int value) {
    if (heap->size == MAX_SIZE) {
        printf("Heap Overflow! Cannot insert %d.\n", value);
        return;
    }

    // 힙의 끝에 값 삽입
    heap->data[heap->size] = value;
    int i = heap->size;
    heap->size++;

    // 부모 노드와 비교하며 힙 속성을 유지
    while (i != 0 && heap->data[parent(i)] < heap->data[i]) {
        // 부모와 교환
        int temp = heap->data[i];
        heap->data[i] = heap->data[parent(i)];
        heap->data[parent(i)] = temp;

        i = parent(i);
    }
}

// 힙에서 최대값 제거 (삭제 후 최대 힙 유지)
int extractMax(MaxHeap *heap) {
    if (heap->size <= 0) {
        printf("Heap Underflow! Cannot extract from an empty heap.\n");
        exit(EXIT_FAILURE);
    }

    int max = heap->data[0]; // 루트 값 저장
    heap->data[0] = heap->data[heap->size - 1]; // 마지막 값을 루트로 이동
    heap->size--;

    // 힙 속성을 복구
    int i = 0;
    while (1) {
        int left = leftChild(i);
        int right = rightChild(i);
        int largest = i;

        // 왼쪽 자식이 더 크다면
        if (left < heap->size && heap->data[left] > heap->data[largest]) {
            largest = left;
        }

        // 오른쪽 자식이 더 크다면
        if (right < heap->size && heap->data[right] > heap->data[largest]) {
            largest = right;
        }

        // 최대값이 현재 노드라면 종료
        if (largest == i) {
            break;
        }

        // 현재 노드와 최대값 노드를 교환
        int temp = heap->data[i];
        heap->data[i] = heap->data[largest];
        heap->data[largest] = temp;

        i = largest; // 최대값 위치로 이동
    }

    return max;
}

// 힙의 최대값 반환
int getMax(MaxHeap *heap) {
    if (heap->size <= 0) {
        printf("Heap is empty!\n");
        exit(EXIT_FAILURE);
    }
    return heap->data[0];
}

// 힙 출력
void printHeap(MaxHeap *heap) {
    printf("Heap: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->data[i]);
    }
    printf("\n");
}

// 메인 함수
int main() {
    MaxHeap heap;
    initHeap(&heap);

    // 힙에 값 삽입
    insert(&heap, 10);
    insert(&heap, 20);
    insert(&heap, 5);
    insert(&heap, 30);
    insert(&heap, 40);

    printHeap(&heap); // 현재 힙 상태 출력

    printf("Max: %d\n", getMax(&heap)); // 최대값 확인

    printf("Extracted Max: %d\n", extractMax(&heap)); // 최대값 삭제
    printHeap(&heap);

    return 0;
}
