#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

const int WMAX = 5e5;
int dp[2][WMAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N; cin >> N;
	vector<pll> v(N);
	for (int i = 0; i < N; i++) cin >> v[i].first >> v[i].second;

	/*
	(거북이 무게 + 버틸 수 있는 무게) 기준 오름차순 정렬
	* 가정 : 거북이의 무게를 Wi, 버틸 수 있는 무게를 Di라고 할 때 (Wi + Di)가 큰 거북이가 아래에 쌓았을 때 답을 구할 수 있다.
	* 증명 :
	귀류법을 이용한다.
	(Wi + Di)가 더 큰 거북이 A가 더 작은 거북이 B위에 올라간 형태의 답이 존재한다고 가정하자. (반대 상황 가정)
	식으로 표현하면 (D_A + W_A > D_B + W_B)가 성립한다. (변형해서 D_A > D_B + W_B - W_A로 보자.)
	이 때, A위에 쌓인 거북이의 무게의 합을 X라고 하면, X + W_A <= D_B가 성립해야 한다.
	따라서 D_A > D_B + W_B - W_A >= (X + W_A) + W_B - W_A = X + W_B이므로, D_A > X + W_B라는 결론을 얻는다.
	A와 B의 위치를 바꿔도 항상 답이 성립하기 때문에 (Wi + Di)가 큰 순서대로 쌓았을 때 최적해를 구하지 못하는 경우는 없다.
	*/
	sort(v.begin(), v.end(), [](const pll& a, const pll& b) {
		if (a.second == b.second) return a.first > b.first;
		return a.second > b.second;
		});

	/*
	* 부분문제 : dp[i][j] : 거북이를 처음부터 i번째까지 검사했고, 버틸 수 있는 무게가 j인 상태에서의 최대 마리수(i는 1부터 시작)
	* 기저사례 : dp[0][any] = 0, 아직 검사를 안한 시점에서 최대 마리수는 항상 0
	* 점화식 : dp[i][j] = max(dp[i-1][j], dp[i-1][j+wi] + 1), j <= di
	dp[i-1][j]는 i번째 거북이를 추가하지 않는 경우, dp[i-1][j+wi] + 1는 i번째 거북이를 추가하는 경우이다.

	걱정되는 점 :
	1. 시간복잡도가 O(NW), W는 최대 무게 이다. 최대 무게가 주어지지 않았기 때문에, 10초 안에 돌아갈정도의 최대 무게로 설정했다.
	(WMAX = 5e5)
	2. 만약 (Wi + Di), 즉 ai bi의 입력에서 bi의 값이 WMAX를 초과할 경우 올바른 답이 구해지지 않을 수 있다.
	*/
	for (int i = 1; i <= N; i++) {
		int w = v[i - 1].first, d = v[i - 1].second - w;
		for (int j = 0; j < WMAX; j++) {
			dp[i % 2][j] = dp[(i - 1) % 2][j];
			if (j + w < WMAX && j <= d) dp[i % 2][j] = max(dp[i % 2][j], dp[(i - 1) % 2][j + w] + 1);
			//	cout << i << ' ' << j << ' ' << dp[i%2][j] << '\n';
		}
	}

	int ans = 0;
	for (int i = 0; i < WMAX; i++) ans = max(ans, dp[N % 2][i]);
	cout << ans << '\n';
	return 0;
}

/*
테스트 케이스

4
300 1000
1000 1200
200 600
100 101
출력 : 3

10
100 1000
200 450
300 300
500 605
700 800
1000 2000
100 3000
400 600
700 900
1000 1200
출력 : 5

2
1 10
10 30
출력 : 2

4
99 100
1 10
3 3
99 101
출력 : 2

4
10 40
10 20
10 30
10 10
출력 : 4

4
10 40
10 20
10 29
10 10
출력 : 3

1
100 100
출력 : 1
*/