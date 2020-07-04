/*
���� �� �����ϴ� �κм���

���̵�� ����:https://kimtruth.github.io/2018/02/24/acmicpc-11053/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
10 20 30 13 9 14 15 16 25 35 3
1  2  3  3  3  3  4  5  6  7  7
1  2  3  2  1  3  4  5  6  7  1 >>> �̰� memo������.
�ڽź��� ������ ���� ����� ���� ��, �� �ִ񰪿� +1?

10 20 10 30 20 50
1  2  2  3  3  4
1  2  1  3  2  4
*/

int A[1005];/*���� �����*/
int memo[1005];/*�ε���0�� ����, i��° �ױ����� �κм����� �ִ����(i��° ���� �ݵ�� ����)*/
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
	for (int i = 2; i <= n; i++) {/*n������ i�� ���ؼ�*/
		int max = 0;
		for (int j = i; j >= 1; j--) {
			if (A[i] > A[j] && max < memo[j]) {/*i���� �����鼭, max������ ����� memo���� ũ��*/
				max = memo[j];/*max�� ������Ʈ*/
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