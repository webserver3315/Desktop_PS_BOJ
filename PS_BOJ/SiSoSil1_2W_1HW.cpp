#include <bits/stdc++.h>
using namespace std;

int arr[3];

int lcm(int a, int b) {
	if (a < b) {
		int tmp = b;  b = a; a = tmp;
	}
	while (a % b != 0) {
		a += a;
	}
	return a;
}

int main() {
	for (int i = 0; i < 3; i++) {
		cin >> arr[i];
	}
	cout << "LCM = " << lcm(lcm(arr[0], arr[1]), arr[2]) << endl;

	return 0;
}