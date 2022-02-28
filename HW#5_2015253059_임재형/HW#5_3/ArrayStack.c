#include <stdio.h>
#include <stdlib.h>
#include "ArrayStack.h"

// 공백스택 생성, create a empty stack
Stack* create() {
	Stack* S = (Stack*)malloc(sizeof(Stack)); //스택 생성
	S->top = -1; //top의 초기값은 -1
	return S;
}

// 스택이 포화상태인지 확인하는 연산, operations to determine if the stack is full
int isFull(Stack* S) {
	return S->top == MAX_SIZE - 1; //0~99까지 차면 100개이므로 top-1이 MAX_SIZE여야 포화
}

// 스택이 공백상태인지 확인하는 연산, operations to determine if the stack is empty			
int isEmpty(Stack* S) {
	return S->top == -1; //top이 -1이면 초기값이므로 공백상태
}

// 스택의 top에 요소를 추가하는 연산, operations to add elements to the top of a stack
void push(Stack* S, element x) {
	if (isFull(S)) { //포화상태인지 검사
		printf("[ERROR] Stack is Full!\n");
		return ERROR;
	}
	else {
		S->stack[++(S->top)] = x; //top + 1 한 위치에 x값을 넣음
	}
}

// 스택에서 마지막에 저장된 요소 삭제 및 반환하는 연산, operations that delete and return the last stored element in the stack	
element pop(Stack* S) {
	if (isEmpty(S)) { //공백상태인지 확인
		return ERROR;
	}
	else {
		element e = S->stack[(S->top)--]; //top에 있는 값을 반환하고 top을 1 줄임
		return e;
	}
}

// 스택에서 마지막에 저장된 요소를 반환하는 연산, operations that return the last stored element in the stack
element peek(Stack* S) {
	if (isEmpty(S)) { //공백상태인지 확인
		return ERROR;
	}
	else {
		return S->stack[S->top]; //top에 있는 값 반환
	}
}

// 스택의 모든 요소 출력, display all elements in the stack
void displayStack(Stack* S) {
	int i;
	printf("STACK [ "); 
	for(i=0; i<=S->top; i++)
		printf("%d ", S->stack[i]);
	printf(" ]\ttop: %d\n", S->top);
}

// 스택 비우기, empty stack
void clear(Stack* S) {
	int i;
	for (i = S->top; i >= 0; i--) //top부터 0까지 pop을 함
		pop(S);
	create(); //새로운 S를 만들어줌
}				

