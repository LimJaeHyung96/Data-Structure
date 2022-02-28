#include <stdio.h>
#include <stdlib.h>
#include "ListGraph.h"
#include "LinkedStack.h"
#include "LinkedQueue.h"

// ���� �׷����� �����ϴ� ����, operations to generate a empty graph
Graph* createGraph(int type) {
	int i;
	Graph* G = (Graph*)malloc(sizeof(Graph));	
	G->n = 0;
	G->type = type;
	for(i=0; i<MAX_SIZE; i++) {
		G->adjList_H[i] = NULL;
		G->visited[i] = FALSE;
		G->pred[i] = -1;
	}
	return G;
}

// �׷����� �������� �˻�, check if the graph is empty
int isEmptyGraph(Graph* G) {
	return G->n == 0;
}

// �׷��� G�� ���� v�� ����, insert vertex v into graph G
void insertVertex(Graph* G, int v) {
	if((G->n)+1 > MAX_SIZE) {
		printf("[ERROR] �׷��� ������ ���� �ʰ�\n");	// [ERROR] Exceeding the number of graph vertices
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
		printf("���� %d�� ��������Ʈ", i);	// Adjacent list with vertex %d
		p = G->adjList_H[i];
		while(p) {
			printf(" -> %d ", p->vertex);
			p = p->link;
		}			
		printf("\n");
	}
}

// visited[], pred[] �ʱ�ȭ, initialized visited[], pre[]
void initSearch(Graph* G) {
	int i;
	for(i=0; i<G->n; i++) {
		G->visited[i] = FALSE;
		G->pred[i] = -1;
	}
}

// ���� �켱 Ž�� iterative version, depth first search iterative version
void dfs_iter(Graph* G, int v) {
	graphNode* w;
	Stack* S = create();
	G->visited[v] = TRUE; //�������� v �湮
	push(S, v);
	printf("%d   ", v);
	while (!isEmpty(S)) {
		v = pop(S); 
		w = G->adjList_H[v]; //w�� v�� ������ �����̸鼭 ���� �湮���� ���� ����
		while (w != NULL) { //������ �ƴ϶��
			if (!(G->visited[w->vertex])) { //w�� �湮���� ���� ���̸�
				push(S, v); //v ���� ��
				G->visited[w->vertex] = TRUE; //w�� �湮
				printf("%d   ", w->vertex);
				v = w->vertex;
				w = G->adjList_H[v];
			}
			else
				w = w->link; //w�� �湮�� ���̸� ���� ���� �̵�
		}
	}
}	

// ���� �켱 Ž�� recursive version, depth first search recursive version
void dfs_recur(Graph* G, int v)	{
	graphNode* w;
	G->visited[v] = TRUE; //v�� �湮
	printf("%d   ", v);
	for (w = G->adjList_H[v]; w; w = w->link) { //v�� ���� ���� ���� �湮
		if (!(G->visited[w->vertex])) //�湮���� �ʾ�����
			dfs_recur(G, w->vertex); //��������� �Լ� ȣ��
	}
}

// �ʺ� �켱 Ž��, width first search
void bfs(Graph* G, int v) {
	graphNode* w;
	Queue* Q = createQueue();
	G->visited[v] = TRUE; //v�� �湮
	printf("%d   ", v);
	enqueue(Q, v);
	while (!isEmptyQueue(Q)) {
		v = dequeue(Q);
		for (w = G->adjList_H[v]; w; w = w->link) { //v�� ������ ��� ������ �湮
			if (!(G->visited[w->vertex])) { //�湮���� �ʾ�����
				enqueue(Q, w->vertex);
				G->visited[w->vertex] = TRUE; //�湮���� �ٲ�
				printf("%d   ", w->vertex);
			}
		}
	}
}		
