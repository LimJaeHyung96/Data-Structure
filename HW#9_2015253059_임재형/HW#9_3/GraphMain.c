#include <stdio.h>
#include "ListGraph.h"

int main() {
	int i;
	Graph *G1, *G2;

	G1 = createGraph(DIRECT);
	G2 = createGraph(DIRECT);
	
	// 방향 그래프 G1, direction graph G1
	for(i=0; i<7; i++)
		insertVertex(G1, i);	// G1의 정점 0~6 삽입, inserting vertices 0 to 6 of G1
	insertEdge(G1, 0, 2); 
	insertEdge(G1, 0, 1);
	insertEdge(G1, 1, 4);
	insertEdge(G1, 1, 3);
	insertEdge(G1, 1, 0);
	insertEdge(G1, 2, 4);
	insertEdge(G1, 2, 0);
	insertEdge(G1, 3, 6);
	insertEdge(G1, 3, 1);
	insertEdge(G1, 4, 6);
	insertEdge(G1, 4, 2);
	insertEdge(G1, 4, 1);
	insertEdge(G1, 5, 6);
	insertEdge(G1, 6, 5);
	insertEdge(G1, 6, 4);
	insertEdge(G1, 6, 3);
	
	printf("\nG1 인접리스트\n");	// G1 adjacent list
	displayGraph(G1);
	printf("\n");
	
	printf("G1 DFS iterative version:\t");
	dfs_iter(G1, 0);
	printf("\n");	
	initSearch(G1);
	
	printf("G1 DFS recursive version:\t");
	dfs_recur(G1, 0);
	printf("\n");
	initSearch(G1);
	
	printf("G1 BFS:\t");
	bfs(G1, 0);
	printf("\n\n");
	
	// 방향 그래프 G2, direction graph G2
	for(i=0; i<8; i++)
		insertVertex(G2, i);	// G2의 정점 0~7 삽입, inserting vertices 0 to 7 of G2
	insertEdge(G2, 0, 2); 
	insertEdge(G2, 0, 1); 
	insertEdge(G2, 1, 4); 
	insertEdge(G2, 1, 3); 
	insertEdge(G2, 1, 0); 
	insertEdge(G2, 2, 6); 
	insertEdge(G2, 2, 5);
	insertEdge(G2, 2, 0);
	insertEdge(G2, 3, 7);
	insertEdge(G2, 3, 1);
	insertEdge(G2, 4, 7);
	insertEdge(G2, 4, 1);
	insertEdge(G2, 5, 7);
	insertEdge(G2, 5, 2);
	insertEdge(G2, 6, 7);
	insertEdge(G2, 6, 2);
	insertEdge(G2, 7, 6);
	insertEdge(G2, 7, 5);
	insertEdge(G2, 7, 4);
	insertEdge(G2, 7, 3);
	
	printf("G2 인접리스트\n");	// G2 adjacent list
	displayGraph(G2);
	printf("\n");
	
	printf("G2 DFS iterative version:\t");
	dfs_iter(G2, 0);
	printf("\n");	
	initSearch(G2);
	
	printf("G2 DFS recursive version:\t");
	dfs_recur(G2, 0);
	printf("\n");
	initSearch(G2);
	
	printf("G2 BFS:\t");
	bfs(G2, 0);
	printf("\n");

	destroyGraph(G1);
	destroyGraph(G2);
		 
	return 0;
}
