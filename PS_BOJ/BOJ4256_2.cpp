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
#define endl '\n'
#define MAX 1005
using namespace std;

vector<bool> visited;
deque<int> preorder;//��Ʈ
vector<int> inorder;//�¿��Ǻ���

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
	preorder.resize(N); inorder.resize(N);//child resize�� �ð� ��ȿ�����ϼ��� ����
	visited.resize(N, false);//resize t t t t t ���� ũ�� 10���� �ٲٸ�, fffffffff�� �ƴ϶� tttttfffff�� �ȴ�!!!!!! ������ �ʱ�ȭ����!!
	for (int i = 1; i < N; i++) {//��ȣ�ϴܻ�
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