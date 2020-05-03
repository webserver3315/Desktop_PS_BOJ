#include <iostream>
#include <vector>
#define endl '\n'//endl �״�� ������� ���� ���� ��붧���� �ð��ʰ����;; ��ȭ��
using namespace std;

int n, m;
bool visited[10];
vector<int> vct;

void DFS(int depth) {
	if (depth == n) {
		for (int i : vct) {
			cout << i << ' ';
		}
		cout << endl;
		return;
	}
	for (int i = 1; i <= m; i++) {
		if (visited[i])
			continue;
		visited[i] = true;
		vct.push_back(i);
		DFS(depth + 1);
		visited[i] = false;
		vct.pop_back();
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);//�� �� �� ���̸� ����Ϸ���?
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n;
	DFS(0);

	return 0;
}