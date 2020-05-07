/*
������ȸ�� �ƿ� ����ϰ� Ǯ ������ ���ϰ� �׳� �����ϰ� �����ߴµ�,
�����ϰ� ������ȸ ���� ���� ª�� Ǯ���±���.
�ٳ����� ������ �ʿ䰡 ��������(Bottom-Up�� ����) ������ ������ȸ�� ���ø����� ����.

����:
https://jklh0202.tistory.com/1
*/

#include <iostream>
#include <string>
#include <vector>
#define MAX 123457
#define endl '\n'
#define int long long
using namespace std;

int N;
vector<int> parent;
vector<vector<int>> child;
vector<int> population;

int postorder(int now) {
	int cnt = population[now];
	for (int i : child[now]) {
		cnt += postorder(i);
	}
	return cnt < 0 ? 0 : cnt;
}

signed main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	++N;
	parent.resize(N, -1);
	population.resize(N, 0);
	child.resize(N);
	for (int i = 2; i < N; i++) {
		string tmpstr; int popu; int next;
		cin >> tmpstr >> popu >> next;
		if (tmpstr == "W")
			popu *= -1;//����� ������ �α��� ǥ��
		parent[i] = next;
		population[i] = popu;
		child[next].push_back(i);
	}
	cout << postorder(1) << endl;
	return 0;
}