#include <iostream>
#include <vector>
#include <algorithm>
//#include <string>
#define MAX (int)2e5+1
#define endl '\n'
using namespace std;

int n;
vector<int> tea;
vector<int> stu;
int Jindo[MAX];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		tea.push_back(tmp);
	}
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		stu.push_back(tmp);
	}
	sort(tea.begin(), tea.end()); sort(stu.begin(), stu.end());
	for (int i = 0; i < n; i++) {
		Jindo[i] = i + 1;
	}


	return 0;
}