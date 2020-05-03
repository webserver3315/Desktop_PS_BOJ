/*
ġŲ ���
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

/*ġŲ���� M���� ����ٰ� �� ��, ������� �ּ��� ġŲ�Ÿ� ������ ���ؼ� ����϶�.
ġŲ���� �ִ� 13��, ���� cartesian coordinate �� �־����Ƿ� �Ÿ��� ���� x, y ������ ���� ���� ������ ���ϸ� �ȴ�.
ġŲ���� K����� �� ��, M���� ���ϴ� �������� KCM�̴�.
�� ��쿡 ���� naive�ϰ� �ּ�ġŲ�Ÿ��� �����ִ� �Լ��� ���� �־��ְ� ���������� �ȴ�.

�׷��ٸ� �� ������ �ϴ� 2������ ���صȴ�.
1. 1��ġŲ������ K�� ġŲ������ M���� �����ϴ� ����� ��
2. �� ����� ���� �ּ�ġŲ�Ÿ��� �����ִ� �Լ��� ����: ������ ���� ���� ��� ġŲ���� ���� �Ÿ��� Ž���ϵ��� �Ѵ�. �� ���̽����� ��*ġŲ�� ������ �ҿ�ȴ�.(��� ��Ƚ���� ������ N**2����)
*/

int N, M;
int Village[52][52];
int Murabito_Kazu, Chicken_Kazu;
int FinalMinChickenKazu = 987654321;
vector<pair<int, int>> Selected_Chicken;
vector<pair<int, int>> Whole_Chicken;
vector<pair<int, int>> Whole_Murabito;

int Get_ChickenDistance() {
	int TotalChickenDistance = 0;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {/*�̷� �������� ����for�� ������ �� ��� RBfL ���°͵� ������ �� �ϴ�. �� ����ȯ�濡�� �ȵɰ��ɼ� ũ����*/
			if (Village[r][c] == 1) {/*�������� �߰ߵǸ�*/
				int MinChickenDistance = 987654320;
				for (auto Chicken : Selected_Chicken) {/*�� ���������κ��� ���� �����ִ� ��� ġŲ���� ���� �Ÿ��� ���Ѵ�.*/
					int ImaChickenDistance = abs(r - Chicken.first) + abs(c - Chicken.second);
					if (MinChickenDistance > ImaChickenDistance)
						MinChickenDistance = ImaChickenDistance;
				}
				TotalChickenDistance += MinChickenDistance;
			}
		}
	}
	return TotalChickenDistance;
}

void Combination_Chicken_Testcase(int start, int depth) {
	if (depth == M) {
		int ImaChickenDistance = Get_ChickenDistance();
		if (ImaChickenDistance < FinalMinChickenKazu) {
			FinalMinChickenKazu = ImaChickenDistance;
		}
		return;
	}
	for (int i = start; i < Chicken_Kazu; i++) {
		Selected_Chicken.push_back(make_pair(Whole_Chicken[i].first, Whole_Chicken[i].second));
		Combination_Chicken_Testcase(i + 1, depth + 1);
		Selected_Chicken.pop_back();
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
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> Village[r][c];
			if (Village[r][c] == 2) {
				Whole_Chicken.push_back(make_pair(r, c));
				Chicken_Kazu++;
			}
			else if (Village[r][c] == 1) {
				Whole_Murabito.push_back(make_pair(r, c));
				Murabito_Kazu++;
			}
		}
	}

	Combination_Chicken_Testcase(0, 0);

	cout << FinalMinChickenKazu << endl;

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << duration << " sec" << endl;
	return 0;
}