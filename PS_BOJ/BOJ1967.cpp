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
vector<pii> adj[MAX];//어디로, 몇가중치의 간선인지 유지하는 인접리스트
int mst[2][MAX];
bool visited[2][MAX];
vector<int> parent;
vector<vector<int>> child;

/*
확실한 것은, 루트로부터 가장 먼 정점은 반드시 둘 중 하나의 정점이 된다는 것이다.
그러므로, 가장 먼 정점 하나 택하고, 그 정점으로부터 가장 먼 정점을 하나 고르면 된다.
당연히 1번정점 루트기준, 잎노드 중 하나가 나머지 그 노드가 됨이 자명하다.

최소신장트리 아닌가? 간선수가 적으니 프림보다는 크루스칼이 적절하고.
크루스칼 2번인듯한데
그런데, 애초에 트리니까, 완탐돌리는게 더 빠를것같은데. 경로유일이라.
*/

void makingMST(int nd, int now, int mode) {//노드, 지금가중치
	for (pii p : adj[nd]) {
		int next = p.ff; int val = p.ss;
		if (!visited[mode][next]) {
			mst[mode][next] = now + val;
			visited[mode][next] = true;
			makingMST(next, now + val, mode);
		}
	}
}

int getMostFar(int mode) {//nd로부터 제일 먼 정점 반환
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
	makingMST(N, 0, 0);//꼭 루트부터 출발 안해도 된다. 즉, makingMST(아무노드, 0, 0); 해도 결과는 같다.
	int start = getMostFar(0);
	visited[1][start] = true;
	makingMST(start, 0, 1);
	int end = getMostFar(1);
	cout << mst[1][end] << endl;


	return 0;
}