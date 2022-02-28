#include <stdio.h>
#include <stdlib.h>
#include "ListGraph.h"

// ���� �׷����� �����ϴ� ����, operations to generate a empty graph
Graph* createGraph(int type) {
	int i;
	Graph* G = (Graph*)malloc(sizeof(Graph));	
	G->n = 0;
	G->type = type;
	for(i=0; i<MAX_SIZE; i++) {
		G->adjList_H[i] = NULL;
	}
	return G;
}

// �׷����� �������� �˻�, check if the graph is empth
int isEmpty(Graph* G) {
	return G->n == 0;
}

// �׷��� G�� ���� v�� ����, insert vertex v into graph G
void insertVertex(Graph* G, int v) {
	if((G->n)+1 > MAX_SIZE) {
		printf("[ERROR] �׷��� ������ ���� �ʰ�\n");	// [ERROR] Graph vertex exceeded
		return;
	}
	G->n++;
}

// �׷��� G�� ����(u, v)�� ����, insert a edge(u, v) into graph G
void insertEdge(Graph* G, int u, int v) {
	graphNode* p = (graphNode*)malloc(sizeof(graphNode));
	graphNode* newNode1 = (graphNode*)malloc(sizeof(graphNode));
	graphNode* newNode2 = (graphNode*)malloc(sizeof(graphNode));
	
	p = G->adjList_H[u];
	while (p) {
		if (p->vertex == v)
			return;
		else
			p = p->link;
	}

	newNode1->vertex = v; //��忡 ������ ����
	newNode1->link = G->adjList_H[u]; //��ũ�� ��� ������ ����
	G->adjList_H[u] = newNode1; //��������Ϳ� ����� ����

	if (G->type == UNDIRECT) { //�������Ͻ� (v,u)�� ����
		newNode2->vertex = u;
		newNode2->link = G->adjList_H[v];
		G->adjList_H[v] = newNode2;
	}
	return;
}

// �׷��� G�� ���� v�� �����ϰ� ����� ��� ���� ����, delete vertex v to graph G and delete all connected edges
void deleteVertex(Graph* G, int v) {
	graphNode* cur;
	graphNode* pre;
	graphNode* temp;
		  
	for (int i = 0; i < G->n && i != v; i++) { //��� ������ ���� ����Ʈ���� v�� ������ ����
		pre = G->adjList_H[i]; //v�� ��� ��� ����
		cur = pre->link; //����忡 ����Ǿ� �ִ� ��� ����
		while (cur != NULL) {
			temp = cur->link;
			if (cur->vertex == v) { //���� ����� ������ �ʵ尡 v�� ������
				pre->link = cur->link; //�� ���� �� ��带 ����
				free(cur);
				break;
			}
			pre = cur;
			cur = temp;
		}
	}

	pre = G->adjList_H[v]; //������� �ϴ� ������ ���������
	cur = G->adjList_H[v]->link;
	while (cur != NULL) { //���� ����
		temp = cur->link;
		free(cur);
		cur = temp;
	}
	G->adjList_H[v] = NULL; //��������Ϳ� NULL����
}

// �׷��� G�� ���� (u, v)�� ����, delete the edge(u, v) to graph G
void deleteEdge(Graph* G, int u, int v) {
	graphNode* p = (graphNode*)malloc(sizeof(graphNode));
	graphNode* pre = (graphNode*)malloc(sizeof(graphNode));

	p = G->adjList_H[u]; //(u,v)�� �ش��ϴ� ���� ����
	while (p != NULL) { //�´� ��� Ž��
		if (p->vertex == v)
			break;
		else
			p = p->link;
	}

	pre = G->adjList_H[u];
	while (pre->link != p) { //����� ���� ��� Ž��
		pre = pre->link;
		if (pre == NULL)
			return;
	}
	pre->link = p->link; //�� ���� �� ��� ����

	if (G->type == UNDIRECT) { //�������Ͻ� ���� ��� ����
		p = G->adjList_H[v]; //(u,v)�� �ش��ϴ� ���� ����
		while (p != NULL) { //�´� ��� Ž��
			if (p->vertex == u)
				break;
			else
				p = p->link;
		}

		pre = G->adjList_H[v];
		while (pre->link != p) { //����� ���� ��� Ž��
			pre = pre->link;
			if (pre == NULL)
				return;
		}
		pre->link = p->link; //�� ���� �� ��� ����
	}
	free(p);
	return;
}

// �׷��� G�� ���ҽ� ����, unresource graph G
void destroyGraph(Graph* G) {
	int i;
	for(i=0; i<G->n; i++) {
		if(G->adjList_H[i] != NULL)
			free(G->adjList_H[i]);
	}
	free(G);
}

// �׷��� G�� ���� ����Ʈ ���� ���, display adjacent list information for graph G
void displayGraph(Graph* G) {
	int i;
	graphNode* p;
	for(i=0; i<G->n; i++) {
		printf("���� %d�� ��������Ʈ", i);	// Adjacent list of vertex %d
		p = G->adjList_H[i];
		while(p) {
			printf(" -> %d ", p->vertex);
			p = p->link;
		}			
		printf("\n");
	}
}

