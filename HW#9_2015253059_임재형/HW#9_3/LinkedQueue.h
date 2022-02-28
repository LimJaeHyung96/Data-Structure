#ifndef __LINKED_QUEUE_H__
#define __CIRCULAR_QUEUE_H__

#define ERROR 123456789
#define TRUE 1
#define FALSE 0
 
typedef int element;

// Queue의 노드 구조를 구조체로 정의, define the node structure in queue as a structure
typedef struct QueueNode {
	element data;
	struct QueueNode* link;
}queueNode;

// Queue의 front, rear를 표현할 구조체, the structure that whill represent the front, rear of the queue
typedef struct LinkedQueue {
	queueNode *front, *rear;
}Queue; 

Queue* createQueue();				// 공백큐 생성, create s empty queue
int isEmptyQueue(Queue* Q);			// 큐가 공백상태인지 확인하는 연산, operations to determine if a queue is empty
void enqueue(Queue* Q, element x);	// 큐의 rear에 요소를 추가하는 연산, operations that add elements to the rear of a queue
element dequeue(Queue* Q);			// 큐에서 가장 먼저 저장된 요소 삭제 및 반환하는 연산, operations that delete and return the first stored element in a queue
void clearQueue(Queue* Q);			// 큐 비우기, empth queue

#endif



