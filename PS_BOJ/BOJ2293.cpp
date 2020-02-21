/*
동전1

동전종류는 100개 이하, 만들어야하는 금액은 10000원 이하
memo[n]=dp[n-arr[n-1]]+dp[n-arr[n-2]]+dp[n-arr[n-3]]+dp[n-arr[n-4]]+...

만일 2,4원이 주어지는데 3원 만드는건 불가능하다. 그러나, 그런 예는 주어지지 않겠지? 믿는다?
아니, 그럼 0 리턴해야지.

동전 중 배수관계인 동전이 있을 경우, 위의 점화식에서 중복되니까 조치해야할듯한데

또한, 중복된 동전이 주어진다면 그건 또 걸러야지;
*/

/*내 과거 풀이보고 느낀건데,
중복은 있을 수 있지만
키워드를 n원을 만드는데 동전 몇 개가 필요한지를 초점으로 더해나가게 되면 중복케이스를 예방할 수 있다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10005
using namespace std;

int N, K;
vector<int> coin;
int memo[MAX];//i원 만드는 방법의 수
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