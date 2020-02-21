/*
������ ǥ��
*/

#include <iostream>
#define endl '\n'
#define MAX (int)1e6+5
using namespace std;


int n, m;
int parent[MAX];
int level[MAX];//��� ����ȭ�� ���ؼ��� root�� level�� ������ ����������Ѵ�


int find(int a) {
	if (parent[a] == a)
		return a;
	//return find(parent[a]);
	return parent[a] = find(parent[a]);//�̷����ϸ� 1����ȭ �� ������ ���ϰ� ���� ��ȯ�����ϴ�. equal �����ڴ� ���Ե� ��(�������� ���������� ���װ��� ������)�� ��ȯ�ϴϱ�.
}

void merge(int a, int b) {
	int ap = find(a); int bp = find(b);
	if (ap == bp) {
		return;
	}
	else if (level[ap] < level[bp]) {
		parent[ap] = bp;
		level[bp] += level[ap];
		level[ap] = 0;
	}
	else {
		parent[bp] = ap;
		level[ap] += level[bp];
		level[bp] = 0;
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i < MAX; i++) {//ó���� �� �ڱ��ڽ��� ����Ű���� ����
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int order, a, b;
		cin >> order >> a >> b;
		if (order == 0) {
			merge(a, b);
		}
		else if (order == 1) {
			int fa = find(a); int fb = find(b);
			if (fa == fb) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
		else {
			cout << "error" << endl;
			return 1;
		}
	}

	return 0;
}