
/*
������

���� �� ���� ���� �� ���ٴ� ���ǿ���, �ִ밪

*/

#include <stdio.h>
#include <stdlib.h>

int wine[10004];/*0�ε����� ����д�.*/
int memo[10004];
int maxmemo, maxval;
int n;

/*
memo[n]��, �ִ��̸� n��° ������ ������ �Դ´ٰ� �����Ѵ�. �ִ��� max�� ���� �����Ѵ�.
memo[n]=memo[n-2]+n or memo[n-3]+2n-1
000000
110110
011011

__1011 - memo[n-3]+wine[n-1]+wine[n]
___101 - memo[n-2]+wine[n]

��, max���� ����

maxmemo���� ��ȯ�� max���� ũ�� maxmemo ������Ʈ
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

	/*3 �̻��̸�, Max�Լ��� �̿��ϵ��� �ؾ��Ѵ�.*/
	for (int i = 3; i <= n; i++) {
		memo[i] = Max(memo[i - 3] + wine[i - 1] + wine[i], memo[i - 2] + wine[i], memo[i - 1]);
		if (memo[i] > maxval) {
			 printf("%d��° ������ ��Ÿ������ �� �ְ�:%d\n",i,memo[i]);
			maxval = memo[i];
		}
		// printmemo();
	}

	if (n >= 3)
		printf("%d\n", maxval);
}
