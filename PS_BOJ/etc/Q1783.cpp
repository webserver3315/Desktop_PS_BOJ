/*
���� ����Ʈ
*/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, m, cnt;
int KnigntMove_X[4] = { 1,2,2,1 };
int KnightMove_Y[4] = { 2,1,-1,-2 };

int KnightMove(int x, int y) {
	cnt = 0;
	if (m >= 6 && n >= 3) {
		cnt += 4;
		m -= 6;

		int katamichiNodeKazu = (n - 1) / 2;/*���� �̵��ϴ� ��*/
		int haba = (n - 1) / 2;/*���� ��*/
		if (m < haba) {/*���� �� ���� �ȵ� ��*/
			cnt += m;
		}
		else {/*�� �ּ�1���� ������*/
			cnt += (m / haba) * katamichiNodeKazu;
			cnt += m % haba;
		}
		
		return 0;
	}
	else if (m < 6 && n >= 3) {
		if (m > 3)
			cnt = 4;
		else if (m == 3)
			cnt = 3;
		else if (m == 2)
			cnt = 2;
		else
			cnt = 1;
	}
	else {/*x�� 2ĭ�� �̵��� ���� ����*/
		if (n == 1) {
			cnt = 1;
			return 0;
		}
		if (n == 2) {/*n==2 or 3*/
			cnt = (m + 1) / 2;
			if (cnt > 4)
				cnt = 4;
		}
	}
}

int main(){
	while (scanf("%d %d", &n, &m) != EOF) {
		KnightMove(0, 0);
		printf("%d\n", cnt);
	}
	return 0;
}