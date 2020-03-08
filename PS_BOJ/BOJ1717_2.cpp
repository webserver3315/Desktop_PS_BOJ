#include <iostream>
#include <cstring>
#define MAX (int)1e6+1
#define endl '\n'
using namespace std;

int N, M;
int parent[MAX];

int find(int n) {
	if (parent[n] < 0)
		return n;
	parent[n] = find(parent[n]);//부모의 부모의 부모의... 제일 근본적인 부모를 찾아서 업데이트해야만 한다.
	return parent[n];//사실 위의 문장과 통합해도 된다.
}

void merge(int a, int b) {//a에 b를 합친다
	a = find(a);
	b = find(b);
	if (a == b)
		return;//동일 집단이었다면 건들지 않는다.
	parent[a] += parent[b];//이렇게 처리하면, 최종 루트노드의 value값에는 루트노드와 같은 그룹의 크기가 음수로 저장되게 된다.
	parent[b] = a;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	memset(parent, -1, sizeof(parent));//이걸 while문 내에 넣어버리는 바람에 삽질했다
	while (M--) {
		int order, a, b;
		cin >> order >> a >> b;
		if (order == 0) {
			merge(a, b);
		}
		else if (order == 1) {
			if (find(a) == find(b))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
		else
			cerr << "ERROR" << endl;
	}
	return 0;
}