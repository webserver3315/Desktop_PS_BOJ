/*
A
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

int T;
string answer[102];
set<char> Kakusin[102];


//��, ���Ͼ��ĺ� ���� 3���� �̰� �ո��±���;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> answer[i];

		if (answer[i].size() == 1) {
			Kakusin[i].insert(answer[i][0]);
			for (char c : Kakusin[i]) {
				cout << c;
			}
			cout << endl;
			continue;
		}

		for (int idx = 0; idx < answer[i].size(); idx++) {
			if (idx == answer[i].size() - 1) {
				if (answer[i][idx] != answer[i][idx - 1]) {
					Kakusin[i].insert(answer[i][idx]);
				}
			}
			else if (idx == 0) {
				if (answer[i][idx] != answer[i][idx + 1]) {
					Kakusin[i].insert(answer[i][idx]);
				}
			}
			else {
				if (answer[i][idx] != answer[i][idx + 1] && answer[i][idx] != answer[i][idx - 1]) {
					Kakusin[i].insert(answer[i][idx]);
				}
			}
		}

		for (char c : Kakusin[i]) {
			cout << c;
		}
		cout << endl;
	}

	/*for (int i = 0; i < T; i++) {
		while (!answer[i].empty()) {
			char ch = answer[i].back();
			answer[i].pop_back();
			if (ch == answer[i].back()) {

			}
		}
	}*/

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << duration << " sec" << endl;
	return 0;
}