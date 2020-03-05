#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAX (int)1e4+1
#define INF 987654321
using namespace std;

int N, K;
vector<int> coin;
int memo[MAX];

/*
동전이 오름차순으로 a1원부터 an원종류까지 있다고 하면,
an까지 표현할 수 있는 최소가짓수를 유지하면 된다.
an 초과시, an으로 나눈 몫을 더하고.
*/

int DP(int n) {
	int& ret = memo[n];
	if (ret != INF)
		return ret;
	
	for (int co : coin) {
		int nokori = n - co;
		if (nokori < 1)
			continue;

		int kazu = DP(nokori) + 1;
		if (kazu < ret) {
			ret = kazu;
		}
	}
	return ret;
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//memset(memo, -1, sizeof(memo));

	cin >> N >> K;
	for (int i = 0; i <= K; i++) {
		memo[i] = INF;
	}
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (tmp < MAX) {
			coin.push_back(tmp);
		}
	}
	sort(coin.begin(), coin.end(), greater<int>());
	int smallest = coin.back();
	int largest = coin.front();
	for (int co : coin) {
		memo[co] = 1;
	}
	int ans = K / largest;
	K %= largest;

	DP(15);

	ans += DP(K);
	cout << ans << endl;

	return 0;
}