/*
집합의 표현
*/

#include <iostream>
#define endl '\n'
#define MAX (int)1e6+5
using namespace std;


int n, m;
int parent[MAX];
int level[MAX];//경로 최적화를 위해서는 root별 level도 별도로 유지해줘야한다


int find(int a) {
	if (parent[a] == a)
		return a;
	//return find(parent[a]);
	return parent[a] = find(parent[a]);//이렇게하면 1레벨화 및 적절한 리턴값 또한 반환가능하다. equal 연산자는 대입된 값(엄밀히는 대입이후의 좌항값의 참조자)을 반환하니까.
}

void merge(int a, int b) {
	int ap = find(a); int bp = find(b);
	if (ap == bp) {
		return;
	}
	else if (level[ap] < level[bp]) {
		parent[ap] = bp;
		level[bp] += level[ap];
		level[ap] = 0;
	}
	else {
		parent[bp] = ap;
		level[ap] += level[bp];
		level[bp] = 0;
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i < MAX; i++) {//처음엔 다 자기자신을 가리키도록 세팅
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int order, a, b;
		cin >> order >> a >> b;
		if (order == 0) {
			merge(a, b);
		}
		else if (order == 1) {
			int fa = find(a); int fb = find(b);
			if (fa == fb) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
		else {
			cout << "error" << endl;
			return 1;
		}
	}

	return 0;
}