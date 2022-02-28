#include <stdio.h>
#include <stdlib.h>
#include "ArrayStack.h"

// ���齺�� ����, create a empty stack
Stack* create() {
	Stack* S = (Stack*)malloc(sizeof(Stack)); //���� ����
	S->top = -1; //top�� �ʱⰪ�� -1
	return S;
}

// ������ ��ȭ�������� Ȯ���ϴ� ����, operations to determine if the stack is full
int isFull(Stack* S) {
	return S->top == MAX_SIZE - 1; //0~99���� ���� 100���̹Ƿ� top-1�� MAX_SIZE���� ��ȭ
}

// ������ ����������� Ȯ���ϴ� ����, operations to determine if the stack is empty			
int isEmpty(Stack* S) {
	return S->top == -1; //top�� -1�̸� �ʱⰪ�̹Ƿ� �������
}

// ������ top�� ��Ҹ� �߰��ϴ� ����, operations to add elements to the top of a stack
void push(Stack* S, element x) {
	if (isFull(S)) { //��ȭ�������� �˻�
		printf("[ERROR] Stack is Full!\n");
		return ERROR;
	}
	else {
		S->stack[++(S->top)] = x; //top + 1 �� ��ġ�� x���� ����
	}
}

// ���ÿ��� �������� ����� ��� ���� �� ��ȯ�ϴ� ����, operations that delete and return the last stored element in the stack	
element pop(Stack* S) {
	if (isEmpty(S)) { //����������� Ȯ��
		return ERROR;
	}
	else {
		element e = S->stack[(S->top)--]; //top�� �ִ� ���� ��ȯ�ϰ� top�� 1 ����
		return e;
	}
}

// ���ÿ��� �������� ����� ��Ҹ� ��ȯ�ϴ� ����, operations that return the last stored element in the stack
element peek(Stack* S) {
	if (isEmpty(S)) { //����������� Ȯ��
		return ERROR;
	}
	else {
		return S->stack[S->top]; //top�� �ִ� �� ��ȯ
	}
}

// ������ ��� ��� ���, display all elements in the stack
void displayStack(Stack* S) {
	int i;
	printf("STACK [ "); 
	for(i=0; i<=S->top; i++)
		printf("%d ", S->stack[i]);
	printf(" ]\ttop: %d\n", S->top);
}

// ���� ����, empty stack
void clear(Stack* S) {
	int i;
	for (i = S->top; i >= 0; i--) //top���� 0���� pop�� ��
		pop(S);
	create(); //���ο� S�� �������
}				

