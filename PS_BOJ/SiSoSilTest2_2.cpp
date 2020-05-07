#include <bits/stdc++.h>
//#define int long long

using namespace std;

/*
연, 월을 입력받아 달력 출력
1년1월1일은 월요일
1년부터 2020년까지 주어질 수 있고, 달이 주어지면 달력출력
깔끔하기만 하면 공백은 크게 신경안써도 됨.

윤년은 2월 28일에 추가적으로 29일도 있음.

400으로 나누어떨어지면 닥치고 윤년
100으로 나누어떨어지면 평년
4로 나누어 떨어지면 윤년

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

void printCal(int y, int m) {//1년1월1일을 월요일로 잡고, 이격날짜 모듈러에 따라 그 달 1일의 요일 결정.
	int r = 0; int c = 0;
	//일 월 화 수 목 금 토
	int mod = dayCalc(y, m, 1) % 7;//7로 나눠떨어지면 월요일, 아니면 +mod한 요일
	if (mod % 7 == 6) c = 0;//일
	else c = (mod % 7) + 1;
	int cnt = monthDay(y, m); int d = 1;
	for (; d <= cnt; d++) {
		calendar[r][c++] = d;
		if (c >= 7) {
			r++; c = 0;
		}
	}

	printf("\t%d년\t%d월\n", y, m);
	printf("일\t월\t화\t수\t목\t금\t토\n");
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
		//printf("%d년 %d월 %d일 포함안하고까지의 경과일: %d일\n", year, month, day, dayCalc(year, month, day));
		printCal(year, month);
	}
	

	return 0;
}