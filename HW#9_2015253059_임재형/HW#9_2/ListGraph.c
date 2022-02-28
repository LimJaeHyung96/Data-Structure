#include <stdio.h>
#include <stdlib.h>
#include "ListGraph.h"

// 공백 그래프를 생성하는 연산, operations to generate a empty graph
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

// 그래프가 공백인지 검사, check if the graph is empth
int isEmpty(Graph* G) {
	return G->n == 0;
}

// 그래프 G에 정점 v를 삽입, insert vertex v into graph G
void insertVertex(Graph* G, int v) {
	if((G->n)+1 > MAX_SIZE) {
		printf("[ERROR] 그래프 정점의 개수 초과\n");	// [ERROR] Graph vertex exceeded
		return;
	}
	G->n++;
}

// 그래프 G에 간선(u, v)를 삽입, insert a edge(u, v) into graph G
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

	newNode1->vertex = v; //노드에 데이터 저장
	newNode1->link = G->adjList_H[u]; //링크에 헤드 포인터 저장
	G->adjList_H[u] = newNode1; //헤드포인터에 새노드 저장

	if (G->type == UNDIRECT) { //무방향일시 (v,u)도 실행
		newNode2->vertex = u;
		newNode2->link = G->adjList_H[v];
		G->adjList_H[v] = newNode2;
	}
	return;
}

// 그래프 G에 정점 v를 삭제하고 연결된 모든 간선 삭제, delete vertex v to graph G and delete all connected edges
void deleteVertex(Graph* G, int v) {
	graphNode* cur;
	graphNode* pre;
	graphNode* temp;
		  
	for (int i = 0; i < G->n && i != v; i++) { //모든 정점의 연결 리스트에서 v의 정보를 삭제
		pre = G->adjList_H[i]; //v의 헤드 노드 저장
		cur = pre->link; //헤드노드에 연결되어 있는 노드 저장
		while (cur != NULL) {
			temp = cur->link;
			if (cur->vertex == v) { //현재 노드의 데이터 필드가 v랑 같으면
				pre->link = cur->link; //앞 노드와 뒷 노드를 연결
				free(cur);
				break;
			}
			pre = cur;
			cur = temp;
		}
	}

	pre = G->adjList_H[v]; //지우고자 하는 정점의 헤드포인터
	cur = G->adjList_H[v]->link;
	while (cur != NULL) { //전부 삭제
		temp = cur->link;
		free(cur);
		cur = temp;
	}
	G->adjList_H[v] = NULL; //헤드포인터에 NULL연결
}

// 그래프 G에 간선 (u, v)를 삭제, delete the edge(u, v) to graph G
void deleteEdge(Graph* G, int u, int v) {
	graphNode* p = (graphNode*)malloc(sizeof(graphNode));
	graphNode* pre = (graphNode*)malloc(sizeof(graphNode));

	p = G->adjList_H[u]; //(u,v)에 해당하는 간선 삭제
	while (p != NULL) { //맞는 노드 탐색
		if (p->vertex == v)
			break;
		else
			p = p->link;
	}

	pre = G->adjList_H[u];
	while (pre->link != p) { //노드의 이전 노드 탐색
		pre = pre->link;
		if (pre == NULL)
			return;
	}
	pre->link = p->link; //앞 노드와 뒷 노드 연결

	if (G->type == UNDIRECT) { //무방향일시 양쪽 모두 삭제
		p = G->adjList_H[v]; //(u,v)에 해당하는 간선 삭제
		while (p != NULL) { //맞는 노드 탐색
			if (p->vertex == u)
				break;
			else
				p = p->link;
		}

		pre = G->adjList_H[v];
		while (pre->link != p) { //노드의 이전 노드 탐색
			pre = pre->link;
			if (pre == NULL)
				return;
		}
		pre->link = p->link; //앞 노드와 뒷 노드 연결
	}
	free(p);
	return;
}

// 그래프 G의 리소스 해제, unresource graph G
void destroyGraph(Graph* G) {
	int i;
	for(i=0; i<G->n; i++) {
		if(G->adjList_H[i] != NULL)
			free(G->adjList_H[i]);
	}
	free(G);
}

// 그래프 G의 인접 리스트 정보 출력, display adjacent list information for graph G
void displayGraph(Graph* G) {
	int i;
	graphNode* p;
	for(i=0; i<G->n; i++) {
		printf("정점 %d의 인접리스트", i);	// Adjacent list of vertex %d
		p = G->adjList_H[i];
		while(p) {
			printf(" -> %d ", p->vertex);
			p = p->link;
		}			
		printf("\n");
	}
}

