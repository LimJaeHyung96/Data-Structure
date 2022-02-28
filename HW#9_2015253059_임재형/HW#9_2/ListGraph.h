#ifndef __LIST_GRAPH_H__
#define _LIST_GRAPH_H__

#define MAX_SIZE 100
#define DIRECT 1
#define UNDIRECT 0

// 인접 리스트의 노드 구조를 구조체로 정의, defines the node structure of an adjacent list as a structure
typedef struct GraphNode {
	int vertex;		// 정점을 나타내는 데이터 필드, data fields representing vertex
	struct GraphNode* link;	// 다음 인접 정점을 연결하는 링크 필드, link field to connect the following adjacent vertex
} graphNode;
 
// 그래프를 인접 리스트로 표현하기 위한 구조체 정의, define structures for representing graphs as adjacent lists
typedef struct GraphType {
	int n;
	int type;	// UNDIRECT: 무방향, DIRECT: 방향 
	graphNode* adjList_H[MAX_SIZE];	// 그래프 정점에 대한 헤드 포인터, head pointer for graph vertex
} Graph;

Graph* createGraph(int type);	// 공백 그래프를 생성하는 연산, operations to generate a empty graph
int isEmpty(Graph* G);	// 그래프가 공백인지 검사, check if the graph is empth
void insertVertex(Graph* G, int v);	// 그래프 G에 정점 v를 삽입, insert vertex v into graph G
void insertEdge(Graph* G, int u, int v);	// 그래프 G에 간선(u, v)를 삽입, insert a edge(u, v) into graph G
void deleteVertex(Graph* G, int v);	// 그래프 G에 정점 v를 삭제하고 연결된 모든 간선 삭제, delete vertex v to graph G and delete all connected edges
void deleteEdge(Graph* G, int u, int v);  // 그래프 G에 간선 (u, v)를 삭제, delete the edge(u, v) to graph G
void destroyGraph(Graph* G);	// 그래프 G의 리소스 해제, unresource graph G
void displayGraph(Graph* G);	// 그래프 G의 인접 리스트 정보 출력, display adjacent list information for graph G
 
#endif

