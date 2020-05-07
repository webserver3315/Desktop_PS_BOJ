#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


/*
��Ʈ����ŷ���� �ϴ°� �ξ� ����ϱ� �ϰڴµ�...
�ϴ� ��Ʋ��������� int���͸� �����. 0�ڸ��� 2���� 0�ڸ���.
http://acmgnyr.org/year2009/problems.shtml
>>>���̳ʸ���ġ �ƴϴ�.
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