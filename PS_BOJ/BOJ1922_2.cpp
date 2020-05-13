#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define endl '\n'
using namespace std;

/*
��Ʈ��ũ ���� ����
�̹��� �������� Ǯ���.
������ �����׷������� �����ѵ�, �����׷��� ��ü�� ���� �ϴ�...
https://huiung.tistory.com/76 ����
*/

int N, M;
bool visited[1001];
vector<pii> adj[1001];//����ġ, ������
priority_queue<pii, vector<pii>, greater<pii>> pq;//����ġ���� �ּ���

int prim() {
	int ans = 0;
	pq.push(mp(0, 1));
	while (!pq.empty()) {
		pii cur = pq.top(); pq.pop();
		if (visited[cur.ss]) continue;//�湮������ �Ÿ���.
		visited[cur.ss] = true;
		ans += cur.ff;
		for (auto next : adj[cur.ss]) {
			if (!visited[next.ss]) {
				pq.push(next);
			}
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back(mp(c, b));
		adj[b].push_back(mp(c, a));
	}
	int result = prim();
	cout << result << endl;

	return 0;
}