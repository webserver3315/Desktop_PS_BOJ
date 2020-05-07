/*
����1

���������� 100�� ����, �������ϴ� �ݾ��� 10000�� ����
memo[n]=dp[n-arr[n-1]]+dp[n-arr[n-2]]+dp[n-arr[n-3]]+dp[n-arr[n-4]]+...

���� 2,4���� �־����µ� 3�� ����°� �Ұ����ϴ�. �׷���, �׷� ���� �־����� �ʰ���? �ϴ´�?
�ƴ�, �׷� 0 �����ؾ���.

���� �� ��������� ������ ���� ���, ���� ��ȭ�Ŀ��� �ߺ��Ǵϱ� ��ġ�ؾ��ҵ��ѵ�

����, �ߺ��� ������ �־����ٸ� �װ� �� �ɷ�����;
*/

/*�� ���� Ǯ�̺��� �����ǵ�,
�ߺ��� ���� �� ������
Ű���带 n���� ����µ� ���� �� ���� �ʿ������� �������� ���س����� �Ǹ� �ߺ����̽��� ������ �� �ִ�.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10005
using namespace std;

int N, K;
vector<int> coin;
int memo[MAX];//i�� ����� ����� ��
bool visit[MAX];

int DP(int n) {
	if (visit[n]) {
		return memo[n];
	}
	for (int i = 0; n - coin[i] < 0; i++) {
		memo[n] += DP(n - coin[n - 1]);
	}
	visit[n] = true;
	return memo[n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		coin.push_back(tmp);
	}
	sort(coin.begin(), coin.end());
	coin.erase(unique(coin.begin(), coin.end()), coin.end());//https://sgc109.tistory.com/99

	for (int i = 0; i < N; i++) {
		memo[coin[i]] = coin[i];
		visit[i] = true;
	}

	cout << DP(K) << endl;

	return 0;
}