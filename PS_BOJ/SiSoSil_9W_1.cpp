#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node_struct {
	char name;
	int number;
	struct node_struct* next;
} Node;

typedef struct head_struct {
	Node* first;
	Node* last;
} Head;

int n, m;

Head* create_head() {
	Head* new_head = (Head*)malloc(sizeof(Head));
	new_head->first = NULL;
	new_head->last = NULL;
	return new_head;
}

Node* create_node(char name, int number) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->name = name;
	new_node->number = number;
	new_node->next = NULL;
	return new_node;
}

void add(Head* head, char name, int number) {
	if (head->last == NULL) {
		head->last = create_node(name, number);
		head->first = head->last;
	}
	else {
		Node* p = head->last;
		p->next = create_node(name, number);
		head->last = p->next;
	}
}

Node* find(Head* head, char name) {
	Node* cur = head->first;
	while (cur != NULL) {
		if (cur->name == name) {
			return cur;
		}
		else cur = cur->next;
	}
	return NULL;
}

Node* removing(Head* head, char name) {//이름 stdio와 충돌해서 정정
	if (head->first == NULL) {//empty
		return NULL;
	}
	Node* cur = head->first;
	if (cur->name == name) {//첫 원소 삭제시
		/*char check = cur->name;
		printf("%c 삭제\n", check);*/
		head->first = cur->next;
		cur->next = cur->next->next;
		free(cur);
		return NULL;
	}	
	while (cur->next != NULL) {
		if (cur->next->name == name) {	
			Node* nxtnxt = cur->next->next;
			/*char check = cur->next->name;
			printf("%c 삭제\n", check);*/
			free(cur->next);
			cur->next = nxtnxt;
			return NULL;
		}
		else cur = cur->next;
	}
	return NULL;
}

int main() {
	Head* head = create_head();
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char a; int b;
		scanf("\n%c %d", &a, &b);
		add(head, a, b);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		char ken;
		scanf("\n%c", &ken);
		removing(head, ken);
	}
	Node* cur = head->first;
	while (cur != NULL) {
		printf("%c %d\n", cur->name, cur->number);
		cur = cur->next;
	}
	return 0;
}