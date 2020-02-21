#include <iostream>
#include <algorithm>
using namespace std;

int tiny[9];
bool visit[9];

void bubblesort(int* arr, int length) {
	for (int i = 0; i < length - 1; i++) {
		for (int j = 0; j < length - i; j++) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	return;
}

void printVisitedAll() {
	for (int i = 0; i < 9; i++) {
		if (visit[i] == true)
			cout << tiny[i] << endl;
	}
	return;
}

void DFS(int sum, int depth, int cursor) {
	if (depth == 7) {
		if (sum == 100) {
			printVisitedAll();
			exit(0);
		}
		else {
			return;
		}
	}
	else if (100 <= sum) {
		return;
	}
	else {
		for (int i = cursor; i < 9; i++) {
			if (visit[i] == true)
				continue;
			else {
				visit[i] = true;
				DFS(sum + tiny[i], depth + 1, i);
				visit[i] = false;
			}
		}
	}
	return;
}

int main() {
	for (int i = 0; i < 9; i++) {
		cin >> tiny[i];
	}

	/*
	일단 정렬박고
	visit 체크 해가면서 7개 합이 100 될때까지 DFS돌린다. 아무답이나 ㄱㄴ하니.
	*/
	sort(tiny, tiny + 9);
	DFS(0, 0, 0);

	return 0;
}