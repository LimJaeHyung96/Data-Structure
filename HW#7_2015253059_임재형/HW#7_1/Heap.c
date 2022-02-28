#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"

// 공백 힙 생성, create a empty heap
Heap* createHeap() {
	Heap* h = (Heap*)malloc(sizeof(Heap));
	h->numOfData = 0;
	return h;
}	

// 힙이 공백인지 검사, check if heap is empty			
int isEmpty(Heap* h) {
	return h->numOfData == 0 ? TRUE : FALSE;
}	

// 힙의 적당한 위치에 원소 x 삽입, insert element x in appropriate position on heap
void insertHeap(Heap* h, HData x) {
	if(h->numOfData == MAX_SIZE) {
		printf("ERROR: Heap is FULL!!\n");
		return;
	}

	int idx = (h->numOfData) + 1; //idx는 마지막 노드
	while (idx != 1) { //루트노드는 위에 노드가 없으므로 비교 불가
		if (x < h->heap[getParentIdx(idx)]) { //현재 원소가 자신의 부모노드보다 작을시
			h->heap[idx] = h->heap[getParentIdx(idx)]; //현재 가르키는 노드에 부모노드의 값을 넣는다
			idx = getParentIdx(idx); //idx는 부모의 노드 번호를 가진다
		}
		else //현재 원소가 자신의 부모노드보다 작을시
			break; //나가서
	}

	h->heap[idx] = x; //현재의 노드에 x값을 넣고
	h->numOfData++; //힙의 크기를 1 늘린다
	return;
}

// 힙에서 키 값이 가장 작은 원소 삭제하고 반환, delete the element with the smallest key value from the heap and return it
HData deleteHeap(Heap* h) {
	if(isEmpty(h)) {
		printf("ERROR: Heap is EMPTY!!\n");
		return 0;
	}
	
	HData item = h->heap[1];
	HData lastVal = h->heap[h->numOfData];
	int parentIdx = 1;
	int childIdx = 2;
	
	while (childIdx <= h->numOfData) { //비교하는 노드의 번호가 현재 데이터 갯수를 넘어갈 수 없음
		if (childIdx < h->numOfData && h->heap[childIdx] > h->heap[childIdx + 1])
			childIdx = getRChildIdx(parentIdx); //자식 노드 둘 중 작은 쪽을 선택한다
		if (lastVal <= h->heap[childIdx]) //마지막 노드 값이 더 작으면 바로 나가서 부모노드를 차지한다
			break;
		else {
			h->heap[parentIdx] = h->heap[childIdx]; //부모노드에 자식노드의 값을 넣고
			parentIdx = childIdx; //자식노드와 그 노드의 아래있는 자식들과 비교하기 위해 parentIdx값을 바꾼다
			childIdx = getLChildIdx(childIdx); //childIdx의 값은 자식노드를 가리킬수 있도록 한다
		}
	}

	h->heap[parentIdx] = lastVal;
	h->numOfData--;
	return item;
}			

// 부모 노드의 인덱스 값 반환, returns the index value of the parent node
int getParentIdx(int idx) {
	return idx/2;
}	

// 왼쪽 자식 노드의 인덱스 값 반환, returns index value of left child node
int getLChildIdx(int idx) {
	return idx*2;
}

// 오른쪽 자식 노드의 인덱스 값 반환, returns index value of right chlid node		
int getRChildIdx(int idx) {
	return idx*2+1;
}

void displayHeap(Heap* h) {
	int i;
	for(i=1; i<=h->numOfData; i++)
		printf("%d %d\n", i, h->heap[i]);
	printf("\n");
}	
