/*
스도쿠
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
//P mypair = make_pair(1.2);//권장사항
//pair<int, int> mypair = make_pair(1, 2);//C++11 비지원시 이렇게
//P mypair = { 1,2 };//C++11 이후부터만 가능
//P mypair(1, 2);//생성자이용
//#define mp(x,y) make_pair(x,y)//고인물용

using namespace std;

/*스도쿠: 가로 판별함수, 세로 판별함수, 3*3사각형 판별함수 총 3가지의 판별함수를 합성한 최종판별함수가 일단 필요하다.
그리고, 채워가는 것은 백트래킹으로 간단히 구현하면 된다.
즉, 이 문제에서의 난점은 판별함수를 만드는 것 뿐이다.

1. 판별함수 만들기
2. 백트래킹으로 판별함수 대조하면서 채워나가기. 빈칸의 개수를 처음에 유지하고, depth==빈칸총갯수가 되면 종료조건이 되도록 설정

*/

int Sudoku[10][10];
int Kuuhaku;//공백칸 갯수
vector<pair<int, int>> KuuhakuVct;

int Which_Square(int row, int column) {/*최좌상단 사각형을 0번 사각형으로 하고, 최우하단 사각형을 8번 사각형으로 한다.*/
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

bool Square_Dekiruka(int insert, int row, int column) {/*일단 시간복잡도가 중요한건 아니기에 naive하게 구현했다.*/
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

bool Square_Dekiruka2(int insert, int row, int column) {/*81개가 아니라 딱 9개만 비교하도록 바꿨다.*/
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


void SolveSudoku_kai(int depth, int HakoBango) {/*내 구코드의 문제점이 보였다. 수정해보자.*/
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