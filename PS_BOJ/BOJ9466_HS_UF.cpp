#include <iostream>

using namespace std;
#define MAX 100010
int arr[MAX], ans, N, T;
int root[MAX];
int Rank[MAX]; // Ʈ���� ���̸� ������ �迭
/* find(x): ��� �̿� */
int find(int x) {
	if (root[x] == x) {
		return x;
	}
	else {
		// "��� ����(Path Compression)"
		// find �ϸ鼭 ���� ��� ���� �θ� ��带 root�� �����.
		return root[x] = find(root[x]);
	}
}

/* union1(x, y): union-by-Rank ����ȭ */
void union1(int x, int y) {
	x = find(x);
	y = find(y);

	// �� ���� root�� ������(�̹� ���� Ʈ��) ��ġ�� �ʴ´�.
	if (x == y)
		return;

	// "union-by-Rank ����ȭ"
	// �׻� ���̰� �� ���� Ʈ���� ���̰� ���� Ʈ�� �ؿ� �ִ´�. ��, ���̰� �� ���� ���� root�� ����
	if (Rank[x] < Rank[y]) {
		root[x] = y; // x�� root�� y�� ����
	}
	else {
		root[y] = x; // y�� root�� x�� ����

		if (Rank[x] == Rank[y])
			Rank[x]++; // ���� ���̰� ���ٸ� ��ģ �� (x�� ���� + 1)
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N;
		for (int i = 0; i < N; i++) {
			root[i] = i;
		}


	}

}