#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

/*
4 0 11 11 11
겹치지 않았던 수 중 가장 큰 수를 가장 앞에.
그 다음에 순서는 상관없음.
*/

int n;
vector<int> arr;

bool desc(int a, int b) {
	return a > b;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}
	sort(arr.begin(), arr.end(), desc);

	/*
	
	*/
	int now = arr[0];
	int koreda = -1;
	for (int i = 0; i < arr.size() - 1; i++) {
		if (now != arr[i + 1]) {//다음수와 다르고
			if (i > 0 && now == arr[i - 1]) {//이전수와도 같다면, 유일한 수가 아니다.
				now = arr[i+1];
				continue;
			}
			koreda = now;//이전수가 없거나 이전수와 다르다면, 유일한 수다.
			break;
		}
		now = arr[i+1];
	}
	if (koreda != -1) {
		cout << koreda << ' ';
		for (int i : arr) {
			if (i != koreda)
				cout << i << ' ';
		}
		cout << endl;
	}
	else {
		for (int i : arr) {
			cout << i << ' ';
		}
		cout << endl;
	}

	return 0;
}