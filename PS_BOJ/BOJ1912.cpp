/*
������
*/

#include <iostream>

using namespace std;
#define MAX 100005
int N;

/*n���� ���� �������� �ִ��� ����ؾ��ϸ�, ���� ������ 10���� �����̰� ���� ũ��� ���� ���� 1000 ���ϴ�.
<
<<
<<<
<<<<
�̷������� �˻��ϵ��� �ϸ� �� �� �ϴ�.
dp�迭�� �ش� ������ �������� 0�� �ε������� ���������� ���� �� ���� �� �ִ� �ִ����� �ǹ�.

dp(1)==memo[1]==arr[1];
int nearest=n;
while(arr[nearest]<0)
	nearest--
dp(n)=arr[n]+dp(nearest)


f(n)=f(
*/

int arr[MAX];
int memo[MAX];
bool visited[MAX];

/*�迭�� ��� ���Ұ� �������? �װ͵� ��ġ�������*/
int dp(int n) {
	if (visited[n]) {
		return memo[n];
	}
	if (memo[n - 1] <= 0) {
		memo[n] = arr[n];
		visited[n] = true;
		return memo[n];
	}
	else {
		memo[n] = arr[n] + memo[n - 1];
		visited[n] = true;
		return memo[n];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	visited[0] = true;
	memo[0] = arr[0];

	for (int i = 0; i < N; i++) {
		dp(i);
	}

	int max = -MAX;
	for (int i = 0; i < N; i++) {
		if (max < memo[i])
			max = memo[i];
	}
	cout << max << endl;

	return 0;
}