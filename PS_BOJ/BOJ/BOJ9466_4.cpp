/*
�� ������Ʈ

�ݺ����� �̿��ؼ� Ǯ���� ������ �ް��ؼ��� �����ϵ��� ����
������ ��Ž�� �ؾ��Ѵٸ�, ������ �ݺ������� DFS�� �� ȿ�����̴�.

10������ ���̽��� 800�и��ʹۿ� �Ȱɸ��µ� �� �ð��ʰ��߳� �ؼ�
������ �հ��� C�ڵ带 �����ôµ�
C�ڵ�� 88�ʹۿ� �Ȱɷȴ�.
��, �̰� �е������� ������ �´�.
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
#define StuMax 100005

int T, N;
int sasumono[StuMax];
bool visited[StuMax];
bool done[StuMax];
int cnt;
vector<int> vii;

/*���Ϳ��� ���� �� �ߺ��Ǵ� �������� ���� ���?*/

int DFS(int n) {
	if (visited[n]) {//���ƿ��� ���
		/*int next = sasumono[n];
		vii.push_back(n);*/
		//int cnt = 0;
		while (!done[n]) {
			done[n] = true;
			//cout << n << " �� Ȯ���� ����Ŭ�� Ǫ��" << endl;
			//vii.push_back(n);
			cnt++;
			n = sasumono[n];
		}
		memset(visited + 1, false, N);
		return cnt;
	}
	if (done[n])
		return 0;
	visited[n] = true;
	//cout << n << " ���� " << sasumono[n] << " ���� ���մϴ�" << endl;
	DFS(sasumono[n]);
	//visited[n] = false;
	//memset(visited, false, N);//�Ź� memset �����°� �������� �ð� ������ ���� ��ƸԾ���.
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> sasumono[i];
		}
		//int inssa = 0;
		for (int start = 1; start <= N; start++) {
			//inssa += DFS(start);
			if(!done[start])
				DFS(start);
		}

		//cout << N - vii.size() << endl;
		cout << N - cnt << endl;
		cnt = 0;
		//vii.clear();
		memset(done + 1, false, N);
		memset(visited + 1, false, N);//�ϴ� �̰� �ϳ� �ð������� �������̴�. 800�и��ʿ��� 250��� ������.
	}

	

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	cout << ctime_duration << " ms" << endl;
	return 0;
}