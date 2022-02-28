#include <stdio.h>
#include <stdlib.h>
#include "SLinkedList.h"

linkedList* initList() {
	linkedList* L;
	L = (linkedList*)malloc(sizeof(linkedList));
	L->head = NULL;
	L->length = 0;
	return L;
}

int getLength(linkedList* L) {
	return L->length; //길이를 반환해서 데이터의 갯수를 셈
}

void insert(linkedList* L, listNode* pre, element x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode)); //새 노드 생성
	newNode->data = x;

	if (L->head == NULL) { //공백리스트에 삽입
		newNode->link = NULL;
		L->head = newNode;
	}
	else if (pre == NULL) { //리스트의 맨 처음 노드로 삽입할 때
		newNode->link = L->head;
		L->head = newNode;
	}
	else { //리스트의 중간에 삽입할 때
		newNode->link = pre->link;
		pre->link = newNode;
	}
	L->length++; //길이 증가
}

void insertFirst(linkedList* L, element x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode)); //새 노드 생성
	newNode->data = x; //새 노드에 데이터 삽입
	newNode->link = L->head; //헤드 포인터의 링크를 새 노드의 링크에 복사
	L->head = newNode; //해드 포인터에 새 노드의 주소값을 넣음
	L->length++; //길이 증가
}

void insertLast(linkedList* L, element x) {
	listNode *newNode, *temp;
	newNode = (listNode*)malloc(sizeof(listNode)); //새 노드 생성
	newNode->data = x; //새 노드에 데이터 삽입
	newNode->link = NULL; //마지막 노드가 될 예정이므로 링크필드는 NULL

	if (L->head == NULL) //공백리스트에 삽입할 때
		L->head = newNode;
	else {
		temp = L->head;
		while (temp->link != NULL) //마지막 노드 찾기(마지막 노드의 링크 필드는 NULL)
			temp = temp->link;
		temp->link = newNode; //찾은 마지막 노드의 링크필드에 새 노드의 주소를 삽입
	}
	L->length++; //길이 증가
}

int deleteNode(linkedList* L, listNode* p) {
	listNode* pre;

	if (L->head == NULL) //공백 리스트일 경우 삭제 실패
		return FALSE;
	if (p == NULL) //삭제하려는 노드가 없는 경우
		return FALSE;
	pre = L->head;
	while (pre->link != p) { //삭제할 노드의 이전 노드를 찾음
		pre = pre->link;
		if (pre == NULL) //삭제할 노드가 없는 경우
			return FALSE;
	}
	pre->link = p->link; //앞 노드와 뒷 노드를 연결해줌
	free(p);

	L->length--; //길이 감소
	return TRUE;
}

int deleteData(linkedList* L, element x) {
	listNode* pre;
	listNode* p = search(L, x); //데이터 필드가 x인 노드를 찾음

	//이후는 deleteNode와 똑같은 동작
	if (L->head == NULL) 
		return FALSE;
	if (p == NULL)
		return FALSE;
	pre = L->head;
	while (pre->link != p) {
		pre = pre->link;
		if (pre == NULL)
			return FALSE;
	}
	pre->link = p->link;
	free(p);

	L->length--;
	return TRUE;
}


listNode* search(linkedList* L, element x) {
	listNode* temp = L->head;
	
	while (temp != NULL) { //마지막 노드까지 검색
		if (temp->data == x) //일치하면 그 노드 반환
			return temp;
		else //일치 하지 않으면 다음 노트 탐색
			temp = temp->link;
	}

	return temp;
}

void displayList(linkedList* L) {
	listNode* p;
	printf("L=(");
	p = L->head;
	while(p != NULL) {
		printf("%d", p->data);
		p = p->link;
		if(p != NULL) printf(", ");
	}
	printf(")\n");
}

void clear(linkedList* L) {
	listNode* p;
	while(L->head != NULL) {
		p = L->head;
		L->head = L->head->link;
		free(p);
		p = NULL;
	}
}
