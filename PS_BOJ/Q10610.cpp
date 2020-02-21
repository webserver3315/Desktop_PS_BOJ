/*
30
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

bool exist0 = false;
int list[100000];

bool desc(int a, int b) {
	return a > b;
}

int main() {
	int i = 0, sum = 0;
	//do {
	//	int result = scnaf("%1d", &list[i]);
	//	if (list[i] == 0) {
	//		exist0 = true;
	//	}
	//	sum += list[i];
	//	++i;
	//} while (result != EOF);

	/*while (scanf("%1d", &list[i]) != EOF) {
		puts("여기까지 왔다");
		if (list[i] == 0) {
			exist0 = true;
		}
		sum += list[i];
		++i;
	}*/

	string input;
	cin >> input;
	/*for (int i = 0; i < input.length(); i++) {
		list[i] = atoi(&input[i]);
		if (list[i] == 0)
			exist0 = true;
		sum += list[i];
	}*/
	int length = input.length();
	for (int i = input.length() - 1; i >= 0; --i) {
		list[i] = atoi(&input[i]);
		input[i] = '\0';
		if (list[i] == 0)
			exist0 = true;
		sum += list[i];
	}
	
	if (exist0 && 0 == sum % 3) {
		sort(list, list + length, desc);
		for (int idx = 0; idx < length; idx++) {
			printf("%d", list[idx]);
		}
		printf("\n");
	}
	else {
		printf("-1\n");
	}
	return 0;
}