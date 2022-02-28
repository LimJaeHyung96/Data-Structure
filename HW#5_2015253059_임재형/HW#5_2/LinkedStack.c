#include <stdio.h>
#include <stdlib.h>
#include "LinkedStack.h"

// ���齺�� ����, create a empty stack
Stack* create() {
	Stack* S = (Stack*)malloc(sizeof(Stack)); //���齺���� ��������
	S->top = NULL; //top ���� NULL�� ����
	return S;
}

// ������ ��ȭ�������� Ȯ���ϴ� ����, operations to determine if the stack is full					
int isFull(Stack* S) {
	return 0; //��ũ�帮��Ʈ�� �̿��� ������ ������ ������
}

// ������ ����������� Ȯ���ϴ� ����, operations to determine if the stack is empty			
int isEmpty(Stack* S) {
	return S->top == NULL; //top��尡 NULL�̸� �ʱⰪ�̹Ƿ� �������
}

// ������ top�� ��Ҹ� �߰��ϴ� ����, operation to add elements to the top of a stack			
void push(Stack* S, element x) {
	stackNode* newNode = (stackNode*)malloc(sizeof(stackNode));
	newNode->data = x; //�� ��忡 ������ ����
	newNode->link = S->top; //�� ����� ��ũ�ʵ忡 ���� ž�� �ִ� ����� �ּҸ� ����
	S->top = newNode; //ž�� �� ���� �ٲ�
}

// ���ÿ��� �������� ����� ��� ���� �� ��ȯ�ϴ� ����, operations that delete and return the last stored element in the stack
element pop(Stack* S) {
	stackNode* temp;
	element e;
	if (isEmpty(S)) { //����������� �˻�
		printf("[ERROR] Stack is EMPTY!!\n");
		return ERROR;
	}
	else {
		temp = S->top; //���� ž�� �ӽ÷� ����
		e = temp->data; //ž�� ������ ����
		S->top = temp->link; //���ο� ž�� ���� ž�� ��ũ�ʵ忡 �ִ� ���
		free(temp); //���� ž�� ����
		return e;
	}
}

// ���ÿ��� �������� ����� ��Ҹ� ��ȯ�ϴ� ����, operations that return the last stored element in the stack			
element peek(Stack* S) {
	if (isEmpty(S)) { //����������� Ȯ��
		printf("[ERROR] Stack is EMPTY!!\n");
		return ERROR;
	}
	else {
		return S->top->data; //ž�� ������ ��ȯ
	}
}

// ������ ��� ��� ���, display all elements in the stack 			
void displayStack(Stack* S) {
	stackNode* p = S->top;
	printf("STACK [ ");
	while(p) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf(" ]\n");
}

// ���� ����, empty stack
void clear(Stack* S) {
	while (S->top != NULL) { //top�� NULL�� �� �� ���� ��带 pop
		pop(S);
	}
}				


