#include <stdio.h>
#include <stdlib.h>

int arr[200000];
int n, m, v;
int question;
int fuc(int x, int y);

int main() {

	scanf("%d", &n);
	scanf("%d", &m);
	scanf("%d", &v);


	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}


	for (int i = 0; i < m; i++) {
		scanf("%d", &question);
		printf("%d\n", arr[fuc(question, v)]);
	}

	return 0;
}

int fuc(int x, int y) {
	if (n > question) {
		return question;
	}
	else {
		return (question - (v - 1)) % (n - v + 1) + (v - 1);
	}
}