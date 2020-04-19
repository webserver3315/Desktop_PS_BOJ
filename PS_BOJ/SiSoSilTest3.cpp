#include <bits/stdc++.h>
using namespace std;

int N;
char** strarr;

int main() {
	scanf("%d", &N);
	strarr = (char**)malloc(sizeof(char*) * (N + 1));
	for (int i = 0; i < N; i++) {
		strarr[i] = (char*)malloc(sizeof(char) * 1000);
	}



	return 0;
}