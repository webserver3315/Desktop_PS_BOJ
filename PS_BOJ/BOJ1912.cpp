/*
연속합
*/

#include <iostream>

using namespace std;
#define MAX 100005
int N;

/*n개의 수의 연속합으 최댓값을 출력해야하며, 수의 개수는 10만개 이하이고 수의 크기는 각각 절댓값 1000 이하다.
<
<<
<<<
<<<<
이런식으로 검사하도록 하면 될 듯 하다.
dp배열엔 해당 수부터 역순으로 0번 인덱스까지 연속적으로 더할 때 얻을 수 있는 최대합을 의미.

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

/*배열의 모든 원소가 음수라면? 그것도 조치해줘야지*/
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