/*
https://velog.io/@skyepodium/%EB%B0%B1%EC%A4%80-1068-%ED%8A%B8%EB%A6%AC
*/
#include <iostream>
#include <vector>
#include <queue>

#define max_int 51
using namespace std;

//�ð� ���⵵: O(n)
//���� ���⵵: O(n)
//����� �˰���: BFS
//����� �ڷᱸ��: ���� ����Ʈ


int n, num, root_node, result = 0;
// �׷����� ������ ���� ����Ʈ
vector<int> v[max_int];

// ���� �湮 ���θ� ������ �迭
bool check[max_int];

// BFS�� �׷����� Ž���մϴ�.
void bfs(int start) {
	check[start] = true;
	queue<int> q;
	q.push(start);

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		// �ڽ��� ���ڸ� ����� ����
		int child_cnt = 0;
		for (int i = 0; i < v[node].size(); i++) {
			int next = v[node][i];
			if (!check[next]) {
				child_cnt++;
				check[next] = true;
				q.push(next);
			}
		}
		// �ڽ��� ������ �ܸ� ��� ����� 1 ���� ��ŵ�ϴ�.
		if (child_cnt == 0) {
			result++;
		}
	}
}

int main() {
	// 1. �Է�
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		// 1) ���� ����Ʈ�� ����ؼ� ����� �׷����� Ʈ���� ������ݴϴ�.
		if (num != -1) {
			v[num].push_back(i);
			v[i].push_back(num);

		}
		// 2) ��Ʈ ����� ��� ǥ���մϴ�.
		else {
			root_node = i;
		}
	}

	// 2. ���� ��� ǥ��
	scanf("%d", &num);
	check[num] = true;

	// 3. ���� ������ ��尡 ��Ʈ ��尡 �ƴ϶�� Ž���� �����մϴ�.
	if (!check[root_node]) bfs(root_node);

	// 4. ���
	printf("%d\n", result);
}
/*
5
-1 -1 -1 0 0
0
�̰� 2 ���;� �ϴµ� ���� 1���� ����߳�
���ʿ� ��Ʈ�� �� �ϳ���� ���� ������ Ʈ����� ���� ����Ǿ��ִٰ� ġ�°ǰ�?
*/