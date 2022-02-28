#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"

// ���� �� ����, create a empty heap
Heap* createHeap() {
	Heap* h = (Heap*)malloc(sizeof(Heap));
	h->numOfData = 0;
	return h;
}	

// ���� �������� �˻�, check if heap is empty			
int isEmpty(Heap* h) {
	return h->numOfData == 0 ? TRUE : FALSE;
}	

// ���� ������ ��ġ�� ���� x ����, insert element x in appropriate position on heap
void insertHeap(Heap* h, HData x) {
	if(h->numOfData == MAX_SIZE) {
		printf("ERROR: Heap is FULL!!\n");
		return;
	}

	int idx = (h->numOfData) + 1; //idx�� ������ ���
	while (idx != 1) { //��Ʈ���� ���� ��尡 �����Ƿ� �� �Ұ�
		if (x < h->heap[getParentIdx(idx)]) { //���� ���Ұ� �ڽ��� �θ��庸�� ������
			h->heap[idx] = h->heap[getParentIdx(idx)]; //���� ����Ű�� ��忡 �θ����� ���� �ִ´�
			idx = getParentIdx(idx); //idx�� �θ��� ��� ��ȣ�� ������
		}
		else //���� ���Ұ� �ڽ��� �θ��庸�� ������
			break; //������
	}

	h->heap[idx] = x; //������ ��忡 x���� �ְ�
	h->numOfData++; //���� ũ�⸦ 1 �ø���
	return;
}

// ������ Ű ���� ���� ���� ���� �����ϰ� ��ȯ, delete the element with the smallest key value from the heap and return it
HData deleteHeap(Heap* h) {
	if(isEmpty(h)) {
		printf("ERROR: Heap is EMPTY!!\n");
		return 0;
	}
	
	HData item = h->heap[1];
	HData lastVal = h->heap[h->numOfData];
	int parentIdx = 1;
	int childIdx = 2;
	
	while (childIdx <= h->numOfData) { //���ϴ� ����� ��ȣ�� ���� ������ ������ �Ѿ �� ����
		if (childIdx < h->numOfData && h->heap[childIdx] > h->heap[childIdx + 1])
			childIdx = getRChildIdx(parentIdx); //�ڽ� ��� �� �� ���� ���� �����Ѵ�
		if (lastVal <= h->heap[childIdx]) //������ ��� ���� �� ������ �ٷ� ������ �θ��带 �����Ѵ�
			break;
		else {
			h->heap[parentIdx] = h->heap[childIdx]; //�θ��忡 �ڽĳ���� ���� �ְ�
			parentIdx = childIdx; //�ڽĳ��� �� ����� �Ʒ��ִ� �ڽĵ�� ���ϱ� ���� parentIdx���� �ٲ۴�
			childIdx = getLChildIdx(childIdx); //childIdx�� ���� �ڽĳ�带 ����ų�� �ֵ��� �Ѵ�
		}
	}

	h->heap[parentIdx] = lastVal;
	h->numOfData--;
	return item;
}			

// �θ� ����� �ε��� �� ��ȯ, returns the index value of the parent node
int getParentIdx(int idx) {
	return idx/2;
}	

// ���� �ڽ� ����� �ε��� �� ��ȯ, returns index value of left child node
int getLChildIdx(int idx) {
	return idx*2;
}

// ������ �ڽ� ����� �ε��� �� ��ȯ, returns index value of right chlid node		
int getRChildIdx(int idx) {
	return idx*2+1;
}

void displayHeap(Heap* h) {
	int i;
	for(i=1; i<=h->numOfData; i++)
		printf("%d %d\n", i, h->heap[i]);
	printf("\n");
}	
