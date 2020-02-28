/*
����, ���� ��� �־����� ���� ����� �����Ѵ�.
�ϴ�, Ʈ���� ���� �� Ǯ��.
1�ʰ�
����� ������ �ִ� 1000��.

������ ���δ� ������ �ش� ����Ʈ���� ��Ʈ���
������ ������ �ش� ����Ʈ���� ���� ����Ʈ��, ������ �ش� ����Ʈ���� ���� ����Ʈ��
��͸� �̿��ؼ� �¿츦 ������ ��Ʈ�� ã��
��,
1. �������� front�� ���Ѵ�. �װ� ���� ����Ʈ�������� ��Ʈ����̴�.
2. �������� front ���� ã��, ���������� ���������� ���� ��ͽ�Ų��.
3. ��� ���ʼ���Ʈ���θ� ����. ����ؼ� ��������Ʈ���� ������ ã�� ������.
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
deque<int> preorder;//��Ʈ
vector<int> inorder;//�¿��Ǻ���

int t;
int N;

//void SubtreeDFS2(int start, int end, int root) {//root��带 �������� �� �� ������ �Լ�. root�� �ݵ�� root���� ����� ��尡 �ԷµǾ����.
//	//start, end�� inorder ���Ϳ�����, root�� preorder������ �ε����� �ǹ��Ѵ�.
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
//	int leftnum = rootidx - start; int rightnum = end - rootidx;//�� �¿� ����Ʈ���� ��尳��
//	SubtreeDFS(start, rootidx - 1, rootidx + 1);
//	SubtreeDFS(rootidx + 1, end, rootidx + leftnum);
//	return;
//}


//void SubtreeDFS3(int start, int end) {//root��带 �������� �� �� ������ �Լ�. root�� �ݵ�� root���� ����� ��尡 �ԷµǾ����.
//	//start, end�� inorder ���Ϳ�����, root�� preorder������ �ε����� �ǹ��Ѵ�.
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
//	int leftnum = rootidx - start; int rightnum = end - rootidx;//�� �¿� ����Ʈ���� ��尳��
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
		parent.resize(N, -1); child.resize(N, mp(-1, -1)); preorder.resize(N); inorder.resize(N);//child resize�� �ð� ��ȿ�����ϼ��� ����
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