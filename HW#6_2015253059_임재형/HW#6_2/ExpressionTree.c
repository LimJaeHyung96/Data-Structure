#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "BinaryTree.h"
#include "LinkedStack.h"

BinTree* createExpTree(char exp[]) {
	Stack* S = createStack();
	BinTree* bNode;
	int expLen = strlen(exp);
	int i;
	
	for (i = 0; i < expLen; i++) { //문자열의 문자들을 하나씩 검사
		bNode = createBT();
		if (isdigit(exp[i])) //피연산자(숫자)일 경우 데이터 삽입
			setData(bNode, exp[i] - '0');
		else { //연산자일 경우 스택에 있는 피연산자 노드들을 하나씩 자식노드로 달아줌
			makeRSubtree(bNode, pop(S));
			makeLSubtree(bNode, pop(S));
			setData(bNode, exp[i]);
		}
		push(S, bNode); //스택에 집어넣음
	}
	return pop(S); //전체 트리를 꺼냄
}

int evalExpTree(BinTree* bt) {
	int op1, op2;

	if (getLSubtree(bt) == NULL && getRSubtree(bt) == NULL) //단말 노드일시 재귀 탈출
		return getData(bt);
	
	op1 = evalExpTree(getLSubtree(bt)); //왼쪽 서브트리를 계산함
	op2 = evalExpTree(getRSubtree(bt)); //오른쪽 서브트리를 계산함

	switch (getData(bt)) {
	case '+':
		return op1 + op2;
	case '-':
		return op1 - op2;
	case '*':
		return op1 * op2;
	case '/':
		return op1 / op2;
	}

	return 0;
}

void showNodeData(int x) {
	if(0<=x && x<=9)			// 피연산자 출력, operand output
		printf("%d ", x);
	else						// 연산자 출력, operator output
		printf("%c ", x);
}

void showPrefixExp(BinTree* bt) { //전위표기식에 맞는 순서대로 정렬
	if (bt == NULL)
		return;

	if (bt->left != NULL || bt->right != NULL)
		printf(" ( ");

	showNodeData(bt->data);		// 연산자 출력, operator output
	showPrefixExp(bt->left);		// 첫 번째 피연산자 출력, first operand output
	showPrefixExp(bt->right);	// 두 번째 피연산자 출력, second operand output

	if (bt->left != NULL || bt->right != NULL)
		printf(" ) ");
}

void showInfixExp(BinTree* bt) {
	if(bt == NULL)
		return;
	
	if(bt->left != NULL || bt->right != NULL)
		printf(" ( ");
	
	showInfixExp(bt->left);		// 첫 번째 피연산자 출력, first operand output
	showNodeData(bt->data);		// 연산자 출력, operator output
	showInfixExp(bt->right);	// 두 번째 피연산자 출력, second operand output
	
	if(bt->left != NULL || bt->right != NULL)
		printf(" ) "); 
}

void showPostfixExp(BinTree* bt) { //후위표기식에 맞는 순서대로 정렬
	if (bt == NULL)
		return;

	if (bt->left != NULL || bt->right != NULL)
		printf(" ( ");

	showPostfixExp(bt->left);		// 첫 번째 피연산자 출력, first operand output
	showPostfixExp(bt->right);	// 두 번째 피연산자 출력, second operand output
	showNodeData(bt->data);		// 연산자 출력, operator output

	if (bt->left != NULL || bt->right != NULL)
		printf(" ) ");
}
