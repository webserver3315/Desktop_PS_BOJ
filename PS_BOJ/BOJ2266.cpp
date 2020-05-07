#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


/*
비트마스킹으로 하는게 훨씬 깔끔하긴 하겠는데...
일단 리틀엔디안으로 int벡터를 만든다. 0자리가 2진수 0자리다.
http://acmgnyr.org/year2009/problems.shtml
>>>바이너리서치 아니다.
https://www.acmicpc.net/board/view/6989
*/

int n, k;

vector<int> itob(int a) {
	vector<int> ans;
	int tmp = a;
	while (tmp > 1) {
		int append = tmp % 2;
		ans.push_back(append);
		tmp /= 2;
	}
	ans.push_back(tmp);
	return ans;
}

int btoi(vector<int> a) {
	int ans = 0;
	for (int i = 0; i < a.size(); i++) {
		ans += pow(2, i) * a[i];
	}
	return ans;
}

int main() {
	cin >> n >> k;
	vector<int> binary = itob(n);
	/*for (int i = binary.size() - 1; k >= 0; k--, i--) {
		binary[i] = 0;
	}*/
	for (int i = 0; i < k && !binary.empty(); i++) {
		binary.pop_back();
	}
	int ans = btoi(binary) + k + 1;
	cout << ans << endl;
	return 0;
}