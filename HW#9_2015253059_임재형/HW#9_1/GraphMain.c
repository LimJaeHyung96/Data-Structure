#include <stdio.h>
#include "ArrayGraph.h"

int main() {
	int i;
	Graph *G1, *G2, *G3, *G4;
	G1 = createGraph(UNDIRECT);
	G2 = createGraph(DIRECT);
	G3 = createGraph(UNDIRECT);
	G4 = createGraph(DIRECT);
	
	// 무방향 그래프 G1, undirect graph G1
	for(i=0; i<4; i++)
		insertVertex(G1, i);	// G1의 정점 0~3 삽입, insert vertex 0~3 of G1
	insertEdge(G1, 0, 1);
	insertEdge(G1, 0, 3);
	insertEdge(G1, 1, 2);
	insertEdge(G1, 1, 3);
	insertEdge(G1, 2, 3);
	printf("G1의 인접행렬\n");	// Adjacent matrix of G1
	displayGraph(G1);
	
	deleteVertex(G1, 2);
	printf("G1의 인접행렬\n");	// Adjacet matrix of G1
	displayGraph(G1);
	
	// 방향 그래프 G2, direct graph G2
	for(i=0; i<4; i++)
		insertVertex(G2, i);	// G2의 정점 0~3 삽입, insert vertex 0~3 of G2
	insertEdge(G2, 0, 1);
	insertEdge(G2, 0, 3);
	insertEdge(G2, 1, 2);
	insertEdge(G2, 1, 3);
	insertEdge(G2, 2, 3);
	printf("G2의 인접행렬\n");	// Adjacent matrix of G2
	displayGraph(G2);
	
	deleteVertex(G2, 2);
	printf("G2의 인접행렬\n");	// Adjacent matrix of G1
	displayGraph(G2);
	
	// 무방향 그래프 G3, undirect graph G3
	for(i=0; i<3; i++)
		insertVertex(G3, i);	// G3의 정점 0~2 삽입, insert vertex 0~2 of G3
	insertEdge(G3, 0, 1);
	insertEdge(G3, 0, 2);
	insertEdge(G3, 1, 2);
	printf("G3 인접행렬\n");	// Adjacent matrix of G3
	displayGraph(G3);
	
	deleteEdge(G3, 0, 1);
	printf("G3 인접행렬\n");	// Adjacent matrix of G3
	displayGraph(G3);
	
	// 무방향 그래프 G4, undirect graph G4
	for(i=0; i<3; i++)
		insertVertex(G4, i);	// G4의 정점 0~2 삽입, insert vertex 0~2 of G4
	insertEdge(G4, 0, 1);
	insertEdge(G4, 0, 2);
	insertEdge(G4, 1, 2);
	printf("G4 인접행렬\n");	// Adjacent matrix of G4
	displayGraph(G4);
	
	deleteEdge(G4, 0, 1);
	printf("G4 인접행렬\n");	// Adjacent matrix of G4
	displayGraph(G4);
	
	destroyGraph(G1);
	destroyGraph(G2);
	destroyGraph(G3);
	destroyGraph(G4);
	 
	return 0;
}
