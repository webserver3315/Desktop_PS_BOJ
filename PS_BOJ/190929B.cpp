/*
B. Filling the Grid
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstdio>
#define ll long long;
using namespace std;

int grid[1000][1000];/*0:����, -1:false, 1:true, [row][column]���̴�*/
int row[1000];
int column[1000];
int r, c;
long long filledCnt;/*���� ĭ ��*/

int PrintGrid() {
	cout << endl;
	for (int rr = 0; rr < r; rr++) {
		for (int cc = 0; cc < c; cc++) {
			cout << grid[rr][cc] << ' ';
		}
		cout << endl;
	}
	return 0;
}

long long my_pow(long long x, long long y) {
	long long tmp = 1;
	if (y == 0)
		return 1;
	for (long long i = 0; i < y; i++) {
		tmp *= x;
	}
	return tmp;
}

int Basic() {
	for (int rr = 0; rr < r; rr++) {
		int tmp = row[rr];
		int j = 0;
		for (; j < tmp; j++) {/*ù����� -1Ȯ�� �ʿ����*/
			if (grid[rr][j] ==0) {
				//cout << rr << j << "cnt++" << endl;
				filledCnt++;
				grid[rr][j] = 1;
			}
		}
		if (j < c) {
			//cout << rr << j << "cnt++" << endl;
			filledCnt++;
			grid[rr][j] = -1;/*���� -1 �ڱ�*/
			//PrintGrid();
		}
	}
	for (int cc = 0; cc < c; cc++) {
		int tmp = column[cc];
		int j = 0;
		for (; j < tmp; j++) {
			if (grid[j][cc] == -1) {/*-1�ε� 1�� �����ؾ߸� �� ���� �ƿ� ���� ���̽��̹Ƿ�*/
				return -1;
			}
			else if (grid[j][cc] == 0) {
				//cout << j << cc << "cnt++" << endl;
				grid[j][cc] = 1;
				filledCnt++;
			}
		}
		if (j < r) {/*���� -1 �ڱ�*/
			if (grid[j][cc] == 0) {
				//cout << j << cc << "cnt++" << endl;
				filledCnt++;
				grid[j][cc] = -1;
				//PrintGrid();
			}
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		int tmp;
		cin >> tmp;
		row[i] = tmp;
	}
	for (int i = 0; i < c; i++) {
		int tmp;
		cin >> tmp;
		column[i] = tmp;
	}
	//PrintGrid();

	int status = Basic();
	if (status == -1) {
		cout << 0 << endl;
		return 0;
	}
	long long nokori = r * c - filledCnt;
	long long division = 1000000007;
	cout << my_pow(2, nokori) % division << endl;
	return 0;
}