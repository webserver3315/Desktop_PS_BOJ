/*
동전 0

5분컷
*/

#include <iostream>
#define MAX 13
using namespace std;

int N, K;
int coin[MAX];

/*배수관계인 동전만 주어진다. 즉, 그리디한 풀이가 적용가능한 유형의 동전문제이다.*/
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> coin[i];
	}

	int cnt = 0;
	for (int i = N; i > 0; i--) {
		cnt += K / coin[i];
		K %= coin[i];
	}
	cout << cnt << endl;

	return 0;
}