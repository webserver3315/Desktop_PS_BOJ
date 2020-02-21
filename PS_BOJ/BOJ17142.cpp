/*
������ 3

�̹��� DFS�� Flood Fill �� �����غ����� ����.
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

/*�ð��� 0.25�� �־�����. �ϴ� ��������.
���̷��� �� M���� Ȱ��ȭ���Ѽ�, ��� ������� ���̷����� �޿���� �Ѵ�.
���̷����� 1�ʿ� 1ĭ Ȯ��ȴ�. - ����Լ��� ���ڷ� ���� �ʸ� �����ؾ߰ڴ�.
Ȱ�����̷����� ��ĭ�� ����, ��Ȱ�����̷��� ĭ���ε� Ȯ��� �� �ִ�. ��, ���� ������ ��� ĭ���� Ȯ�갡���ϴ�.


�ð��� ��� ���̹Ƿ�, DFS���ٴ� BFS��, �� ���ڿ� ���� �ʸ� ���ܼ� flood fill ��Ű�� ���� �����غ��δ�. �ƽ��Ե� �� BFS�ΰ�. �����ؼ��� �̹��� �ѹ� DFS ���?
��, �ƴϴ�. ���� ���ڿ� �ʸ� ���ܼ� ���ڸ� struct�� ���� �ʿ� ����, �󺸿��� 0�� �����, 1�� ��, 2�� ���̷��� ��ġ�������, 3�� ���ʹ��̷���(0��), 4���ʹ� 1������ ������ ���̷��� �̷��� �����ϸ� �� ���ϰڴ�. �׷��ٰ� ������ char ������ ����, int�� ����.

������ 2���� �ɰ� �� �ִ�.
1. ���̷��� �� V���� �ִٰ� �� ��, VCM���� ���ʷ� Ȱ��ȭ��ų ���̷��� M���� �����ϴ� �Լ�
2. �� ��쿡 ���� �����µ� �ɸ��� �ּҽð��� ��ȯ�ϴ� �Լ�

1���� �ذ��ϱ� ���ؼ��� ������ ����ؾ� �Ѵ�.
�̸� ���� �ʿ��� �ڷᱸ���δ�
���ʹ��̷�����ǥ ������ ����
Ȱ��ȭ���̷�����ǥ ���ÿ� ����

�����Ѱ� �ִµ�, �Ұ����� ��쵵 �����Ѵ�. �ش� ���, -1�� ��ȯ�ؾ� �Ѵ�.
��� ĭ�� �������� ���ߴٴ� ���� ������Ű�� ���ؼ��� ����ĭ�� ������ ������ �ʿ䰡 �ִ�.
*/

int TotalLargestTimeforDFS=987654321;
int EachLargestTimeforDFS;
int OriginalLabo[51][51];
int Labo[51][51];
int N, M;//�����Ҵ� ���簢��, ��ġ�� ���̷��� ��
int dr[4] = { 1,-1,0,0 }; int dc[4] = { 0,0,-1,1 };
int MinKakusanTime = 987654321;
vector<pair<int, int>> Kanou_Virus;
vector<pair<int, int>> Setchi_Virus;
int Hajime_BlankKazu;

void PrintLabo() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << Labo[i][j] << ' ';
		}
		cout << endl;
	}
	return;
}

void CleanLabo() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			Labo[r][c] = OriginalLabo[r][c];
		}
	}
	return;
}

int VirusKaiho_BFS() {
	int final_time = 0;
	queue<pair<int, int>> KakusanChu;
	for (auto HajimeVirus : Setchi_Virus)
		KakusanChu.push(HajimeVirus);

	while (!KakusanChu.empty()) {
		int r = KakusanChu.front().first; int c = KakusanChu.front().second;
		KakusanChu.pop();
		for (int i = 0; i < 4; i++) {
			int rr = r + dr[i]; int cc = c + dc[i];
			if (rr >= N || rr < 0 || cc >= N || cc < 0 || Labo[rr][cc] == 1 || (Labo[rr][cc] != 0 && Labo[rr][cc] <= Labo[r][c])) {/*���� ������Ұ� ��ܶ�ų� ���̶�� �ɷ��� �Ѵ�. ����, ���� ���� ��Ҹ� ���� Ȯ��� �ʿ䰡 ����.*/
				continue;
			}
			if(Labo[rr][cc]<Labo[r][c])
			Labo[rr][cc] = Labo[r][c] + 1;
			if (final_time < Labo[rr][cc])
				final_time = Labo[rr][cc];
			KakusanChu.push({ rr,cc });
		}
	}
	
	return final_time;
}


