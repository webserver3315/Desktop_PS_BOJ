#include <stdio.h>
#include "printTree.c"

// printTree.c �� ���ǵ� "Tree" ����ü
// typedef struct BTreeNode {
//     int data;
//     struct BTreeNode * left;
//     struct BTreeNode * right;
// } Tree;

// ���ο� ��带 �����ϴ� �Լ�
Tree* newNode(int data) {
	Tree* new = (Tree*)malloc(sizeof(Tree));
	new->data = data;
	new->left = NULL;
	new->right = NULL;
	return new;
}

// Tree�� ���� �ϳ��� �����ϴ� �Լ�
// ���Ե� ����� �����͸� ��ȯ��
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

// Pre-order�� ���� val�� ���Ҹ� ã�� �� �����͸� ��ȯ�ϴ� �Լ�
// �ش� ���Ұ� ������ NULL�� ��ȯ
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

// Tree�� �Ҵ�� �޸𸮸� �ʱ�ȭ �ϴ� �Լ�
void deleteTree(Tree* root) {
	Tree* left = root->left;
	Tree* right = root->right;
	free(root);
	if (left != NULL) deleteTree(left);
	if (right != NULL) deleteTree(right);
}

// BST ���� �Է� ����
int main() {
	Tree* root;
	int number;

	// Root Node �ʱ�ȭ
	scanf(" %d", &number);
	root = newNode(number);

	// printTree() �Լ��� ��°�ڸ� ��� �� ��°�ڸ� ���� ���� ��� �غ��� ����
	printTree(root);

	while (1) {
		scanf(" %d", &number);
		insert(root, number);
		printTree(root);
	}


	deleteTree(root);
}