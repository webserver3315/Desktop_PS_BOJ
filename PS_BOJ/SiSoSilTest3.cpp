#include <bits/stdc++.h>
using namespace std;

int N;
int slen;
char str[10000000];
int ans[11];
int bufsiz;
int idx;
int deg, coeff;

void SignCheck() {//degree, coefficient
	if (str[idx] == '\n') {
		idx++;
	}
	if (str[idx] == '-') {
		idx++;
		coeff *= -1;
	}
	else if (str[idx] == '+') {
		idx++;
	}
}

void CoeffCheck() {
	if ('0' <= str[idx] && str[idx] <= '9') {//���ڶ��
		coeff *= str[idx] - '0';
		idx++;
	}
}

void xCheck() {
	if (str[idx] == 'x') {
		idx++;
	}
	else {
		printf("x�� �־�� �ϴµ� ����???\n");
	}
}

void DegreeCheck() {
	if (str[idx] == '^') {
		idx++;
		//deg = str[idx] - '0';
		char tmp = str[idx];
		deg = tmp - '0';
		idx++;
	}
}

void Calc() {
	printf("deg = %d �� coeff = %d �� ���Ѵ�\n", deg, coeff);
	ans[deg] += coeff;
}

void CheckSet() {
	deg = 1; coeff = 1;
	SignCheck();
	CoeffCheck();
	xCheck();
	DegreeCheck();
	Calc();
}

int main() {
	scanf("%d", &N);
	char tmp, before;
	for (int i = 0; i < N; i++) {
		while (scanf("%c", &tmp) != EOF) {
			str[slen++] = tmp;
		}
	}

	idx++;
	while(idx<slen) {
		CheckSet();
	}
	
	for (int i = 0; i < 10; i++) {
		printf("%d���� ����� %d\n", i, ans[i]);
	}

	return 0;
}