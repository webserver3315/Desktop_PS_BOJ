#include <stdio.h>
#include <stdlib.h>
#define int long long
using namespace std;

int n;
int arr[1001][1001];

void make() {
	int cnt = 1;
	int r = 0; int c = n / 2;
	while (cnt <= n * n) {
		//printf("%lld %lld¿¡ %lld »ðÀÔ \n", r, c, cnt);
		arr[r][c] = cnt;
		if (cnt % n) {
			r--; c--;
			if (r < 0) r = n - 1;
			if (c < 0) c = n - 1;
		}
		else {
			r++;
		}
		cnt++;
	}
}

signed main() {
	scanf("%lld", &n);
	make();
	for (int r = 0; r < n; r++) {
		for (int c = n - 1; c >= 0; c--) {
			printf("%4lld ", arr[r][c]);
		}
		printf("\n");
	}

	return 0;
}