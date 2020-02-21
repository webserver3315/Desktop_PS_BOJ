#include <iostream>
#include <deque>
#include <vector>
#include <utility>
#include <string.h>
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define MAX (int)1e5+1
#define endl '\n'
using namespace std;

bool visited[MAX];
int N;//nodekazu
vector<int> parent;
vector<vector<int>> child;//2��Ʈ����� ���� �����Ƿ� vector<pair>�� �ƴ϶� vector<vector<int>>�� ���.

void appendChild(int a, int b) {//�� ��� ��� ó������ ����, ���� ���յ� ���̾��ٸ� ���� ���� �ѵ�,
	int root = visited[a] ? a : b;
	int chd = visited[a] ? b : a;
	child[root].push_back(chd);
	parent[chd] = root;
	visited[chd] = true;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	parent.resize(N + 1, -1);
	child.resize(N + 1);
	visited[1] = true;
	for (int i = 0; i < N - 1; i++) {
		int a; int b;
		cin >> a >> b;
		appendChild(a, b);
	}
	for (int i = 2; i <= N; i++) {
		cout << parent[i] << endl;
	}
	return 0;
}