#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

// 공백 이진 트리 생성 연산, empty binary tree generation operations
BinTree* createBT(){
	BinTree* bt = (BinTree*)malloc(sizeof(BinTree));
	bt->key = EMPTY;
	bt->left = NULL;
	bt->right = NULL;
	return bt;
}

// 이진 트리가 비어있는지 검사하는 연산, operations to check if the binary tree is empty
int isBTEmpty(BinTree* bt) {
	if(bt->left == NULL && bt->right == NULL && bt->key == EMPTY)
		return TRUE;
	else
		return FALSE;
}

// 왼쪽 서브트리가 bt1, 오른쪽 서브트리가 bt2, x값을 가지는 노드를 루트로 하는 이진트리 반환, returns a binary tree rooted at a node whose left subtree is bt1, whose right subtree is bt2, x
BinTree* makeBT(BinTree* bt1, BTData x, BinTree* bt2) {
	BinTree* bt = (BinTree*)malloc(sizeof(BinTree));
	bt->key = x;
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
	return bt->right; //bt의 오른쪽 링크필드에 있는 bt반환
}

// bt의 root 노드에 x 값 저장, store x value in root node of bt
void setData(BinTree* bt, BTData x) {
	bt->key = x; //x값 노드에 저장
}

// bt의 root에 저장된 데이터를 반환, returns data stored in bt's root
BTData getData(BinTree* bt) {
	if (bt == NULL) //bt가 NULL일시 -1 아니면 bt의 데이터 반환
		return -1;
	else
		return bt->key;
}

// bt가 가리키는 노드를 루트로 하는 트리 전부 소멸, destroy all trees rooted at nodes bt points to
void deleteBT(BinTree* bt) {
	if(bt == NULL)
		return;
	
	deleteBT(bt->left);
	deleteBT(bt->right);
	
	printf("delete tree data: %d \n", bt->key);
	free(bt);
}

// 중위 순회, inorder traversal
void InorderTraverse(BinTree* bt, visitFuncPtr action) {
	if (bt != NULL) {
		InorderTraverse(bt->left, action); //왼쪽 서브트리를 방문
		action(bt->key); //출력
		InorderTraverse(bt->right, action); //오른쪽 서브트리를 방문
	}
}

// 데이터 x가 저장된 노드 탐색, searching nodes where data x is stored
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

// 데이터 x 저장, insert data x
void insertBST(BinTree* bt, BTData x) {
	BinTree* p = bt;
	BinTree* parent = NULL;	
	
	// 삽입할 노드 탐색, searching nodes to insert
	while (p != NULL) {
		if (x == p->key)
			return;
		parent = p;
		if (x < p->key)
			p = p->left;
		else
			p = p->right;
	}

	// 삽입할 노드 생성, create node to insert
	BinTree* newNode = (BinTree*)malloc(sizeof(BinTree));
	newNode->key = x;
	newNode->left = NULL;
	newNode->right = NULL;

	// 삽입 노드 연결, connect insert node
	if (bt == NULL)
		bt = newNode;
	else if (x < parent->key)
		parent->left = newNode;
	else
		parent->right = newNode;
}

// 데이터 x 노드 삭제, delete data x node
void deleteBST(BinTree* bt, BTData x) {
	BinTree* p = bt;
	BinTree* parent = NULL;

	while (p != NULL && p->key != x) { //p가 NULL이 되거나 p의 key값이 x와 같아지면 삭제노드와 부모노드 탐색 성공
		parent = p; //루트노드부터 시작해서 부모로 바꿈
		if (x < parent->key) //x가 부모의 키값보다 작으면 왼쪽
			p = parent->left;
		else
			p = parent->right;//x가 부모의 키값보다 크면 오른쪽으로 p값을 설정해줌
	}//p값의 키 값이 x과 같아지면 반복문 탈출
		
	// 삭제할 노드가 없는 경우, if there are no nodes to delete
	if (p == NULL)
		return; //삭제 안함

	// CASE 1: 삭제할 노드의 차수가 0인 경우, CASE 1: if the node to be deleted has a degree of 0
	if (p->left == NULL && p->right == NULL) {
		if (parent->left = p)
			parent->left = NULL; //부모노드의 왼쪽에 있으면 부모노드의 왼쪽 링크필드를 NULL로
		else
			parent->right = NULL; //부모노드의 왼쪽에 있으면 부모노드의 오른쪽 링크필드를 NULL로
	}

	// CASE 2: 삭제할 노드의 차수가 1인 경우, CASE 2: if the node to be deleted has a degree of 1
	else if (p->left == NULL || p->right == NULL) {
		if (p->left != NULL) {
			if (parent->left == p) //부모의 왼쪽에 있는 것을 삭제할 시 삭제하는 것의 왼쪽에 있는 노드를 부모노드와 연결
				parent->left = p->left;
			else //부모노트의 오른쪽에 있는 것을 삭제할 시 삭제하는 것의 왼쪽에 있는 노드를 부모노드와 연결
				parent->right = p->left;
		}
		else {
			if (parent->left == p) //부모의 왼쪽에 있는 것을 삭제할 시 삭제하는 것의 오른쪽에 있는 노드를 부모노드와 연결
				parent->left = p->right;
			else //부모의 오른쪽에 있는 것을 삭제할 시 삭제하는 것의 오른쪽에 있는 노드를 부모노드와 연결
				parent->right = p->right;
		}
	}

	// CASE 3: 삭제할 노드의 차수가 2인 경우, CASE 3: if the node to be deleted has a degree of 2
	else if (p->left != NULL && p->right != NULL) {
		BinTree* temp = p->left;
		BinTree* temp_parent = p;

		//삭제하는 것의 왼쪽서브트리에서 후계자를 지정해야함
		while (temp->right != NULL) { //왼쪽에서 가장 큰 값을 설정해야 하므로 노드의 오른쪽을 없을 때 까지 따라감
			temp_parent = temp;
			temp = temp->right;
		}

		p->key = temp->key; //현재 노드의 키값을 후계자의 키값으로 변경
		deleteBST(p->left, temp->key); //왼쪽 서브트리에서 찾아낸 후계자를 이미 복사했기 때문에 원래 있는 노드는 삭제해야 하므로 한번 더 실행
	}

}	

