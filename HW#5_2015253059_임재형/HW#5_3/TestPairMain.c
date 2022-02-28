#include <stdio.h>
#include <stdlib.h>
#include "ArrayStack.h"

int testPair(char* exp) {
	Stack* S = (Stack*)malloc(sizeof(Stack));
	S = create();
	char symbol, lparen;
	int i, length = strlen(exp);

	for (i = 0; i <= length-1; i++) {
		symbol = exp[i]; //�� ���ھ� �˻�
		if (symbol == '(' || symbol == '{' || symbol == '[') //��ȣ ������ push
			push(S, symbol);
		else if (symbol == ')' || symbol == '}' || symbol == ']') {
			lparen = peek(S); //���� ���� �ִ� ���� char������ ����
			if ((lparen == '(' && symbol == ')') || (lparen == '{' && symbol == '}') || (lparen == '[' && symbol == ']')) //���� ��ġ�� ���
				pop(S); //����
			else
				return FALSE; //���� ��ġ���� ���� ��� false
		}
	}

	if (isEmpty(S))
		return TRUE; //�� ������ ��������� �ùٸ� ����
	else
		return FALSE; //�� �����µ� ��ȣ�� ���������� �߸��� ����
}

int main() {
	int i;
	char* x[4] = {"(A - B) * C) + D", "(A - B) * C + ( D", "A [ B ( C ] )", "{A / (B - C)}"};

	for(i=0; i<4; i++) {
		printf("%s ", x[i]);
		if(testPair(x[i]))
			printf("-> ������ ��ȣ�� �ùٸ��� ���Ǿ����ϴ�!\n");
		else
			printf("-> ������ ��ȣ�� Ʋ�Ƚ��ϴ�!\n");
	}
	
	return 0;
}
