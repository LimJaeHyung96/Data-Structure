#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100		// 배열의 최대 크기

typedef int element;
typedef struct {
	element list[MAX_SIZE];	// 배열 정의
	int length;		// 현재 배열에 저장된 자료들의 개수
}ArrayListType;

// 오류 처리 함수
void error(char* message)
{
	printf("%s\n", message);
}

// 리스트 초기화
void init(ArrayListType* L)
{
	L->length = 0;
}

// 빈 리스트 검사
// 리스트가 비어 있으면 1을 반환
// 그렇지 않으면 0을 반환
int isEmpty(ArrayListType* L)
{
	return L->length == 0;
}

// 리스트가 포화상태인 검사
// 리스트가 가득차 있으면 1을 반환
// 그렇지 않으면 0을 반환
int isFull(ArrayListType* L)
{
	return L->length == MAX_SIZE;
}

// 리스트의 모든 요소 출력
void display(ArrayListType* L)
{
	int i;
	printf("===Print Lists===\n");
	for (i = 0; i < L->length; i++)
		printf("ArrayList[%d]: %d\n", i, L->list[i]);
}

// 삽입 함수 
// pos: 삽입하고자 하는 위치
// item: 삽입하고자 하는 자료
void insert(ArrayListType* L, int pos, element item)
{
	int i;
	if (isFull(L)) //리스트가 가득 찼는지 검사
		error("List is Full!");
	else if ((pos < 0) || pos > L->length) //입력할 범위가 실제로 있는지 검사
		error("Index Error");
	else {
		for (i = (L->length - 1); i >= pos; i--) //입력 자리를 만들기 위해 요소들을 하나씩 뒤로 밈
			L->list[i + 1] = L->list[i];
		L->list[pos] = item; //빈 자리에 item 삽입
		L->length++; //리스트 길이 증가
		printf("ArrayList[%d]에 %d 삽입\n", pos, item);
	}
}

// 리스트 맨 앞에 요소 삽입
void insertFirst(ArrayListType* L, element item)
{
	int i;
	if (isFull(L)) //리스트가 가득 찼는지 검사
		error("List is Full!");
	else {
		for (i = (L->length - 1); i >= 0; i--) //모든 요소들을 한 칸씩 뒤로 밀어냄
			L->list[i + 1] = L->list[i];
		L->list[0] = item; //맨 앞자리에 item 삽입
		L->length++; //리스트 길이 증가
		printf("ArrayList[0]에 %d 삽입\n",item);
	}
}

// 리스트 맨 끝에 요소 삽입
void insertLast(ArrayListType* L, element item)
{
	if (isFull(L)) //리스트가 가득 찼는지 검사
		error("List is Full!");
	else {
		L->list[L->length] = item; //리스트의 맨 뒤에 item 삽입
		L->length++; //리스트 길이 증가
		printf("ArrayList[%d]에 %d 삽입\n",L->length-1 ,item);
	}
}

// 삭제 함수
// pos: 삭제하고자 하는 위치
// 반환값: 삭제되는 자료
element delete(ArrayListType* L, int pos)
{
	int i;
	element item;
	if (isEmpty(L)) //리스트가 비어있는지 검사
		error("List is Empty!");
	else if ((pos < 0) || (pos >= L->length)) //잘못된 위치의 요소를 삭제하는지 검사
		error("Index Error");
	else {
		item = L->list[pos];
		for (i = pos; i < L->length; i++) //삭제한 위치에서부터 뒤에있는 요소을 땡겨옴
			L->list[i] = L->list[i + 1];
		L->length--; //리스트 길이 감소
		return item;
	}
}

// 리스트의 모든 요소 삭제
void clear(ArrayListType* L)
{
	int i;
	for (i = (L->length - 1); i >= 0; i--)
		delete(L, i);
	init(L); //리스트 초기화
}

// pos 위치의 요소를 item으로 교체
void replace(ArrayListType* L, int pos, element item)
{
	if ((pos < 0) || pos > L->length) //입력할 범위가 실제로 있는지 검사
		error("Index Error");
	else
		L->list[pos] = item; //입력한 위치의 요소를 교체
}

// item이 리스트에 있는지 검사
// 리스트에 있으면 1을 반환
// 그렇지 않으면 0을 반환
int isList(ArrayListType* L, element item)
{
	int value = 0; // 기본 0으로 설정
	for (int i = 0; i < L->length; i++) { //리스트의 요소를 처음부터 마지막까지 검사
		if (L->list[i] == item) { //item과 리스트의 요소가 일치할 시
			value = 1; //value를 1로 설정
			break; //for문에서 빠져나감
		}
	}
	return value; //일치하는 것이 있을 시 1 아니면 0 반환
}

// pos 위치의 요소를 반환
element getItem(ArrayListType* L, int pos)
{
	return L->list[pos]; //현재 위치의 요소를 반환
}

// 리스트의 길이(항목의 개수)를 구함
int getLength(ArrayListType* L)
{
	return L->length; // 리스트의 길이 반환
}


int main()
{
	ArrayListType* plist;

	// ListType를 동적으로 생성하고 ListType를 가리키는 
	// 포인터를 함수의 파라미터로 전달한다.
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
