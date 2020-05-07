#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double n;

double mysqrt(double n) {
	double lo = 0, hi = n, mid;
	for (int i = 0; i < 1000; i++) {//UsingBinSearch //이거 while(lo<hi) 로 하면 오히려 덜 계산해서 정확도가 떨어질 수 있으므로 딱 떨어지지 않는 한 무조건 최소 1000번은 돌리게끔 한 듯 하다.
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