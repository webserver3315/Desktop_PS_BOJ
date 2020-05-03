/*
Knights
*/

#include <iostream>
#include <cstdio>
using namespace std;

int n;

int W_First(int n) {
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			printf("W");
		}
		else {
			printf("B");
		}
	}
	printf("\n");
	return 0;
}

int B_First(int n) {
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			printf("B");
		}
		else {
			printf("W");
		}
	}
	printf("\n");
	return 0;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {/*nÀÌ È¦¼ö¶ó¸é*/
		if (i % 2 == 1) {
			W_First(n);
		}
		else {
			B_First(n);
		}
	}
	return 0;
}