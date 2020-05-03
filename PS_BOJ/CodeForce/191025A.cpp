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

/*�׽�Ʈ���̽� ������ t��, 100�� ����
���ڿ��� �־�����. 500���� �����̴�.
���ڿ��� ����, Ȯ���� �۵����� ������ �� �ִ� ���ǵ��� ���������� �����϶�.
���峭 ������ �ߺ��Էµȴ�.

�յڰ� �ڽŰ� ��� �ٸ� ö�ڰ� �ִٸ� �ش� ö�ڴ� ������ �����̶�� Ȯ�Ű����ϴ�.
�Ϲ����� Ž���� �ڸ� Ȯ���ϸ� �� �� �ϴ�.

����, ����� �۵��ϴ� ������ ���ٸ�, ������� �� �����϶�.
*/

int T;
string Strings[102];//ȭ�鿡 ���� ö��
set<string> Kakusin[102];//Ȯ���� �� �ִ� ���ǵ�

void GetNoBroken(int Case, string answer) {
	if (answer.size() == 1)
		cout << answer;
	else {
		for (int idx = 0; idx < answer.size() - 1; idx++) {
			if (answer[idx] == answer[idx + 1])
				idx++;
			else {
				string inserting(1, answer[idx]);
				Kakusin[Case].insert(inserting);
			}
		}
		if (answer.back() != answer[answer.size() - 2]) {
			string inserting(1, answer.back());
			Kakusin[Case].insert(inserting);
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

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> Strings[i];
	}

	/*for (int i = 0; i < T; i++) {
		int idx = 0;
		for (; idx < Strings[i].size() - 1; idx++) {
			if (Strings[i][idx] == Strings[i][idx + 1]) {
				idx++;
				continue;
			}
			else {
				Kakusin[i].insert(Strings[i][idx]);
			}
		}
		if (Strings[i].size() != 1) {
			if (Strings[i][Strings[i].size() - 1] == Strings[i][Strings[i].size() - 2]) {
				Kakusin[i].insert(Strings[i][idx]);
			}
		}
		else {
			Kakusin[i].insert(Strings[i][idx]);
		}
	}*/

	for (int i = 0; i < T; i++) {
		GetNoBroken(i, Strings[i]);
	}

	for (int i = 0; i < T; i++) {
		for (string c : Kakusin[i]) {
			cout << c;
		}
		cout << endl;
	}

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << duration << " sec" << endl;
	return 0;
}