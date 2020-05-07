/*
�� ������Ʈ

1�� 2�� �����ϸ� ���� �׷��� �ǰ�, 2�� 3�� �����ϰ� 3�� 1�� �����ϴ� ������, ����Ŭ�� �����Ǹ� �׷��� �ȴ�.
���� �ڱ��ڽ��� �����ϸ� Ȧ�� �׷��� �ȴ�
�л��� ���� 10�� �����̴�.
�׽�Ʈ���̽� ���� ������ �־�����.
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

/*��� ������Ʈ ������ ������ �ʴ� �л����� ���� ����ϴ� ���α׷��� �ۼ��϶�

*/

int T, N;
int arr[100005];//-1�̶�� �̹� �׷쿡 �� �л��̹Ƿ� ������ �ʿ䰡 ���ٴ� ��. �� �л��� ������ �׷쿡 �����ϴ� ���� �Ұ����ϴ�.
bool visited[100005];
int inssacnt;

void clearvisit() {
	memset(visited, false, N);
}

void printall() {
	cout << endl;
	cout << "arr" << endl;
	for (int i = 1; i <= N; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
	cout << "visited" << endl;;
	for (int i = 1; i <= N; i++) {
		cout << visited[i] << ' ';
	}
	cout << endl;
	cout << "inssacnt" << endl;
	cout << inssacnt << endl;
}

void IsCycle(int n) {/*���� �̹� �׷쿡 �Ҽӵ� �л��̸� �Լ� ��Ʈ����.
					���ʼ����� �л��� �ù������� ������ ��, �湮ǥ�ø� ��´�
					�湮ǥ��Ȯ�� �� �����л��� ����Ű�� �л����� ���� �̸� �ؽ�Ʈ��� �Ѵ�
					�湮ǥ��Ȯ�� �� �ؽ�Ʈ�� ����Ű�� �л����� ���� �̸� �ؽ�Ʈ��� �Ѵ�. ���� �ؽ�Ʈ�� -1�� ����Ų�ٸ� ��Ʈ����.
					�湮ǥ��Ȯ�� �� �ؽ�Ʈ�� ����Ű�� �л����� ���� �̸� �ؽ�Ʈ��� �Ѵ�. ���� �ؽ�Ʈ�� -1�� ����Ų�ٸ� ��Ʈ����.
					�湮ǥ��Ȯ�� �� �ؽ�Ʈ�� ����Ű�� �л����� ���� �̸� �ؽ�Ʈ��� �Ѵ�. ���� �ؽ�Ʈ�� -1�� ����Ų�ٸ� ��Ʈ����.
					...
					�������� �湮ǥ��Ȯ���� �ɸ� ���̴�
					�� ��, �ؽ�Ʈ�κ��� ��ȯ�̴�.
					�ؽ�Ʈ�κ��� ������ �� ��ȯ�� ��� �л��� ����Ű�� ���� -1 ��´�
					*/
	if (arr[n] == -1) {
		cout << n << "�� ��޾��Ѵ�" << endl;
		return;
	}
	//printall();
	int next = n;
	while (!visited[arr[next]]) {
		if (arr[next] == -1)
			return;
		visited[next] = true;
		cout << next << " ���� �갡 ����Ű�� " << arr[next] << " ���� �̵�" << endl;
		next = arr[next];
	}
	cout << next << " ���� ����" << endl;
	//��𿡼� ������, �װ��� ����Ŭ�̴�.
	int next = n;
	while (visited[arr[next]]) {
		visited[next] = false;
		/*cout << next << " ���� �갡 ����Ű�� " << arr[next] << " ���� �̵�" << endl;*/
		next = arr[next];
		arr[next] = -1;
	}


	/*while (visited[arr[next]]) {
		visited[next] = false;
		if (arr[next] != -1) {
			inssacnt++;
			cout << next << "�� Ȯ���� �׷쿡 ���ϹǷ� -1�� �����" << endl;
			arr[next] == -1;
		}
		next = arr[next];
	}*/
	
	clearvisit();
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
			cin >> arr[i];
		}
		for (int i = 1; i <= N; i++) {
			IsCycle(i);
		}
		cout << inssacnt << endl;
	}


	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << ctime_duration << " ms" << endl;
	return 0;
}