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
#include <utility>
#include <algorithm>
#define endl '\n'
#define pii pair<int,int>
#define ff first
#define ss second
#define mp(a,b) make_pair(a,b)
#define MAX 1005
using namespace std;

vector<int> parent;
vector<pii> child;
deque<int> preorder;//루트
vector<int> inorder;//좌우판별용

int t;
int N;

//void SubtreeDFS2(int start, int end, int root) {//root노드를 기점으로 좌 우 나누는 함수. root는 반드시 root임이 보장된 노드가 입력되어야함.
//	//start, end는 inorder 벡터에서의, root는 preorder에서의 인덱스를 의미한다.
//	int rootidx = -1;
//	for (int i = 1; i <= N; i++) {
//		if (root == inorder[i]) {
//			rootidx = i;
//			break;
//		}
//	}
//	if (start == end) {
//		cout << preorder[root] << endl;
//		return;
//	}
//	int leftnum = rootidx - start; int rightnum = end - rootidx;//각 좌우 서브트리당 노드개수
//	SubtreeDFS(start, rootidx - 1, rootidx + 1);
//	SubtreeDFS(rootidx + 1, end, rootidx + leftnum);
//	return;
//}


//void SubtreeDFS3(int start, int end) {//root노드를 기점으로 좌 우 나누는 함수. root는 반드시 root임이 보장된 노드가 입력되어야함.
//	//start, end는 inorder 벡터에서의, root는 preorder에서의 인덱스를 의미한다.
//	int root = preorder[cur];
//	cout << "start, end : " << start << ' ' << end << endl;
//	int rootidx = -1;
//	if (start == end) {
//		int ans = preorder[start];
//		cout << ans << ' ';
//		return;
//	}
//	for (int i = 1; i <= N; i++) {
//		if (root == inorder[i]) {
//			rootidx = i;
//			break;
//		}
//	}
//	int leftnum = rootidx - start; int rightnum = end - rootidx;//각 좌우 서브트리당 노드개수
//	SubtreeDFS(start, rootidx - 1);
//	SubtreeDFS(rootidx + 1, end);
//	cur++;
//	return;
//}

int cur = 1;
void SubtreeDFS(int start, int end) {
	if (cur > N)
		return;
	int root = preorder[cur++];
	cout << "start, end : " << start << ' ' << end << endl;
	cout << "root: " << root << endl;
	int rootidx = -1;
	for (int i = 1; i <= N; i++) {
		if (root == inorder[i]) {
			rootidx = i;
			break;
		}
	}
	int leftnum = rootidx - start; int rightnum = end - rootidx;
	SubtreeDFS(start, rootidx - 1);
	if (rightnum != 0)
		SubtreeDFS(rootidx + 1, end);
	else {
		SubtreeDFS(end, end);
	}

	int ans = inorder[start];
	cout << ans << ' ';
	return;

	cout << "err" << endl;
	return;
}

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

bool visited[MAX] = { true, };
void DFS(int start, int end) {
	int root;
	if (!preorder.empty()) {
		while (visited[preorder.front()])
			preorder.pop_front();
		root = preorder.front();
		preorder.pop_front();
		visited[root] = true;
	}
	//if (start >= end) {
	//	cout << inorder[start] << ' ';
	//	return;
	//}
	/*cout << "start, end : " << start << ' ' << end << endl;
	cout << "root: " << root << endl;*/
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

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> N;
		N++;
		parent.resize(N, -1); child.resize(N, mp(-1, -1)); preorder.resize(N); inorder.resize(N);//child resize시 시간 비효율적일수도 있음
		memset(visited, false, N);
		visited[0] = true;
		N--;
		for (int i = 1; i <= N; i++) {
			cin >> preorder[i];
		}
		for (int i = 1; i <= N; i++) {
			cin >> inorder[i];
		}
		//SubtreeDFS(1, N);
		DFS(1, N);
		cout << endl;
	}

	return 0;
}