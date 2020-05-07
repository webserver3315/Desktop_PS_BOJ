#include <bits/stdc++.h>
//#define int long long

using namespace std;

/*
��, ���� �Է¹޾� �޷� ���
1��1��1���� ������
1����� 2020����� �־��� �� �ְ�, ���� �־����� �޷����
����ϱ⸸ �ϸ� ������ ũ�� �Ű�Ƚᵵ ��.

������ 2�� 28�Ͽ� �߰������� 29�ϵ� ����.

400���� ����������� ��ġ�� ����
100���� ����������� ���
4�� ������ �������� ����

*/

int t;
int year, month;
int calendar[7][7];

int isLeap(int y) {
	if (y % 400 == 0) {
		return 1;
	}
	else if (y % 100 == 0) {
		return 0;
	}
	else if (y % 4 == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int monthDay(int y, int m) {
	switch (m) {
	case 1: return 31;
	case 2:
		if (isLeap(y)) return 29;
		else return 28;
	case 3: return 31;
	case 4: return 30;
	case 5: return 31;
	case 6: return 30;
	case 7: return 31;
	case 8: return 31;
	case 9: return 30;
	case 10: return 31;
	case 11: return 30;
	case 12: return 31;
	}
}

int dayCalc(int y, int m, int d) {
	int cnt = 0;
	for (int yy = 1; yy < y; yy++) {
		if (isLeap(yy)) cnt += 366;
		else cnt += 365;
	}
	for (int mm = 1; mm < m; mm++) {
		cnt += monthDay(y,mm);
	}
	cnt += (d - 1);
	return cnt;
}

void printCal(int y, int m) {//1��1��1���� �����Ϸ� ���, �̰ݳ�¥ ��ⷯ�� ���� �� �� 1���� ���� ����.
	int r = 0; int c = 0;
	//�� �� ȭ �� �� �� ��
	int mod = dayCalc(y, m, 1) % 7;//7�� ������������ ������, �ƴϸ� +mod�� ����
	if (mod % 7 == 6) c = 0;//��
	else c = (mod % 7) + 1;
	int cnt = monthDay(y, m); int d = 1;
	for (; d <= cnt; d++) {
		calendar[r][c++] = d;
		if (c >= 7) {
			r++; c = 0;
		}
	}

	printf("\t%d��\t%d��\n", y, m);
	printf("��\t��\tȭ\t��\t��\t��\t��\n");
	for (int r = 0; r < 7; r++) {
		for (int c = 0; c < 7; c++) {
			if (calendar[r][c] == 0) printf("\t");
			else printf("%d\t", calendar[r][c]);
		}
		printf("\n");
	}

}

int main() {

	//scanf("%d", &t);
	t = 1;
	while (t--) {
		scanf("%d %d", &year, &month);
		//int day;
		//scanf("%d %d %d", &year, &month, &day);
		//printf("%d�� %d�� %d�� ���Ծ��ϰ������ �����: %d��\n", year, month, day, dayCalc(year, month, day));
		printCal(year, month);
	}
	

	return 0;
}