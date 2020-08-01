#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define myMAX 100010
using namespace std;

vector<int> adj[myMAX];
int parent[myMAX];
deque<int> lfq;
int maxdepth[myMAX];
bool visited[myMAX];
bool localvisit[myMAX];
int N, S, D;
int steps;
vector<int> cstk;

void get_leaf() {
	for (int i = 1; i <= N; i++) {
		if (i == S)
			continue;
		if (adj[i].size() == 1) {
			lfq.push_back(i);
		}
	}
}

void assign_maxdepth(int root) {
	get_leaf();
	
	while (!lfq.empty()) {
		int cnt = lfq.size();
		while (cnt--) {
			int cur = lfq.front();
			lfq.pop_front();
			int next = parent[cur];
			if (next == 0) continue;
			//cout << cur << " ���� " << next << " �� �����۾��� ������Ʈ�� ����: "<< max(maxdepth[cur] + 1, maxdepth[next]) << endl;
			maxdepth[next] = max(maxdepth[cur] + 1, maxdepth[next]);
			lfq.push_back(next);
		}
	}
	
	//for (int i = 1; i <= N; i++) {
	//	cout << i << "�� ����� �����۾��� " << maxdepth[i] << endl;
	//}
}

void make_parent() {
	int root = S;
	deque<int> dq;

	dq.push_back(S);
	localvisit[S] = true;
	while (!dq.empty()) {
		int cur = dq.front();
		dq.pop_front();
		for (int next : adj[cur]) {
			if (localvisit[next] == true) {
				continue;
			}
			localvisit[next] = true;
			parent[next]=cur;
			dq.push_back(next);
		}
	}
	//for (int i = 2; i <= N; i++) {
	//	cout << i << " �� �θ�� " << parent[i] << endl;
	//}
}

void DFS(int root) {
	cstk.push_back(root);
	while (!cstk.empty()) {
		int cur = cstk.back();
		cstk.pop_back();
		for (int next : adj[cur]) {
			if (maxdepth[next] < D) continue; //maxdepth �� D���� ������ �Ÿ���
			if (next == parent[cur]) continue; // �θ���� �Ÿ���
			steps++;
			//cout << cur << " ���� " << next << " �� ���� " << endl;
			cstk.push_back(next);
		}
		steps++;
		//cout << cur << "���� ���ƿ�" << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> S >> D;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	make_parent();
	assign_maxdepth(S);
	DFS(S);

	cout << steps - 1 << endl;

	//N = myMAX - 1;
	//for (int i = 1; i <= N; i++) {
	//	cout << i << " " << i + 1 << endl;
	//}

	return 0;
}