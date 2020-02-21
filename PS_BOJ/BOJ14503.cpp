#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <utility>
#define MAX (int)55
#define endl '\n'
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second

//����==(����+2)%4
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

using namespace std;

int t;
int R, C;
int rr, cc;
int mode;
int field[MAX][MAX];
bool cleaned[MAX][MAX];
int cnt;
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

int Soji() {
	while (1) {
		if (!cleaned[rr][cc]) {//1�� ����
			cleaned[rr][cc] = true;
			cnt++;
		}
		for (int i = 0; i < 5; i++) {//2�� ����
			if (i == 4) {//�����¿� ��� ����� ���
				int rrr = rr + dr[(mode + 2) % 4]; int ccc = cc + dc[(mode + 2) % 4];//rrr,ccc==������ ���� �Ǵ� ĭ
				if (field[rrr][ccc] == 1)//�ڰ� ���̸� ���������.
					return cnt;
				else {//���Ŭ���ε� �ڰ� ���� �ƴ� ���, �����ϰ� 2������ ����Ѵ�.
					rr = rrr; cc = ccc;
					break;
				}
			}
			int rrr = rr + dr[i]; int ccc = cc + dc[i];
			if (!cleaned[rrr][ccc] && field[rrr][ccc] == 0)//�� �ƴϰ� û�� �ȵ� ĭ ������ ������.
				break;
		}
		//������� �Դٴ� ����, �� ���� �� û�� �ȵ� �� �ƴ� ĭ�� �ִٴ� ��.
		int rrr, ccc;
		for (int i = 0; i < 4; i++) {
			int newMode = abs((mode - i) % 4);//��>��>��>��...������ �����Ѵ�.
			rrr = rr + dr[newMode]; ccc = cc + dc[newMode];
			if (!cleaned[rrr][ccc] && field[rrr][ccc] == 0)
				break;
		}
		rr = rrr; cc = ccc;
		continue;
	}
	return -1;
}


int main() {
	cin >> t;
	while (t--) {
		int cnt = 0;
		cin >> R >> C;
		cin >> rr >> cc >> mode;
		for (int i = 0; i < MAX; i++) {
			memset(field[i], 0, MAX);
			memset(cleaned[i], false, MAX);
		}
		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				cin >> field[r][c];
			}
		}
		Soji();
		cout << cnt << endl;
	}
	return 0;
}