#include <bits/stdc++.h>
using namespace std;

int printbinary(int n) {
	if (n == 0)
		return 0;
	printbinary(n / 2);
	if (n % 2)
		cout << 1;
	else
		cout << 0;
	return 0;
}

int main() {
	int n;
	while (cin >> n) {
		printbinary(n);
		cout << endl;
	}

	return 0;
}