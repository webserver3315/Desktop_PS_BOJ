/*
N과 M(1)


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
array<bool, 9> visit;
vector<int> GlobalVct;
queue<int> KotaeQue;
/*길이 M인 중복없이 N중에서 고른 수열을 모두 구하라.
아아아 ㅅㅂ 사전순 아니네.
1~8까지밖에 없으니 visit 배열 써야겠구만
사전순 아니니까 start 매개변수도 필요하다.
4312는 이중으로 호출된 start매개변수가 자동으로 해결해줄 것이다.

현재 사이즈가 M 초과면 바로 전부출력하고 리턴0 때린다. 사이즈는 kotaeque랑 size매개변수가 동기화된다.

*/

int DFS(array<bool,9>& Localvisit, int depth, int Vctsize) {
	if (depth >= N) {
		return 0;
	}
	else if (Vctsize >= M ) {
		for (int tmp : GlobalVct) {
			cout << tmp << ' ';
		}
		cout << '\n';
		return 0;
	}
	
	for (int i = 1; i <= N; i++) {
		if (Localvisit[i] == false) {
			Localvisit[i] = true;
			GlobalVct.push_back(i);
			DFS(Localvisit, depth + 1, Vctsize + 1);
			Localvisit[i] = false;
			GlobalVct.pop_back();
			DFS(Localvisit, depth + 1, Vctsize);
		}
	}
}


/*
터지는 조건은 N보다 큰 수를 조사하거나, M이 가득 찼을 때.
근데 M이 가득 찼을때면 그냥 끝까지 패싱해버리는게 낫지 않나? 느리더라도 별로 생각 깊게 안해도 된다.
*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;

	DFS(visit, 0, 0);

	return 0;
}