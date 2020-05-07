/*
���డ��
*/

#include <iostream>
#define endl '\n'
#define MAX (int)1005
using namespace std;

/*
����� ���õ��� ���Ͽ����ε�� �׷�ȭ�Ѵ�
�׷�ȭ ���� ��, �����ȹ�� �������ȸ�ϸ� ��� ���ϱ׷����� �����Ѵ�.
������ ���Ƽ� ���� ����� ���� ����ϹǷ�, ���������� �߿����� �ʴ�.
���ϱ׷��� �ƴ� ���ð� �� �ϳ��� ������ ��Ʈ����.
*/

int n, m;
int adj[MAX][MAX];
int tripseq[MAX];
int prt[MAX];
int level[MAX];

int find(int a) {
	if (prt[a] == a)
		return a;
	return prt[a] = find(prt[a]);
}

void merge(int a, int b) {
	int pa = find(a); int pb = find(b);
	if (pa == pb)
		return;
	else if (level[pa] < level[pb]) {
		level[pb]++;
		level[pa] = 0;
		prt[pa] = pb;
	}
	else {
		level[pa]++;
		level[pb] = 0;
		prt[pb] = pa;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {//���Ͽ����ε�Ʈ���� ��� �� �ݵ�� �ʱ�ȭ�ϴ°� ��������!
		prt[i] = i;
	}

	for (int from = 1; from <= n; from++) {//���ô� 1������ ����
		for (int to = 1; to <= n; to++) {
			/*cin >> adj[from][to];*/
			int tmp;
			cin >> tmp;
			if (tmp)
				merge(from, to);
		}
	}

	for (int i = 0; i < m; i++)
		cin >> tripseq[i];

	int group = find(tripseq[0]);
	for (int i = 1; i < m; i++) {
		if (group != find(tripseq[i])) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}