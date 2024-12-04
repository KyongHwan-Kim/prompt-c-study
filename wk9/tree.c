#include <stdio.h>
#include <stdlib.h>

// 노드 구조체 정의
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// 새로운 노드 생성
Node* createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 트리에 데이터 삽입 (BST 형태로 삽입)
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data); // 트리가 비어있으면 새 노드 생성
    }

    if (data < root->data) {
        root->left = insert(root->left, data); // 왼쪽 서브트리에 삽입
    } else {
        root->right = insert(root->right, data); // 오른쪽 서브트리에 삽입
    }
    return root;
}

// 트리에서 최솟값 찾기
Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// 트리에서 노드 삭제
Node* deleteNode(Node* root, int data) {
    if (root == NULL) {
        return root; // 트리가 비어있음
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data); // 왼쪽 서브트리에서 삭제
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data); // 오른쪽 서브트리에서 삭제
    } else {
        // 삭제할 노드를 찾음
        if (root->left == NULL && root->right == NULL) {
            // 1. 리프 노드인 경우
            free(root);
            return NULL;
        } else if (root->left == NULL) {
            // 2. 자식이 하나(오른쪽)인 경우
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            // 2. 자식이 하나(왼쪽)인 경우
            Node* temp = root->left;
            free(root);
            return temp;
        } else {
            // 3. 자식이 두 개 있는 경우
            Node* temp = findMin(root->right); // 오른쪽 서브트리의 최솟값 찾기
            root->data = temp->data;          // 삭제할 노드의 값을 대체
            root->right = deleteNode(root->right, temp->data); // 대체 노드 삭제
        }
    }
    return root;
}

// 트리의 순회
// 중위 순회 (Inorder Traversal): Left -> Root -> Right
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// 메모리 해제
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// 메인 함수
int main() {
    Node* root = NULL;

    // 트리에 데이터 삽입
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    // 노드 삭제 테스트
    printf("Deleting 20\n");
    root = deleteNode(root, 20);
    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Deleting 30\n");
    root = deleteNode(root, 30);
    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Deleting 50\n");
    root = deleteNode(root, 50);
    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    // 메모리 해제
    freeTree(root);

    return 0;
}
