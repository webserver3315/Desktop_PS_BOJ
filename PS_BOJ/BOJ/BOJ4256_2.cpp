/*
전위, 중위 결과 주어지고 후위 결과를 내야한다.
일단, 트리를 만든 뒤 풀자.
1초고
노드의 개수는 최대 1000개.

전위의 문두는 무조건 해당 서브트리의 루트노드
중위의 좌측은 해당 서브트리의 좌측 서브트리, 우측은 해당 서브트리의 우측 서브트리
재귀를 이용해서 좌우를 가르고 루트를 찾고
즉,
1. 전위에서 front를 팝한다. 그게 현재 서브트리에서의 루트노드이다.
2. 후위에서 front 값을 찾고, 좌측범위와 우측범위를 각각 재귀시킨다.
3. 계속 왼쪽서브트리로만 간다. 재귀해서 우측서브트리도 잠깐잠깐 찾는 식으로.
*/

#include <iostream>
#include <vector>
#include <deque>
#define endl '\n'
#define MAX 1005
using namespace std;

vector<bool> visited;
deque<int> preorder;//루트
vector<int> inorder;//좌우판별용

int t;
int N;

int findRootIdx(int root) {
	int rootidx = -1;
	for (int i = 1; i <= N; i++) {
		if (root == inorder[i]) {
			rootidx = i;
			break;
		}
	}
	return rootidx;
}


void DFS(int start, int end) {
	int root;
	while (visited[preorder.front()])
		preorder.pop_front();
	root = preorder.front();
	preorder.pop_front();
	visited[root] = true;

	int rootidx = findRootIdx(root);

	if (start < rootidx - 1)
		DFS(start, rootidx - 1);
	else if (start == rootidx - 1)
		DFS(start, start);
	if (rootidx + 1 < end)
		DFS(rootidx + 1, end);
	else if (rootidx + 1 == end)
		DFS(end, end);
	cout << root << ' ';
	return;
}

void Input() {
	for (int i = 1; i <= N; i++) {
		cin >> preorder[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> inorder[i];
	}
}

void Initialize() {
	N++;
	preorder.resize(N); inorder.resize(N);//child resize시 시간 비효율적일수도 있음
	visited.resize(N, false);//resize t t t t t 에서 크기 10으로 바꾸면, fffffffff가 아니라 tttttfffff가 된다!!!!!! 이전건 초기화안함!!
	for (int i = 1; i < N; i++) {//등호일단뺌
		visited[i] = false;
	}
	visited[0] = true;
	N--;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> N;
		Initialize();
		Input();
		DFS(1, N);
		cout << endl;
	}
	return 0;
}