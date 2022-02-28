#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100		// �迭�� �ִ� ũ��

typedef int element;
typedef struct {
	element list[MAX_SIZE];	// �迭 ����
	int length;		// ���� �迭�� ����� �ڷ���� ����
}ArrayListType;

// ���� ó�� �Լ�
void error(char* message)
{
	printf("%s\n", message);
}

// ����Ʈ �ʱ�ȭ
void init(ArrayListType* L)
{
	L->length = 0;
}

// �� ����Ʈ �˻�
// ����Ʈ�� ��� ������ 1�� ��ȯ
// �׷��� ������ 0�� ��ȯ
int isEmpty(ArrayListType* L)
{
	return L->length == 0;
}

// ����Ʈ�� ��ȭ������ �˻�
// ����Ʈ�� ������ ������ 1�� ��ȯ
// �׷��� ������ 0�� ��ȯ
int isFull(ArrayListType* L)
{
	return L->length == MAX_SIZE;
}

// ����Ʈ�� ��� ��� ���
void display(ArrayListType* L)
{
	int i;
	printf("===Print Lists===\n");
	for (i = 0; i < L->length; i++)
		printf("ArrayList[%d]: %d\n", i, L->list[i]);
}

// ���� �Լ� 
// pos: �����ϰ��� �ϴ� ��ġ
// item: �����ϰ��� �ϴ� �ڷ�
void insert(ArrayListType* L, int pos, element item)
{
	int i;
	if (isFull(L)) //����Ʈ�� ���� á���� �˻�
		error("List is Full!");
	else if ((pos < 0) || pos > L->length) //�Է��� ������ ������ �ִ��� �˻�
		error("Index Error");
	else {
		for (i = (L->length - 1); i >= pos; i--) //�Է� �ڸ��� ����� ���� ��ҵ��� �ϳ��� �ڷ� ��
			L->list[i + 1] = L->list[i];
		L->list[pos] = item; //�� �ڸ��� item ����
		L->length++; //����Ʈ ���� ����
		printf("ArrayList[%d]�� %d ����\n", pos, item);
	}
}

// ����Ʈ �� �տ� ��� ����
void insertFirst(ArrayListType* L, element item)
{
	int i;
	if (isFull(L)) //����Ʈ�� ���� á���� �˻�
		error("List is Full!");
	else {
		for (i = (L->length - 1); i >= 0; i--) //��� ��ҵ��� �� ĭ�� �ڷ� �о
			L->list[i + 1] = L->list[i];
		L->list[0] = item; //�� ���ڸ��� item ����
		L->length++; //����Ʈ ���� ����
		printf("ArrayList[0]�� %d ����\n",item);
	}
}

// ����Ʈ �� ���� ��� ����
void insertLast(ArrayListType* L, element item)
{
	if (isFull(L)) //����Ʈ�� ���� á���� �˻�
		error("List is Full!");
	else {
		L->list[L->length] = item; //����Ʈ�� �� �ڿ� item ����
		L->length++; //����Ʈ ���� ����
		printf("ArrayList[%d]�� %d ����\n",L->length-1 ,item);
	}
}

// ���� �Լ�
// pos: �����ϰ��� �ϴ� ��ġ
// ��ȯ��: �����Ǵ� �ڷ�
element delete(ArrayListType* L, int pos)
{
	int i;
	element item;
	if (isEmpty(L)) //����Ʈ�� ����ִ��� �˻�
		error("List is Empty!");
	else if ((pos < 0) || (pos >= L->length)) //�߸��� ��ġ�� ��Ҹ� �����ϴ��� �˻�
		error("Index Error");
	else {
		item = L->list[pos];
		for (i = pos; i < L->length; i++) //������ ��ġ�������� �ڿ��ִ� ����� ���ܿ�
			L->list[i] = L->list[i + 1];
		L->length--; //����Ʈ ���� ����
		return item;
	}
}

// ����Ʈ�� ��� ��� ����
void clear(ArrayListType* L)
{
	int i;
	for (i = (L->length - 1); i >= 0; i--)
		delete(L, i);
	init(L); //����Ʈ �ʱ�ȭ
}

// pos ��ġ�� ��Ҹ� item���� ��ü
void replace(ArrayListType* L, int pos, element item)
{
	if ((pos < 0) || pos > L->length) //�Է��� ������ ������ �ִ��� �˻�
		error("Index Error");
	else
		L->list[pos] = item; //�Է��� ��ġ�� ��Ҹ� ��ü
}

// item�� ����Ʈ�� �ִ��� �˻�
// ����Ʈ�� ������ 1�� ��ȯ
// �׷��� ������ 0�� ��ȯ
int isList(ArrayListType* L, element item)
{
	int value = 0; // �⺻ 0���� ����
	for (int i = 0; i < L->length; i++) { //����Ʈ�� ��Ҹ� ó������ ���������� �˻�
		if (L->list[i] == item) { //item�� ����Ʈ�� ��Ұ� ��ġ�� ��
			value = 1; //value�� 1�� ����
			break; //for������ ��������
		}
	}
	return value; //��ġ�ϴ� ���� ���� �� 1 �ƴϸ� 0 ��ȯ
}

// pos ��ġ�� ��Ҹ� ��ȯ
element getItem(ArrayListType* L, int pos)
{
	return L->list[pos]; //���� ��ġ�� ��Ҹ� ��ȯ
}

// ����Ʈ�� ����(�׸��� ����)�� ����
int getLength(ArrayListType* L)
{
	return L->length; // ����Ʈ�� ���� ��ȯ
}


int main()
{
	ArrayListType* plist;

	// ListType�� �������� �����ϰ� ListType�� ����Ű�� 
	// �����͸� �Լ��� �Ķ���ͷ� �����Ѵ�.
	plist = (ArrayListType*)malloc(sizeof(ArrayListType));
	init(plist);
	insert(plist, 0, 10);
	insert(plist, 0, 20);
	insertFirst(plist, 5);
	insertLast(plist, 30);
	insert(plist, -1, 3);
	if (isFull(plist))
		printf("IS FULL\n");
	else
		printf("IS NOT FULL\n");
	display(plist);
	printf("LENGTH IS %d\n", getLength(plist));
	for (int i = 0; i < getLength(plist) - 1; i++) {
		if (getItem(plist, i) < 15)
			delete(plist, i);
	}
	element temp;
	temp = getItem(plist, 0);
	replace(plist, 0, getItem(plist, 1));
	replace(plist, 1, temp);
	display(plist);
	clear(plist);
	if (isEmpty(plist))
		printf("IS EMPTY\n");
	else
		printf("IS NOT EMPTY\n");
	free(plist);

	return 0;
}
