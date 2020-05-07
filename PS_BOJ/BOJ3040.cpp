#include <iostream>
#define swap(type, a, b) do{type tmp=a;a=b;b=tmp;}while(0);
using namespace std;

int tiny[9];
bool visited[9];
int n;

void MyBubbleSort(int* arr, int len) {
	for (int i = len - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(int, arr[j], arr[j + 1]);
			}
		}
	}
	return;
}

void printVisited() {
	for (int i = 0; i < 9; i++) {
		if (visited[i] == true)
			cout << tiny[i] << endl;
	}
	return;
}

void DFS(int sum, int depth, int cursor) {
	if (depth == 7) {
		if (sum == 100) {
			printVisited();
			exit(0);
		}
		return;
	}
	else if (sum == 100) {
		return;
	}
	else {
		for (int i = cursor; i < 9; i++) {
			if (visited[i] == true) {
				continue;
			}
			else {
				visited[i] = true;
				DFS(sum + tiny[i], depth + 1, i);
				visited[i] = false;
			}
		}
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		cin >> tiny[i];
	}
	MyBubbleSort(tiny, 9);
	DFS(0, 0, 0);
	return 0;
}