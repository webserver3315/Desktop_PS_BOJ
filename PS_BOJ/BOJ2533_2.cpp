/*
얼리어댑터가 이접해야만 나올 수 있는 최적해가 있다면, 이 문제의 반례가 된다.
참조:https://jaimemin.tistory.com/592
해당 가설을 전제로 다시 풀어보자.
*/
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cstring>
#define MAX (int)1e6+5
#define endl '\n'
using namespace std;

int N;
//vector<int> parent(MAX, -1);
vector<int> child[MAX];
vector<int> adj[MAX];
bool visited[MAX];
int cnt1;//1번 노드와 같은 색깔인 노드들
int cnt2;//1번 노드와 다른 색깔인 노드들
int memo[MAX][2];//0: 촌놈, 1: 얼리

void makeTree(int n, int depth) {
	visited[n] = true;
	for (int ch : adj[n]) {
		if (!visited[ch]) {
			//parent[ch] = n;
			child[n].push_back(ch);
			makeTree(ch, depth + 1);
		}
	}
}

int DP(int n, bool isEarly) {
	/*
	해당 루트를 칠할 때, 나올 수 있는 최소의 얼리어답터 수를 각각 출력한다.
	만일 루트가 얼리어답터라면, 자식도 얼리어답터여도 상관없다.
		min(DP(ch, isEarly),DP(ch, !isEarly))를 모두 더한 뒤, 루트도 얼리이므로 +1한다.
	다만, 루트가 촌놈이면 자식 전부가 얼리어답터여야만 한다.
		DP(ch, isEarly) 를 모두 더한 뒤, 루트는 촌놈이므로 +1 안한다.
	이 규칙은 루트말고 다른 노드가 들어와도 일괄적용된다.
	*/
	int& ret = memo[n][isEarly];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int chd : child[n]) {
		if (isEarly) {
			int add = min(DP(chd, true), DP(chd, false));
			ret += add;
		}
		else {
			int add = DP(chd, true);
			ret += add;
		}
	}
	if (isEarly)
		ret += 1;
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	int a, b;
	for (int i = 1; i < N; i++) {
		cin >> a >> b;
		adj[a].push_back(b); adj[b].push_back(a);
	}
	memset(memo, -1, sizeof(memo));
	makeTree(1, 1);

	cnt1 = DP(1, true);
	cnt2 = DP(1, false);
	cout << min(cnt1, cnt2) << endl;

	return 0;
}