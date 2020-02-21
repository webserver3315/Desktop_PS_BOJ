/*
SWEA A ����
������
2ȸ��
*/

#include <iostream>
#include <vector>
#include <deque>
#include <utility>
#define pii pair<int,int>
#define ff first
#define ss second
#define mp(a,b) make_pair(a,b)
#define MAX 10
#define endl '\n'
using namespace std;

vector<pii> newWallPos;
int maxAnzen;
int R, C;
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };
int field[MAX][MAX];//0: ��ĭ, 1: ��, 2: ���̷���

//���� ������ 3���� ������ ��. �ȼ����� �ȵǰ� �� ������ �ȵ�.
//���� 3���� ���� ��, ���������� �ִ���?
//���̷��� ������ 2�� �̻� 10 �����̴�.

/*
int �迭�� ���μ��α��̰� �־����� ��
�ִ���� �۶߷� ���������� ũ�⸦ ��ȯ�ϴ� �Լ��� �����,

���� ����� ��� ����� ���� DFS�� ����� �Լ��� ������.
�� ���, ��üĭ�� ������ �ִ� 64���ϱ�
64C3==64*63*62/2==12������.

1��ȸ ���� Ŀ�������ϴ�.
�۶߸��� �� ��ü�� ������ �����̴ϱ�.
�ϴ� ������ Ǯ� Ǯ�� �� ����. �δ��Ȳ������ �ƴϰ�.
*/

void printArray(int arr[][MAX]) {
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cout << arr[r][c] << ' ';
		}
		cout << endl;
	}
}

int AnzenRyouiki(int lab[][MAX]) {//R,C�� ���������� ��������
	//vector�� ����ü�� lab�� ������ CallByValue�� ���� ������ �� ������, B����� �� �� CBR�� �غ����� �迭�� ����ߴ�.
	//BFS�� �۶߸���.
	deque<pii> viruses;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			if (lab[r][c] == 2) {
				viruses.push_back(mp(r, c));
			}
		}
	}
	while (!viruses.empty()) {
		pii now = viruses.front();
		viruses.pop_front();
		int r = now.ff;
		int c = now.ss;
		for (int i = 0; i < 4; i++) {
			int rr = r + dr[i];
			int cc = c + dc[i];
			if (rr < 0 || cc < 0 || rr >= R || cc >= C || lab[rr][cc] != 0) {
				continue;
			}
			lab[rr][cc] = 2;
			viruses.push_back(mp(rr, cc));
		}
	}
	int Anzen = 0;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			if (lab[r][c] == 0) {
				Anzen++;
			}
		}
	}
	return Anzen;
}//�ٵ� �̷��� �ϸ� ��������field���� �����ؼ� lab�� �ٷ�°� �ƴ϶�, field�� �״�� address�� �ٷ�� ���� �ʳ�? ���� �����ؿ��������.

void MakeSame(int a[][MAX], int b[][MAX]) {
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			a[r][c] = b[r][c];
		}
	}
	return;
}

void DFS(int r, int c, int wallcnt) {
	if (wallcnt == 3) {
		int original[MAX][MAX];
		MakeSame(original, field);
		/*cout << "�۶߸��� ��" << endl;
		printArray(original);
		cout << endl;*/
		int Anzen = AnzenRyouiki(field);
		/*cout << "�۶߸��� ��, ���������� " << Anzen << endl;
		printArray(field);
		cout << endl;*/
		MakeSame(field, original);
		if (Anzen > maxAnzen) {
			maxAnzen = Anzen;
		}
		return;
	}
	else {
		for (; r < R; r++) {
			for (; c < C; c++) {
				if (field[r][c] == 0) {
					//newWallPos.push_back(mp(r, c));
					//cout << r << ' ' << c << " �� ���� ����" << endl;
					field[r][c] = 1;
					DFS(r, c, wallcnt + 1);
					//newWallPos.pop_back();
					//cout << r << ' ' << c << " �� ���� �㹳" << endl;
					field[r][c] = 0;
				}
			}
			c = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cin >> field[r][c];
		}
	}
	DFS(0, 0, 0);
	cout << maxAnzen << endl;

	return 0;
}//Ǫ�µ� 30��15�� �ɸ