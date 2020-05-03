/*
ATM

간단하게 오름차순정렬한다음 멱수열합때리면 되잖아;
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> line;

int desc(int a, int b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(false);
	int n;
	int sum = 0;
	cin >> n;
	while (n--) {
		int num;
		cin >> num;
		line.push_back(num);
	}
	sort(line.begin(), line.end(),desc);
	for (int i = 0; i < (int)line.size(); i++) {
		sum += (i + 1) * line[i];
	}
	printf("%d", sum);
	return 0;
}