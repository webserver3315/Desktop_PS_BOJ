#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int jmp, n;

typedef struct __node {
	int bango;
	struct __node* prev;
	struct __node* next;
}Dnode;

typedef struct {//���̳�� ������= head, �Ӹ����������=head->next, ������� ������=head->prev
	Dnode* head;
	Dnode* crnt;
	int size;
}List;

void AppendNode(List* list, int val) {

}
void DeleteNode(List* list, int idx) {

}

int main() {
	scanf("%d %d", &n, &jmp);
	List list;

	return 0;
}