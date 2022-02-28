#include <stdio.h>
#include "SLinkedList.h"

int main(){
	linkedList* L;
	listNode* p;
	int length;

	printf("\n(1)공백리스트 생성하기\n");
	L = initList(); //공백리스트 생성
	displayList(L);
	printf("리스트에 저장된 데이터 개수 : %d\n", getLength(L));
	

	printf("\n(2)리스트에 10, 50 노드를 순서대로 삽입하기\n");
	insertFirst(L, 10); //10 노드 먼저 삽입
	insert(L, search(L, 10), 50); //10 뒤에 50노드 삽입
	displayList(L);
	printf("리스트에 저장된 데이터 개수 : %d\n", getLength(L));

	printf("\n(3)리스트에 마지막에 80 노드를 추가하기\n");
	insertLast(L, 80);
	displayList(L);
	printf("리스트에 저장된 데이터 개수 : %d\n", getLength(L));

	printf("\n(4)리스트에서 50 노드 탐색하기\n");
	if(search(L, 50)->data == 50)
		printf("50 노드를 찾았습니다\n");
	else
		printf("50 노드를 찾지 못했습니다\n");

	printf("\n(5)50 노드 뒤에 60 노드 삽입하기\n");
	insert(L, search(L, 50), 60);
	displayList(L);
	printf("리스트에 저장된 데이터 개수 : %d\n", getLength(L));

	printf("\n(6)리스트에서 80 노드 삭제하기( node 사용 )\n");
	if (deleteNode(L, search(L, 80))) //데이터 필드가 80인 노드를 검색해서 삭제
		printf("노드 삭제 성공!\n");
	else
		printf("노드 삭제 실패!\n");
	displayList(L);
	printf("리스트에 저장된 데이터 개수 : %d\n", getLength(L));

	printf("\n(7)리스트에서 50 노드 삭제하기( element 사용 )\n");
	if (deleteData(L, 50))
		printf("노드 삭제 성공!\n");
	else
		printf("노드 삭제 실패!\n");
	displayList(L);
	printf("리스트에 저장된 데이터 개수 : %d\n", getLength(L));

	clear(L);

	return 0;
}
