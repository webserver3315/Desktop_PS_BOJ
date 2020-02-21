/*
�Ը��Ǵ���2
*/

#include <iostream>
#include <utility>
#include <deque>
#include <cstring>
//#include <cmath>//INT_MAX ����
#include <climits>//INT_MAX�� cmath�� �ƴ϶� climits�� �ִ�!!!!
#define endl '\n'
#define MAX (int)23
#define ff first
#define ss second
#define mp(x,y) make_pair(x,y)

typedef std::pair<int, int> pii;

using namespace std;

/*
�ϴ� �߰��� ������ 5�����ű� ������ Ű��. ���� ���� �ڰ� �����Ѵ�.
�� ���ű��� �ּҳʺ�� 1ĭ�̰� �ݵ�� ������ ���簢�����̸�, 5�����ű��� �߾��� x,y �������� �»�/���ϴܱ����� d1+1, ���/���ϴ� ������ d2+1, �� ���ǵȴ�.

1. 5�� ���ű� ��ĥ�ϴ� �Լ��� ������
2. 5�����ű� ����� �о, 1,2,3,4 ���ű��� �з��ϴ� �Լ��� ������
3. ������ ������ ���� ���, �� ���ű��� �α����� ���� ���ϴ� �Լ��� ������
4. 3���Լ����� �ִ񰪰� �ּڰ��� ����.
5. 5�� ���ű��� ���� �� �ִ� ��� ����� ���� ���� 1~4�� �ݺ��ϸ�, �ּ� �ִ�������� ������Ʈ����

���� �������� �����¿� �������� ��� ���������, ������ ��������� ���� ����ȴ�.

������ ����Ī�� �����ϴϱ�, x,y�� 1,1~n,n ���°� �ƴ϶� 1,1~n/2+1,n/2+1���� ���°ɷ� �ϴ°� ���� �� �ϴ�. ���귮 1/4�� �ȴ�.
*/

int N;
int r5, c5;
//int d1, d2;
int population[MAX][MAX];//�α��� ���ű��� r,c�� 1���� �����ϵ��� ����
int regiment[MAX][MAX];//���ű� ������ �ȳ��� �� ����� ��ħ
int populationOfRegiment[6];//�� ���ű��� �α��� ����
int dr[4] = { 1, -1,0,0 };
int dc[4] = { 0,0,-1,1 };
int minMaxDiff = INT_MAX;

bool IsInBoundary(int x, int y, int d1, int d2) {//�̷��� ������ ���� 5�����ű��� �����ȿ� �� ���°��� ���� ��
	int ur, uc, rr, rc, dr, dc, lr, lc;
	ur = x; uc = y;
	rr = x + d2; rc = y + d2;
	lr = x + d1; lc = y - d1;
	dr = x + d1 + d2; dc = y + d2 - d1;
	if (ur > N || rr > N || lr > N || dr > N
		|| uc > N || rc > N || lc > N || dc > N
		|| ur < 1 || rr < 1 || lr < 1 || dr < 1
		|| uc < 1 || rc < 1 || lc < 1 || dc < 1)
		return false;
	return true;
}

void printRegiment() {
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			cout << regiment[r][c] << ' ';
		}
		cout << endl;
	}
}

