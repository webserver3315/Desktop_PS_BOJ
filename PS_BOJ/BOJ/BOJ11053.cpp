/*
���� �� �����ϴ� �κм���

�̰� �ø�� ����. 2�������� ���2�����̰�. �ٵ� 2�������� �Ȱ����� 1000���� 1000000���� ����ũ�Ⱑ ���� �þ��.
�װ� Ȥ�� ���� dp�� �ƴ϶� ������ ����ó�� Ǯ����ϴ°ǰ�;

�κм����� ������ �ʿ䰡 ���ٴ� ���� �����϶�.
*/

#include <iostream>

#define MAX 1005

using namespace std;


int N;
int arr[MAX], memo[MAX];

int dp(int n) {
	if (memo[n] != 0) {
		return memo[n];
	}
	for (int idx = n-1; idx >= 0; idx--) {
		if (arr[n] > arr[idx]) {
			memo[n] = dp(idx) + 1;
			break;
		}
	}
	return memo[n];
}

int dp2(int n) {
	if (!memo[n]) {
		return memo[n];
	}
	for (int maxmemoidx = n - 1; maxmemoidx >= 0; maxmemoidx--) {
		if (arr[n] > arr[maxmemoidx]) {
			memo[n] = dp(maxmemoidx) + 1;
			break;
		}
	}
	return memo[n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	memo[0] = 1;

	int max = 0;
	/*for (int i = 1; i < N; i++) {
		int tmp = dp(i);
		if (max < tmp)
			max = tmp;
	}*/
	cout << dp2(N-1) << endl;

	return 0;
}