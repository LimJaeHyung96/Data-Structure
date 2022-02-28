#ifndef __ARRAY_GRAPH_H__
#define _ARRAY_GRAPH_H__

#define MAX_SIZE 100
#define DIRECT 1
#define UNDIRECT 0

// 그래프를 인접 행렬로 표현하기 위한 구조체 정의, define structures for representing graphs as adjacent matrix
typedef struct GraphType {
	int n;
	int type;	// UNDIRECT: 무방향, DIRECT: 방향 
	int adjMatrix[MAX_SIZE][MAX_SIZE];
} Graph;

Graph* createGraph(int type);	// 공백 그래프를 생성하는 연산, operations to generate a empty graph
int isEmpty(Graph* G);	// 그래프가 공백인지 검사, check if the graph is empty
void insertVertex(Graph* G, int v);	// 그래프 G에 정점 v를 삽입, insert vertex v into graph G
void insertEdge(Graph* G, int u, int v);	// 그래프 G에 간선(u, v)를 삽입, insert a edge(u, v) into graph G
void deleteVertex(Graph* G, int v);	// 그래프 G에 정점 v를 삭제하고 연결된 모든 간선 삭제, delete vertex v to graph G and delete all connected edges
void deleteEdge(Graph* G, int u, int v);  // 그래프 G에 간선 (u, v)를 삭제, delete the edge(u, v) to graph G
void destroyGraph(Graph* G);	// 그래프 G의 리소스 해제, unresource graph G
void displayGraph(Graph* G);	// 그래프 G의 인접 행렬 정보 출력, display adjacent matrix information for graph G
 
#endif
