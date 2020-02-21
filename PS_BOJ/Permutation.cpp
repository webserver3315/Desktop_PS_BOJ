/*
nPr
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
#include <ctime>
#define endl '\n'
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



int Permutation(int Selected) {/*kensakuchu�� nCr���� ����Ѵ�. nCr������ i=kensakuchu�� �ʱ�ȭ������, Ǯ��ȸ�ؾ��ϴ� nPr�� �ʿ����.
								  ���, ������ ��� ���հ� �ٸ��� kensakuchu ��� visited�� �ʿ��ϴ�.*/
	if (Selected == M) {
		for (int tmp : Stack) {
			cout << tmp << ' ';
		}
		cout << endl;
		return 0;
	}
	for (int i = 1; i <= N; i++) {/*������ �� ��쿣, kensakuchu ���ڴ� �ʿ����. �ֳ��ϸ� nokori�� kensakuchu�� ������ �����鼭, nokori�� �׻� �����ٴڳ��� �����̴�.*/
		if (!visited[i]) {
			Stack.push_back(i);
			visited[i] = true;
			Permutation(Selected + 1);
			Stack.pop_back();
			visited[i] = false;
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> N >> M;
	Permutation(0);

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << duration << " sec" << endl;
	return 0;
}