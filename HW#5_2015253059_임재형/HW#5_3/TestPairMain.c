#include <stdio.h>
#include <stdlib.h>
#include "ArrayStack.h"

int testPair(char* exp) {
	Stack* S = (Stack*)malloc(sizeof(Stack));
	S = create();
	char symbol, lparen;
	int i, length = strlen(exp);

	for (i = 0; i <= length-1; i++) {
		symbol = exp[i]; //한 글자씩 검사
		if (symbol == '(' || symbol == '{' || symbol == '[') //괄호 종류면 push
			push(S, symbol);
		else if (symbol == ')' || symbol == '}' || symbol == ']') {
			lparen = peek(S); //제일 위에 있는 것을 char형으로 받음
			if ((lparen == '(' && symbol == ')') || (lparen == '{' && symbol == '}') || (lparen == '[' && symbol == ']')) //쌍이 일치할 경우
				pop(S); //꺼냄
			else
				return FALSE; //쌍이 일치하지 않을 경우 false
		}
	}

	if (isEmpty(S))
		return TRUE; //다 끝나고 비어있으면 올바른 수식
	else
		return FALSE; //다 끝났는데 괄호가 남아있으면 잘못된 수식
}

int main() {
	int i;
	char* x[4] = {"(A - B) * C) + D", "(A - B) * C + ( D", "A [ B ( C ] )", "{A / (B - C)}"};

	for(i=0; i<4; i++) {
		printf("%s ", x[i]);
		if(testPair(x[i]))
			printf("-> 수식의 괄호가 올바르게 사용되었습니다!\n");
		else
			printf("-> 수식의 괄호가 틀렸습니다!\n");
	}
	
	return 0;
}
