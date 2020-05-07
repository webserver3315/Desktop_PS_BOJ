/*
��
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

/*���� ũ�� N*N
�� �� ������� K
�� �ʱ���ġ�� ���»��, �ʱ���̴� 1, �ʱ�Ӹ��� ��������

�����ϴµ�, ����� ������ �Ӹ��� ���� �ǰ�, ����� �Ӹ��� ��.
����� ������ ����ĭ�� �Ӹ��� �ǰ�, �������� ���� 1ĭ ���.(�̰� ���� �۱⸸ �ϴٸ� ����Ʈ�� �����ϸ� �����ҵ��ϱ��ѵ�)

�ʱ⿡ ����� ��ġ �� ���� �̵���ο����� �ش�. �� ������ ���� ���ӿ����Ǵ��� ���϶�.
���ӿ����� ������, ���� �� �Ǵ� �ڱ��ڽ��� ���� �ε��� �� ������.

ù �ٿ� ����ũ�� N�� �־�����, �����ٿ��� ������� K�� �־�����.
���� K���� ������ ����� ��ġ�̴�.
�����ġ �Է��� ����Ǹ�, ���� ���⺯ȯȽ�� L�� �־�����
���� L���� ������ X�ʿ� ���� "L" "D" �϶�� ���̴�. ���� ��ȸ��, ��ȸ���� �ǹ��Ѵ�.
X�� 10000 ������ �����̰�, ������ȯ������ X�� �����ϴ� ������ �־�����.

������ �ɰ�����. �ϴ� �� ������ �ùķ��̼��� �����̴�.
1. ���� ��� ������ ���̸�, ��ȣ�� ��� �Ҵ��� ���ΰ�? 0�� �� ĭ, 1�� ��, 2���� �ö󰡴� ������ ���� �������� �Ӹ��� ������ ���ΰ�?
2. L�� D ������ ��� ������ ���ΰ�?
3. �� ���� �� �ʿ� ������ ��� �� ���̳�?
*/

/*�� ������ list<pair<int,int>> �� ����. �ƴ� �ƴϴ�, vector<pair<int,int>>�� �����ϴ�. �� ������, �þ�⸸ �ϸ� �߰������� ���� �Ͼ�� ������ ����Ǳ� �����̴�.
���� list ��ٰ� at ������ ���εǾ ���Դ´�.


*/

int Map[101][101];/*-1: ���, 0: �����, 1����: �첿������ // ���� ����!!!*/
vector<pair<int, int>> Snake;//vector�� back�� �밡����.
int N, A, O;//���庯ũ��, �������, ��ɼ�
queue<pair<int, string>> Order;
int State;//0: ����, 1: ����, 2:����, 3:����
int dr[4] = { 0,1,0,-1 }; int dc[4] = { 1,0,-1,0 };
int Time = 1;
bool GameOver;

void PrintMap() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cout << Map[r][c] << ' ';
		}
		cout << endl;
	}
	return;
}

void Turn_Right() {
	State += 1;
	if (State == 4)
		State = 0;
	return;
}

void Turn_Left() {
	State -= 1;
	if (State == -1)
		State = 3;
	return;
}

void Forward() {

	if (Time == 5) {
		int k = 1;
		k++;
		//stop at here
	}

	pair<int, int> NextPosition = Snake.back();
	//int rr = NextPosition.first += dr[State]; int cc = NextPosition.second += dc[State];//rr, cc: ���� ������ ĭ�� row, column ��ȣ//Ȥ�� ��������� �����ֳ�?
	NextPosition.first += dr[State]; NextPosition.second += dc[State];
	int rr = NextPosition.first; int cc = NextPosition.second;

	if (Map[rr][cc] > 0 || rr >= N || cc >= N || rr < 0 || cc < 0) {/*������ ĭ�� �쿡 ��Ұų� ��ܶ�� ���ӿ���*/
		/*if (Map[rr][cc] > 0)
			cout << "��ü�� �浹!!!" << endl;
		else
			cout << "���� �浹!!!" << endl;*/
		GameOver = true;
		return;
	}
	else if (Map[rr][cc] == -1) {/*������ ������ ���� ���ĭ�̸�*/
		Snake.push_back({ rr,cc });/*�װ��� ���ο� �Ӹ��� �ȴ�.*/
		Map[rr][cc] = Snake.size();
	}
	else if (Map[rr][cc] == 0) {/*�Ϲ�ĭ�̶�� �Ӹ� ���� �� ��ܾ� �Ѵ�.*/
		//for (vector<pair<int,int>>::iterator iter = Snake.begin(); iter < Snake.end() - 1; iter++) {//�������� ����. �Ӹ��� ���� ó���Ѵ�.
		//	Snake[iter].first = Snake[iter + 1].first; Snake[iter].second = Snake[iter + 1].second;
		//}
		Map[Snake.front().first][Snake.front().second] = 0;/*������ �� ĭ�� �� ���̹Ƿ�*/

		for (int idx = 0; idx < Snake.size() - 1; idx++) {
			Snake[idx].first = Snake[idx + 1].first; Snake[idx].second = Snake[idx + 1].second;/*������ �� ��° ������ �ű��*/
			Map[Snake[idx].first][Snake[idx].second] = idx + 1;/*�� ��° ������ �������ڷ� Map ������Ʈ*/
		}
		Map[rr][cc] = Snake.size();/*������ ĭ�� ���ο� �Ӹ��� �� ���̹Ƿ�*/
		Snake.back().first = rr; Snake.back().second = cc;
	}
	else {/*�� ���� ���� ���� �� �����Ƿ�*/
		cout << "ERROR ERROR ERROR ERROR ERROR ERROR ERROR " << endl;
		GameOver = true;
		return;
	}

	Time++;
	return;
}

void Solve() {
	while (!GameOver) {/*��� 100�� �ȿ� ������ ������ �Ǿ��ִٰ� ����������, �ϴ� GameOver ������ �����ϵ��� �ߴ�*/
		//cout << Time << " �� ����" << endl;
		if (Order.empty() || Time != Order.front().first) {
			Forward();
		}
		else {
			string NowOrder = Order.front().second;
			if (NowOrder == "L") {
				Order.pop();
				//cout << Time << " �� ����, ������ ��ȸ�� " << endl;
				Forward();
				Turn_Left();
			}
			else if (NowOrder == "D") {
				Order.pop();
				//cout << Time << " �� ����, ������ ��ȸ�� " << endl;
				Forward();
				Turn_Right();
			}
			else {/*�� ���� ����̶� ���� �� ����.*/
				cout << "ERROR ERROR ERROR ERROR ERROR ERROR ERROR " << endl;
				return;
			}
		}

		/*PrintMap();
		cout << endl;*/
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> N;
	cin >> A;
	for (int i = 0; i < A; i++) {
		int r; int c;
		cin >> r >> c;/*��� �ھƳ��� ��ǥ �Է� �� �ݿ�*/
		Map[r - 1][c - 1] = -1;
	}
	cin >> O;
	for (int i = 0; i < O; i++) {
		int time; string order;
		cin >> time >> order;
		Order.push({ time,order });
	}

	Snake.push_back({ 0,0 });/*0,0�� ����Ʈ�� ��ĭ�̴�.*/
	Map[0][0] = 1;

	Solve();

	cout << Time << endl;

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << duration << " sec" << endl;
	return 0;
}