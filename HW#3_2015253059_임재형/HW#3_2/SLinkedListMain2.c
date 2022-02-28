#include <stdio.h>
#include "SLinkedList2.h"

int main(){
	linkedList* L;
	listNode* p;
	
	printf("(1)공백리스트 생성하기\n");
	L = initList(); //공백리스트 생성
	displayList(L);
	printf("리스트에 저장된 데이터 개수 : %d\n", getLength(L));
	
	printf("\n(2)리스트에 월, 화, 목 노드를 순서대로 삽입하기\n");
	insertFirst(L, "월");
	insertLast(L, "화");
	insertLast(L, "목");
	displayList(L);
	printf("리스트에 저장된 데이터 개수 : %d\n", getLength(L));
	 
	printf("\n(3)목 노드 뒤에 일 노드 삽입하기\n");
	insert(L, search(L, "목"), "일");
	displayList(L);
	printf("리스트에 저장된 데이터 개수 : %d\n", getLength(L));

	printf("\n(4)리스트에서 수 노드 탐색하기\n");
	if (search(L, "수") == NULL)
		printf("찾는 데이터가 없습니다.\n");
	else
		printf("수 노드를 찾았습니다\n");

	printf("\n(5)리스트 순서를 역순으로 바꾸기\n");
	reverse(L);
	displayList(L);
	printf("리스트에 저장된 데이터 개수 : %d\n", getLength(L));

	clear(L);

	return 0;
}

