/*
�Ʊ���
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define endl '\n'
#define MAX 21
#define ff first
#define ss second
using namespace std;

typedef pair<int, int> pii;

/*
����� ũ�⸦ Ű�� �Ͽ� �켱����ť�� ����� ���� �� �������� �𸣰�����, �ϴ� naive�ϰ� Ǯ���.
���̽� ���� �ʿ䵵 ���� �̰� �� ������ ��Ģ��� �����̰Բ��� �ϸ� �ȴ�.
*/
int N;
int field[MAX][MAX];
int sec;
int ssize = 2;//���ũ��
int eatcnt;
int sr, sc;//�����ġ

void printfield() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cout << field[r][c] << ' ';
		}
		cout << endl;
	}
}


/*
������ ������ �ִ�.
���� ū ����⿡ �ѷ����� ���� ������� ���, ���� �� ����.
*/


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> field[r][c];
			if (field[r][c] == 9) {
				sr = r; sc = c;
			}
		}
	}

	bool hasEaten = true;
	while (hasEaten) {//������������
		printfield();
		cout << endl;

		int shortestDistance = MAX * 3;
		hasEaten = false;
		
		vector<pii> canEat;
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				if (field[r][c] == 0 || ssize <= field[r][c])//���̰ų�, ũ�Ⱑ �� ū ������ �Ÿ���
					continue;
				pii pos = { r,c };
				int distance = abs(sr - r) + abs(sc - c);
				canEat.push_back(pos);//�ＺA������ �̷��� �ؾߵǴ°� �³�...? C++11�� �������Ѵٰ� �� �Ҿ��ϴ�
				if (shortestDistance > distance)
					shortestDistance = distance;
				if (!hasEaten)
					hasEaten = true;
			}
		}
		if (!hasEaten)//�������Ѱ� �ϳ��� �����ٸ� �ű⼭ ��
			break;
		
		sort(canEat.begin(), canEat.end());//���͸� row ���� ��, �� �������� column ���� �� �켱���� ���� ������, ���� �������� �Ÿ� �ּҰ��� �� �������� ������.
		int vctsize = canEat.size();//cpp17������ ���� �ʿ������ �Ｚȯ�涧����
		int toeatr, toeatc;//������ ��ǥ
		for (int i = 0; i < vctsize; i++) {
			int distance = abs(canEat[i].ff - sr) + abs(canEat[i].ss - sc);
			if (shortestDistance == distance) {//���������ڸ� ����
				toeatr = canEat[i].ff; toeatc = canEat[i].ss;
				break;
			}
		}

		cout << toeatr << ' ' << toeatc << " �� �Խ��ϴ�" << endl;
		field[sr][sc] = 0;
		field[toeatr][toeatc] = 9;
		sec += shortestDistance;//1ĭ�� 1���̹Ƿ�
		eatcnt++;
		if (eatcnt == ssize) {//���̸����� ��� ������
			eatcnt = 0; ssize++;
		}
	}

	std::cout << sec << endl;

	return 0;
}