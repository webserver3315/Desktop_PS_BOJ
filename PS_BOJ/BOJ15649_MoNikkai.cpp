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
#define endl '\n'
using namespace std;

int N, M;
vector<int> Stack;
bool visited[10];

/*������ visited�� �ʿ��ϴ�. ��� kensakuchu ���ڰ� �ʿ����.
IsComplete������ ���ڰ� 1����, �翬�� �Ǻ� �� 1���� �ϸ� �ȴ�. r�� ä���������� Ȯ���ϸ� �ȴ�.
��, for �������� visited ���� üũ�� ����� ���� ���Ծ �ȵȴ�.
*/
void Permutation(int Selected) {
	if (Selected == M) {
		for (int tmp : Stack) {
			cout << tmp << ' ';
		}
		cout << endl;
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			Stack.push_back(i);
			visited[i] = true;/*visit �� ���� �ݵ�� ����� �Ѵ�!!!*/
			Permutation(Selected + 1);/*���ڴ� i�� �ƴ϶�, Selected + 1 �̴�!!!*/
			visited[i] = false;
			Stack.pop_back();
		}
		else
			continue;
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	Permutation(0);
}