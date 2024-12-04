**학습 범위 : 스택, 큐, 힙, 트리 및 최종 정리**

## **1.  자료 구조**

**자료구조의 핵심인 스택, 큐, 힙, 트리**의 개념에 대해서 조사하세요. 원하신다면, 코드 구현을 해 오셔도 좋습니다.

### 스택 (Stack)
- 개념: 스택은 후입선출(LIFO: Last In, First Out) 방식의 자료구조입니다. 마지막에 삽입된 데이터가 가장 먼저 삭제됩니다.
- 주요 연산:
  - push: 스택에 데이터를 삽입
  - pop: 스택에서 데이터를 제거 및 반환
  - peek: 스택의 최상단 데이터를 확인
- 응용 사례: 웹 브라우저의 뒤로 가기, 괄호 검사, 실행 취소 기능 등.

### 큐
- 개념: 큐는 선입선출(FIFO: First In, First Out) 방식의 자료구조입니다. 가장 먼저 삽입된 데이터가 가장 먼저 삭제됩니다.
- 주요 연산:
  - enqueue: 큐에 데이터를 삽입
  - dequeue: 큐에서 데이터를 제거 및 반환
  - peek: 큐의 가장 앞 데이터를 확인
- 응용 사례: 프로세스 스케줄링, 데이터 스트리밍 처리 등.
### 힙
- 개념: 힙은 완전 이진 트리 형태의 자료구조로, 부모 노드가 자식 노드보다 크거나 작은 성질(최대 힙/최소 힙)을 가집니다.
- 주요 연산:
  - insert: 힙에 데이터를 삽입
  - delete: 힙에서 루트 노드를 제거
  - heapify: 삽입 또는 삭제 후 힙 속성을 유지
- 응용 사례: 우선순위 큐, 정렬 알고리즘(힙 정렬) 등.
### 트리
- 개념: 트리는 계층적 구조를 가진 비선형 자료구조로, 부모-자식 관계를 가집니다. 루트 노드에서 시작하며, 자식 노드는 0개 이상의 하위 노드를 가질 수 있습니다.
- 종류:
  - 이진 트리: 각 노드가 최대 두 개의 자식을 가짐.
  - 이진 탐색 트리: 왼쪽 자식은 부모보다 작고, 오른쪽 자식은 부모보다 큼.
- 응용 사례: 데이터베이스 인덱스, 네트워크 라우팅, 표현식 평가 등.
## **2.  최종 정리**

지금까지 배운 내용을 토대로 간단한 자신만의 미니 프로그램을 하나 만드세요. 어떤 프로그램이든 상관은 없으나, 자신이 짠 코드가 **어떻게 구성되어 있고**, **어떻게 동작하는지** 설명할 수 있어야 합니다.

### 스택과 큐를 활용한 텍스트 편집기
설명: 텍스트 편집기의 실행 취소(undo)와 다시 실행(redo) 기능 구현.

- 기능:
  - 사용자 입력을 스택에 저장.
  - "실행 취소" 시 스택에서 pop하여 복구.
  - "다시 실행" 시 큐로 관리하여 복구.
```
[출력 결과]
Simple Text Editor (C Language)
1. Edit text
2. Undo
3. Redo
4. Show current text
5. Exit

Choose an option: 1
Enter new text: Hello, World!

Choose an option: 4
Current text: Hello, World!

Choose an option: 1
Enter new text: Hello, C Programming!

Choose an option: 4
Current text: Hello, C Programming!

Choose an option: 2
Choose an option: 4
Current text: Hello, World!

Choose an option: 3
Choose an option: 4
Current text: Hello, C Programming!

```
