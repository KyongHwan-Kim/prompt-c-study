#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LENGTH 100
#define MAX_STACK_SIZE 100

// 스택 구조 정의
typedef struct {
    char data[MAX_STACK_SIZE][MAX_TEXT_LENGTH];
    int top;
} Stack;

// 스택 초기화
void initStack(Stack* stack) {
    stack->top = -1;
}

// 스택 비었는지 확인
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// 스택 가득 찼는지 확인
int isFull(Stack* stack) {
    return stack->top == MAX_STACK_SIZE - 1;
}

// 스택에 데이터 추가
void push(Stack* stack, const char* text) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push.\n");
        return;
    }
    strcpy(stack->data[++(stack->top)], text);
}

// 스택에서 데이터 제거
char* pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return NULL;
    }
    return stack->data[(stack->top)--];
}

// 현재 스택의 최상단 데이터 반환
char* peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return NULL;
    }
    return stack->data[stack->top];
}

// 텍스트 편집기 구현
int main() {
    Stack undoStack, redoStack;
    char text[MAX_TEXT_LENGTH] = "";
    char input[MAX_TEXT_LENGTH];
    int choice;

    initStack(&undoStack);
    initStack(&redoStack);

    printf("Simple Text Editor (C Language)\n");
    printf("1. Edit text\n2. Undo\n3. Redo\n4. Show current text\n5. Exit\n");

    while (1) {
        printf("\nChoose an option: ");
        scanf("%d", &choice);
        getchar();  // 입력 버퍼 정리

        switch (choice) {
            case 1:
                // 텍스트 수정
                printf("Enter new text: ");
                fgets(input, MAX_TEXT_LENGTH, stdin);
                input[strcspn(input, "\n")] = 0;  // 개행 문자 제거
                push(&undoStack, text);  // 이전 상태를 Undo 스택에 저장
                strcpy(text, input);
                initStack(&redoStack);  // Redo 스택 초기화
                break;

            case 2:
                // Undo
                if (isEmpty(&undoStack)) {
                    printf("Nothing to undo.\n");
                } else {
                    push(&redoStack, text);  // 현재 상태를 Redo 스택에 저장
                    strcpy(text, pop(&undoStack));  // Undo 스택에서 이전 상태 가져오기
                }
                break;

            case 3:
                // Redo
                if (isEmpty(&redoStack)) {
                    printf("Nothing to redo.\n");
                } else {
                    push(&undoStack, text);  // 현재 상태를 Undo 스택에 저장
                    strcpy(text, pop(&redoStack));  // Redo 스택에서 상태 가져오기
                }
                break;

            case 4:
                // 현재 텍스트 출력
                printf("Current text: %s\n", text);
                break;

            case 5:
                // 종료
                printf("Exiting text editor.\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
