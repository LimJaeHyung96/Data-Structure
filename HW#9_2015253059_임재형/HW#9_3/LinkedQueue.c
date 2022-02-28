#include <stdio.h>
#include <stdlib.h>
#include "LinkedQueue.h"

// ����ť ����, create s empty queue
Queue* createQueue() {
	Queue* Q = (Queue*)malloc(sizeof(Queue));
	Q->front = NULL;
	Q->rear = NULL;
	return Q;
}

// ť�� ����������� Ȯ���ϴ� ����, operations to determine if a queue is empty	
int isEmptyQueue(Queue* Q) {
	return Q->front == NULL; //ť�� ��������� 1�� ��ȯ
}	

// ť�� rear�� ��Ҹ� �߰��ϴ� ����, operations that add elements to the rear of a queue
void enqueue(Queue* Q, element x) {
	queueNode* newNode = (queueNode*)malloc(sizeof(queueNode));
	newNode->data = x; //�� ��� ����
	newNode->link = NULL;
	if (isEmptyQueue(Q)) //ť�� ���������� ����Ʈ
		Q->front = newNode;
	else
		Q->rear->link = newNode; //�� �ܿ� ��� ����
	Q->rear = newNode; //rear�� �� ��� ����
}	

// ť���� ���� ���� ����� ��� ���� �� ��ȯ�ϴ� ����, operations that delete and return the first stored element in a queue
element dequeue(Queue* Q) {
	queueNode* temp;
	element e;

	if (isEmptyQueue(Q))
		return ERROR;
	else {
		temp = Q->front;
		e = temp->data;
		Q->front = temp->link; //���� ���� ����� ��Ҹ� �����ϱ� ���� �� ���� ��带 ����Ʈ�� ����
		free(temp);
		if (Q->front == NULL) //ť�� �ϳ��ۿ� ������� front = rear�̰� front�� �����ǹǷ� rear�� NULL
			Q->rear = NULL;
		return e;
	}
}

// ť ����, empth queue		
void clearQueue(Queue* Q) {
	queueNode* p;
	while(Q->front) {
		p = Q->front;
		Q->front = Q->front->link;
		free(p);
		p = NULL;
	}
}			

