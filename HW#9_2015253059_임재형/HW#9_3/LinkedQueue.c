#include <stdio.h>
#include <stdlib.h>
#include "LinkedQueue.h"

// 공백큐 생성, create s empty queue
Queue* createQueue() {
	Queue* Q = (Queue*)malloc(sizeof(Queue));
	Q->front = NULL;
	Q->rear = NULL;
	return Q;
}

// 큐가 공백상태인지 확인하는 연산, operations to determine if a queue is empty	
int isEmptyQueue(Queue* Q) {
	return Q->front == NULL; //큐가 비어있으면 1을 반환
}	

// 큐의 rear에 요소를 추가하는 연산, operations that add elements to the rear of a queue
void enqueue(Queue* Q, element x) {
	queueNode* newNode = (queueNode*)malloc(sizeof(queueNode));
	newNode->data = x; //새 노드 생성
	newNode->link = NULL;
	if (isEmptyQueue(Q)) //큐가 비어있을경우 프론트
		Q->front = newNode;
	else
		Q->rear->link = newNode; //그 외엔 노드 연결
	Q->rear = newNode; //rear에 새 노드 저장
}	

// 큐에서 가장 먼저 저장된 요소 삭제 및 반환하는 연산, operations that delete and return the first stored element in a queue
element dequeue(Queue* Q) {
	queueNode* temp;
	element e;

	if (isEmptyQueue(Q))
		return ERROR;
	else {
		temp = Q->front;
		e = temp->data;
		Q->front = temp->link; //가장 먼저 저장된 요소를 삭제하기 위해 그 다음 노드를 프론트로 저장
		free(temp);
		if (Q->front == NULL) //큐에 하나밖에 없을경우 front = rear이고 front가 삭제되므로 rear도 NULL
			Q->rear = NULL;
		return e;
	}
}

// 큐 비우기, empth queue		
void clearQueue(Queue* Q) {
	queueNode* p;
	while(Q->front) {
		p = Q->front;
		Q->front = Q->front->link;
		free(p);
		p = NULL;
	}
}			

