#include <iostream>
using namespace std;

int n;
int tiny[1000];

void bubblesort(int* arr, int length) {//이거 불량함수임.
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

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tiny[i];
		//cin >> tiny[i];
		if (i == 500) {
			cout << "도달" << endl;
		}
		if (i == 900) {
			cout << "도달" << endl;
		}
		if (i == 999) {
			cout << "도달" << endl;
		}
	}
	bubblesort2(tiny, n);
	for (int i = 0; i < n; i++) {
		cout << tiny[i] << endl;
	}

	return 0;
}