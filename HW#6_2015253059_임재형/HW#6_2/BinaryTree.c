#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

// ���� ���� Ʈ�� ���� ����, blank binary tree generation operations
BinTree* createBT(){
	BinTree* bt = (BinTree*)malloc(sizeof(BinTree));
	bt->data = EMPTY;
	bt->left = NULL;
	bt->right = NULL;
	return bt;
}

// ���� Ʈ���� ����ִ��� �˻��ϴ� ����, operations to check if the binary tree is empty
int isBTEmpty(BinTree* bt) {
	if(bt->left == NULL && bt->right == NULL && bt->data == EMPTY)
		return TRUE;
	else
		return FALSE;
}

// ���� ����Ʈ���� bt1, ������ ����Ʈ���� bt2, x���� ������ ��带 ��Ʈ�� �ϴ� ����Ʈ�� ��ȯ, returns a binary tree rooted at a node whose left subtree is bt1, whose right subtree is bt2, x
BinTree* makeBT(BinTree* bt1, BTData x, BinTree* bt2) {
	BinTree* bt = (BinTree*)malloc(sizeof(BinTree));
	bt->data = x;
	bt->left = bt1;
	bt->right = bt2;
	return bt;
}

// bt2�� bt1�� ���� ����Ʈ���� ����, connect bt2 to the left subtree of bt1
void makeLSubtree(BinTree* bt1, BinTree* bt2) {
	bt1->left = bt2; //bt1�� ���� ��ũ�ʵ忡 bt2�� ������ �� ����
}

// bt2�� bt1�� ������ ����Ʈ���� ����, connect bt2 to the right subtree of bt1
void makeRSubtree(BinTree* bt1, BinTree* bt2) {
	bt1->right = bt2; //bt1�� ������ ��ũ�ʵ忡 bt2�� ������ �� ����
}

// bt�� ���� ����Ʈ���� ��ȯ, returns the left subtree of bt
BinTree* getLSubtree(BinTree* bt) {
	return bt->left; //bt�� ���� ��ũ�ʵ忡 �ִ� bt��ȯ
}

// bt�� ������ ����Ʈ���� ��ȯ, returns the right subtree of bt
BinTree* getRSubtree(BinTree* bt) {
	return bt->right; //bt�� ���� ��ũ�ʵ忡 �ִ� bt��ȯ
}

// bt�� root ��忡 x �� ����, store x value in root node of bt
void setData(BinTree* bt, BTData x) {
	bt->data = x; //x�� ��忡 ����
}

// bt�� root�� ����� �����͸� ��ȯ, ���� ������ -1 ��ȯ, retruns data stored in bt's root, returns -1 if no value exists
BTData getData(BinTree* bt) {
	if (bt == NULL) //bt�� NULL�Ͻ� -1 �ƴϸ� bt�� ������ ��ȯ
		return -1;
	else
		return bt->data;
}

// bt�� ����Ű�� ��带 ��Ʈ�� �ϴ� Ʈ�� ���� �Ҹ�, destroy all trees rooted at nodes bt points to
void deleteBT(BinTree* bt) {
	if(bt == NULL)
		return;
	
	deleteBT(bt->left);
	deleteBT(bt->right);
	
	printf("tree �� ����: %d \n", bt->data);	// delete tree data:
	free(bt);
}

// ���� ��ȸ, inorder
void InorderTraverse(BinTree* bt, visitFuncPtr action) {
	if (bt != NULL) {
		InorderTraverse(bt->left, getData); //���� ����Ʈ���� �湮
		InorderTraverse(bt->right, printf("%d ", bt->data)); //����� �ϰ� ������ ����Ʈ���� �湮
	}
}

// ���� ��ȸ, preorder
void PreorderTraverse(BinTree* bt, visitFuncPtr action) {
	if (bt != NULL) {
		PreorderTraverse(bt->left, printf("%d ", bt->data)); //����� �ϰ� ���� ����Ʈ�� �湮
		PreorderTraverse(bt->right, getData); //������ ����Ʈ�� �湮
	}
}

// ���� ��ȸ, postorder
void PostorderTraverse(BinTree* bt, visitFuncPtr action) {
	if (bt != NULL) {
		PostorderTraverse(bt->left, getData); //���� ����Ʈ�� �湮
		PostorderTraverse(bt->right, getData); //������ ����Ʈ�� �湮
		printf("%d ", bt->data); //���
	}
}

