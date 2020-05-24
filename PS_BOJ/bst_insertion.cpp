#include <stdio.h>
#include "printTree.c"

// printTree.c 에 정의된 "Tree" 구조체
// typedef struct BTreeNode {
//     int data;
//     struct BTreeNode * left;
//     struct BTreeNode * right;
// } Tree;

// 새로운 노드를 생성하는 함수
Tree* newNode(int data) {
	Tree* new = (Tree*)malloc(sizeof(Tree));
	new->data = data;
	new->left = NULL;
	new->right = NULL;
	return new;
}

// Tree에 원소 하나를 삽입하는 함수
// 삽입된 노드의 포인터를 반환함
Tree* insert(Tree* root, int data) {
	if (root == NULL) {
		root = newNode(data);
		return root;
	}
	Tree* it = root;
	while (1) {
		if (data >= it->data) {
			if (it->right == NULL) {
				it->right = newNode(data);
				return it->right;
			}
			else
				it = it->right;
		}
		else if (data < it->data) {
			if (it->left == NULL) {
				it->left = newNode(data);
				return it->left;
			}
			else
				it = it->left;
		}
	}
}

// Pre-order로 값이 val인 원소를 찾고 그 포인터를 반환하는 함수
// 해당 원소가 없으면 NULL을 반환
Tree* find(Tree* root, int val) {
	if (root->data == val)
		return root;

	Tree* left = NULL, * right = NULL;
	if (root->left != NULL)
		left = find(root->left, val);
	if (root->right != NULL)
		right = find(root->right, val);

	if (left != NULL) return left;
	else return right;
}

// Tree에 할당된 메모리를 초기화 하는 함수
void deleteTree(Tree* root) {
	Tree* left = root->left;
	Tree* right = root->right;
	free(root);
	if (left != NULL) deleteTree(left);
	if (right != NULL) deleteTree(right);
}

// BST 원소 입력 예시
int main() {
	Tree* root;
	int number;

	// Root Node 초기화
	scanf(" %d", &number);
	root = newNode(number);

	// printTree() 함수로 넷째자리 양수 및 셋째자리 음수 까지 출력 해볼수 있음
	printTree(root);

	while (1) {
		scanf(" %d", &number);
		insert(root, number);
		printTree(root);
	}


	deleteTree(root);
}