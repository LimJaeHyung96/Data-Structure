#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

// 공백 이진 트리 생성 연산, blank binary tree generation operations
BinTree* createBT(){
	BinTree* bt = (BinTree*)malloc(sizeof(BinTree));
	bt->data = EMPTY;
	bt->left = NULL;
	bt->right = NULL;
	return bt;
}

// 이진 트리가 비어있는지 검사하는 연산, operations to check if the binary tree is empty
int isBTEmpty(BinTree* bt) {
	if(bt->left == NULL && bt->right == NULL && bt->data == EMPTY)
		return TRUE;
	else
		return FALSE;
}

// 왼쪽 서브트리가 bt1, 오른쪽 서브트리가 bt2, x값을 가지는 노드를 루트로 하는 이진트리 반환, returns a binary tree rooted at a node whose left subtree is bt1, whose right subtree is bt2, x
BinTree* makeBT(BinTree* bt1, BTData x, BinTree* bt2) {
	BinTree* bt = (BinTree*)malloc(sizeof(BinTree));
	bt->data = x;
	bt->left = bt1;
	bt->right = bt2;
	return bt;
}

// bt2를 bt1의 왼쪽 서브트리로 연결, connect bt2 to the left subtree of bt1
void makeLSubtree(BinTree* bt1, BinTree* bt2) {
	bt1->left = bt2; //bt1의 왼쪽 링크필드에 bt2의 포인터 값 삽입
}

// bt2를 bt1의 오른쪽 서브트리로 연결, connect bt2 to the right subtree of bt1
void makeRSubtree(BinTree* bt1, BinTree* bt2) {
	bt1->right = bt2; //bt1의 오른쪽 링크필드에 bt2의 포인터 값 삽입
}

// bt의 왼쪽 서브트리를 반환, returns the left subtree of bt
BinTree* getLSubtree(BinTree* bt) {
	return bt->left; //bt의 왼쪽 링크필드에 있는 bt반환
}

// bt의 오른쪽 서브트리를 반환, returns the right subtree of bt
BinTree* getRSubtree(BinTree* bt) {
	return bt->right; //bt의 왼쪽 링크필드에 있는 bt반환
}

// bt의 root 노드에 x 값 저장, store x value in root node of bt
void setData(BinTree* bt, BTData x) {
	bt->data = x; //x값 노드에 저장
}

// bt의 root에 저장된 데이터를 반환, 값이 없으면 -1 반환, retruns data stored in bt's root, returns -1 if no value exists
BTData getData(BinTree* bt) {
	if (bt == NULL) //bt가 NULL일시 -1 아니면 bt의 데이터 반환
		return -1;
	else
		return bt->data;
}

// bt가 가리키는 노드를 루트로 하는 트리 전부 소멸, destroy all trees rooted at nodes bt points to
void deleteBT(BinTree* bt) {
	if(bt == NULL)
		return;
	
	deleteBT(bt->left);
	deleteBT(bt->right);
	
	printf("tree 값 삭제: %d \n", bt->data);	// delete tree data:
	free(bt);
}

// 중위 순회, inorder
void InorderTraverse(BinTree* bt, visitFuncPtr action) {
	if (bt != NULL) {
		InorderTraverse(bt->left, getData); //왼쪽 서브트리를 방문
		InorderTraverse(bt->right, printf("%d ", bt->data)); //출력을 하고 오른쪽 서브트리를 방문
	}
}

// 전위 순회, preorder
void PreorderTraverse(BinTree* bt, visitFuncPtr action) {
	if (bt != NULL) {
		PreorderTraverse(bt->left, printf("%d ", bt->data)); //출력을 하고 왼쪽 서브트리 방문
		PreorderTraverse(bt->right, getData); //오른쪽 서브트리 방문
	}
}

// 후위 순회, postorder
void PostorderTraverse(BinTree* bt, visitFuncPtr action) {
	if (bt != NULL) {
		PostorderTraverse(bt->left, getData); //왼쪽 서브트리 방문
		PostorderTraverse(bt->right, getData); //오른쪽 서브트리 방문
		printf("%d ", bt->data); //출력
	}
}

