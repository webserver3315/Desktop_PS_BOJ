/*
�ٸ������2
*/

#include <iostream>
#include <string>
#include <queue>
#include <deque>
#include <algorithm>
#include <vector>
#include <array>
#include <cmath>
#include <cstdio>
#include <ctime>
#define endl '\n'
using namespace std;

int DFS_cnt;
int R, C, NumberOfCountry = 1;
int map[10][10];/*r,c ���̸� 2�������ͷ� Ǯ���ٰ� �ϴ� ���������� ������ �迭�� �����ߴ�.*/
int KyoriTable[10][10];/*���� �ִܰŸ��� �����ϴ� ���̺��̴�.*/
int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0,-1,1 };
int MinTotalDistance = 99999;
bool visited[10];
bool TraverseComplete;/*��ȸ�����Ұ��*/
/*�ٸ��� �ݵ�� �������̾�߸� �ϰ�, ���̴� �ݵ�� 2 �̻��̾�߸� �Ѵ�.
�� ���� �� ���� �����ϴ� �ٸ��� �� ���� ���� ���, �� �ٸ��� �� ���� �մ� �ٸ��� ��޵��� ���Ѵ�.
�ٸ��� ������ ���Ǹ�, �� ��� �ٸ��� ���̴� �ߺ��Ǿ� ���ȴ�.
���� ������ ���̴� 10 ���Ϸ� ����Ǹ� ���� ������ 2�� �̻� 6�� �������� ����ȴ�.
��� ���� ������ �Ұ����ϴٸ� -1�� ����ϸ� �ȴ�.

���� N�����, �ٸ��� ���� N-1�� �̻��̾�߸� �Ѵ�. �׸���, N-1���� �ٸ��� � ���� ����� ���ᤡ���ϴ�.
�׷���, N-1���� �ٸ��� �״� �� ���� N�� �̻��� �ٸ��� ���� ���� �� ȿ������ ��찡 �����ϱ� �ϴ°�?

�� ���
1. �Էµ� ���� �ϴ� 1, 2, 3, ... , 6���� ��ȣ�� �ű��.
2. �� �� �� ������ �ִܰŸ��� ���Ѵ�. ���� �ٸ��� ���°� �Ұ����ϴٸ�, -1�� ä���ִ´�.
>>>������ ���� �� �ִ� �ٸ��� ���� �ƹ��� ���ƺ��� n+m������. �׷��ϱ� ���� ���Ƽ� �ִܰŸ��� �����ؼ� ����. ���� DFS�� BFS �� �ʿ�� ���⼱ ����.
3. �ϼ��� �Ÿ�2�����迭�� �̿��ؼ�, �ִܰŸ����ǿ������� �ذ��Ѵ�. �� ����� BFS�̴�. ������ n�� ���� �� ���ƾ��ϴ� ���̰� n���� ������ BFS��.
*/

void PrintMap() {
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cout << map[r][c] << ' ';
		}
		cout << endl;
	}
	return;
}

void PrintKyoriMap() {
	for (int r = 1; r <= NumberOfCountry; r++) {
		for (int c = 1; c <= NumberOfCountry; c++) {
			cout << KyoriTable[r][c] << ' ';
		}
		cout << endl;
	}
	return;
}

bool IsTraverseCompleted() {
	for (int i = 1; i <= NumberOfCountry; i++) {
		if (visited[i] == false)
			return false;
	}
	return true;
}

