#include <stdio.h>
#include <stdlib.h>
#include "LinkedStack.h"

// ���齺�� ����, create a empty stack
Stack* create() {
	Stack* S = (Stack*)malloc(sizeof(Stack));
	S->top = NULL;
	return S;
}


// ������ ����������� Ȯ���ϴ� ����, operations to determine if the stack is empty		
int isEmpty(Stack* S) {
	return S->top == NULL; //top��尡 NULL�̸� �ʱⰪ�̹Ƿ� �������
}

// ������ top�� ��Ҹ� �߰��ϴ� ����, operations that add elements to top of stack		
void push(Stack* S, element x) {
	stackNode* newNode = (stackNode*)malloc(sizeof(stackNode));
	newNode->data = x; //�� ��忡 ������ ����
	newNode->link = S->top; //�� ����� ��ũ�ʵ忡 ���� ž�� �ִ� ����� �ּҸ� ����
	S->top = newNode; //ž�� �� ���� �ٲ�
}

// ���ÿ��� �������� ����� ��� ���� �� ��ȯ�ϴ� ����, operations to delete and return the last stored element on the stack
element pop(Stack* S) {
	stackNode* temp;
	element e;
	if (isEmpty(S))  //����������� �˻�
		return ERROR;
	else {
		temp = S->top; //���� ž�� �ӽ÷� ����
		e = temp->data; //ž�� ������ ����
		S->top = temp->link; //���ο� ž�� ���� ž�� ��ũ�ʵ忡 �ִ� ���
		free(temp); //���� ž�� ����
		return e;
	}
}

// ���� ����, empty stack
void clear(Stack* S) {
	stackNode* p;
	while(S->top) {
		p = S->top;
		S->top = S->top->link;
		free(p);
		p = NULL;
	}
}				


