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
nPr을 구할 때는 이 재귀문을 써야한다.
우선, visited 배열이 필요하고,(nCr과는 다르다!)
IsComplete조건은 nokori가 0일 때==출력 후 자폭 / kensakuchu(=커서)가 끝에 다다랐을 때는 가냥 자폭

for문을 순회하는데, for문은 첫 원소부터 마지막 원소까지 항상 순회시킨다.
가끔 감 떨어질 때 하는 실수인데, DFS 내에서의 DFS 호출은 단 1번만 하면 된다.
미연시선지마냥 푸시, DFS, 팝, DFS 하면 안된다는 말이다. 푸시 DFS 팝 으로 끝내야한다.
또한, 푸시 팝의 연산 이전에 nPr같은 경우는, 반드시 visited 여부를 확인해야만 한다는 것에 주의해야한다.
visited 여부의 확인 여부가 nPr과 nCr의 차이점이다.

DFS의 인자는 모함수 인자인 kensakuchu가 아닌, 배열[i]로 잡아야 한다.
*/
void Permutation(int nokori) {/*솔직히 이 경우엔, kensakuchu 인자는 필요없다. 왜냐하면 nokori와 kensakuchu의 보폭이 같으면서, nokori가 항상 먼저바닥나기 때문이다.*/
	if (nokori == 0) {
		for (int tmp : Stack) {
			cout << tmp << ' ';
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) {/*kensakuchu는 nCr에서 사용한다. nCr에서는 i=kensakuchu로 초기화되지만, 풀순회해야하는 nPr은 필요없다.
								  대신, 순열의 경우 조합과 다르게 kensakuchu 대신 visited가 필요하다.*/
		if (visited[i] == false) {/*P의 경우, visited 체크!!!!*/
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