/*
가장 긴 증가하는 부분수열
*/

#include <iostream>
#define MAX 1005
using namespace std;

int n;
int memo[MAX];//1번인덱스부터 시작
int arr[MAX];

/*

*/
int dp(int x) {
	if (memo[x])
		return memo[x];
	if(arr[x]>arr[)
	return memo[x];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	memo[1] = 1;

	int max = 0;
	for (int i = 1; i <= n; i++) {
		int tmp = dp(i);
		if (max < tmp)
			max = tmp;
	}
	cout << max << endl;

	return 0;
}