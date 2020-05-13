#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

/*
��Ʈ��ũ ���� ����
�ּҽ���Ʈ��
ũ�罺Į�� Ǯ��
ũ�罺Į�� ���Ͽ����ε�� ����
https://www.acmicpc.net/problem/1922 ����
*/

struct Edge {
	int u, v, w;
	Edge() : Edge(-1, -1, 0) {}
	Edge(int uu, int vv, int ww) : u(uu), v(vv), w(ww) {}
	bool operator <(const Edge& O)const { return w < O.w; }
};

int par[1001];
Edge e[(int)1e5];

int find(int a) {
	if (par[a] < 0) return a;
	return par[a] = find(par[a]);
}

bool merge(int a, int b) {
	a = find(a); b = find(b);
	if (a == b) return false;//�̹� ���� chunk �Ҽ��̶�� ���� ��ȯ
	else par[b] = a;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	fill(par, par + n, -1);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		e[i] = Edge(a - 1, b - 1, c);
	}
	sort(e, e + m);

	int result = 0, cnt = 0;
	for (int i = 0;; i++) {
		if (merge(e[i].u, e[i].v)) {
			result += e[i].w;
			if (++cnt == n - 1) break;
		}
	}
	cout << result << endl;
	return 0;
}