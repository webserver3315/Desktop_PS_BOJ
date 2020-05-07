/*
nCr
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

/*조합의 경우, 순열과 다르게 visited가 필요없는 대신, dfs의 인자 수가 하나 더 늘어난다.
전진만 하면 되므로, kensakuchu 인자를 추가로 가져간다.

kensakuchu 인자가 들어옴으로써 인자가 총 2개가 되었으니, 정석적으로 한다면 IsComplete문 또한 두 가지 인자를 모두 고려하는 방향대로 만들어져야 한다.
대신, 실행부에서의 visited 체크는 당연히 없으니 필요없다.*/
void Combination(int Start, int Selected) {
	if (Selected == M) {
		for (int tmp : Stack) {
			cout << tmp << ' ';
		}
		cout << endl;
		return;
	}
	for (int i = Start; i <= N; i++) {/*kensakuchu부터 시작하는걸로 해야한다. 앞만보고 전진하도록 했으니까.*/
		Stack.push_back(i);
		Combination(i + 1, Selected + 1);/*또 실수했다, Start가 아니라 i를 인자로 가져와야 한다!!!!!!!!!!*/
		Stack.pop_back();
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> N >> M;
	Combination(1, 0);

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << ctime_duration << " ms" << endl;
	return 0;
}