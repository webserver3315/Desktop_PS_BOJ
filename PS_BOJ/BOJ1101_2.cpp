/*
https://www.acmicpc.net/source/17053114
�� ��ĵ� ������,
�Ʒ�ó��
�¿��� �а� �쿡�� ���� ���·�
��Ī�̵��� �����ص� �ȴ�! �����ϰ� ����ϴ�.
*/

#include <stdio.h>
int main() {
	int x, y, k = 0;
	int n, cnt = 0;

	scanf("%d", &n);
	while (n--) {
		scanf("%d %d", &x, &y);

		cnt = 0;
		k = 0;
		while (x < y) {
			k++;
			x += k;
			cnt++;
			if (x < y) {
				y -= k;
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}

	return 0;
}