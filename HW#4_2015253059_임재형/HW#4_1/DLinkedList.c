#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

linkedList* initList() {
	linkedList* L;
	L = (linkedList*)malloc(sizeof(linkedList));
	L->head = NULL;
	L->length = 0;
	return L;
}

int getLength(linkedList* L) {
	return L->length;
}


void insert(linkedList* L, listNode* pre, element x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = x;
	
	if (L->head == NULL) { //공백리스트에 삽입
		newNode->rlink = NULL;
		newNode->llink = NULL;
		L->head = newNode;
	}
	else if (pre == NULL) { //리스트의 맨 처음 노드로 삽입
		insertFirst(L, x);
	}
	else { //리스트의 중간에 삽입할때
		newNode->rlink = pre->rlink;
		pre->rlink = newNode;
		newNode->llink = pre;
		if (newNode->rlink != NULL) //삽입 자리에 다음 노드가 있을 경우
			newNode->rlink->llink = newNode; //다음 노드의 llink에 자신의 포인터 값을 넣음
	}
	L->length++;
}

void insertFirst(linkedList* L, element x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = x;
	
	newNode->llink = NULL;
	newNode->rlink = L->head; //헤드포인터의 링크필드 값 복사
	L->head = newNode; //헤드포인터의 링크필드에 새 노드 주소 값 삽입

	L->length++;
}

void insertLast(linkedList* L, element x) {
	listNode *newNode, *temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = x;
	
	temp = L->head;
	while (temp->rlink != NULL) { //마지막 노드를 찾음
		temp = temp->rlink;
	}

	newNode->rlink = NULL;
	newNode->llink = temp; //마지막 노드이 주소 삽입
	temp->rlink = newNode; //마지막이었던 노드에 newNode의 주소값 삽입

	L->length++;
}

int deleteNode(linkedList* L, listNode* p) {
	if (L->head == NULL) //공백리스트인 경우
		return FALSE;

	if (p == NULL) //삭제할 노드가 없는 경우
		return FALSE;

	if (p->llink == NULL) //첫번째 노드가 삭제되는 경우
		L->head = p->rlink;
	else
		p->llink->rlink = p->rlink;

	if (p->rlink != NULL) //삭제할 노드가 마지막 노드가 아닐 경우
		p->rlink->llink = p->llink;

	free(p);
	L->length--;
	return TRUE;
}

listNode* search(linkedList* L, element x) {
	listNode* temp = L->head;
	
	while(temp != NULL) {
		if(temp->data == x)
			return temp;
		else
			temp = temp->rlink;
	}
	return temp;
}

void displayList(linkedList* L) {
	listNode* p;
	printf("L=(");
	p = L->head;
	while(p != NULL) {
		printf("%d", p->data);
		p = p->rlink;
		if(p != NULL) printf(", ");
	}
	printf(")\n");
}

void clear(linkedList* L) {
	listNode* p;
	while(L->head != NULL) {
		p = L->head;
		L->head = L->head->rlink;
		free(p);
		p = NULL;
	}
}

