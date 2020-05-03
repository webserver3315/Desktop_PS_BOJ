/*
������ �ý�

�̰� ��ܹ����� �����ѵ�? ���� ������ ����� �ݵ�� ���� �ʿ䰡 ���� ��.
�� �����ָ��� �뷮�� �־����� 3�ܿ��ӸԴ°� �Ұ����� ��, �ִ������� ���϶�.

�� �����ֱ����� �ִ�뷮��
<
<<
<<<
������ ���Ѵ�.

�׸���, 3�� ���� �Դ� ���� �Ұ����ϹǷ� ��ܹ������� ũ�� ���� �ȴ�

n��° ���� �ݵ�� ���� ��, n���� ���� ������ �� �ִ�
memo[n] = max(dp(n - 4) + max(arr[n - 1], arr[n - 2]), dp(n - 3) + arr[n - 1]) + arr[n];
*/

#include <stdio.h>
#include <iostream>
#include <climits>
#include <algorithm>
#define MAX 10005
using namespace std;

int N;
int arr[MAX];
int memo[MAX];
bool visit[MAX];

/*�� ��ȭ���� ���� ����� ���� �� �ѵ�, ��� �׽�Ʈ���̽��� ����ϸ� �� �� ���� �ȸԴ� ������ ����Ǿ��������� �ұ��ϰ� ������ ���. �ͱ�.*/
int dp(int n) {
	/*if (n == 7)
		getchar();*/
	if (n < 0)
		return 0;
	if (visit[n]) {
		return memo[n];
	}
	visit[n] = true;
	memo[n] = max(dp(n - 4) + max(arr[n - 1], arr[n - 2]), dp(n - 3) + arr[n - 1]) + arr[n];
	return memo[n];
}

int dp2(int n) {
	if (n < 0)
		return 0;
	if (visit[n]) {
		return memo[n];
	}
	visit[n] = true;
	memo[n] = max(max(dp(n - 3) + arr[n - 1], dp(n - 2)) + arr[n], dp(n - 1));
	return memo[n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	visit[0] = true;
	visit[1] = true; memo[1] = arr[1];
	visit[2] = true; memo[2] = arr[1] + arr[2];
	//visit[2] = true; memo[2] = arr[2];
	visit[3] = true; memo[3] = max(arr[1], arr[2]) + arr[3];
	visit[4] = true; memo[4] = max(arr[1] + arr[2], arr[1] + arr[3]) + arr[4];

	int max = -INT_MAX;
	for (int i = 1; i <= N; i++) {
		int tmp = dp(i);
		cout << "arr[" << i << "] is " << arr[i] << " dp(" << i << ") is " << tmp << endl;
		if (max < tmp)
			max = tmp;
	}

	/*for (int i = 0; i <= N; i++) {
		cout << memo[i] << ' ';
	}
	cout << endl;*/

	cout << max << endl;

	return 0;
}