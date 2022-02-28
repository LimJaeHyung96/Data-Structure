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
	
	for (i = 0; i < expLen; i++) { //���ڿ��� ���ڵ��� �ϳ��� �˻�
		bNode = createBT();
		if (isdigit(exp[i])) //�ǿ�����(����)�� ��� ������ ����
			setData(bNode, exp[i] - '0');
		else { //�������� ��� ���ÿ� �ִ� �ǿ����� ������ �ϳ��� �ڽĳ��� �޾���
			makeRSubtree(bNode, pop(S));
			makeLSubtree(bNode, pop(S));
			setData(bNode, exp[i]);
		}
		push(S, bNode); //���ÿ� �������
	}
	return pop(S); //��ü Ʈ���� ����
}

int evalExpTree(BinTree* bt) {
	int op1, op2;

	if (getLSubtree(bt) == NULL && getRSubtree(bt) == NULL) //�ܸ� ����Ͻ� ��� Ż��
		return getData(bt);
	
	op1 = evalExpTree(getLSubtree(bt)); //���� ����Ʈ���� �����
	op2 = evalExpTree(getRSubtree(bt)); //������ ����Ʈ���� �����

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
	if(0<=x && x<=9)			// �ǿ����� ���, operand output
		printf("%d ", x);
	else						// ������ ���, operator output
		printf("%c ", x);
}

void showPrefixExp(BinTree* bt) { //����ǥ��Ŀ� �´� ������� ����
	if (bt == NULL)
		return;

	if (bt->left != NULL || bt->right != NULL)
		printf(" ( ");

	showNodeData(bt->data);		// ������ ���, operator output
	showPrefixExp(bt->left);		// ù ��° �ǿ����� ���, first operand output
	showPrefixExp(bt->right);	// �� ��° �ǿ����� ���, second operand output

	if (bt->left != NULL || bt->right != NULL)
		printf(" ) ");
}

void showInfixExp(BinTree* bt) {
	if(bt == NULL)
		return;
	
	if(bt->left != NULL || bt->right != NULL)
		printf(" ( ");
	
	showInfixExp(bt->left);		// ù ��° �ǿ����� ���, first operand output
	showNodeData(bt->data);		// ������ ���, operator output
	showInfixExp(bt->right);	// �� ��° �ǿ����� ���, second operand output
	
	if(bt->left != NULL || bt->right != NULL)
		printf(" ) "); 
}

void showPostfixExp(BinTree* bt) { //����ǥ��Ŀ� �´� ������� ����
	if (bt == NULL)
		return;

	if (bt->left != NULL || bt->right != NULL)
		printf(" ( ");

	showPostfixExp(bt->left);		// ù ��° �ǿ����� ���, first operand output
	showPostfixExp(bt->right);	// �� ��° �ǿ����� ���, second operand output
	showNodeData(bt->data);		// ������ ���, operator output

	if (bt->left != NULL || bt->right != NULL)
		printf(" ) ");
}
