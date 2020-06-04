#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;


/*
�̵� �ٽ� Ǯ �� ������ ��.
https://hsdevelopment.tistory.com/390
https://snowfleur.tistory.com/108

*/

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {//u12�� u13�� �������� �ݽð�� ���, �ð�� ������ȯ. �Ź߲�����
	//return (x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1);
	if ((x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1) > 0) return 1;
	else if ((x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1) < 0) return -1;
	else return 0;
}

bool isCross(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {//�ŷڰ����� �����Ǻ��Լ�
	if (ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4) == 0 &&
		ccw(x3, y3, x4, y4, x1, y1) * ccw(x3, y3, x4, y4, x2, y2) == 0) {//���� -> �������� or �������� or ������ 3��1
		if ((min(x1, x2) <= max(x3, x4) && min(x3, x4) <= max(x1, x2)) ||
			min(y1, y2) <= max(y3, y4) && min(y3, y4) <= max(y1, y2)) return true;
		else return false;
	}
	else if (ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4) <= 0 &&
		ccw(x3, y3, x4, y4, x1, y1) * ccw(x3, y3, x4, y4, x2, y2) <= 0) {//�ٸ� ���� �� ���� ���� �Ѵ� ���� -> �����̶�� ������ �����ٴ°�
		return true;
	}
	return false;
}
/*
�� �Լ� �ݷ�
1
91694 48046 32986 7003
32159 94057 95298 91455
���� �Ӱ��� �����ϱ� ������ �����ϱ�
*/

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t;
	cin >> t;
	for (int i = 1; i <= t;i++) {
		if (i == 13) {
			cout << 1010101010 << endl;
			cout << 1010101010 << endl;
			printf("stop");
			cout << 1010101010 << endl;
		}
		int x1; int y1; int x2; int y2; int x3; int y3; int x4; int y4;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

		if (isCross(x1, y1, x2, y2, x3, y3, x4, y4))
			cout << 1 << endl;
		else cout << 0 << endl;
	}
	
	return 0;
}