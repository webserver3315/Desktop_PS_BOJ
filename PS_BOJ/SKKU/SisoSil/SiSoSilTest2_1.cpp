#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n;
int arr[1000][1000];

//홀수만 주어짐이 보장된다.

int main() {
	/*ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);*/

	scanf("%d", &n);
	for (int r = 0, c = n / 2, num = 1; num <= n * n; num++) {
		arr[r][c] = num;
		if (num % n==0) r++;
		else {
			r--; c++;
			if (r < 0) r = n - 1;
			if (c > (n - 1)) c = 0;
		}
	}
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			printf("% 4d", arr[r][c]);
		}
		printf("\n");
	}

	return 0;
}