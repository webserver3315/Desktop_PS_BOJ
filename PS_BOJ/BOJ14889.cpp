/*
��ŸƮ�� ��ũ
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


/*�౸�ϴµ� N�� �𿴰� �翬�� ¦����.
i�� ����� j�� ����� ���� ���� ������ �� ���� �������� �ɷ�ġ�� ���̺�� �־�����.
�뷱���� �ִ��� ���� ���, ������ �ɷ�ġ ���� �ּҰ��� ����϶�.
������ ����� 4��~20����� �����ϴ�.

��� Ǫ����...
�ϴ� ���� �������°�
10*9/2=45, 45*9�� ���� 500. ������ �ѿ��� ������ ��� ���� ������ �ƹ��� �˳��ϰ� ��Ƶ� 500������ �ȵ�.
500���� ���� Brute�ϰ� 1���� ��ü sum - 2����sum�� ���� ������ �ϰ�, �� �� min���� ����ϸ� �Ǵ� ���̴�.
Brute�ϰ� �ϴ� ���� ��ȿ�ϴ�.

�� ������ �׷��� ������� �ʴ�. �� ������ �ɰ� �� �ֱ� �����̴�. 3���� �̻��̸� ���� ���������� ������
�켱, �� �ο����� �־����Ƿ�
1. nC2�� © �� �ִ� �� ������ ��� ����
2. �ش� �� ��� �� �ɷ�ġ ���̸� ���ϴ� �Լ�

nC2�� ���� �����ϴ� ���� ���� �����ұ�...? �ϴ� Combination�� �����ϹǷ� start ������ ����� ��ͷ� ���������ϴ�.
����, ���� �� ���ۿ� �����Ƿ� ���� �� VS �Ȼ��� �� ������ ���� ���� �����ϴ�. start������ �̿��� ���� �� ������ ���� �ߺ��� ���� �� �ִ�. ��, �迭�� 1���� �ʿ��ϴ�.
���� ����ִ� �ο��� ���� �����ϴ� ������� vector�� �ش� �ο��� �̸��� �ֱ⺸�ٴ�, visited �迭 ���� 1���� ���� �ڵ��� 1��, 2���� �����ڵ��� 2�� ��ִ°ɷ� ����.
�װ� �ξ� ���� find �ӵ��� �����´�. set���°ͺ��ٵ� ���� ���̴�. ���ʿ� 20��ۿ� ���⿡ �̷� ����˻��� �����ϴ�.
*/

int N;
int MinDifference = 987654321;
int NoryokuTable[22][22];
int TeamStatus[22];/*0:����, 1:1��, 2:2��*/

/*int GetDifference() {
	int Team1_Sum = 0; int Team2_Sum = 0;
	for (int i = 1; i <= N; i++) {
		if (TeamStatus[i] != 1)
			continue;
		for (int j = i + 1; j <= N; j++) {
			if (TeamStatus[j] != 1)
				continue;
			cout << "1�� ��: " << i << " �� " << j << " �� �ó����� " << NoryokuTable[i][j] << ' ' << NoryokuTable[j][i] << " �� ���ؼ� " << Team1_Sum << "�� " << NoryokuTable[i][j] + NoryokuTable[j][i] << " �� ���ߴ�." << endl;
			Team1_Sum += NoryokuTable[i][j] + NoryokuTable[j][i];
			cout << "2�� ��: " << N + 1 - i << " �� " << N + 1 - j << " �� �ó����� " << NoryokuTable[N + 1 - i][N + 1 - j] << ' ' << NoryokuTable[N + 1 - j][N + 1 - i] << " �� ���ؼ� " << Team2_Sum << "�� " << NoryokuTable[N + 1 - i][N + 1 - j] + NoryokuTable[N + 1 - j][N + 1 - i] << " �� ���ߴ�." << endl;
			Team2_Sum += NoryokuTable[N + 1 - i][N + 1 - j] + NoryokuTable[N + 1 - j][N + 1 - i];
		}
	}
	int difference = abs(Team1_Sum - Team2_Sum);
	return difference;
}*/


int GetDifference() {
	int Team1_Sum = 0; int Team2_Sum = 0;
	for (int i = 1; i <= N; i++) {
		if (TeamStatus[i] != 1)
			continue;
		for (int j = i + 1; j <= N; j++) {
			if (TeamStatus[j] != 1)
				continue;
			//cout << "1�� ��: " << i << " �� " << j << " �� �ó����� " << NoryokuTable[i][j] << ' ' << NoryokuTable[j][i] << " �� ���ؼ� " << Team1_Sum << "�� " << NoryokuTable[i][j] + NoryokuTable[j][i] << " �� ���ߴ�." << endl;
			Team1_Sum += NoryokuTable[i][j] + NoryokuTable[j][i];
		}
	}
	for (int i = 1; i <= N; i++) {
		if (TeamStatus[i] != 2)
			continue;
		for (int j = i + 1; j <= N; j++) {
			if (TeamStatus[j] != 2)
				continue;
			//cout << "2�� ��: " << i << " �� " << j << " �� �ó����� " << NoryokuTable[i][j] << ' ' << NoryokuTable[j][i] << " �� ���ؼ� " << Team2_Sum << "�� " << NoryokuTable[i][j] + NoryokuTable[j][i] << " �� ���ߴ�." << endl;
			Team2_Sum += NoryokuTable[i][j] + NoryokuTable[j][i];
		}
	}
	int difference = abs(Team1_Sum - Team2_Sum);
	return difference;
}

void Team1_Print() {
	cout << "1��: " << endl;
	for (int i = 1; i <= N; i++) {
		if (TeamStatus[i] == 1)
			cout << i << ' ';
	}
	cout << endl;

	cout << "2��: " << endl;
	for (int i = 1; i <= N; i++) {
		if (TeamStatus[i] == 2)
			cout << i << ' ';
	}
	cout << endl;
	return;
}

void Team_Sentaku(int start, int depth) {
	if (depth == N / 2) {
		//Team1_Print();
		int NewMin = GetDifference();
		if (MinDifference > NewMin) {
			//cout << "�ּ��հ� ������Ʈ : " << MinDifference << " ���� " << NewMin << " ��" << endl << endl;
			MinDifference = NewMin;
		}
		return;
	}
	for (int i = start; i <= N; i++) {
		TeamStatus[i] = 1;
		//cout << i << "�� 1�� ���� �־����ϴ�" << endl;
		Team_Sentaku(i + 1, depth + 1);
		//cout << i << "�� 2�� ���� �ǵ��Ƚ��ϴ�" << endl;
		TeamStatus[i] = 2;
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
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> NoryokuTable[i][j];
		}
	}
	for (int i = 1; i <= N; i++) {/*Unselected��� 2������ϵ��� �ʱ�ȭ*/
		TeamStatus[i] = 2;
	}


	Team_Sentaku(1, 0);/*��, ���� �̰� 0,0���� ��Ҵٰ� ������ϴµ� 20�� ��ƸԾ���;*/
	cout << MinDifference << endl;

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << duration << " sec" << endl;
	return 0;
}