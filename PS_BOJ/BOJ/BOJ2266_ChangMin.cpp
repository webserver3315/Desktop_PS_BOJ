#include <stdio.h>

int main() {

	int loop;

	scanf("%d", &loop);

	for (int j = 0; j < loop; j++) {

		int n, k;
		int flag = 1;
		int answer = 0;

		scanf("%d %d", &n, &k);

		if (n == 1) {
			answer = k;
		}

		else {
			while (n - 2) {
				if (k == 1) {
					flag = 0;
					break;
				}
				else {
					n--;
					k /= 2;
					answer++;
				}
			}
			if (flag == 1) {
				for (int i = 1; i < 500; i++) {
					int gold = i * i + i;
					if (gold >= k * 2) break;
					else answer++;
				}
			}
		}

		printf("%d\n", answer+1);

	}
}