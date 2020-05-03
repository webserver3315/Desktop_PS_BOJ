#include <bits/stdc++.h>
using namespace std;

int N;
char** str;
int slen;
int coeff[10];

int main() {
	scanf("%d", &N);
	str = (char**)malloc(sizeof(char*) * (N + 1));
	for (int i = 0; i < N; i++) {
		str[i]=(char*)malloc(sizeof(char) * 1000);
		scanf("%s", &str[i]);
	}

	for (int i = 0; i < N; i++) {
		printf("%s\n", str[i]);
	}

	free(str);

	return 0;
}