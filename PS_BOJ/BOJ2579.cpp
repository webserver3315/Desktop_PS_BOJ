/*
��� ������
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
#include <cstring>
#include <ctime>
#include <climits>
using namespace std;
#define endl '\n'
//#define ff first
//#define ss second
//typedef std::pair <int, int> pii;
//#define mp(x,y) make_pair(x,y)
//P mypair = make_pair(1.2);//�������
//pair<int, int> mypair = make_pair(1, 2);//C++11 �������� �̷���
//P mypair = { 1,2 };//C++11 ���ĺ��͸� ����
//P mypair(1, 2);//�������̿�

/*�� ���� �� ��ܾ� ���� �� ������, 0����ܿ��� ����� ������ ����� �ݵ�� ��ƾ� �Ѵ�.
ó���� �����ϰ�� �� �� ���� �ϳ����� ���� �� ����. �������� ���ӵ� �� ���� ����� ��°� ������.
������ ������ �ִ���?
����� 300������, ������ ���� 10000����.

��ȭ�� - An = Max(A(n-2),A(n-3)+arr[n-1])+arr[n]
*/


/*�����κй����� �����ϴ°�? 
*/

/*���ʿ� 3��� ������ �̵��ϴ°� �⺻������ ������ ��������. 2��ܾ� �������� �̵��ϴ� ���� ���� ������.
4��°ĭ �׷��� �� �ٿ��� 1ĭ 2ĭ 1ĭ �����̴°� �ݵ�� �����ϱ⿡.
����, �ϴ� �⺻������ ������ �̵��ϵ�, 
�Ҵ�����
���ߴ��
�ҼҴ��
�ҼҼҴ�
��ҼҼ�
�Ҵ�Ҽ�
�ҼҴ�Ҵ��
�ҼҼҴ��Ҵ�

�ش� ���̵� �������� ��ȭ�� ã�Ҵ�.
An = Max( A(n-2), A(n-3)+arr[n-1] ) + arr[n]
*/

int arr[303];//��ܺ� ����
int memo[303];
int s;//stair

int DP(int n) {
	if (n <= 0)
		return 0;
	else if (n < 3)
		return memo[n];
	else
		if (!memo[n]) //memo�� �ȵǾ��ִٸ�
			memo[n] = max(DP(n - 2), DP(n - 3) + arr[n - 1]) + arr[n];
	return memo[n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> s;
	for (int i = 1; i <= s; i++) {
		cin >> arr[i];
	}
	memo[1] = arr[1];
	memo[2] = arr[1] + arr[2];

	cout << DP(s) << endl;

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << ctime_duration << " ms" << endl;
	return 0;
}