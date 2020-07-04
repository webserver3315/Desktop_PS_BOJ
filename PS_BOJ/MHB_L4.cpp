#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
const int INF = 1000000000; // ���� ���� �� ���� ��ΰ�


/*
��������� ��������ġ Ǯ�������
�� ���κ��� ��� ���� ���� �ִܰŸ��� �ܹ��� ���´�.
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
	for (int i = 0; i < N - 1; i++) { // (N-1)���� ����
		for (int j = 0; j < N; j++) {
			// N-1���� ������ ���� �� ������ i+1�� ������ ���Ŀ��� �ִܰ�� ����
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