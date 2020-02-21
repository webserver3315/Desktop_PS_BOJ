/*
N�� M 10
����
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

/*�����̸�, �ߺ��� �Է��� �־�����. ����, �������� set�� �ߺ������ �߻��� ���� ��ü�� ���� ���̴�. find���� logN�� �ҿ�Ǵ� ������ ������ ũ���� ���� ����̴�.
�ϴ� ���������� Ǯ��, �ٸ� Ǯ�̹���� �����غ���.

*/

int N, M;
bool visited[10];
set<vector<int>> mukashi;
vector<int> mystack;
vector<int> kouhou;

void Combination3(int depth, int start) {
	if (depth == M) {
		if (mukashi.find(mystack) != mukashi.end())
			return;
		mukashi.insert(mystack);
		for (int tmp : mystack)
			cout << tmp << ' ';
		cout << endl;
		return;
	}
	for (int i = start; i < N; i++) {
		mystack.push_back(kouhou[i]);
		Combination3(depth + 1, i + 1);
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

	Combination3(0, 0);

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << duration << " sec" << endl;
	return 0;
}