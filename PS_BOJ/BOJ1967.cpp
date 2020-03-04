#include <iostream>
#include <vector>
#include <deque>
#include <utility>
#include <algorithm>
#define MAX (int)1e4+1
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define endl '\n'
using namespace std;

int N;
//int adj[MAX][MAX];
vector<pii> adj[MAX];//����, ���ġ�� �������� �����ϴ� ��������Ʈ
int mst[2][MAX];
bool visited[2][MAX];
vector<int> parent;
vector<vector<int>> child;

/*
Ȯ���� ����, ��Ʈ�κ��� ���� �� ������ �ݵ�� �� �� �ϳ��� ������ �ȴٴ� ���̴�.
�׷��Ƿ�, ���� �� ���� �ϳ� ���ϰ�, �� �������κ��� ���� �� ������ �ϳ� ���� �ȴ�.
�翬�� 1������ ��Ʈ����, �ٳ�� �� �ϳ��� ������ �� ��尡 ���� �ڸ��ϴ�.

�ּҽ���Ʈ�� �ƴѰ�? �������� ������ �������ٴ� ũ�罺Į�� �����ϰ�.
ũ�罺Į 2���ε��ѵ�
�׷���, ���ʿ� Ʈ���ϱ�, ��Ž�����°� �� �����Ͱ�����. ��������̶�.
*/

void makingMST(int nd, int now, int mode) {//���, ���ݰ���ġ
	for (pii p : adj[nd]) {
		int next = p.ff; int val = p.ss;
		if (!visited[mode][next]) {
			mst[mode][next] = now + val;
			visited[mode][next] = true;
			makingMST(next, now + val, mode);
		}
	}
}

int getMostFar(int mode) {//nd�κ��� ���� �� ���� ��ȯ
	int maxval = 0;
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (maxval < mst[mode][i]) {
			maxval = mst[mode][i];
			ans = i;
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	parent.resize(N + 1, -1);
	child.resize(N + 1);
	for (int i = 1; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		child[a].push_back(b);
		parent[b] = a;
		adj[a].push_back(mp(b, c));
		adj[b].push_back(mp(a, c));
	}
	
	visited[0][N] = true;
	makingMST(N, 0, 0);//�� ��Ʈ���� ��� ���ص� �ȴ�. ��, makingMST(�ƹ����, 0, 0); �ص� ����� ����.
	int start = getMostFar(0);
	visited[1][start] = true;
	makingMST(start, 0, 1);
	int end = getMostFar(1);
	cout << mst[1][end] << endl;


	return 0;
}