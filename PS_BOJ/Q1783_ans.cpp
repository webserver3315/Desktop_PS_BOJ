#include <iostream>
using namespace std;

int main() {
	int N, M, ans;
	while (scanf("%d%d", &N, &M)!=EOF) {
		if (N == 1) ans = 1; //1
		else if (N == 2) ans = M >= 9 ? 4 : (M + 1) / 2; //2
		//2���� ��� ans = min(4, (M+1)/2); �ε� ǥ�� ����
		else if (N >= 3) { //3
			if (M <= 6) ans = M <= 4 ? M : 4;
			else ans = M - 2;
		}
		printf("%d\n", ans);
	}
	return 0;
}