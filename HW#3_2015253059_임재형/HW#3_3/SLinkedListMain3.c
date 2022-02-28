#include <stdio.h>
#include "SLinkedList3.h"

int whoIsPrecede(element d1, element d2) {
	return d1 > d2 ? 0 : 1;
}

int main(){
	linkedList* L;
	listNode* p;
	
	printf("(1)���鸮��Ʈ �����ϱ�\n");
	L = initList(); //���鸮��Ʈ ����
	displayList(L);
	printf("����Ʈ�� ����� ������ ���� : %d\n", getLength(L));

	setSortRule(L, whoIsPrecede);	// ����Ʈ�� ���� ������ �Ǵ� �Լ� ���

	printf("\n(2)����Ʈ�� 10, 80, 50 ��带 �����ϵ� ������������ ������ �ϱ�\n");

	sortInsert(L, 10);
	sortInsert(L, 80);
	sortInsert(L, 50);
	displayList(L);
	printf("����Ʈ�� ����� ������ ���� : %d\n", getLength(L));
	
	printf("\n(3)����Ʈ���� 50 ��� Ž���ϱ�\n");
	if (search(L, 50) == NULL)
		printf("ã�� �����Ͱ� �����ϴ�.\n");
	else
		printf("50 ��带 ã�ҽ��ϴ�\n");
	
	printf("\n(4)40 ��� �����ϱ�(��������)\n");
	sortInsert(L, 40);
	displayList(L);
	printf("����Ʈ�� ����� ������ ���� : %d\n", getLength(L));
	
	printf("\n(5)����Ʈ���� 50 ��� �����ϱ�\n");
	if (delete(L, search(L, 50))) //������ �ʵ尡 50�� ��带 �˻��ؼ� ����
		printf("��� ���� ����!\n");
	else
		printf("��� ���� ����!\n");
	displayList(L);
	printf("����Ʈ�� ����� ������ ���� : %d\n", getLength(L));
	
	clear(L);

	return 0;
}

