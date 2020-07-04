#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
const int INF = 1000000000; // 절대 나올 수 없는 경로값


/*
벨만포드로 음수가중치 풀어버리기
한 노드로부터 모든 노드로 가는 최단거리가 단번에 나온다.
*/
int main() {
	int N, M, dist[500];
	scanf("%d %d", &N, &M);
	vector<pii> adj[500];
	for (int i = 0; i < M; i++) {
		int A, B, C;
		scanf("%d %d %d", &A, &B, &C);
		adj[A - 1].push_back(pii(B - 1, C));
	}
	fill(dist, dist + N, INF);
	dist[0] = 0;
	for (int i = 0; i < N - 1; i++) { // (N-1)번의 루프
		for (int j = 0; j < N; j++) {
			// N-1번의 루프에 걸쳐 각 정점이 i+1개 정점을 거쳐오는 최단경로 갱신
			for (auto& p : adj[j]) {
				int next = p.first, d = p.second;
				if (dist[j] != INF && dist[next] > dist[j] + d) {
					dist[next] = dist[j] + d;
				}
			}
		}
	}
	for (int i = 1; i < N; i++)
		printf("%d\n", dist[i] != INF ? dist[i] : -1);
}