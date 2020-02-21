/*
N�� M 12
�ߺ�����
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

/*�ߺ������̴�. �ð��� �ΰ��� �Ʊ�� ���������� �켱�� NAIVE�ϰ� set���� Ǯ���.
*/

int N, M;
vector<int> mystack;
vector<int> kouhou;
set<vector<int>> mukashi;


/*�ߺ������̴�, �ϴ� ���ĵ� kouhou��� ���� �Ͽ� ������ �ϸ� �ȴ�.
���, ������ start�� �ʿ��ϴ�.*/
void MultisetCombination3(int depth, int start) {
	if (depth == M) {
		if (mukashi.find(mystack) != mukashi.end())/*���� set�� �̹� �ִ� ����output�̶��*/
			return;
		mukashi.insert(mystack);
		for (int tmp : mystack)
			cout << tmp << ' ';
		cout << endl;
		return;
	}
	for (int i = start; i < N; i++) {
		mystack.push_back(kouhou[i]);
		MultisetCombination3(depth + 1, i);/*i+1�� �ƴ϶� i��� ���� Combination�� MultisetCombination�� �����̴�. ����, start �� �ƴԿ� �����ؾ��Ѵ�.*/
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

	MultisetCombination3(0, 0);

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << duration << " sec" << endl;
	return 0;
}