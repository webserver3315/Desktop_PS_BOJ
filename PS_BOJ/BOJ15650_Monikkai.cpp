/*
N�� M(2)
nCm�� ����Ͻÿ�
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

/*������ ���, ������ �ٸ��� visited�� �ʿ���� ���, dfs�� ���� ���� �ϳ� �� �þ��.
������ �ϸ� �ǹǷ�, kensakuchu ���ڸ� �߰��� ��������.

kensakuchu ���ڰ� �������ν� ���ڰ� �� 2���� �Ǿ�����, ���������� �Ѵٸ� IsComplete�� ���� �� ���� ���ڸ� ��� ����ϴ� ������ ��������� �Ѵ�.
���, ����ο����� visited üũ�� �翬�� ������ �ʿ����.*/

void Combination(int kensakuchu, int nokori) {
	if (nokori == 0) {
		for (int tmp : Stack) {
			cout << tmp << ' ';
		}
		cout << endl;
		return;
	}
	else if (kensakuchu == N + 1) {/*kensakuchu�� IsComplete 2���������� �ھҴµ�, kensaku�� nokori�� ����ȭ�Ǿ��ִ� �̻�, ������ �ʿ���� �ڵ��.*/
		return;
	}
	for (int i = kensakuchu; i <= N; i++) {/*kensakuchu���� �����ϴ°ɷ� �ؾ��Ѵ�. �ո����� �����ϵ��� �����ϱ�.*/
		Stack.push_back(i);
		Combination(i + 1, nokori - 1);/* ������ ���� �ϴ� �Ǽ��ε�, kensakuchu+1�� �ƴ϶� i+1�̴�! */
		Stack.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	Combination(1, M);
	return 0;
}