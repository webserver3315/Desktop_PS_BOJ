#include <stdio.h>
#include <stdlib.h>
typedef struct mynode {
	int data;
	struct mynode* left;
	struct mynode* right;
}Node;



int N, M;
Node* Tree;
int cnt;

//Tree tree;
//typedef struct mytree {
//	Node* root;
//}Tree;
//Tree* NewTree() {
//	Tree* ret = (Tree*)malloc(sizeof(Tree));
//	ret->root = NULL;
//	return ret;
//}

Node* NewNode(int data) {
	Node* nn = (Node*)malloc(sizeof(Node));
	nn->data = data;
	nn->left = NULL;
	nn->right = NULL;
	return nn;
}

Node* Search(Node* root, int val) {// Pre-order로 값이 val인 원소를 찾고 그 포인터를 반환하는 함수. 해당 원소가 없으면 NULL을 반환
	if (root->data == val) return root;
	Node* left = NULL; Node* right = NULL;
	if (root->left != NULL)
		left = Search(root->left, val);
	if (root->right != NULL)
		right = Search(root->right, val);

	if (left != NULL) return left;
	else return right;
}

Node* Insert(Node* root, int data) {
	int cond;
	if (root == NULL) {
		root = NewNode(data);
		return root;
	}
	Node* cur = root;
	while (1) {
		if (data >= cur->data) {
			if (cur->right == NULL) {
				cur->right = NewNode(data);
				return cur->right;
			}
			else cur = cur->right;
		}
		else {
			if (cur->left == NULL) {
				cur->left = NewNode(data);
				return cur->left;
			}
			else cur = cur->left;
		}
	}
}

Node* Delete(Node* root, int data) {
	Node* temp = root;
	Node* parent = temp;
	Node* target;

	while (temp->data != data) {
		parent = temp;
		if (temp->data <= data) temp = temp->right;
		else temp = temp->left;
	}
	target = temp;
	if (target->left == NULL && target->right == NULL) {//자식 없음
		if (target->data == parent->data)
			return NULL;
		if (parent->left != NULL && target->data == parent->left->data)
			parent->left = NULL;
		else
			parent->right = NULL;
		free(target);
	}
	else if (target->left != NULL && target->right != NULL) {//두 자식 모두 있음
		temp = target->right;
		while (temp->left != NULL) {
			temp = temp->left;
		}
		int num = temp->data;
		Delete(root, temp->data);
		target->data = num;
	}
	else {//하나만 있음
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
}

void postorder(Node* root) {
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->data);
	}
	printf("\n");
}

void preorder(Node* root) {
	if (root != NULL) {
		cnt++;
		preorder(root->left);
		preorder(root->right);
	}
}

int main() {
	scanf("%d", &N);

	int tmp;
	scanf("%d", &tmp);
	Tree = NewNode(tmp);

	for (int i = 1; i < N; i++) {
		int tmp;
		scanf("%d", &tmp);
		Insert(Tree, tmp);
	}

	//postorder(Tree);

	scanf("%d", &M);
	Node* location = Search(Tree, M);
	if (location == NULL) printf("-1\n");
	else {
		preorder(location);
		printf("%d\n", cnt - 1);
	}

	return 0;
}