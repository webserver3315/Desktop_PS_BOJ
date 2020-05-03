/*
���� 0

5����
*/

#include <iostream>
#define MAX 13
using namespace std;

int N, K;
int coin[MAX];

/*��������� ������ �־�����. ��, �׸����� Ǯ�̰� ���밡���� ������ ���������̴�.*/
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