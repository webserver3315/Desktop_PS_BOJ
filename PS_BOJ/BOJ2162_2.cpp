#include <bits/stdc++.h>
#define endl '\n'
#define MAX 3001
using namespace std;

/*
���б׷�
�� ���б����Ǻ��Լ��� ������ �ִ� �� ����.
https://hugssy.tistory.com/119 ����
*/

typedef struct myLine {
	int x1, y1;
	int x2, y2;
}line;

int N;
int par[MAX];
line vct[MAX];
int chd[MAX];

int find(int a) {//par�迭�� ���� �ڱ��ּҷ� �ʱ�ȭ�Ǿ���Կ� ����
	if (par[a] == a) return a;
	return par[a] = find(par[a]);
}

void merge(int a, int b) {//b�� a ���� -> merge a2b
	par[find(a)] = find(b);
}

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {//u12�� u13�� �������� �ݽð�� ���, �ð�� ������ȯ. �Ź߲�����
	return (x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1);
}

bool isCross(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	if (ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4) <= 0 &&
		ccw(x3, y3, x4, y4, x1, y1) * ccw(x3, y3, x4, y4, x2, y2) <= 0) {//����� �ϴ� �����̶�� ������ �����ٴ°�
		if ((x1 > x3 && x1 > x4 && x2 > x3 && x2 > x4) ||//x ��Ÿ��� �������������� ������
			(x3 > x1 && x3 > x2 && x4 > x1 && x4 > x2)) return false;
		else if ((y1 > y3 && y1 > y4 && y2 > y3 && y2 > y4) ||//y ��Ÿ��� �������������� ������
			(y3 > y1 && y3 > y2 && y4 > y1 && y4 > y2)) return false;
		else return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) par[i] = i;//par�ʱ�ȭ
	for (int i = 1; i <= N; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		vct[i].x1 = x1;	vct[i].y1 = y1;
		vct[i].x2 = x2;	vct[i].y2 = y2;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (isCross(vct[i].x1, vct[i].y1,
				vct[i].x2, vct[i].y2,
				vct[j].x1, vct[j].y1,
				vct[j].x2, vct[j].y2
			)) merge(i, j);
		}
	}

	for (int i = 1; i <= N; i++) {
		chd[find(i)]++;
	}
	int cnt = 0;//�׷��
	int maxnum = 0;
	for (int i = 1; i <= N; i++) {
		if (chd[i] > 0) cnt++;
		if (maxnum < chd[i]) maxnum = chd[i];
	}
	cout << cnt << endl << maxnum << endl;

	return 0;
}