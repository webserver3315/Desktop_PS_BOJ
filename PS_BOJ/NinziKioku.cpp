#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int jmp, n;

typedef struct __node {
	int bango;
	struct __node* prev;
	struct __node* next;
}Dnode;

typedef struct {//더미노드 포인터= head, 머리노드포인터=head->next, 꼬리노드 포인터=head->prev
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