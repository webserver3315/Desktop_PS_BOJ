#include <iostream>
#include <vector>
#include <set>
#define endl '\n'
#define MAX 550
using namespace std;

int T;
int N;//��� ��
int M;//���� ��
int adj[MAX][MAX];//������ Ʈ���̱⿡, appending�ϴ� �������� �θ�� �ڽ��� �����°� ���ǹ��ϱ⿡ �׷����� �����Ͽ� Ǯ��� �ߴ�.
bool visited[MAX];//��� �湮 ����
int VertexCnt;
int NodeCnt;
int TreeCnt;

/*
Ʈ�������� ���δ� iff �ش� ���κ��� ��Ž ������ �� ����� ���� == ���� + 1 �� �����ϴ����� ������ ��ġ�̴�. �̰� �̿��ϸ� �ȴ�.
����Ŭ�� �������δ� �ش� ����� �������η� ��ĥ �� �ִ�. �̰� ������ �˾Ҵ���� 9466�� ������ ���� Ǯ �� �־�������?
�����, ������ 0���� ���� �����ؾ� �Ѵ�! �� ��, Ʈ���� ������ ����� ������ �����ϴ�!
������ ���� �������� https://blog.naver.com/webserver3315/221581373909 �� �����ߴ�.
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
			//cout << node << " �� " << i << " ������ ������ �������ϴ�" << endl;
			VertexCnt++;
			if (!visited[i]) {
				//cout << i << "�� ��忡 �����մϴ�" << endl;
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
		//cout << "���ο� ����" << endl;
		VertexCnt = 0; NodeCnt = 0; TreeCnt = 0;
		ArrInitialize();
		
		for (int i = 1; i <= N; i++) {
			if (!visited[i]) {
				VertexCnt = 0; NodeCnt = 0;
				DFS(i);
				//cout << "��� ī��Ʈ�� ���� ī��Ʈ�� ����: " << NodeCnt << ' ' << VertexCnt << endl;
				if (2 * (NodeCnt - 1) == VertexCnt)
					TreeCnt++;
			}
		}
		//cout << "Ʈ�� ���� : " << TreeCnt << endl;
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