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

/*순열은 visited가 필요하다. 대신 kensakuchu 인자가 필요없다.
IsComplete조건은 인자가 1개니, 당연히 판별 단 1번만 하면 된다. r개 채워졌는지만 확인하면 된다.
단, for 루프에서 visited 여부 체크를 해줘야 함을 빼먹어선 안된다.
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
			visited[i] = true;/*visit 값 수정 반드시 해줘야 한다!!!*/
			Permutation(Selected + 1);/*인자는 i가 아니라, Selected + 1 이다!!!*/
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