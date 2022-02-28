#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

// ���� ���� Ʈ�� ���� ����, empty binary tree generation operations
BinTree* createBT(){
	BinTree* bt = (BinTree*)malloc(sizeof(BinTree));
	bt->key = EMPTY;
	bt->left = NULL;
	bt->right = NULL;
	return bt;
}

// ���� Ʈ���� ����ִ��� �˻��ϴ� ����, operations to check if the binary tree is empty
int isBTEmpty(BinTree* bt) {
	if(bt->left == NULL && bt->right == NULL && bt->key == EMPTY)
		return TRUE;
	else
		return FALSE;
}

// ���� ����Ʈ���� bt1, ������ ����Ʈ���� bt2, x���� ������ ��带 ��Ʈ�� �ϴ� ����Ʈ�� ��ȯ, returns a binary tree rooted at a node whose left subtree is bt1, whose right subtree is bt2, x
BinTree* makeBT(BinTree* bt1, BTData x, BinTree* bt2) {
	BinTree* bt = (BinTree*)malloc(sizeof(BinTree));
	bt->key = x;
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
	return bt->right; //bt�� ������ ��ũ�ʵ忡 �ִ� bt��ȯ
}

// bt�� root ��忡 x �� ����, store x value in root node of bt
void setData(BinTree* bt, BTData x) {
	bt->key = x; //x�� ��忡 ����
}

// bt�� root�� ����� �����͸� ��ȯ, returns data stored in bt's root
BTData getData(BinTree* bt) {
	if (bt == NULL) //bt�� NULL�Ͻ� -1 �ƴϸ� bt�� ������ ��ȯ
		return -1;
	else
		return bt->key;
}

// bt�� ����Ű�� ��带 ��Ʈ�� �ϴ� Ʈ�� ���� �Ҹ�, destroy all trees rooted at nodes bt points to
void deleteBT(BinTree* bt) {
	if(bt == NULL)
		return;
	
	deleteBT(bt->left);
	deleteBT(bt->right);
	
	printf("delete tree data: %d \n", bt->key);
	free(bt);
}

// ���� ��ȸ, inorder traversal
void InorderTraverse(BinTree* bt, visitFuncPtr action) {
	if (bt != NULL) {
		InorderTraverse(bt->left, action); //���� ����Ʈ���� �湮
		action(bt->key); //���
		InorderTraverse(bt->right, action); //������ ����Ʈ���� �湮
	}
}

// ������ x�� ����� ��� Ž��, searching nodes where data x is stored
BinTree* searchBST(BinTree* bt, BTData x) {
	BinTree* p = bt;
	while (p != NULL) {
		if (x == p->key)
			return p;
		if (x < p->key)
			p = p->left;
		else
			p = p->right;
	}
	return NULL;
}

// ������ x ����, insert data x
void insertBST(BinTree* bt, BTData x) {
	BinTree* p = bt;
	BinTree* parent = NULL;	
	
	// ������ ��� Ž��, searching nodes to insert
	while (p != NULL) {
		if (x == p->key)
			return;
		parent = p;
		if (x < p->key)
			p = p->left;
		else
			p = p->right;
	}

	// ������ ��� ����, create node to insert
	BinTree* newNode = (BinTree*)malloc(sizeof(BinTree));
	newNode->key = x;
	newNode->left = NULL;
	newNode->right = NULL;

	// ���� ��� ����, connect insert node
	if (bt == NULL)
		bt = newNode;
	else if (x < parent->key)
		parent->left = newNode;
	else
		parent->right = newNode;
}

// ������ x ��� ����, delete data x node
void deleteBST(BinTree* bt, BTData x) {
	BinTree* p = bt;
	BinTree* parent = NULL;

	while (p != NULL && p->key != x) { //p�� NULL�� �ǰų� p�� key���� x�� �������� �������� �θ��� Ž�� ����
		parent = p; //��Ʈ������ �����ؼ� �θ�� �ٲ�
		if (x < parent->key) //x�� �θ��� Ű������ ������ ����
			p = parent->left;
		else
			p = parent->right;//x�� �θ��� Ű������ ũ�� ���������� p���� ��������
	}//p���� Ű ���� x�� �������� �ݺ��� Ż��
		
	// ������ ��尡 ���� ���, if there are no nodes to delete
	if (p == NULL)
		return; //���� ����

	// CASE 1: ������ ����� ������ 0�� ���, CASE 1: if the node to be deleted has a degree of 0
	if (p->left == NULL && p->right == NULL) {
		if (parent->left = p)
			parent->left = NULL; //�θ����� ���ʿ� ������ �θ����� ���� ��ũ�ʵ带 NULL��
		else
			parent->right = NULL; //�θ����� ���ʿ� ������ �θ����� ������ ��ũ�ʵ带 NULL��
	}

	// CASE 2: ������ ����� ������ 1�� ���, CASE 2: if the node to be deleted has a degree of 1
	else if (p->left == NULL || p->right == NULL) {
		if (p->left != NULL) {
			if (parent->left == p) //�θ��� ���ʿ� �ִ� ���� ������ �� �����ϴ� ���� ���ʿ� �ִ� ��带 �θ���� ����
				parent->left = p->left;
			else //�θ��Ʈ�� �����ʿ� �ִ� ���� ������ �� �����ϴ� ���� ���ʿ� �ִ� ��带 �θ���� ����
				parent->right = p->left;
		}
		else {
			if (parent->left == p) //�θ��� ���ʿ� �ִ� ���� ������ �� �����ϴ� ���� �����ʿ� �ִ� ��带 �θ���� ����
				parent->left = p->right;
			else //�θ��� �����ʿ� �ִ� ���� ������ �� �����ϴ� ���� �����ʿ� �ִ� ��带 �θ���� ����
				parent->right = p->right;
		}
	}

	// CASE 3: ������ ����� ������ 2�� ���, CASE 3: if the node to be deleted has a degree of 2
	else if (p->left != NULL && p->right != NULL) {
		BinTree* temp = p->left;
		BinTree* temp_parent = p;

		//�����ϴ� ���� ���ʼ���Ʈ������ �İ��ڸ� �����ؾ���
		while (temp->right != NULL) { //���ʿ��� ���� ū ���� �����ؾ� �ϹǷ� ����� �������� ���� �� ���� ����
			temp_parent = temp;
			temp = temp->right;
		}

		p->key = temp->key; //���� ����� Ű���� �İ����� Ű������ ����
		deleteBST(p->left, temp->key); //���� ����Ʈ������ ã�Ƴ� �İ��ڸ� �̹� �����߱� ������ ���� �ִ� ���� �����ؾ� �ϹǷ� �ѹ� �� ����
	}

}	

