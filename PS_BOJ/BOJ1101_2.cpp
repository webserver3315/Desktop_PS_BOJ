/*
https://www.acmicpc.net/source/17053114
내 방식도 맞지만,
아래처럼
좌에서 밀고 우에서 당기는 형태로
대칭이동을 구현해도 된다! 참신하고 깔끔하다.
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