void assignRegiment(int x, int y, int d1, int d2) {//x,y�� 5�����ű� �ֺϴ�.
	//memset(regiment, 0, (N + 1) * (N + 1));//�ǳ�?
	//if (IsInBoundary(x, y, d1, d2) == false)//�����ʰ� ����Ǹ� ��곶����������
	//	return;

	for (int d = 0; d <= d1; d++) {
		regiment[x + d][y - d] = 5;
	}
	for (int d = 0; d <= d2; d++) {
		regiment[x + d][y + d] = 5;
	}
	for (int d = 0; d <= d2; d++) {
		regiment[x + d1 + d][y - d1 + d] = 5;
	}
	for (int d = 0; d <= d1; d++) {
		regiment[x + d2 + d][y + d2 - d] = 5;
	}

	/*���� 5�� ��ĥ*/
	//int ur = x; int dr = x + d1 + d2;/*5�����ű��� �ֺϴܰ� �ֳ���*/
	bool spotted = false;
	for (int r = x + 1; r < x + d1 + d2; r++) {
		spotted = false;
		for (int c = 1; c <= N; c++) {
			if (regiment[r][c] == 5) {
				if (spotted)
					break;
				else {
					spotted = true;
					continue;
				}
			}
			else {
				if (spotted)
					regiment[r][c] = 5;
				else
					continue;
			}
		}
	}

	/*5���ƴ� ������ �κ� ���� 1,2,3,4�� �Ҵ�*/
	for (int r = 1; r < x + d1; r++) {//1
		for (int c = 1; c <= y; c++) {
			if (regiment[r][c] != 5) {
				regiment[r][c] = 1;
			}
		}
	}
	for (int r = 1; r <= x + d2; r++) {//2
		for (int c = y + 1; c <= N; c++) {//c=y+1�����ε� y����ߴ�...
			if (regiment[r][c] != 5) {
				regiment[r][c] = 2;
			}
		}
	}
	for (int r = x + d1; r <= N; r++) {//3
		for (int c = 1; c < y - d1 + d2; c++) {
			if (regiment[r][c] != 5) {
				regiment[r][c] = 3;
			}
		}
	}
	for (int r = x + d2 + 1; r <= N; r++) {//4
		for (int c = y - d1 + d2; c <= N; c++) {
			if (regiment[r][c] != 5) {
				regiment[r][c] = 4;
			}
		}
	}
}

bool regimentPopulationCount() {//false�� ���ű� �� �α��� 0�� ���ű��� �ִٴ� ��
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			populationOfRegiment[regiment[r][c]] += population[r][c];
		}
	}
	for (int i = 1; i < 6; i++) {
		if (!populationOfRegiment[i])
			return false;
	}
	return true;
}

int GetMaxDiff() {
	int min = INT_MAX; int max = 0;
	for (int i = 1; i < 6; i++) {
		if (min > populationOfRegiment[i])
			min = populationOfRegiment[i];
		if (max < populationOfRegiment[i])
			max = populationOfRegiment[i];
	}
	return max - min;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			cin >> population[r][c];
		}
	}

	for (int r = 1; r <= N / 2 + 1; r++) {
		for (int c = 1; c <= N / 2 + 1; c++) {
			for (int d2 = 1; d2 <= N - c; d2++) {
				for (int d1 = 1; d1 < N - r - d2; d1++) {
					if (IsInBoundary(r, c, d1, d2) == false)//�����ʰ� ����Ǹ� ��곶����������
						continue;


					for (int r = 1; r <= N; r++) {//�����ʵ� 0���� �ʱ�ȭ
						for (int c = 1; c <= N; c++) {
							regiment[r][c] = 0;
						}
					}
					//memset(populationOfRegiment, 0, 6);//���뺰 �α��� 0���� �ʱ�ȭ//�����𸣰����� �̰� ����� �ȵ��ư���
					for (int i = 1; i < 6; i++)
						populationOfRegiment[i] = 0;

					/*if (r == 2 && c == 3 && d1 == 1 && d2 == 2) {
						int tmp = 1;
						cout << tmp << "���⼭�����" << endl;
					}*/

					assignRegiment(r, c, d1, d2);


					if (regimentPopulationCount() == false)
						continue;
					if (minMaxDiff > GetMaxDiff()) {
						cout << "�ּ����� ������Ʈ: " << minMaxDiff << " ���� " << GetMaxDiff() << endl;
						minMaxDiff = GetMaxDiff();//�������� ���� ���ϰ� �̷��� ¥�� ��ȿ�����̷���?
					}
					cout << "r: " << r << " c: " << c << " d1: " << d1 << " d2: " << d2 << endl;
					printRegiment();
					cout << "1 : " << populationOfRegiment[1] << endl
						<< "2 : " << populationOfRegiment[2] << endl
						<< "3 : " << populationOfRegiment[3] << endl
						<< "4 : " << populationOfRegiment[4] << endl
						<< "5 : " << populationOfRegiment[5] << endl;
					cout << endl;
				}
			}
		}
	}
	cout << minMaxDiff << endl;

	return 0;
}
