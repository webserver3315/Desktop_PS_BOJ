/*
���� ����
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

/*������ ������ ������ �� ���� �κм����� ������ ���� ������ �� ������ ���� �����̶�� �θ���.
���� ���, ���� ���� �ݺ��Ǹ� ���� ����.
2121ó�� ���� ������ �ݺ��Ǿ ���� ����.
�ϴ� ������� ������ ����ؾ��ϹǷ�, vector<int> IntList �� ��������.
�׸���, �ּ��� ���������� ����ؾ��Ѵ�.
������ �̰� �˻縦 �ϴ°�? �˻縦 �ϰ� �̴°�?
�� ������ Ư¡ �� �ϳ���, optimal subset �� �����Ѵٴ� ���̴�. ���������� �κм����� ���� ���������̴�. �̸� �̿��ϸ� dp�� �����ϴ�.
�˻縦 �ϰ� ���� �ʿ�� ����. ������ �̰� ���ο� ������ ���� �˻縸 �ϴ°� �´�. optimal subset�� Ȱ���ϱ� ���ؼ����.
�ߺ��� ���ǰ�, ���� ���� �Ű����ϹǷ� �Ź� 1���� 3���� �˻綧���� �ߺ������̴�.

�� ������ �ɰ� �ʿ�� ���ٰ� ���δ�.
�ƴ�, �����ϳ�. �ɰ����ϳ�.
1. DFS�Լ�
2. ���� �������� IntList�� ���� �������� �ƴ��� �Ǻ��ϴ� �Լ�
*/

int N;
vector<int> IntList;
vector<int> Kotae;

//bool HasSubset(vector<int>::iterator MotherBegin, vector<int>::iterator MotherEnd, vector<int>::iterator SonBegin, vector<int>::iterator SonEnd) {
//	int MotherLength = MotherBegin - MotherEnd; int SonLength = SonBegin - SonEnd;
//	for (vector<int>::iterator MotherStart = MotherBegin; MotherStart < MotherEnd - SonLength; MotherStart++) {
//		
//	}
//}

bool IsFine() {/*��ġ�� �κм����� �ִ��� �˻��ϴ� �Լ��̴�. �κм����� ���� 1�� �� ���� �ְ�, N-1�� �� ���� �ִ�.
			   ��� üũ�ұ�. ���� 1���� IntList.size()-1 ��ŭ�� ���̸� �����ϰ� �� Ƚ����ŭ ��ȸ������. n(n-1)/2�� ����Ƚ���� �ҿ�� ���̴�.
			   �� �̷��� ��û�ϰ� Ǭ�ٰ� �ϴ��� ��� 1��� ���� ���� �ʿ����Ӵ�.*/
	for (int length = 1; length < IntList.size(); length++) {//Ȥ�� size()�� unsigned�� ���ϵǱ⿡ ������ ������ ������ ������..�Ҿ��ϳ�
		for (int start = 0; start < IntList.size() - length; start++) {
			 IsSubset = search(IntList.begin(), IntList.end(), IntList.begin() + start, IntList.begin() + start + length);
			if (IsSubset)
				return false;
		}
	}
	return true;
}

void DFS(int depth) {
	if (depth == N) {
		if (Kotae.empty())
			Kotae = IntList;
		return;
	}
	for (int i = 1; i <= 3; i++) {
		IntList.push_back(i);
		if (IsFine())
			DFS(depth + 1);
		IntList.pop_back();
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

	DFS(0);

	for (int tmp : Kotae)
		cout << tmp;
	cout << endl;

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << duration << " sec" << endl;
	return 0;
}