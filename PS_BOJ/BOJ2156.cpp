/*
포도주 시식

이거 계단문제랑 동일한데? 단지 마지막 계단을 반드시 밟을 필요가 없을 뿐.
각 포도주마다 용량이 주어지고 3잔연속먹는건 불가능할 때, 최대점수를 구하라.

각 포도주까지의 최대용량을
<
<<
<<<
식으로 구한다.

그리고, 3잔 연속 먹는 것이 불가능하므로 계단문제마냥 크게 보면 된다

n번째 잔은 반드시 먹을 때, n까지 잔이 범위일 시 최댓값
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

/*본 점화식은 전혀 모순이 없는 듯 한데, 모든 테스트케이스를 통과하며 두 번 연속 안먹는 경우까지 고려되어있음에도 불구하고 오답이 뜬다. 왤까.*/
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