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
	
	if (L->head == NULL) { //���鸮��Ʈ�� ����
		newNode->rlink = NULL;
		newNode->llink = NULL;
		L->head = newNode;
	}
	else if (pre == NULL) { //����Ʈ�� �� ó�� ���� ����
		insertFirst(L, x);
	}
	else { //����Ʈ�� �߰��� �����Ҷ�
		newNode->rlink = pre->rlink;
		pre->rlink = newNode;
		newNode->llink = pre;
		if (newNode->rlink != NULL) //���� �ڸ��� ���� ��尡 ���� ���
			newNode->rlink->llink = newNode; //���� ����� llink�� �ڽ��� ������ ���� ����
	}
	L->length++;
}

void insertFirst(linkedList* L, element x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = x;
	
	newNode->llink = NULL;
	newNode->rlink = L->head; //����������� ��ũ�ʵ� �� ����
	L->head = newNode; //����������� ��ũ�ʵ忡 �� ��� �ּ� �� ����

	L->length++;
}

void insertLast(linkedList* L, element x) {
	listNode *newNode, *temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = x;
	
	temp = L->head;
	while (temp->rlink != NULL) { //������ ��带 ã��
		temp = temp->rlink;
	}

	newNode->rlink = NULL;
	newNode->llink = temp; //������ ����� �ּ� ����
	temp->rlink = newNode; //�������̾��� ��忡 newNode�� �ּҰ� ����

	L->length++;
}

int deleteNode(linkedList* L, listNode* p) {
	if (L->head == NULL) //���鸮��Ʈ�� ���
		return FALSE;

	if (p == NULL) //������ ��尡 ���� ���
		return FALSE;

	if (p->llink == NULL) //ù��° ��尡 �����Ǵ� ���
		L->head = p->rlink;
	else
		p->llink->rlink = p->rlink;

	if (p->rlink != NULL) //������ ��尡 ������ ��尡 �ƴ� ���
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

