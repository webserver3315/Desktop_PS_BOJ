#include <bits/stdc++.h>
#define endl '\n'
#define int double
#define pdd pair<double,double>
#define ff first
#define ss second
#define mp(a,b) make_pair(a,b)
using namespace std;

typedef struct myLine {//ax+by=c from 1 to 2
	double a, b, c;
	double x1, x2, y1, y2;
}line;

signed N;
vector<line> vct;
vector<pdd> cross;


int det(int a, int b, int c, int d) {
	return a * d - b * c;
}

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {//u12�� u13�� �������� �ݽð�� ���, �ð�� ������ȯ. �Ź߲�����
	return (x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1);
}

bool isCross(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {//���� ���� ������ Ȯ���� Ȯ������
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

pdd getPoint(signed i1, signed i2) {//index1, index2�� ������ ������ �����ٴ� �����Ͽ�. �� isCross�� ����ÿ��� �����.
	int a, b, c, aa, bb, cc;
	a = vct[i1].a; b = vct[i1].b; c = vct[i1].c;
	aa = vct[i2].a; bb = vct[i2].b; cc = vct[i2].c;
	int d1 = det(a, b, aa, bb);//Cramer's Rule
	if (abs(d1 - 0.0) < 0.00000000000001) {//���г� ������ ����Ǿ��ִµ� d1�� 0�̶�� -> �����ѵ� ������???? �ٵ� ������ ���ѱ����� ���ٰ� �ߴµ�??? -> õ��â������ �� �������� �����°Ŵ�.
		//double�� ��� 0�� ���ϸ� �ȵǱ� �ϴµ�...��Ȯ���� ���Ƿ��̶� �ؾ� ��Ȯ�ѵ�; �ϴ� ��������
		int x1 = vct[i1].x1; int x2 = vct[i1].x2; int y1 = vct[i1].y1; int y2 = vct[i1].y2;
		int x3 = vct[i2].x1; int x4 = vct[i2].x2; int y3 = vct[i2].y1; int y4 = vct[i2].y2;
		int xx, yy;
		if (x1 == x3 && y1 == y3) {
			xx = x1;
			yy = y1;
		}
		else if (x1 == x4 && y1 == y4) {
			xx = x1;
			yy = y1;
		}
		else if (x2 == x3 && y2 == y3) {
			xx = x2;
			yy = y2;
		}
		else if (x2 == x4 && y2 == y4) {
			xx = x2;
			yy = y2;
		}
		return mp(yy, xx);
	}
	int d2 = det(c, b, cc, bb);
	int d3 = det(a, c, aa, cc);
	int xx = d2 / d1;
	int yy = d3 / d1;
	return mp(yy, xx);//y �켱�����̴ϱ�
}

line makeLine(int x1, int y1, int x2, int y2) {
	int a, b, c;
	a = y2 - y1;
	b = x1 - x2;
	c = x1 * (y2 - y1) - y1 * (x2 - x1);
	line ret;
	ret.a = a; ret.b = b; ret.c = c;
	ret.x1 = x1; ret.x2 = x2; ret.y1 = y1; ret.y2 = y2;
	return ret;
}

signed main() {
	//ios::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);
	cout << setprecision(3);

	cin >> N;
	for (signed i = 0; i < N; i++) {
		double a, b, c, d;
		cin >> a >> b >> c >> d;
		line tmp = makeLine(a, b, c, d);
		vct.push_back(tmp);
	}

	for (signed i = 0; i < vct.size(); i++) {
		for (signed j = 0; j < i; j++) {
			if (isCross(vct[i].x1, vct[i].y1, vct[i].x2, vct[i].y2,
				vct[j].x1, vct[j].y1, vct[j].x2, vct[j].y2)) {
				//cout << i+1 << " �� ���а� " << j+1 << " �� ������ ������ Ȯ���� �ִ�!!!!!!" << endl;
				cross.push_back(getPoint(i, j));
			}
		}
	}
	sort(cross.begin(), cross.end(),greater<pdd>());//��������
	//cout << cross[0].ss << endl;
	printf("%.3lf\n", cross[0].ss);

	return 0;
}