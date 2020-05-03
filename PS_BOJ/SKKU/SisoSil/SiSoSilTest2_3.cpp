#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef struct __node {
	int val;
	struct __node* next;
	struct __node* prev;
}node;

int jmp, n;
node curnode;
node arr[6000];
int arrsize;

int kill() {
	int jmpcnt = jmp;
	//node curnode = arr[cur];
	while (--jmpcnt) {
		curnode = *curnode.next;
		//printf("%d로 점프\n", curnode.val);
	}
	(*curnode.prev).next = curnode.next;
	(*curnode.next).prev = curnode.prev;
	arrsize--;
	int ret = curnode.val;
	//printf("%d 사살\n", curnode.val);
	curnode = *curnode.next;
	return ret;
}

int main() {
	scanf("%d %d", &n, &jmp);
	arrsize = n;
	for (int i = 0; i < n; i++) {
		//scanf("%d", &arr[i].val);
		arr[i].val = i + 1;
	}
	for (int i = 1; i < n - 1; i++) {
		arr[i].prev = &arr[i - 1];
		arr[i].next = &arr[i + 1];
	}
	arr[0].prev = &arr[n - 1]; arr[0].next = &arr[1];
	arr[n - 1].prev = &arr[n - 2]; arr[n - 1].next = &arr[0];

	curnode = arr[0];
	for (int i = 0; i < n - 1; i++) {
		//printf("killed %d\n", kill());
		printf("%d ", kill());
	}
	printf("\n%d ", kill());

	return 0;
}