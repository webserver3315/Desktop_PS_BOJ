/*
가장 긴 증가하는 부분수열

아이디어 참조:https://kimtruth.github.io/2018/02/24/acmicpc-11053/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
10 20 30 13 9 14 15 16 25 35 3
1  2  3  3  3  3  4  5  6  7  7
1  2  3  2  1  3  4  5  6  7  1 >>> 이걸 memo값으로.
자신보다 작지만 가장 가까운 수의 값, 즉 최댓값에 +1?

10 20 10 30 20 50
1  2  2  3  3  4
1  2  1  3  2  4
*/

int A[1005];/*수열 저장용*/
int memo[1005];/*인덱스0은 공란, i번째 항까지의 부분수열의 최대길이(i번째 항은 반드시 포함)*/
int n;

int printmemo() {
	for (int i = 1; i <= n; i++) {
		printf("%d ", memo[i]);
	}
	printf("\n");
}

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
	}

	memo[1] = 1;
	for (int i = 2; i <= n; i++) {/*n까지의 i에 대해서*/
		int max = 0;
		for (int j = i; j >= 1; j--) {
			if (A[i] > A[j] && max < memo[j]) {/*i보다 작으면서, max값보다 저장된 memo값이 크면*/
				max = memo[j];/*max값 업데이트*/
			}
		}
		memo[i] = max + 1;
		// printmemo();
	}

	int realmax = 0;
	for (int i = 1; i <= n; i++) {
		if (realmax < memo[i])
			realmax = memo[i];
	}
	printf("%d\n", realmax);
}