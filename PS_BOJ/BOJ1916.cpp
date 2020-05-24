#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define endl '\n'
#define mymax INT_MAX
using namespace std;

/*
�ּҺ�뱸�ϱ� ����.
int ���� �ذ�ȴ�.
*/

int V, E;
int A, B;
vector<pii> adj[1001];
bool visit[1001];
int dist[1001];
priority_queue<pii, vector<pii>, greater<pii>> pq;

void dik() {
	fill(dist, dist + V + 1, mymax);
	dist[A] = 0;
	pq.push(mp(0, A));
	while (!pq.empty()) {
		pii cur = pq.top(); pq.pop();
		if (visit[cur.ss]) continue;
		visit[cur.ss] = true;
		for (auto& next : adj[cur.ss]) {
			if (dist[next.ss] > dist[cur.ss] + next.ff) {//if�� ���� �Ǽ��ؼ� ����뿡 10�� ���ȴ�.
				//cout << dist[next.ss] << " �� " << dist[next.ss] + next.ff << "�� ������Ʈ" << endl;
				dist[next.ss] = dist[cur.ss] + next.ff;
				pq.push(mp(dist[next.ss], next.ss));
			}
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back(mp(c, b));
	}
	cin >> A >> B;
	dik();
	cout << dist[B] << endl;

	return 0;
}