#include <bits/stdc++.h>
#define int long long//안되면 밑의 pii도 long long으로 바꿀 것
#define endl '\n'
#define pii pair<int,int>
//#define pii pair<long long, long long>
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define VMAX 10001
using namespace std;

/*
백준 1197 스패닝트리가 L10E와 비슷해서 그걸로 대체
프림사용. 그리고 프림이 다익과 어떤 줄이 다른지 비교대조할 것.
*/

int V, E;
vector<pii> adj[VMAX];
bool visited[VMAX];
priority_queue<pii, vector<pii>, greater<pii>> pq;//확보간선유지용 최소힙

int prim() {
	int ret = 0;
	pq.push(mp(0, 1));
	while (!pq.empty()) {
		pii cur = pq.top(); pq.pop();//확보한 간선 중 가장 싼 간선
		if (visited[cur.ss]) continue;
		visited[cur.ss] = true;
		ret += cur.ff;
		for (auto& next : adj[cur.ss]) {//다음 노드와 연결된 모든 노드를 검색
			if (visited[next.ss]) continue;//이미 들렀다면 거르고
			pq.push(next);//안들른 노드면 통하는 간선을 pq에 넣는다.
		}
	}
	return ret;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back(mp(c, b));
		adj[b].push_back(mp(c, a));
	}
	//1번부터 시작

	cout << prim() << endl;
	return 0;
}