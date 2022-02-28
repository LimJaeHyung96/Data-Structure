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
	
	if (PL->head == NULL) { //공백 리스트일때
		PL->head = newNode;
	}
	else {
		PL->last->link = newNode; //last노드의 뒤에 newNode를 삽입
	}
	PL->last = newNode; //newNode가 새로운 last노드가 됨
}

polyList* subPoly(polyList* A, polyList* B) {
	polyList* C = initList();
	Node* polyA = A->head;
	Node* polyB = B->head;
	int sub = 0;
	
	while (polyA != NULL && polyB != NULL) {
		if (polyA->exp == polyB->exp) { //차수가 같을 때
			sub = polyA->coef - polyB->coef;
			if (sub != 0) //계산값이 0이 아니어야 항을 추가
				appendTerm(C, sub, polyA->exp);
			polyA = polyA->link; //두 식 모두 다음 항을 검사
			polyB = polyB->link;
		}
		else if (polyA->exp > polyB->exp) { //A의 차수가 더 클 때
			appendTerm(C, polyA->coef, polyA->exp); //바로 C에 대입
			polyA = polyA->link;
		}
		else { //B의 차수가 더 클때
			appendTerm(C, -polyB->coef, polyB->exp); //바로 C에 대입
			polyB = polyB->link;
		}
	}
	
	while (polyA != NULL) { //A가 더 길었을 경우 남은 부분 전부 대입
		appendTerm(C, polyA->coef, polyA->exp);
		polyA = polyA->link;
	}
	while (polyB != NULL) { //B가 더 길었을 경우 남은 부분 전부 대입
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