void MakingKyoriTable() {
	for (int r = 0; r < R; r++) {/*�Ÿ����̺� �ʱ�ȭ*/
		for (int c = 0; c < C; c++) {
			KyoriTable[r][c] = 10;
		}
	}

	for (int r = 0; r < R; r++) {/*�¿��� ��θ� Ž��*/
		int start = -1; int end = -1; int distance = 0;
		for (int c = 0; c < C; c++) {
			if (map[r][c] != 0) {/*�������*/
				if (start == -1) {/*ù ������ ���*/
					start = map[r][c];/*��������*/
					distance = 0;
				}
				else {/*���������� ��������̶��*/
					end = map[r][c];/*��������*/
					if (distance != 1 && KyoriTable[start][end] > distance && start != end) {
						KyoriTable[start][end] = distance;
						KyoriTable[end][start] = distance;
					}
					start = map[r][c];/*���ο� ���۱����� ����*/
					distance = 0;
				}
			}
			else {
				distance++;
			}
		}
	}

	for (int c = C - 1; c >= 0; c--) {/*�󿡼� �Ϸθ� Ž��*/
		int start = -1; int end = -1; int distance = 0;
		for (int r = 0; r < R; r++) {
			if (map[r][c] != 0) {/*�������*/
				if (start == -1) {/*ù ������ ���*/
					start = map[r][c];/*��������*/
					distance = 0;
				}
				else {/*���������� ��������̶��*/
					end = map[r][c];/*��������*/
					if (distance != 1 && KyoriTable[start][end] > distance && start != end) {
						KyoriTable[start][end] = distance;
						KyoriTable[end][start] = distance;
					}
					start = map[r][c];/*���ο� ���۱����� ����*/
					distance = 0;
				}
			}
			else {
				distance++;
			}
		}
	}
	return;
}

void NumberingMap() {
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			if (map[r][c] == -1) {/*���ھ��� �������*/
				map[r][c] = NumberOfCountry;
				queue< pair <int, int> > ColonyQueue;
				ColonyQueue.push(make_pair(r, c));
				while (!ColonyQueue.empty()) {
					pair <int, int> Ima = ColonyQueue.front();
					ColonyQueue.pop();
					int rr = Ima.first; int cc = Ima.second;
					for (int i = 0; i < 4; i++) {/*�����¿쿡 ���Ͽ�*/
						if (rr + dr[i] >= 0 && rr + dr[i] < R && cc + dc[i] >= 0 && cc + dc[i] < C && map[rr + dr[i]][cc + dc[i]] == -1) {/*��ܱ����� �ƴϸ鼭 �������� ���̶��*/
							map[rr + dr[i]][cc + dc[i]] = NumberOfCountry;
							ColonyQueue.push(make_pair(rr + dr[i], cc + dc[i]));
						}
					}
				}
				NumberOfCountry++;
			}
		}
	}
	NumberOfCountry--;

	return;
}

void DFS(int depth, int Sum) {
	//cout << "ȣ��_DFS depth, sum : " << depth << ' ' << Sum << endl;
	if (depth == NumberOfCountry-1) {
		//cout << "��ȸ�Ϸ�" << endl;
		if (!TraverseComplete)
			TraverseComplete = true;
		if (Sum < MinTotalDistance) {
			//cout << "@@@@@@�ּ��� ����� ������Ʈ�մϴ�. " << MinTotalDistance << " >>> " << Sum << endl;
			MinTotalDistance = Sum;
		}
		return;
	}
	for (int HajimeKuni = 1; HajimeKuni <= NumberOfCountry; HajimeKuni++) {
		if (!visited[HajimeKuni])
			continue;
		for (int OwariKuni = 1; OwariKuni <= NumberOfCountry; OwariKuni++) {
			if (visited[OwariKuni] || KyoriTable[HajimeKuni][OwariKuni] == 10)/*�̹� �湮�� ����ų� �ڱ��ڽ��̸� �Ÿ���*/
				continue;
			visited[OwariKuni] = true;
			//cout << HajimeKuni << " �� " << OwariKuni << "�� �����ϴ� �ٸ��� �������ϴ�." << endl;
			DFS(depth + 1, Sum + KyoriTable[HajimeKuni][OwariKuni]);
			//cout << HajimeKuni << " �� " << OwariKuni << "�� �����ϴ� �ٸ��� �ν����ϴ�." << endl;
			visited[OwariKuni] = false;
		}
	}
	return;
}

int main() {
	cin >> R >> C;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			int tmp;
			cin >> tmp;
			if (tmp == 1)
				tmp = -1;
			map[r][c] = tmp;
		}
	}

	NumberingMap();
	PrintMap();
	cout << endl;

	MakingKyoriTable();//��1�� �����ϴ°� ��� ������ ŷ�ɼ� ����.
	PrintKyoriMap();

	visited[1] = true;
	DFS(0, 0);

	if (TraverseComplete)
		cout << MinTotalDistance << endl;
	else
		cout << -1 << endl;

	return 0;
}