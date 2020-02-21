/*
N과 M(2)
nCm을 출력하시오
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

/*조합의 경우, 순열과 다르게 visited가 필요없는 대신, dfs의 인자 수가 하나 더 늘어난다.
전진만 하면 되므로, kensakuchu 인자를 추가로 가져간다.

kensakuchu 인자가 들어옴으로써 인자가 총 2개가 되었으니, 정석적으로 한다면 IsComplete문 또한 두 가지 인자를 모두 고려하는 방향대로 만들어져야 한다.
대신, 실행부에서의 visited 체크는 당연히 없으니 필요없다.*/

void Combination(int kensakuchu, int nokori) {
	if (nokori == 0) {
		for (int tmp : Stack) {
			cout << tmp << ' ';
		}
		cout << endl;
		return;
	}
	else if (kensakuchu == N + 1) {/*kensakuchu를 IsComplete 2차조건으로 박았는데, kensaku와 nokori가 동기화되어있는 이상, 솔직히 필요없는 코드다.*/
		return;
	}
	for (int i = kensakuchu; i <= N; i++) {/*kensakuchu부터 시작하는걸로 해야한다. 앞만보고 전진하도록 했으니까.*/
		Stack.push_back(i);
		Combination(i + 1, nokori - 1);/* 굉장히 자주 하는 실수인데, kensakuchu+1이 아니라 i+1이다! */
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