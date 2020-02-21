/*
1,2,3 ¥ı«œ±‚
*/

#include <iostream>

using namespace std;

int func(int n) {
	if (n <= 0) {
		return 0;
	}
	else if (1 == n) {
		return 1;
	}
	else if (n == 2) {
		return 2;
	}
	else if (n == 3) {
		return 4;
	}
	else {
		return func(n - 1) + func(n - 2) + func(n - 3);
	}
}

int main() {
	int loop;
	scanf("%d", &loop);
	while (loop--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", func(n));
	}
	return 0;
}