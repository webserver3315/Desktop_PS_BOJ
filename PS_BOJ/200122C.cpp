/*
���� 2��
�� ��ǲ������ 9�¹̸�.
��, �̰� �������� �������� �������ϴٰ��� ������ �ð��ʰ���.
�Ҽ��θ� �������ϳ�... �װ� Ʋ����.
2��6�µ� �����ϱ� �����̴�.
�׷���, �ȵǴ� ���� �̹� �湮���� �� ���̴�.
*/
#include <iostream>
#include <utility>
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
#include <cstring>
#include <ctime>
#include <climits>
using namespace std;
#define endl '\n'
#define MAX 31625
//#define ff first
//#define ss second
//typedef std::pair <int, int> pii;
//#define mp(x,y) make_pair(x,y)
//P mypair = make_pair(1.2);//�������
//pair<int, int> mypair = make_pair(1, 2);//C++11 �������� �̷���
//P mypair = { 1,2 };//C++11 ���ĺ��͸� ����
//P mypair(1, 2);//�������̿�

int t;
int n;
int EratosArr[MAX];//0:�Ҽ�, 1:�ռ���

void Eratos() {
	int target = 2;
	for (; target < MAX; target++) {
		if (EratosArr[target] == 1) {
			continue;
		}
		else {
			int tmp = target;
			while (tmp < MAX) {
				tmp += target;
				EratosArr[tmp] = 1;
			}
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> t;
	Eratos();
	while (t--) {
		cin >> n;

	}


	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << ctime_duration << " ms" << endl;
	return 0;
}