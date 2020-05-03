#include <iostream>
#include <map>
#define int long long
#define mp(a,b) make_pair(a,b)
#define endl '\n'
using namespace std;

int N, P, Q;
map<int, int> memo;

int DP(int n) {
	if (n < 0)
		return 0;
	if (memo.find(n) != memo.end())
		return memo.find(n)->second;
	int a = n / P; int b = n / Q;
	memo.insert(mp(n, DP(a) + DP(b)));
	return memo.find(n)->second;
}

//int DP(int n) {
//	//if (memo.find(n) != memo.end())
//	//	return memo.find(n)->second;
//	/*if (memo.count(n))
//		return memo[n];*/
//	if (memo.find(n) != memo.end())
//		return memo.find(n)->second;
//	int a = n / P; int b = n / Q;
//	memo.insert(mp(n, DP(a) + DP(b)));
//	//memo[n] = DP(a) + DP(b);
//	return memo[n];
//}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> P >> Q;
	//memo.insert(pair<int, int>(0, 1));
	//memo.insert(mp(0, 1));
	memo[0] = 1;
	cout << DP(N) << endl;

	return 0;
}