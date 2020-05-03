#include <iostream>
#include <cstring>
#define MAX (int)1e6+1
#define endl '\n'
using namespace std;

int N, M;
int parent[MAX];

int find(int n) {
	if (parent[n] < 0)
		return n;
	parent[n] = find(parent[n]);//�θ��� �θ��� �θ���... ���� �ٺ����� �θ� ã�Ƽ� ������Ʈ�ؾ߸� �Ѵ�.
	return parent[n];//��� ���� ����� �����ص� �ȴ�.
}

void merge(int a, int b) {//a�� b�� ��ģ��
	a = find(a);
	b = find(b);
	if (a == b)
		return;//���� �����̾��ٸ� �ǵ��� �ʴ´�.
	parent[a] += parent[b];//�̷��� ó���ϸ�, ���� ��Ʈ����� value������ ��Ʈ���� ���� �׷��� ũ�Ⱑ ������ ����ǰ� �ȴ�.
	parent[b] = a;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	memset(parent, -1, sizeof(parent));//�̰� while�� ���� �־������ �ٶ��� �����ߴ�
	while (M--) {
		int order, a, b;
		cin >> order >> a >> b;
		if (order == 0) {
			merge(a, b);
		}
		else if (order == 1) {
			if (find(a) == find(b))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
		else
			cerr << "ERROR" << endl;
	}
	return 0;
}