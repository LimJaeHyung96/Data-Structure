#ifndef __S_LINKED_LIST3_H__
#define __S_LINKED_LIST3_H__

#define TRUE 1
#define FALSE 0

typedef int element;

// 단순연결리스트의 노드 구조를 구조체로 정의
typedef struct ListNode {
	element data;
	struct ListNode* link;
}listNode;

// 리스트 시작을 나타내는 head 노드를 구조체로 정의
typedef struct LinkedList {
	listNode* head;
	int length;
	int (*comp)(element d1, element d2);				// 정렬 기준을 등록하기 위한 멤버
}linkedList;

linkedList* initList();		// 공백리스트 생성 
int getLength(linkedList* L);							// 리스트에 저장되어 있는 데이터의 수 반환 
void displayList(linkedList* L);						// 리스트의 모든 요소 출력
void clear(linkedList* L);								// 리스트의 전체 메모리 해제 
void setSortRule(linkedList* L, int (*comp)(element d1, element d2));	// 정렬 기준 함수 등록 
void sortInsert(linkedList* L, element x);				// 노드 삽입시 정렬 기준에 따라 삽입
int delete(linkedList* L, listNode* p);					// 노드 삭제 
listNode* search(linkedList* L, element x);				// 검색  

#endif

