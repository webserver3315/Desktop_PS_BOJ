#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define endl '\n'
#define mymax 9999999
using namespace std;

/*
�ִܰ��
������������ �ּҰŸ�����. ���ͽ�Ʈ���.

���ͽ�Ʈ��� ������ �� 2�� �ٸ���. ���� �����ϴ�. �� �ϳ� �ܿ�� �ϳ��� ��¥��.
���������� ������ ũ�罺Į�� ���� �� ���̱� ������, ��μ����� �� �ᵵ �����ϴٰ� ���� �ȴ�.
*/

int V, E;
int K;
vector<pii> adj[20001];//w,e
bool visit[20001];
int dist[20001];
//int myprev[20001];//-1�� �ʱ�ȭ �ʿ�
vector<int> ans;
priority_queue<pii, vector<pii>, greater<pii>> pq;//�� greater<>() �Ұ�ȣ �Ⱥ���?

void Dik() {//Dijkstra
	fill(dist, dist + V+1, mymax);
	dist[K] = 0;
	pq.push(mp(0, K));
	while (!pq.empty()) {
		pii cur = pq.top(); pq.pop();
		if (visit[cur.ss]) continue;
		visit[cur.ss] = true;
		for (auto& next : adj[cur.ss]) {
			if (dist[next.ss] > dist[cur.ss] + next.ff) {
				dist[next.ss] = dist[cur.ss] + next.ff;
				pq.push(mp(dist[next.ss], next.ss));
			}
		}
	}
	//while (!pq.empty()) { // PQ�� ��� ����
	//	int curr;
	//	do {
	//		curr = pq.top().second;
	//		pq.pop();
	//	} while (!pq.empty() && visit[curr]); // curr�� �湮�� �����̸� ����
	//	// �� �̻� �湮�� �� �ִ� ������ ������ ����
	//	if (visit[curr]) break;

	//	visit[curr] = true; // �湮
	//	for (auto& p : adj[curr]) {
	//		int next = p.second, d = p.first;
	//		// �Ÿ��� ���ŵ� ��� PQ�� ���� ����
	//		if (dist[next] > dist[curr] + d) {
	//			//cout << dist[next] << " �� " << dist[curr] + d << "�� ������Ʈ" << endl;
	//			dist[next] = dist[curr] + d;
	//			pq.push(mp(dist[next], next));
	//		}
	//	}
	//}

	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> V >> E;
	cin >> K;
	for (int i = 0; i < E; i++) {
		int s, e, w;
		cin >> s >> e >> w;
		adj[s].push_back(mp(w, e));
		//adj[e].push_back(mp(w, s));
	}
	Dik();
	for (int i = 1; i <= V; i++) {
		if (dist[i] != mymax)cout << dist[i] << endl;
		else cout << "INF" << endl;
	}

	return 0;
}

/*
6 9
1
1 2 7
1 3 9
1 6 14
2 4 15
2 3 10
3 6 2
3 4 11
4 5 6
5 6 9
����Ⱑ��, 
0
7
9
20
20
11

*/