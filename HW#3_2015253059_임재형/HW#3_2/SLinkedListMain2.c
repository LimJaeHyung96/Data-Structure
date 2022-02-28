#include <stdio.h>
#include "SLinkedList2.h"

int main(){
	linkedList* L;
	listNode* p;
	
	printf("(1)���鸮��Ʈ �����ϱ�\n");
	L = initList(); //���鸮��Ʈ ����
	displayList(L);
	printf("����Ʈ�� ����� ������ ���� : %d\n", getLength(L));
	
	printf("\n(2)����Ʈ�� ��, ȭ, �� ��带 ������� �����ϱ�\n");
	insertFirst(L, "��");
	insertLast(L, "ȭ");
	insertLast(L, "��");
	displayList(L);
	printf("����Ʈ�� ����� ������ ���� : %d\n", getLength(L));
	 
	printf("\n(3)�� ��� �ڿ� �� ��� �����ϱ�\n");
	insert(L, search(L, "��"), "��");
	displayList(L);
	printf("����Ʈ�� ����� ������ ���� : %d\n", getLength(L));

	printf("\n(4)����Ʈ���� �� ��� Ž���ϱ�\n");
	if (search(L, "��") == NULL)
		printf("ã�� �����Ͱ� �����ϴ�.\n");
	else
		printf("�� ��带 ã�ҽ��ϴ�\n");

	printf("\n(5)����Ʈ ������ �������� �ٲٱ�\n");
	reverse(L);
	displayList(L);
	printf("����Ʈ�� ����� ������ ���� : %d\n", getLength(L));

	clear(L);

	return 0;
}

