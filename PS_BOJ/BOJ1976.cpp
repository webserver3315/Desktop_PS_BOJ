/*
여행가자
*/

#include <iostream>
#define endl '\n'
#define MAX (int)1005
using namespace std;

/*
연결된 도시들을 유니온파인드로 그룹화한다
그룹화 종료 후, 여행계획을 정방향순회하며 모두 동일그룹인지 조사한다.
어차피 돌아서 가도 직통과 같이 취급하므로, 인접유무가 중요하지 않다.
동일그룹이 아닌 도시가 단 하나라도 나오면 터트린다.
*/

int n, m;
int adj[MAX][MAX];
int tripseq[MAX];
int prt[MAX];
int level[MAX];

int find(int a) {
	if (prt[a] == a)
		return a;
	return prt[a] = find(prt[a]);
}

void merge(int a, int b) {
	int pa = find(a); int pb = find(b);
	if (pa == pb)
		return;
	else if (level[pa] < level[pb]) {
		level[pb]++;
		level[pa] = 0;
		prt[pa] = pb;
	}
	else {
		level[pa]++;
		level[pb] = 0;
		prt[pb] = pa;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {//유니온파인드트리는 사용 전 반드시 초기화하는거 잊지말것!
		prt[i] = i;
	}

	for (int from = 1; from <= n; from++) {//도시는 1번부터 시작
		for (int to = 1; to <= n; to++) {
			/*cin >> adj[from][to];*/
			int tmp;
			cin >> tmp;
			if (tmp)
				merge(from, to);
		}
	}

	for (int i = 0; i < m; i++)
		cin >> tripseq[i];

	int group = find(tripseq[0]);
	for (int i = 1; i < m; i++) {
		if (group != find(tripseq[i])) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}