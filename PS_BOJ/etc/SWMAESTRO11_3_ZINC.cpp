#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int N, K;
vector<int> v;
int cache[3005][3005];

int solve(int pos, int K) {
	if (K == 1) return v[N - 1] - v[pos];
	if (K != 1 && pos == N - 1) return 1e9;

	int& ret = cache[pos][K];
	if (ret != -1) return ret;

	ret = 1e9;
	for (int i = pos + 1; i < N; i++)
		ret = min(ret, solve(i, K - 1) + v[i - 1] - v[pos]);
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	v.resize(N);
	for (int i = 0; i < N; i++) cin >> v[i];

	memset(cache, -1, sizeof(cache));
	cout << solve(0, K) << '\n';
	return 0;
}