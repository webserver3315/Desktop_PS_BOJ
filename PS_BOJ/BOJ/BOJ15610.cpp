#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double n;

double mysqrt(double n) {
	double lo = 0, hi = n, mid;
	for (int i = 0; i < 1000; i++) {//UsingBinSearch //�̰� while(lo<hi) �� �ϸ� ������ �� ����ؼ� ��Ȯ���� ������ �� �����Ƿ� �� �������� �ʴ� �� ������ �ּ� 1000���� �����Բ� �� �� �ϴ�.
		mid = (lo + hi) / 2;
		if (mid * mid == n)
			return mid;
		else if (mid * mid > n)
			hi = mid;
		else
			lo = mid;
	}
	return mid;
}

int main() {
	std::cout << std::setprecision(10);
	cin >> n;
	/*double ans = sqrt(n);
	cout << ans << endl;*/
	double ans = mysqrt(n);
	cout << 4 * ans << endl;
	return 0;
}