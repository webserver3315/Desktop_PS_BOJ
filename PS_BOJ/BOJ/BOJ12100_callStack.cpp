/*
2048(EASY)

>>>�浹/��ħ ��Ȳ�� �ذ��ؾ��ϴ� ���ڸ� ������ ������ ����ȴ�.
��� �Ϲ������� Ǯ�� �� �ذ���� ����غ���.

�����¿� 4���� ������ 5�� �ݺ��ϴ°��̹Ƿ�, 2�� 10�� �� 1000�����ۿ� �ȵȴ�.
�ùķ��̼� �������ѳ��� ���Ʈ���� ������ �ȴ�.
��, 1���̹Ƿ� ���̽��� 1���� ���� ���� �������Ѵ�
*/

#include <iostream>
#include <vector>
#define endl '\n'
#define MAX 25
using namespace std;

int N;
int field_Original[MAX][MAX];
//int field_Ima[MAX][MAX];
int maxval;
vector<vector<int>> dfsway;

void fieldInitialize(int**& field_Ima) {
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			field_Ima[r][c] = field_Original[r][c];
		}
	}
}

void GoDown(int r, int c, int**& field_Ima) {
	if (!field_Ima[r][c] || r > N || c > N || r < 1 || c < 1)
		return;
	int rr = r; int cc = c;
	while (rr < N && !field_Ima[rr + 1][c]) {//�����̳� �ε����� ������ ��½�Ų��
		rr++;
	}
	if (rr == N) {//������� ������
		field_Ima[rr][cc] = field_Ima[r][c];
		field_Ima[r][c] = 0;
	}
	else if (field_Ima[rr + 1][cc]) {//�ε����� ��������
		int rrr = rr + 1; int ccc = c;
		if (field_Ima[rrr][ccc] == field_Ima[rr][cc]) {//������ ���� �����Ѵ�
			field_Ima[rrr][ccc] *= 2;
			if (maxval < field_Ima[rrr][ccc])
				maxval = field_Ima[rrr][ccc];
			field_Ima[r][c] = 0;
		}
		else {//�ƴϸ� �ű� ä �״�� �д�.
			field_Ima[rr][cc] = field_Ima[r][c];
			field_Ima[r][c] = 0;
		}
	}
	else {
		cout << "ERROR" << endl;
	}
}

void GoRight(int r, int c, int**& field_Ima) {
	if (!field_Ima[r][c] || r > N || c > N || r < 1 || c < 1)
		return;
	int rr = r; int cc = c;
	while (cc < N && !field_Ima[rr][c + 1]) {//�����̳� �ε����� ������ ��½�Ų��
		cc++;
	}
	if (cc == N) {//������� ������
		field_Ima[rr][cc] = field_Ima[r][c];
		field_Ima[r][c] = 0;
	}
	else if (field_Ima[rr][cc + 1]) {//�ε����� ��������
		int rrr = rr; int ccc = cc + 1;
		if (field_Ima[rrr][ccc] == field_Ima[rr][cc]) {//������ ���� �����Ѵ�
			field_Ima[rrr][ccc] *= 2;
			if (maxval < field_Ima[rrr][ccc])
				maxval = field_Ima[rrr][ccc];
			field_Ima[r][c] = 0;
		}
		else {//�ƴϸ� �ű� ä �״�� �д�.
			field_Ima[rr][cc] = field_Ima[r][c];
			field_Ima[r][c] = 0;
		}
	}
	else {
		cout << "ERROR" << endl;
	}
}

void GoLeft(int r, int c, int**& field_Ima) {
	if (!field_Ima[r][c] || r > N || c > N || r < 1 || c < 1)
		return;
	int rr = r; int cc = c;
	while (cc > 1 && !field_Ima[rr][cc - 1]) {//�����̳� �ε����� ������ ��½�Ų��
		cc--;
	}
	if (cc == 1) {//������� ������
		field_Ima[rr][cc] = field_Ima[r][c];
		field_Ima[r][c] = 0;
	}
	else if (field_Ima[rr][cc - 1]) {//�ε����� ��������
		int rrr = rr; int ccc = cc - 1;
		if (field_Ima[rrr][ccc] == field_Ima[rr][cc]) {//������ ���� �����Ѵ�
			field_Ima[rrr][ccc] *= 2;
			if (maxval < field_Ima[rrr][ccc])
				maxval = field_Ima[rrr][ccc];
			field_Ima[r][c] = 0;
		}
		else {//�ƴϸ� �״�� �д�.
			field_Ima[rr][cc] = field_Ima[r][c];
			field_Ima[r][c] = 0;
		}
	}
	else {
		cout << "ERROR" << endl;
	}
}

void GoUp(int r, int c, int**& field_Ima) {//r c�� ĭ�� ������ �� ��½�Ų��
	if (!field_Ima[r][c] || r > N || c > N || r < 1 || c < 1)
		return;
	int rr = r; int cc = c;
	while (rr > 1 && !field_Ima[rr - 1][c]) {//�����̳� �ε����� ������ ��½�Ų��
		rr--;
	}

	if (rr == 1) {//������� ������
		field_Ima[rr][cc] = field_Ima[r][c];
		field_Ima[r][c] = 0;
		return;
	}
	else if (field_Ima[rr - 1][c]) {//�ε����� ��������
		int rrr = rr - 1; int ccc = c;
		if (field_Ima[rrr][ccc] == field_Ima[rr][cc]) {//������ ���� �����Ѵ�
			field_Ima[rrr][ccc] *= 2;
			if (maxval < field_Ima[rrr][ccc])
				maxval = field_Ima[rrr][ccc];
			field_Ima[r][c] = 0;
			return;
		}
		else {//�ƴϸ� �״�� �д�.
			field_Ima[rr][cc] = field_Ima[r][c];
			field_Ima[r][c] = 0;
			return;
		}
	}
	else {
		cout << "ERROR" << endl;
		return;
	}
}

void printfieldIma(int**& field_Ima) {
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			cout << field_Ima[r][c] << ' ';
		}
		cout << endl;
	}
	maxval = 0;
}

void AllGo(int d, int** field_Ima) {//d�� 1,2,3,4 ���� ��,��,��,��
	if (d == 1) {
		for (int r = 1; r < N; r++) {
			for (int c = 1; c <= N; c++) {
				GoUp(r, c, field_Ima);
			}
		}
	}
	else if (d == 2) {
		for (int r = N; r > 1; r--) {
			for (int c = N; c > 1; c--) {
				GoDown(r, c, field_Ima);
			}
		}
	}
	else if (d == 3) {
		for (int r = 1; r < N; r++) {
			for (int c = 1; c <= N; c++) {
				GoLeft(r, c, field_Ima);
			}
		}
	}
	else if (d == 4) {
		for (int r = N; r > 1; r--) {
			for (int c = N; c > 1; c--) {
				GoRight(r, c, field_Ima);
			}
		}
	}
}

/*����ϴ� ��� ����� ���� 1000����.
�� ��츦 ������ ������ �ϴ� �ʱ�ȭ�ϴµ����� 400�� ���� �Ҹ�
�����¿� �� ��� �̵��ϴµ����� �ּ� 400�� ���� �Ҹ�
������ ���귮 �ƽ��ƽ��ѵ�
*/

int DFS(int depth) {
	if (depth == 5) {
		return;
	}
	int tmpfield[MAX][MAX];
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			tmpfield[r][c]=
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			cin >> field_Original[r][c];
		}
	}
	


	return 0;
}