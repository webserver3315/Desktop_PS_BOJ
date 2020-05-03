/*
������ ��������
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWHPkqBqAEsDFAUn&categoryId=AWHPkqBqAEsDFAUn&categoryType=CODE
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

/*�Ｚ������ �� �׷����� �ϴ� �׽�Ʈ���̽� �� T���� �ڰ�
�� T���� ������ ���� �ڿ��� ���� N�� �־�����. 100 ������ �ڿ������� ����ȴ�.
�� ������ 100 ������ �ڿ����̴�.
�� ���������� ������ �� �ٸ���, �л��� ���� �� �ִ� ������ ������ �������.

�ϴ� �� ����.
100 ������ �����̸� ���� ���� 100���� ���� �ʴ´�.
����, ������Ľ����� �ص� ��������ʳ�? 0������ 10000�������� �Ѱ�ϱ� true�� false�� �����ϴ°� ���� �� �ϴ�.

��� ������ ���� �־����� ���� �� �ΰ�����. ���߰ų� Ʋ���ų�.
�׷��Ƿ� �̿��ý� DFS�� �����Ѵ�.
�����ٲ� ������ ���ϼ����� �����ϹǷ� ������ �ϸ� �ǰ�, combination���� �����ϸ� �ȴ�.

�̹� ������ �״��, �鸣�� ���� ������� false �� true�� �ش� visit[value]�� ���� �ٲ۴�.
�׸��� ���������� true�� visit�� ���� ����Ѵ�.
*/

int T;

void PrintVisited(vector<bool>& visit) {
	int i = 0;
	for (auto tmp : visit) {
		if (tmp == true) {
			cout << i << ' ';
		}
		i++;
	}
	cout << endl;
	return;
}

int KazoeruVisit(vector<bool>& visit) {
	int Cnt = 0;
	for (auto tmp : visit) {
		if (tmp == true) {
			Cnt++;
		}
	}
	return Cnt;
}

void Combination(int start, int end, int sum, vector<bool>& visit, vector<int>& scores) {
	if (start == end) {
		//cout << "���" << endl;
		return;
	}
	for (int i = start; i < end; i++) {
		sum += scores[i];
		//cout << scores[i] << "�� ���ؼ� ���� " << sum << " �� �Ǿ����ϴ�" << endl;
		if (!visit[sum]) {
			visit[sum] = true;
			Combination(i + 1, end, sum, visit, scores);
		}
		sum -= scores[i];
		if (!visit[sum])//���� �ʿ������ �ƹ��͵� ���� �ʴ� ��츦 ���ϱ� ���ؼ� �ʿ��� �ڵ��. �ӵ��鿡���� �� �ڵ带 ���� ��µǴ� �信 �ϰ������� +1 �ϴ°� ���� ������.
			visit[sum] = true;
		//cout << scores[i] << "�� ���� ���� " << sum << " �� �Ǿ����ϴ�" << endl;
		Combination(i + 1, end, sum, visit, scores);
	}
	return;
}

/*���� �� N�� ���ڷ� �ް�, set�� �����Ѵ�.
N������ ���ڸ� ���� visit�� ��� ���ҿ� ���� ���ϰ�, ���� �������� insert, �ƴϸ� �Ѿ��.

*/
void DP(int N, set<int>& visit, vector<int> scores) {
	for (int i = 0; i < N; i++) {
		int end = visit.size();
		set<int>::iterator iter = visit.begin();
		for (int idx = 0; idx < end; iter++, idx++) {
			int tmp = *iter;
			int tmptmp = tmp + scores[i];
			//cout << tmptmp << " = " << tmp << " + " << scores[i] << endl;
			visit.insert(tmptmp);
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

	cin >> T;
	/*for (int i = 1; i <= T; i++) {
		int N;
		cin >> N;
		vector<bool> visit(10000, false);
		vector<int> scores; scores.reserve(100);
		for (int idx = 0; idx < N; idx++) {
			int tmp;
			cin >> tmp;
			scores.push_back(tmp);
		}
		cout << "#" << i << ' ';
		Combination(0, scores.size(), 0, visit, scores);
		cout << KazoeruVisit(visit) << endl;
		//PrintVisited(visit);
	}*/
	
	for (int i = 1; i <= T; i++) {
		int N;
		cin >> N;
		set<int> visit;
		vector<int> scores; scores.reserve(100);
		for (int idx = 0; idx < N; idx++) {
			int tmp;
			cin >> tmp;
			scores.push_back(tmp);
		}
		visit.insert(0);
		DP(N, visit, scores);
		cout << "#" << i << ' ';
		cout << visit.size() << endl;
		//PrintVisited(visit);
	}

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << ctime_duration << " ms" << endl;
	return 0;
}