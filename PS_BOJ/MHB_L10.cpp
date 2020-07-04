#include <bits/stdc++.h>
#define int long long//�ȵǸ� ���� pii�� long long���� �ٲ� ��
#define endl '\n'
#define pii pair<int,int>
//#define pii pair<long long, long long>
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define VMAX 10001
using namespace std;

/*
���� 1197 ���д�Ʈ���� L10E�� ����ؼ� �װɷ� ��ü
�������. �׸��� ������ ���Ͱ� � ���� �ٸ��� �񱳴����� ��.
*/

int V, E;
vector<pii> adj[VMAX];
bool visited[VMAX];
priority_queue<pii, vector<pii>, greater<pii>> pq;//Ȯ������������ �ּ���

int prim() {
	int ret = 0;
	pq.push(mp(0, 1));
	while (!pq.empty()) {
		pii cur = pq.top(); pq.pop();//Ȯ���� ���� �� ���� �� ����
		if (visited[cur.ss]) continue;
		visited[cur.ss] = true;
		ret += cur.ff;
		for (auto& next : adj[cur.ss]) {//���� ���� ����� ��� ��带 �˻�
			if (visited[next.ss]) continue;//�̹� �鷶�ٸ� �Ÿ���
			pq.push(next);//�ȵ鸥 ���� ���ϴ� ������ pq�� �ִ´�.
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
	//1������ ����

	cout << prim() << endl;
	return 0;
}