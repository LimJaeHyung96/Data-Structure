#include <stdio.h>
#include "ArrayStack.h"

int main() {
	Stack* S;
	element item;
	int i;
	
	printf("\n(1) 공백 스택 생성하기\n");	// (1) To create a blank stack
	S = create();
	displayStack(S);
	
	printf("\n(2) 스택에 10, 20을 차례로 삽입\n");	// (2) Insert 10, 20 into the stack in order
	push(S, 10);
	displayStack(S);
	push(S, 20);
	displayStack(S);

	printf("\n(3) 현재 top의 요소를 출력\n");	// (3) Display elements of the current top
	printf("top에 저장된 요소 : %d\n",peek(S));

	printf("\n(4) 스택에서 요소 삭제\n");	// (4) Deleting an element from the stack
	printf("%d 삭제\n", pop(S));
	displayStack(S);
	
	printf("\n(5) 스택에서 요소 삭제\n");	// (5) Deleting an element from the stack
	printf("%d 삭제\n", pop(S));
	displayStack(S);

	printf("\n(6) 스택에서 요소 삭제\n");	// (6) Deleting an elment from the stack
	pop(S);
	displayStack(S);

	printf("\n(7) 스택에 1부터 10까지 자연수를 차례로 삽입\n");	// (7) Insert natural numbers from 1 to 10 into the stack in oerder
	for (int i = 1; i < 11; i++)
		push(S, i);
	displayStack(S);

	printf("\n(8) 스택 비우기\n");	// (8) Empty stack
	clear(S);
	displayStack(S);

	return 0;
}
