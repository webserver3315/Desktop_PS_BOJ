/*
ī�� �����ϱ�
*/

#include <iostream>

using namespace std;

int takaist[1005];//i�� ��µ� �ʿ��� �ְ��� ����
int cardprice[1005];//1����
int N;

int dp(int n) {
	if (takaist[n] != 0) {
		return takaist[n];
	}
	takaist[n] = cardprice[n];
	for (int i = 1; i <= n / 2; i++) {
		if (takaist[n] < dp(n - i) + dp(i))
			takaist[n] = dp(n-i) + dp(i);
	}
	return takaist[n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++){
		cin >> cardprice[i];
	}

	cout << dp(N) << endl;

	return 0;
}