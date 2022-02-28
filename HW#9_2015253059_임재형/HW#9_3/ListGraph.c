#include <stdio.h>
#include <stdlib.h>
#include "ListGraph.h"
#include "LinkedStack.h"
#include "LinkedQueue.h"

// 공백 그래프를 생성하는 연산, operations to generate a empty graph
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

// 그래프가 공백인지 검사, check if the graph is empty
int isEmptyGraph(Graph* G) {
	return G->n == 0;
}

// 그래프 G에 정점 v를 삽입, insert vertex v into graph G
void insertVertex(Graph* G, int v) {
	if((G->n)+1 > MAX_SIZE) {
		printf("[ERROR] 그래프 정점의 개수 초과\n");	// [ERROR] Exceeding the number of graph vertices
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
		printf("정점 %d의 인접리스트", i);	// Adjacent list with vertex %d
		p = G->adjList_H[i];
		while(p) {
			printf(" -> %d ", p->vertex);
			p = p->link;
		}			
		printf("\n");
	}
}

// visited[], pred[] 초기화, initialized visited[], pre[]
void initSearch(Graph* G) {
	int i;
	for(i=0; i<G->n; i++) {
		G->visited[i] = FALSE;
		G->pred[i] = -1;
	}
}

// 깊이 우선 탐색 iterative version, depth first search iterative version
void dfs_iter(Graph* G, int v) {
	graphNode* w;
	Stack* S = create();
	G->visited[v] = TRUE; //시작정점 v 방문
	push(S, v);
	printf("%d   ", v);
	while (!isEmpty(S)) {
		v = pop(S); 
		w = G->adjList_H[v]; //w는 v에 인접한 정점이면서 아직 방문하지 않은 정점
		while (w != NULL) { //공백이 아니라면
			if (!(G->visited[w->vertex])) { //w가 방문되지 않은 곳이면
				push(S, v); //v 저장 후
				G->visited[w->vertex] = TRUE; //w를 방문
				printf("%d   ", w->vertex);
				v = w->vertex;
				w = G->adjList_H[v];
			}
			else
				w = w->link; //w가 방문한 곳이면 다음 노드로 이동
		}
	}
}	

// 깊이 우선 탐색 recursive version, depth first search recursive version
void dfs_recur(Graph* G, int v)	{
	graphNode* w;
	G->visited[v] = TRUE; //v를 방문
	printf("%d   ", v);
	for (w = G->adjList_H[v]; w; w = w->link) { //v에 인접 정점 전부 방문
		if (!(G->visited[w->vertex])) //방문되지 않았으면
			dfs_recur(G, w->vertex); //재귀적으로 함수 호출
	}
}

// 너비 우선 탐색, width first search
void bfs(Graph* G, int v) {
	graphNode* w;
	Queue* Q = createQueue();
	G->visited[v] = TRUE; //v를 방문
	printf("%d   ", v);
	enqueue(Q, v);
	while (!isEmptyQueue(Q)) {
		v = dequeue(Q);
		for (w = G->adjList_H[v]; w; w = w->link) { //v에 인접한 모든 정점을 방문
			if (!(G->visited[w->vertex])) { //방문하지 않았으면
				enqueue(Q, w->vertex);
				G->visited[w->vertex] = TRUE; //방문으로 바꿈
				printf("%d   ", w->vertex);
			}
		}
	}
}		
