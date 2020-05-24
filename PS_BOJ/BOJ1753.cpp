#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define endl '\n'
#define mymax 9999999
using namespace std;

/*
최단경로
음수간선없는 최소거리문제. 다익스트라다.

다익스트라와 프림은 딱 2줄 다르다. 거의 동일하다. 즉 하나 외우면 하나는 공짜다.
밀집지향인 프림은 크루스칼에 비해 덜 쓰이긴 하지만, 양민수준은 뭘 써도 무방하다고 보면 된다.
*/

int V, E;
int K;
vector<pii> adj[20001];//w,e
bool visit[20001];
int dist[20001];
//int myprev[20001];//-1로 초기화 필요
vector<int> ans;
priority_queue<pii, vector<pii>, greater<pii>> pq;//왜 greater<>() 소괄호 안붙지?

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
	//while (!pq.empty()) { // PQ가 비면 종료
	//	int curr;
	//	do {
	//		curr = pq.top().second;
	//		pq.pop();
	//	} while (!pq.empty() && visit[curr]); // curr가 방문한 정점이면 무시
	//	// 더 이상 방문할 수 있는 정점이 없으면 종료
	//	if (visit[curr]) break;

	//	visit[curr] = true; // 방문
	//	for (auto& p : adj[curr]) {
	//		int next = p.second, d = p.first;
	//		// 거리가 갱신될 경우 PQ에 새로 넣음
	//		if (dist[next] > dist[curr] + d) {
	//			//cout << dist[next] << " 을 " << dist[curr] + d << "로 업데이트" << endl;
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
양방향가정, 
0
7
9
20
20
11

*/