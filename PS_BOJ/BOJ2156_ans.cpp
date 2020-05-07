
/*
포도주

연속 세 잔을 마실 수 없다는 조건에서, 최대값

*/

#include <stdio.h>
#include <stdlib.h>

int wine[10004];/*0인덱스는 비워둔다.*/
int memo[10004];
int maxmemo, maxval;
int n;

/*
memo[n]시, 최댓값이며 n번째 와인은 무조건 먹는다고 가정한다. 최댓값은 max로 따로 유지한다.
memo[n]=memo[n-2]+n or memo[n-3]+2n-1
000000
110110
011011

__1011 - memo[n-3]+wine[n-1]+wine[n]
___101 - memo[n-2]+wine[n]

중, max값을 선택

maxmemo보다 반환된 max값이 크면 maxmemo 업데이트
*/

int Max(int a, int b, int c) {
	if (b > c) {
		if (a > b)
			return a;
		return b;
	}
	if (c > a)
		return c;
	return a;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &wine[i]);
	}

	memo[0] = 0;
	memo[1] = wine[1];
	memo[2] = wine[2] + wine[1];
	if (1 == n) {
		printf("%d\n", memo[1]);
		return 0;
	}
	if (2 == n) {
		printf("%d\n", memo[2]);
		return 0;
	}

	/*3 이상이면, Max함수를 이용하도록 해야한다.*/
	for (int i = 3; i <= n; i++) {
		memo[i] = Max(memo[i - 3] + wine[i - 1] + wine[i], memo[i - 2] + wine[i], memo[i - 1]);
		if (memo[i] > maxval) {
			 printf("%d번째 와인을 막타때렸을 때 최고값:%d\n",i,memo[i]);
			maxval = memo[i];
		}
		// printmemo();
	}

	if (n >= 3)
		printf("%d\n", maxval);
}
