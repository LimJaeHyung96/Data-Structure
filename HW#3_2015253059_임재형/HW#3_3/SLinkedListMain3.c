#include <stdio.h>
#include "SLinkedList3.h"

int whoIsPrecede(element d1, element d2) {
	return d1 > d2 ? 0 : 1;
}

int main(){
	linkedList* L;
	listNode* p;
	
	printf("(1)공백리스트 생성하기\n");
	L = initList(); //공백리스트 생성
	displayList(L);
	printf("리스트에 저장된 데이터 개수 : %d\n", getLength(L));

	setSortRule(L, whoIsPrecede);	// 리스트의 정렬 기준이 되는 함수 등록

	printf("\n(2)리스트에 10, 80, 50 노드를 삽입하되 내림차순으로 들어가도록 하기\n");

	sortInsert(L, 10);
	sortInsert(L, 80);
	sortInsert(L, 50);
	displayList(L);
	printf("리스트에 저장된 데이터 개수 : %d\n", getLength(L));
	
	printf("\n(3)리스트에서 50 노드 탐색하기\n");
	if (search(L, 50) == NULL)
		printf("찾는 데이터가 없습니다.\n");
	else
		printf("50 노드를 찾았습니다\n");
	
	printf("\n(4)40 노드 삽입하기(내림차순)\n");
	sortInsert(L, 40);
	displayList(L);
	printf("리스트에 저장된 데이터 개수 : %d\n", getLength(L));
	
	printf("\n(5)리스트에서 50 노드 삭제하기\n");
	if (delete(L, search(L, 50))) //데이터 필드가 50인 노드를 검색해서 삭제
		printf("노드 삭제 성공!\n");
	else
		printf("노드 삭제 실패!\n");
	displayList(L);
	printf("리스트에 저장된 데이터 개수 : %d\n", getLength(L));
	
	clear(L);

	return 0;
}

