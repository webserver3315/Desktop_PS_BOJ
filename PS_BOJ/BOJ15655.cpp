/*
N��M 6
����
�񿬼������� �ߺ����� �Է� �־���
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

int N, M;
vector<int> kouhou;
vector<int> mystack;

void Combination2(int Start, int Depth) {
	if (Depth == M) {
		for (int i : mystack)
			cout << i << ' ';
		cout << endl;
		return;
	}
	for (int i = Start; i < N; i++) {
		mystack.push_back(kouhou[i]);
		Combination2(i + 1, Depth + 1);
		mystack.pop_back();
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		kouhou.push_back(tmp);
	}
	sort(kouhou.begin(), kouhou.end());

	Combination2(0, 0);

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << duration << " sec" << endl;
	return 0;
}