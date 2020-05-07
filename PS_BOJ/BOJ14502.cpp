/*
������

P.S - �÷����� �˰��� BFS���� DFS�ε� �����ϴ� �� �����س���.
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

/*������ ũ��� N*M
���̷����� �����¿� ������ ��ĭ���� ��� �������� �� �ִ� - Flood Fill
���� ���� �� ������, ���� �� �������� �������� 3���� ������ �Ѵ�. ��ĭ�� �ּ� 3�� �̻� �־�����.
0�� ����, 1�� ��, 2�� ���̷����� ���Ѵ�.
���̷����� �����ؼ� ���� �� �ִ� �ִ��� ���������� ���϶�.

�ش� ������ 2������ ���� �� �ִ�.
��ĭ ���� B��� ���� ��, ���� ���� �� �ִ� ����� ���� BC3�̴�.

1. ���� ����� ��츦 �����ϴ� ����Լ�
2. ��Ȳ�� �־����� ���, ���̷����� �۶߷� �ش� Case������ ���������� ���ϴ� �Լ�

���̷����� ��ġ�� vector�� �����ϴ°� ������.
��, ���� ������ ���� �������ص� �ɱ�.
�ƴϴ�, ������ pair�� vector�� �����ؾ� BC3�� ���ϱ� ������̴�.

ó������������ ������ġ ����
ó������������ ���̷��� ����
���ø޸𸮿� ����ġ ����

�ϴ� �̷��� �ʿ��ϴ�.
*/

int R, C;//R, C
int Labo[9][9];//0:����, 1:��, 2:���� ���̷���, 3: ���� ���̷���
int MaxSafe;
int dr[4] = { 1,-1,0,0 }; int dc[4] = { 0,0,-1,1 };
vector<pair<int, int>> Hatsu_Blank;
vector<pair<int, int>> Hatsu_Virus;
vector<pair<int, int>> Stack_Wall;

void PrintLabo() {
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cout << Labo[r][c] << ' ';
		}
		cout << endl;
	}
	return;
}

void CleanLabo() {
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			if (Labo[r][c] == 3)
				Labo[r][c] = 0;
		}
	}
	return;
}

int VirusKaiho() {/*�ش� Case������ �������� ĭ �� ���*/
	queue<pair<int, int>> Susume_Virus;/*BFS�� ���� �÷������� �����ϱ� ���� ť�̴�.*/
	for (auto EachVirus : Hatsu_Virus) {
		Susume_Virus.push(EachVirus);
	}
	int SusunndaKazu = 0;
	while (!Susume_Virus.empty()) {
		pair<int, int> ImaVirus = Susume_Virus.front();
		Susume_Virus.pop();
		int r = ImaVirus.first; int c = ImaVirus.second;
		//if (Labo[r][c] == 0 || 1)
		//	continue;
		for (int i = 0; i < 4; i++) {
			int rr = r + dr[i]; int cc = c + dc[i];
			if (rr >= R || rr < 0 || cc >= C || cc < 0 || Labo[rr][cc] != 0)/*����ʰ��ϰų� ����ĭ�� �ƴ϶��*/
				continue;
			Labo[rr][cc] = 3;
			SusunndaKazu++;
			Susume_Virus.push({ rr,cc });
		}
	}
	return Hatsu_Blank.size() - SusunndaKazu - 3;
}

void MakeLaboGreatAgain(int depth, int start) {//���� 3������ ����� �Լ��̴�.
	if (depth == 3) {
		int ImaSafe = VirusKaiho();
		//cout << "���̷��� ��� �۶߸�. �׷��� �̷��� ��." << endl;
		//PrintLabo();
		if (ImaSafe > MaxSafe) {
			//cout << "�ִ� ������ ������Ʈ: " << MaxSafe << " ���� " << ImaSafe << endl;
			MaxSafe = ImaSafe;
		}
		//cout << endl;
		CleanLabo();
		return;
	}
	for (int position = start; position < Hatsu_Blank.size(); position++) {
		int row = Hatsu_Blank[position].first; int column = Hatsu_Blank[position].second;
		Stack_Wall.push_back({ row,column });
		Labo[row][column] = 1;
		//cout << row << " �� " << column << " �� ���� ������" << endl;
		//PrintLabo();
		//cout << endl;
		MakeLaboGreatAgain(depth + 1, position + 1);
		Labo[row][column] = 0;
		Stack_Wall.pop_back();
		//cout << row << " �� " << column << " �� ���� �㹰����" << endl;
		//PrintLabo();
		//cout << endl;
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> R >> C;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cin >> Labo[r][c];
			if (Labo[r][c] == 0) {
				Hatsu_Blank.push_back({ r,c });
			}
			else if (Labo[r][c] == 2) {
				Hatsu_Virus.push_back({ r,c });
			}
		}
	}

	MakeLaboGreatAgain(0, 0);

	cout << MaxSafe << endl;

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << duration << " sec" << endl;
	return 0;
}