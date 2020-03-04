#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX (int)1e4+5
#define endl '\n'
using namespace std;

int N;
vector<int> adj[MAX];
vector<int> value(MAX, -1);
vector<int> parent(MAX, -1);
vector<int> child[MAX];
//int memo[2][MAX];//0:isBad, 1:IsGood
int memo[MAX][2];//0:isBad, 1:IsGood
bool visited[MAX];

int DP(int nd, bool isGood) {
	int& ret = memo[nd][isGood];
	if (ret != -1)
		return ret;

	ret = (isGood ? value[nd] : 0);//선택하냐안하냐로 일단 해당노드인구를 더하느냐 안더하느냐가 갈리므로 바로 적용해주고
	for (int chd : child[nd]) {
		if (isGood)//선택했다면, 이전마을에서 true라는 선택지는 절대 없다
			ret += DP(chd, false);
		else//선택안했다면, 이전마을에서 false해도 되고 true해도 되고, 더 좋은 선지를 취사선택하면된다.
			ret += max(DP(chd, false), DP(chd, true));
		//참고로, 선택을 계속 안하는 선지는 알고리즘상 일어날 리가 없으니 안심해도 된다.
	}
	return ret;
}

void maketree(int nd) {
	visited[nd] = true;
	for (int chd : adj[nd]) {
		if (!visited[chd]) {
			child[nd].push_back(chd);
			parent[chd] = nd;
			maketree(chd);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> value[i];
	}
	int a, b;
	for (int i = 1; i < N; i++) {
		cin >> a >> b;
		adj[a].push_back(b); adj[b].push_back(a);
	}
	memset(memo, -1, sizeof(memo));
	maketree(1);
	int ans = max(DP(1, true), DP(1, false));
	cout << ans << endl;

	return 0;
}