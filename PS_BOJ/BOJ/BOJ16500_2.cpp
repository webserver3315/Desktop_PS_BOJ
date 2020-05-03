#include <iostream>
#include <vector>
#include <string>
#define MAX 101
using namespace std;

int N;
string spl;//sample
vector<string> arr;

//bool stringCmp(string::iterator start, string::iterator end, string cmp) {//[start,end)
//	for (auto idx = start, int i=0; idx < end; idx++) {
//		if(spl[idx])
//	}
//}

int DFS(int curr) {
	if (curr == spl.length()) {
		cout << 1 << endl;
		exit(0);
	}

	for (string tmp : arr) {
		int start = curr;
		int end = curr + tmp.length();
		//if (spl.compare(start, end, tmp) == 0) {
		if (spl.substr(start, tmp.length()) == tmp) {
			//cout << tmp << "가 일단 들어맞는다" << endl;
			DFS(end);
			//cout << tmp << "빠꾸다" << endl;
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> spl;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}
	DFS(0);
	cout << 0 << endl;
	return 0;
}