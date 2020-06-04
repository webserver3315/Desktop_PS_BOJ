#include <bits/stdc++.h>
#define endl '\n'
#define MAX 3001
using namespace std;

/*
���б׷�
�׷������ UFT��
*/

typedef struct myLine {//ax+by=c, s<=x<=e
	int x1, y1, x2, y2;
	int a, b, c, s, e;
}line;

int N;
int par[MAX];
line arr[MAX];
int childnum[MAX];

line makeLine(int x1, int y1, int x2, int y2) {
	int a, b, c, s, e;
	a = y2 - y1;
	b = x1 - x2;
	c = x1 * (y2 - y1) - y1 * (x2 - x1);
	s = min(x1, x2);
	e = max(x1, x2);
	line ret;
	ret.a = a; ret.b = b; ret.c = c; ret.s = s; ret.e = e;
	return ret;
}

int det(int a, int b, int c, int d) {
	return a * d - b * c;
}

bool intersect(int i1, int i2) {//index1, index2�� ������ �����ϸ� true, �ȸ����� false
	int a, b, c, aa, bb, cc, s, ss, e, ee;
	a = arr[i1].a; b = arr[i1].b; c = arr[i1].c; s = arr[i1].s; e = arr[i1].e;
	aa = arr[i2].a; bb = arr[i2].b; cc = arr[i2].c; ss = arr[i2].s; ee = arr[i2].e;
	int d1 = det(a, b, aa, bb);
	if (d1 == 0) {//�� ������ identical�ϰų� ����
		if (a * cc == aa * c) {//�ƿ� ���ٸ�,
			if (min(e, ee) >= max(s, ss)) return true;//x���� ��ġ���� Ȯ��
			return false;
		}
		else {//�����ϴٸ� ���� �ȸ���
			return false;
		}
	}
	else {//���� �ٸ�
		int d2 = det(c, b, cc, bb);
		int d3 = det(a, c, aa, cc);
		float xx = float(d2) / d1; float yy = float(d2) / d1;
		if (max(s, ss) <= xx && xx <= min(e, ee)) return true;//x���� ��ġ���� Ȯ��
		return false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		arr[i] = makeLine(x1, y1, x2, y2);
	}
	//for (int i = 0; i < N; i++) {
	//	for (int j = i+1; j < N; j++) {
	//		if (intersect(i, j))
	//			cout << i << " �� ���а� " << j << " �� ������ ������!!!" << endl;
	//		else
	//			cout << i << " �� ���а� " << j << " �� ������ �ȸ�����" << endl;
	//	}
	//}

	for (int i = 0; i < N; i++) {
		par[i] = i;
		childnum[i] = 1;
	}

	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			if (intersect(i, j)) {
				merge(i, j);
			}
		}
	}

	int grpcnt = 0;
	for (int i = 0; i < N; i++) {
		if (par[i] == i) grpcnt++;
	}
	int max = 0;
	for (int i = 0; i < N; i++) {
		if (max < childnum[i]) max = childnum[i];
	}
	cout << grpcnt << endl << max << endl;

	return 0;
}