#ifndef __S_LINKED_LIST2_H__
#define __S_LINKED_LIST2_H__

#define TRUE 1
#define FALSE 0

typedef char* element;	// Require modification

// 단순연결리스트의 노드 구조를 구조체로 정의
typedef struct ListNode {
	element data;
	struct ListNode* link;
}listNode;

// 리스트 시작을 나타내는 head 노드를 구조체로 정의
typedef struct LinkedList {
	listNode* head;
	int length;
}linkedList;

linkedList* initList();									// 공백리스트 생성 
void insert(linkedList* L, listNode* pre, element x);	// 중간 노드로 삽입 
void insertFirst(linkedList* L, element x);				// 첫 번째 노드로 삽입 
void insertLast(linkedList* L, element x);				// 마지막 노드로 삽입 
int delete(linkedList* L, listNode* p);					// 노드 삭제 
listNode* search(linkedList* L, element x);				// 검색 
int getLength(linkedList* L);							// 리스트에 저장되어 있는 데이터의 수 반환 
void displayList(linkedList* L);						// 리스트의 모든 요소 출력 
void clear(linkedList* L);								// 리스트의 전체 메모리 해제 
void reverse(linkedList* L);							// 리스트의 노드 순서를 역순으로 바꿈 

#endif

