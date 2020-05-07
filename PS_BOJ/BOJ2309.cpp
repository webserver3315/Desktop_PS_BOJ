#include <iostream>
using namespace std;

int tiny[9];
bool visit[9];

void bubblesort(int* arr, int length) {//�ҷ��Լ�
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

void bubblesort2(int* arr, int length) {
	for (int i = length - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	return;
}

void bubblesort3(int* arr, int length) {//�ҷ��Լ� ����_fail
	for (int i = 1; i < length - 1; i++) {
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

void bubblesort4(int* arr, int length) {//�ҷ��Լ� ������ ����_Success
	for (int i = 1; i <= length - 1; i++) {
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
	�ϴ� ���Ĺڰ�
	visit üũ �ذ��鼭 7�� ���� 100 �ɶ����� DFS������. �ƹ����̳� �����ϴ�.
	*/
	bubblesort4(tiny, 9);
	DFS(0, 0, 0);

	return 0;
}