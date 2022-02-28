#include <stdio.h>
#include <stdlib.h>
#include "SLinkedList3.h"

linkedList* initList() {
	linkedList* L;
	L = (linkedList*)malloc(sizeof(linkedList));
	L->head = NULL;
	L->length = 0;
	L->comp = NULL;
	return L;
}

int getLength(linkedList* L) {
	return L->length; //길이를 반환해서 데이터의 갯수를 셈
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

void setSortRule(linkedList* L, int (*comp)(element d1, element d2)){
	L->comp = comp;		// 리스트의 멤버 comp를 초기화
}

void sortInsert(linkedList* L, element x) {
	listNode* newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = x;

	if (L->head == NULL) { //공백 리스트일때 삽입
		newNode->link = NULL;
		L->head = newNode;
	}
	else {
		listNode* p = L->head;

		int a = p->data;
		int b = p->data;
		while (p->link != NULL) { //마지막 노드 전까지 탐색
			a = p->data; //현재 노드 데이터
			p = p->link;
			b = p->data; //다음 노드 데이터

			if (x < a && x > b) { //요소가 a와 b사이에 있는 값일때 사이에 삽입
				newNode->link = search(L, a)->link;
				search(L, a)->link = newNode;
				break;
			}
		}

		if (L->comp(x, L->head->data) == 0) { //x가 가장 큰 수일때 가장 앞에 삽입
			newNode->link = L->head;
			L->head = newNode;
		}
		else if (L->comp(b, x) == 0) { //x가 가장 작은 수 일때 가장 뒤에 삽입
			newNode->link = NULL;
			search(L, b)->link = newNode;
		}
	}

	L->length++;
}

int delete(linkedList* L, listNode* p) {
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




