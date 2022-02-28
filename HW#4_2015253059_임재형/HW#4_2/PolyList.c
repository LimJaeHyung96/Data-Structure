#include <stdio.h>
#include <stdlib.h>
#include "PolyList.h"

polyList* initList() {
	polyList* PL = (polyList*)malloc(sizeof(polyList));
	PL->head = NULL;
	PL->last = NULL;
	return PL;
}

void appendTerm(polyList* PL, float coef, int exp) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->coef = coef;
	newNode->exp = exp;
	newNode->link = NULL;
	
	if (PL->head == NULL) { //���� ����Ʈ�϶�
		PL->head = newNode;
	}
	else {
		PL->last->link = newNode; //last����� �ڿ� newNode�� ����
	}
	PL->last = newNode; //newNode�� ���ο� last��尡 ��
}

polyList* subPoly(polyList* A, polyList* B) {
	polyList* C = initList();
	Node* polyA = A->head;
	Node* polyB = B->head;
	int sub = 0;
	
	while (polyA != NULL && polyB != NULL) {
		if (polyA->exp == polyB->exp) { //������ ���� ��
			sub = polyA->coef - polyB->coef;
			if (sub != 0) //��갪�� 0�� �ƴϾ�� ���� �߰�
				appendTerm(C, sub, polyA->exp);
			polyA = polyA->link; //�� �� ��� ���� ���� �˻�
			polyB = polyB->link;
		}
		else if (polyA->exp > polyB->exp) { //A�� ������ �� Ŭ ��
			appendTerm(C, polyA->coef, polyA->exp); //�ٷ� C�� ����
			polyA = polyA->link;
		}
		else { //B�� ������ �� Ŭ��
			appendTerm(C, -polyB->coef, polyB->exp); //�ٷ� C�� ����
			polyB = polyB->link;
		}
	}
	
	while (polyA != NULL) { //A�� �� ����� ��� ���� �κ� ���� ����
		appendTerm(C, polyA->coef, polyA->exp);
		polyA = polyA->link;
	}
	while (polyB != NULL) { //B�� �� ����� ��� ���� �κ� ���� ����
		appendTerm(C, -polyB->coef, polyB->exp);
		polyB = polyB->link;
	}
	
	
	return C;
}

void displayPoly(polyList* PL) {
	Node* p = PL->head;
	for (; p; p = p->link) {
		if (p->coef > 0)
			printf("\t+");
		else
			printf("\t");
		printf("%.0fx^%d", p->coef, p->exp);
	}
	printf("\n");
}
