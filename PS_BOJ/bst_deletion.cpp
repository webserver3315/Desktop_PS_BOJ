#include <stdio.h>
#include "printTree.cpp"

Tree* deletion(Tree* root, int data) {

	Tree* temp = root;
	Tree* parent = temp;
	Tree* target;

	while (temp->data != data) {

		parent = temp;

		if (temp->data <= data)
			temp = temp->right;
		else
			temp = temp->left;
	}
	target = temp;

	if (target->left == NULL && target->right == NULL) {

		if (target->data == parent->data)
			return NULL;

		if (parent->left != NULL && target->data == parent->left->data)
			parent->left = NULL;
		else
			parent->right = NULL;

		free(target);
	}

	else if (target->left != NULL && target->right != NULL) {
		temp = target->right;
		//parent = target;

		while (temp->left != NULL) {
			//parent = temp;
			temp = temp->left;
		}

		int num = temp->data;
		deletion(root, temp->data);
		target->data = num;

	}

	else {
		if (target->data == parent->data) {

			if (target->right != NULL)
				return target->right;
			else if (target->left != NULL)
				return target->left;

		}


		if (target->right != NULL) {
			if (parent->left != NULL && target->data == parent->left->data)
				parent->left = target->right;
			else if (parent->right != NULL && target->data == parent->right->data)
				parent->right = target->right;
		}
		if (target->left != NULL) {
			if (parent->left != NULL && target->data == parent->left->data)
				parent->left = target->left;
			else if (parent->right != NULL && target->data == parent->right->data)
				parent->right = target->left;
		}
		free(target);

	}

	return root;

}

Tree* newNode(int data) {
	Tree* new = (Tree*)malloc(sizeof(Tree));
	new->data = data;
	new->left = NULL;
	new->right = NULL;
	return new;
}

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

// Tree�� �Ҵ�� �޸𸮸� �ʱ�ȭ �ϴ� �Լ� 
void deleteTree(Tree* root) {
	Tree* left = root->left;
	Tree* right = root->right;
	free(root);
	if (left != NULL) deleteTree(left);
	if (right != NULL) deleteTree(right);
}

// BST ��� ���� ����
int main() {

	Tree* root;
	int number;

	root = newNode(10);
	insert(root, 5);
	insert(root, 15);
	insert(root, 3);
	insert(root, 8);
	insert(root, 12);
	insert(root, 2);
	insert(root, 7);
	insert(root, 9);
	insert(root, 18);
	insert(root, 19);
	insert(root, 13);

	printTree(root);

	while (1) {

		scanf("%d", &number);
		root = deletion(root, number);
		printTree(root);

	}

	deleteTree(root);

}

