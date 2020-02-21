/*

*/

#include <iostream>
#include <string>
#include <queue>
#include <deque>
#include <algorithm>
#include <vector>
#include <array>
#include <cmath>
#include <cstdio>
using namespace std;

int N, M;
vector<int> Stack;
bool visited[10];

/*
nPr�� ���� ���� �� ��͹��� ����Ѵ�.
�켱, visited �迭�� �ʿ��ϰ�,(nCr���� �ٸ���!)
IsComplete������ nokori�� 0�� ��==��� �� ���� / kensakuchu(=Ŀ��)�� ���� �ٴٶ��� ���� ���� ����

for���� ��ȸ�ϴµ�, for���� ù ���Һ��� ������ ���ұ��� �׻� ��ȸ��Ų��.
���� �� ������ �� �ϴ� �Ǽ��ε�, DFS �������� DFS ȣ���� �� 1���� �ϸ� �ȴ�.
�̿��ü������� Ǫ��, DFS, ��, DFS �ϸ� �ȵȴٴ� ���̴�. Ǫ�� DFS �� ���� �������Ѵ�.
����, Ǫ�� ���� ���� ������ nPr���� ����, �ݵ�� visited ���θ� Ȯ���ؾ߸� �Ѵٴ� �Ϳ� �����ؾ��Ѵ�.
visited ������ Ȯ�� ���ΰ� nPr�� nCr�� �������̴�.

DFS�� ���ڴ� ���Լ� ������ kensakuchu�� �ƴ�, �迭[i]�� ��ƾ� �Ѵ�.
*/
void Permutation(int nokori) {/*������ �� ��쿣, kensakuchu ���ڴ� �ʿ����. �ֳ��ϸ� nokori�� kensakuchu�� ������ �����鼭, nokori�� �׻� �����ٴڳ��� �����̴�.*/
	if (nokori == 0) {
		for (int tmp : Stack) {
			cout << tmp << ' ';
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) {/*kensakuchu�� nCr���� ����Ѵ�. nCr������ i=kensakuchu�� �ʱ�ȭ������, Ǯ��ȸ�ؾ��ϴ� nPr�� �ʿ����.
								  ���, ������ ��� ���հ� �ٸ��� kensakuchu ��� visited�� �ʿ��ϴ�.*/
		if (visited[i] == false) {/*P�� ���, visited üũ!!!!*/
			Stack.push_back(i);
			visited[i] = true;
			Permutation(nokori - 1);
			visited[i] = false;
			Stack.pop_back();
		}
		else
			continue;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	Permutation(M);
	return 0;
}