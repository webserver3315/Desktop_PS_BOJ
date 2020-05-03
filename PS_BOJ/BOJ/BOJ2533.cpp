#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cstring>
#define MAX (int)1e6+5
#define endl '\n'
using namespace std;

int N;
vector<int> parent(MAX,-1);
vector<int> child[MAX];
vector<int> adj[MAX];
bool visited[MAX];
bool visited2[MAX];
int level[MAX];//각 노드별 깊이를 유지
deque<int> buffer;
int cnt1;//1번 노드와 같은 색깔인 노드들
int cnt2;//1번 노드와 다른 색깔인 노드들


//int getLevel(int n) {//루트노드 픽할 시 트리전체의 Height를 구하는 함수이지, 각 노드의 depth를 구하는 함수가 아니다!
//	if (level[n] != -1)
//		return level[n];
//	int result = 1;
//	for (int ch : child[n]) {
//		result = max(result, getLevel(ch) + 1);
//	}
//	level[n] = result;
//	return result;
//}
//
//int getLevel(int n) {
//	visited2[n] = true;
//
//}

void makeTree(int n, int depth) {
	visited[n] = true;
	level[n] = depth;
	if (depth % 2 == 0)
		cnt2++;
	else
		cnt1++;
	for (int ch : adj[n]) {
		if (!visited[ch]) {
			parent[ch] = n;
			child[n].push_back(ch);
			makeTree(ch, depth + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	int a, b;
	for (int i = 1; i < N; i++) {
		cin >> a >> b;
		adj[a].push_back(b); adj[b].push_back(a);
	}
	memset(level, -1, sizeof(level));
	makeTree(1, 1);

	cout << min(cnt1, cnt2) << endl;

	return 0;
}