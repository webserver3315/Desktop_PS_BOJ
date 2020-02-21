/*
���ǿ�����
*/

#include <iostream>
#include <string>
#include <queue>
#include <deque>
#include <algorithm>
#include <vector>
#include <array>
#include <cmath>
#include <cstdio>
#include <ctime>
#define endl '\n'
using namespace std;

//#define X first
//#define Y second
//typedef pair <int, int> P;
//P mypair = make_pair(1.2);//�������
//pair<int, int> mypair = make_pair(1, 2);//C++11 �������� �̷���
//P mypair = { 1,2 };//C++11 ���ĺ��͸� ����
//P mypair(1, 2);//�������̿�
//#define mp(x,y) make_pair(x,y)//���ι���

int N, MinSum=INT_MAX;
int KyoriTable[17][17];
bool visited[17];
bool KotaeExist;

bool IsTraverseCompleted() {
	for (int i = 1; i <= N; i++) {
		if (!visited[i])
			return false;
	}
	return true;
}

/*1������ N�� ���ñ��� ��ȸ�ϴ� �ִܺ���� ���س����Ѵ�.
�ϴ��� ���� �˰����� ������, �켱 DFS�� Brute�ϰ� ���غ��� �������� �ѹ� �� ���غ����� �Ѵ�.
���� �ð��� ���� ���ͽ�Ʈ�� �� ��������, �����̵���ȱ��� �غ���.

1������� �ϴ� ������ ������ �Ѵ�. ���� ��� ���󿡼� �����ϵ��� ����� ����. ���� 1��������� ����.

��, �� ������ �ٸ������2 �������� �ణ �� ��ƴ�. A-B�� B-A ����� �������� �ʴ�.
�׸��� �� �� �κ��� �ٸ���. �� ���� ��ȸ������. ��, �ٸ�ó�� ������ ���� �ּҺ�� ����ϴ°� �ƴ϶�, �Ѻױ׸��Ⱑ �����ؾ߸� �Ѵ�.*/

void DFS(int depth, int Sum) {
	cout << "ȣ��_DFS depth, sum : " << depth << ' ' << Sum << endl;
	if (depth==N-1) {
		cout << "��ȸ�Ϸ�" << endl;
		if (!KotaeExist)
			KotaeExist = true;
		if (Sum < MinSum) {
			cout << "@@@@@@�ּ��� ����� ������Ʈ�մϴ�. " << MinSum << " >>> " << Sum << endl;
			MinSum = Sum;
		}
		return;
	}
	for (int HajimeKuni = 1; HajimeKuni <= N; HajimeKuni++) {
		if (!visited[HajimeKuni])
			continue;
		for (int OwariKuni = 1; OwariKuni <= N; OwariKuni++) {
			if (visited[OwariKuni] || KyoriTable[HajimeKuni][OwariKuni]==0)/*�̹� �湮�� ����ų� �ڱ��ڽ��̸� �Ÿ���*/
				continue;
			visited[OwariKuni] = true;
			cout << HajimeKuni << " �� " << OwariKuni << "�� �����ϴ� �ٸ��� �������ϴ�." << endl;
			DFS(depth + 1, Sum + KyoriTable[HajimeKuni][OwariKuni]);
			cout << HajimeKuni << " �� " << OwariKuni << "�� �����ϴ� �ٸ��� �ν����ϴ�." << endl;
			visited[OwariKuni] = false;
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

	cin >> N;/*���ü� �Է� �� �ִܰŸ� ���̺� �Է�*/
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> KyoriTable[i][j];
		}
	}

	visited[1] = true;
	DFS(0, 0);

	if (!KotaeExist)
		cout << 0 << endl;
	else
		cout << MinSum << endl;

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << duration << " sec" << endl;
	return 0;
}