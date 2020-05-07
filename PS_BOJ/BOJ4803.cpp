#include <iostream>
#include <vector>
#include <set>
#define endl '\n'
#define MAX 550
using namespace std;

int T;
int N;//노드 수
int M;//간선 수
int adj[MAX][MAX];//무방향 트리이기에, appending하는 시점에서 부모와 자식을 따지는게 무의미하기에 그래프로 간주하여 풀기로 했다.
bool visited[MAX];//노드 방문 여부
int VertexCnt;
int NodeCnt;
int TreeCnt;

/*
트리인지의 여부는 iff 해당 노드로부터 완탐 돌렸을 시 노드의 개수 == 간선 + 1 이 성립하느냐의 문제와 동치이다. 이걸 이용하면 된다.
사이클의 생성여부는 해당 등식의 성립여부로 퉁칠 수 있다. 이걸 사전에 알았더라면 9466번 문제도 쉽게 풀 수 있었으려나?
참고로, 간선이 0개일 때도 상정해야 한다! 이 때, 트리의 개수는 노드의 개수와 동일하다!
구현은 과거 포스팅인 https://blog.naver.com/webserver3315/221581373909 을 참조했다.
*/

//class Tree {
//public:
//	int N;
//	vector<int> parent;
//	vector<vector<int>> children;
//	set<int> numberOfTree;
//	Tree():N(0){}
//	Tree(int N) :N(N) {
//		parent.resize(N, -1);
//		children.resize(N);
//	}
//	int findRoot(int node) {
//		if (parent[node] == -1)
//			return node;
//		return findRoot(parent[node]);
//	}
//};

void DFS(int node) {
	NodeCnt++;
	visited[node] = true;
	for (int i = 1; i <= N; i++) {
		if (adj[node][i] == 1) {
			//cout << node << " 와 " << i << " 사이의 간선을 세었습니다" << endl;
			VertexCnt++;
			if (!visited[i]) {
				//cout << i << "번 노드에 진입합니다" << endl;
				DFS(i);
			}
		}
	}
}

void ArrInitialize() {
	for (int r = 0; r < MAX; r++) {
		for (int c = 0; c < MAX; c++) {
			adj[r][c] = 0; adj[c][r] = 0;
		}
		visited[r] = false;
	}

	for (int i = 0; i < M; i++) {
		int a; int b;
		cin >> a >> b;
		adj[a][b]++; adj[b][a]++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (cin >> N >> M && N!=0) {
		T++;
		//cout << "새로운 시작" << endl;
		VertexCnt = 0; NodeCnt = 0; TreeCnt = 0;
		ArrInitialize();
		
		for (int i = 1; i <= N; i++) {
			if (!visited[i]) {
				VertexCnt = 0; NodeCnt = 0;
				DFS(i);
				//cout << "노드 카운트와 간선 카운트는 각각: " << NodeCnt << ' ' << VertexCnt << endl;
				if (2 * (NodeCnt - 1) == VertexCnt)
					TreeCnt++;
			}
		}
		//cout << "트리 개수 : " << TreeCnt << endl;
		if (TreeCnt == 0) {
			cout << "Case " << T << ": No trees." << endl;
		}
		else if (TreeCnt == 1) {
			cout << "Case " << T << ": There is one tree." << endl;
		}
		else {
			cout << "Case " << T << ": A forest of " << TreeCnt << " trees." << endl;
		}
	}
	return 0;
}