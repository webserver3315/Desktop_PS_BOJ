/*
������
*/

#include <iostream>
#include <set>
#include <map>
#include <deque>
#include <vector>
#include <queue>
#include <array>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <climits>
#define endl '\n'
//#define X first
//#define Y second
//typedef pair <int, int> P;
//P mypair = make_pair(1.2);//�������
//pair<int, int> mypair = make_pair(1, 2);//C++11 �������� �̷���
//P mypair = { 1,2 };//C++11 ���ĺ��͸� ����
//P mypair(1, 2);//�������̿�
//#define mp(x,y) make_pair(x,y)//���ι���

using namespace std;

/*������: ���� �Ǻ��Լ�, ���� �Ǻ��Լ�, 3*3�簢�� �Ǻ��Լ� �� 3������ �Ǻ��Լ��� �ռ��� �����Ǻ��Լ��� �ϴ� �ʿ��ϴ�.
�׸���, ä������ ���� ��Ʈ��ŷ���� ������ �����ϸ� �ȴ�.
��, �� ���������� ������ �Ǻ��Լ��� ����� �� ���̴�.

1. �Ǻ��Լ� �����
2. ��Ʈ��ŷ���� �Ǻ��Լ� �����ϸ鼭 ä��������. ��ĭ�� ������ ó���� �����ϰ�, depth==��ĭ�Ѱ����� �Ǹ� ���������� �ǵ��� ����

*/

int Sudoku[10][10];
int Kuuhaku;//����ĭ ����
vector<pair<int, int>> KuuhakuVct;

int Which_Square(int row, int column) {/*���»�� �簢���� 0�� �簢������ �ϰ�, �ֿ��ϴ� �簢���� 8�� �簢������ �Ѵ�.*/
	int square_number = (row / 3) * 3 + (column / 3);
	return square_number;
}

bool Row_Dekiruka(int insert, int row, int column) {
	for (int r = 0; r < 9; r++) {
		if (insert == Sudoku[r][column])
			return false;
	}
	return true;
}

bool Column_Dekiruka(int insert, int row, int column) {
	for (int c = 0; c < 9; c++) {
		if (insert == Sudoku[row][c])
			return false;
	}
	return true;
}

bool Square_Dekiruka(int insert, int row, int column) {/*�ϴ� �ð����⵵�� �߿��Ѱ� �ƴϱ⿡ naive�ϰ� �����ߴ�.*/
	int ImaSquare = Which_Square(row, column);
	for (int r = 0; r < 9; r++) {
		for (int c = 0; c < 9; c++) {
			if (ImaSquare != Which_Square(r, c))
				continue;
			else if (insert == Sudoku[r][c])
				return false;
		}
	}
	return true;
}

bool Square_Dekiruka2(int insert, int row, int column) {/*81���� �ƴ϶� �� 9���� ���ϵ��� �ٲ��.*/
	int Ima_SquareNumber = Which_Square(row, column);
	for (int r = (Ima_SquareNumber / 3) * 3; r < (Ima_SquareNumber / 3) * 3 + 3; r++) {
		for (int c = (Ima_SquareNumber % 3) * 3; c < (Ima_SquareNumber % 3) * 3 + 3; c++) {
			if (Sudoku[r][c] == insert)
				return false;
		}
	}
	return true;
}

bool Dekiruka(int insert, int row, int column) {
	if (Row_Dekiruka(insert, row, column) && Column_Dekiruka(insert, row, column) && Square_Dekiruka2(insert, row, column))
		return true;
	return false;
}

void PrintAll() {
	for (int r = 0; r < 9; r++) {
		for (int c = 0; c < 9; c++) {
			cout << Sudoku[r][c] << ' ';
		}
		cout << endl;
	}
	return;
}

void SolveSudoku(int depth, int HakoBango) {
	if (depth == Kuuhaku) {
		PrintAll();
		exit(0);
	}
	for (int i = HakoBango; i < 81; i++) {
		int row = HakoBango / 9; int column = HakoBango % 9;
		if (Sudoku[row][column] != 0)
			continue;
		for (int insert = 1; insert < 10; insert++) {
			if (!Dekiruka(insert, row, column))
				continue;
			Sudoku[row][column] = insert;
			//cout << "depth: " << depth << " HakoBango: " << HakoBango << endl;
			//PrintAll();
			//cout << endl;
			SolveSudoku(depth + 1, i);
			//cout << "depth: " << depth << " HakoBango: " << HakoBango << endl;
			//PrintAll();
			//cout << endl;
			Sudoku[row][column] = 0;
		}
	}
	return;
}


void SolveSudoku_kai(int depth, int HakoBango) {/*�� ���ڵ��� �������� ������. �����غ���.*/
	if (depth == Kuuhaku) {
		PrintAll();
		exit(0);
	}
	
	for (int i = HakoBango; i < 81; i++) {
		int row = HakoBango / 9; int column = HakoBango % 9;
		if (Sudoku[row][column] != 0)
			continue;
		for (int insert = 1; insert < 10; insert++) {
			if (!Dekiruka(insert, row, column))
				continue;
			Sudoku[row][column] = insert;
			//cout << "depth: " << depth << " HakoBango: " << HakoBango << endl;
			//PrintAll();
			//cout << endl;
			SolveSudoku(depth + 1, i);
			//cout << "depth: " << depth << " HakoBango: " << HakoBango << endl;
			//PrintAll();
			//cout << endl;
			Sudoku[row][column] = 0;
		}
	}
	return;
}

void SolveSudoku2(int depth) {
	if (depth == Kuuhaku) {
		PrintAll();
		exit(0);
	}
	int row = KuuhakuVct[depth].first; int column = KuuhakuVct[depth].second;
	for (int i = 1; i < 10; i++) {
		if (Dekiruka(i, row, column)) {
			Sudoku[row][column] = i;
			SolveSudoku2(depth + 1);
			Sudoku[row][column] = 0;
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	for (int r = 0; r < 9; r++) {
		for (int c = 0; c < 9; c++) {
			int tmp;
			cin >> tmp;
			if (tmp == 0) {
				KuuhakuVct.push_back({ r,c });
				++Kuuhaku;
			}
			Sudoku[r][c] = tmp;
		}
	}

	SolveSudoku2(0);

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << duration << " sec" << endl;
	return 0;
}