/*
후위순회로 아예 깔끔하게 풀 생각은 안하고 그냥 우직하게 구현했는데,
교묘하게 후위순회 사용시 아주 짧게 풀리는구나.
잎노드부터 수색할 필요가 있을때는(Bottom-Up식 수색) 앞으로 후위순회를 떠올리도록 하자.

참조:
https://jklh0202.tistory.com/1
*/

#include <iostream>
#include <string>
#include <vector>
#define MAX 123457
#define endl '\n'
#define int long long
using namespace std;

int N;
vector<int> parent;
vector<vector<int>> child;
vector<int> population;

int postorder(int now) {
	int cnt = population[now];
	for (int i : child[now]) {
		cnt += postorder(i);
	}
	return cnt < 0 ? 0 : cnt;
}

signed main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	++N;
	parent.resize(N, -1);
	population.resize(N, 0);
	child.resize(N);
	for (int i = 2; i < N; i++) {
		string tmpstr; int popu; int next;
		cin >> tmpstr >> popu >> next;
		if (tmpstr == "W")
			popu *= -1;//늑대는 음수의 인구로 표기
		parent[i] = next;
		population[i] = popu;
		child[next].push_back(i);
	}
	cout << postorder(1) << endl;
	return 0;
}