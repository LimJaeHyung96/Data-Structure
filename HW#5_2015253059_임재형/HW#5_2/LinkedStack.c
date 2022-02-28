#include <stdio.h>
#include <stdlib.h>
#include "LinkedStack.h"

// 공백스택 생성, create a empty stack
Stack* create() {
	Stack* S = (Stack*)malloc(sizeof(Stack)); //공백스택을 생성해줌
	S->top = NULL; //top 노드는 NULL인 상태
	return S;
}

// 스택이 포화상태인지 확인하는 연산, operations to determine if the stack is full					
int isFull(Stack* S) {
	return 0; //링크드리스트를 이용한 스택은 범위가 무제한
}

// 스택이 공백상태인지 확인하는 연산, operations to determine if the stack is empty			
int isEmpty(Stack* S) {
	return S->top == NULL; //top노드가 NULL이면 초기값이므로 공백상태
}

// 스택의 top에 요소를 추가하는 연산, operation to add elements to the top of a stack			
void push(Stack* S, element x) {
	stackNode* newNode = (stackNode*)malloc(sizeof(stackNode));
	newNode->data = x; //새 노드에 데이터 삽입
	newNode->link = S->top; //새 노드의 링크필드에 현재 탑에 있는 노드의 주소를 삽입
	S->top = newNode; //탑을 새 노드로 바꿈
}

// 스택에서 마지막에 저장된 요소 삭제 및 반환하는 연산, operations that delete and return the last stored element in the stack
element pop(Stack* S) {
	stackNode* temp;
	element e;
	if (isEmpty(S)) { //공백상태인지 검사
		printf("[ERROR] Stack is EMPTY!!\n");
		return ERROR;
	}
	else {
		temp = S->top; //현재 탑을 임시로 저장
		e = temp->data; //탑의 데이터 저장
		S->top = temp->link; //새로운 탑은 현재 탑의 링크필드에 있는 노드
		free(temp); //이전 탑을 삭제
		return e;
	}
}

// 스택에서 마지막에 저장된 요소를 반환하는 연산, operations that return the last stored element in the stack			
element peek(Stack* S) {
	if (isEmpty(S)) { //공백상태인지 확인
		printf("[ERROR] Stack is EMPTY!!\n");
		return ERROR;
	}
	else {
		return S->top->data; //탑의 데이터 반환
	}
}

// 스택의 모든 요소 출력, display all elements in the stack 			
void displayStack(Stack* S) {
	stackNode* p = S->top;
	printf("STACK [ ");
	while(p) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf(" ]\n");
}

// 스택 비우기, empty stack
void clear(Stack* S) {
	while (S->top != NULL) { //top이 NULL이 될 때 까지 노드를 pop
		pop(S);
	}
}				


