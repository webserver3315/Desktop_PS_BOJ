/*
�Ʊ���
*/

#include <iostream>
#include <deque>
#define endl '\n'
#define MAX 21
//#define ff first
//#define ss second
using namespace std;

//typedef pair<int, int> pii;

struct fish {
	int r; int c; int s;//size
};

/*
����� ũ�⸦ Ű�� �Ͽ� �켱����ť�� ����� ���� �� �������� �𸣰�����, �ϴ� naive�ϰ� Ǯ���.
���̽� ���� �ʿ䵵 ���� �̰� �� ������ ��Ģ��� �����̰Բ��� �ϸ� �ȴ�.
*/
int N;
int field[MAX][MAX];
int sec;
int ssize = 2;//���ũ��
int eatcnt;
deque<fish> dqfish;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> field[r][c];
			if (field[r][c] != 0 && field[r][c] != 9) {
				fish Fish = { r,c,field[r][c] };
				dqfish.push_back(Fish);
			}
		}
	}

	bool hasEaten = true;
	while (!hasEaten) {//������������
		int shortestDistance = MAX * 3;
		hasEaten = false;
		int numFish = dqfish.size();
		for (int i = 0; i < numFish; i++) {
			fish nowfish = dqfish.front();
			dqfish.pop_front;
			if (nowfish.s < ssize) {//������, �ϴ� �������ִ�

			}

		}


	}

	cout << sec << endl;

	return 0;
}