/*����̷����� �ٽ� �ǵ��ư��� ������ �ĺ��Ǿ���.*/
int VirusKaiho_BFS2() {
	int final_time = 0;
	int SusunndaKazu = 0;
	queue<pair<int, int>> KakusanChu;
	for (auto HajimeVirus : Setchi_Virus)
		KakusanChu.push(HajimeVirus);

	while (!KakusanChu.empty()) {
		int r = KakusanChu.front().first; int c = KakusanChu.front().second;
		KakusanChu.pop();
		for (int i = 0; i < 4; i++) {
			int rr = r + dr[i]; int cc = c + dc[i];
			if (rr >= N || rr < 0 || cc >= N || cc < 0 || Labo[rr][cc] != 0) {/*���� ������Ұ� ��ܶ�ų� ���̶�� �ɷ��� �Ѵ�. ����, ���� ���� ��Ҹ� ���� Ȯ��� �ʿ䰡 ����.*/
				continue;
			}
			if (Labo[rr][cc] < Labo[r][c] + 1)
					SusunndaKazu++;
				Labo[rr][cc] = Labo[r][c] + 1;
			if (final_time < Labo[rr][cc])
				final_time = Labo[rr][cc];
			KakusanChu.push({ rr,cc });
		}
	}

	cout << "Ȯ�� ����" << endl;
	PrintLabo();
	cout << endl;
	if (Hajime_BlankKazu == SusunndaKazu)
		return final_time - 3;
	return -1;
}


/*��ĭ�� ���̷��� �ĺ����� �ٸ��� ��޵ȴ�. �� ���̷��� �ĺ��������� ���̷����� �۶߸� �ʿ�� ����. ���������� �� "��ĭ"�� �� ä��� �ȴ�.*/
void VirusKaiho_DFS(int r, int c, int corruptedBlank){
	int final_time = 0;
	if (corruptedBlank == Hajime_BlankKazu) {/*��� ��ĭ�� �� �޿��ٸ�, �ɸ� �ð��� �����ؾ���*/
		if (EachLargestTimeforDFS < TotalLargestTimeforDFS)
			TotalLargestTimeforDFS = EachLargestTimeforDFS;
		EachLargestTimeforDFS = 0;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int rr = r + dr[i]; int cc = c + dc[i];
		if (rr >= N || rr < 0 || cc >= N || cc < 0) {/*��ܶ��*/
			continue;
		}
		if (Labo[rr][cc] > Labo[r][c] + 1 || Labo[rr][cc] == 2) {/*��� ��ġ�� �ְų�, ���̷��� �����ڸ����ٸ� ����*/
			if (Labo[rr][cc] == 0) {
				Labo[rr][cc] = Labo[r][c] + 1;
				if (Labo[rr][cc] > EachLargestTimeforDFS)
					EachLargestTimeforDFS = Labo[rr][cc];
				VirusKaiho_DFS(rr, cc, corruptedBlank + 1);
				Labo[rr][cc] = OriginalLabo[rr][cc];
			}
			else {
				Labo[rr][cc] = Labo[r][c] + 1;
				if (Labo[rr][cc] > EachLargestTimeforDFS)
					EachLargestTimeforDFS = Labo[rr][cc];
				VirusKaiho_DFS(rr, cc, corruptedBlank);
				Labo[rr][cc] = OriginalLabo[rr][cc];
			}
		}
	}
	return;
}

void SelectVirus(int depth) {
	if (depth == M) {
		cout << "M���� ���̷��� ��ġ�Ϸ�" << endl;
		VirusKaiho_DFS();
		PrintLabo();
		cout << endl;
		if (TestcaseFinalTime < MinKakusanTime) {
			cout << "�ּ�Ȯ��ð� ������Ʈ: " << MinKakusanTime << " ���� " << TestcaseFinalTime << endl;
			MinKakusanTime = TestcaseFinalTime;
		}
		cout << "�� �ʱ�ȭ" << endl;
		CleanLabo();
		PrintLabo();
		cout << endl;
		return;
	}
	for (int idx = depth; idx < Kanou_Virus.size(); idx++) {
		pair<int, int> Ima_Virus = Kanou_Virus[idx];
		int r = Ima_Virus.first; int c = Ima_Virus.second;
		Labo[r][c] = 3;/*Ȱ��ȭ�� ���̷����� 2���� 3���� ǥ�ĺ���.*/
		Setchi_Virus.push_back(Ima_Virus);

		cout << r << " , " << c << " ��ġ�� " << idx << " ��° ���̷��� ��ġ" << endl;
		PrintLabo();
		cout << endl;

		SelectVirus(depth + 1);
		Labo[r][c] = 2;

		cout << r << " , " << c << " ��ġ�� " << idx << " ��° ���̷��� ȸ��" << endl;
		PrintLabo();
		cout << endl;

		Setchi_Virus.pop_back();
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
			int tmp;
			cin >> tmp;
			Labo[r][c] = tmp; OriginalLabo[r][c] = tmp;
			if (Labo[r][c] == 2)
				Kanou_Virus.push_back({ r,c });
			else if (Labo[r][c] == 0)
				Hajime_BlankKazu++;
		}
	}

	SelectVirus(0);

	cout << TotalLargestTimeforDFS << endl;

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << duration << " sec" << endl;
	return 0;
}