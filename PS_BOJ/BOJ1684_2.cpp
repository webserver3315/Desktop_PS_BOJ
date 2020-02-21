/*
���Ʈ�ϰ� Ǯ���� ������
�ִ������� �̿��� ������ �ع����� Ǯ���� �ߴ�.

�� ���̵���
https://m.blog.naver.com/kyaryunha/221191076960
�� �����ߴ�.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

int n;
vector<int> arr;
vector<int> diff;

int myabs(int a) {
	if (a < 0)
		return -a;
	return a;
}

int gcd(int a, int b) {//�������� ����ص���.
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}

	for (int i = 0; i < n - 1; i++) {
		int tmp = myabs(arr[i] - arr[i + 1]);
		if (tmp == 0)
			continue;
		diff.push_back(tmp);
	}

	/*
	diff�� ��� ������ �ִ������� ���ϱ⸸ �ϸ� �ȴ�.
	*/
	int gcdtmp = gcd(diff[0], diff[1]);
	for (int i = 2; i < diff.size(); i++) {
		gcdtmp = gcd(gcdtmp, diff[i]);
	}
	cout << gcdtmp << endl;

	return 0;
}