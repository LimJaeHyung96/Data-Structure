#include <stdio.h>
#include "SLinkedList.h"

int main(){
	linkedList* L;
	listNode* p;
	int length;

	printf("\n(1)���鸮��Ʈ �����ϱ�\n");
	L = initList(); //���鸮��Ʈ ����
	displayList(L);
	printf("����Ʈ�� ����� ������ ���� : %d\n", getLength(L));
	

	printf("\n(2)����Ʈ�� 10, 50 ��带 ������� �����ϱ�\n");
	insertFirst(L, 10); //10 ��� ���� ����
	insert(L, search(L, 10), 50); //10 �ڿ� 50��� ����
	displayList(L);
	printf("����Ʈ�� ����� ������ ���� : %d\n", getLength(L));

	printf("\n(3)����Ʈ�� �������� 80 ��带 �߰��ϱ�\n");
	insertLast(L, 80);
	displayList(L);
	printf("����Ʈ�� ����� ������ ���� : %d\n", getLength(L));

	printf("\n(4)����Ʈ���� 50 ��� Ž���ϱ�\n");
	if(search(L, 50)->data == 50)
		printf("50 ��带 ã�ҽ��ϴ�\n");
	else
		printf("50 ��带 ã�� ���߽��ϴ�\n");

	printf("\n(5)50 ��� �ڿ� 60 ��� �����ϱ�\n");
	insert(L, search(L, 50), 60);
	displayList(L);
	printf("����Ʈ�� ����� ������ ���� : %d\n", getLength(L));

	printf("\n(6)����Ʈ���� 80 ��� �����ϱ�( node ��� )\n");
	if (deleteNode(L, search(L, 80))) //������ �ʵ尡 80�� ��带 �˻��ؼ� ����
		printf("��� ���� ����!\n");
	else
		printf("��� ���� ����!\n");
	displayList(L);
	printf("����Ʈ�� ����� ������ ���� : %d\n", getLength(L));

	printf("\n(7)����Ʈ���� 50 ��� �����ϱ�( element ��� )\n");
	if (deleteData(L, 50))
		printf("��� ���� ����!\n");
	else
		printf("��� ���� ����!\n");
	displayList(L);
	printf("����Ʈ�� ����� ������ ���� : %d\n", getLength(L));

	clear(L);

	return 0;
}
