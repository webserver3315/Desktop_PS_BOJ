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
vector<vector<int>> child;//2진트리라는 말이 없으므로 vector<pair>가 아니라 vector<vector<int>>를 썼다.

void appendChild(int a, int b) {//두 노드 모두 처음보는 노드고, 추후 통합될 것이었다면 답이 없긴 한데,
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