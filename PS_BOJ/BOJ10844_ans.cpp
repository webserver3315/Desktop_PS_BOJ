#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	vector<vector<int>> d(n, vector<int>(10, 0));
	d[0] = { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

	for (int i = 1; i < n; i++) {
		for (int digit = 0; digit < 10; digit++) {
			if (digit == 0) {
				d[i][digit] = d[i - 1][1];
			}
			else if (digit == 9) {
				d[i][digit] = d[i - 1][8];
			}
			else {
				d[i][digit] = (d[i - 1][digit - 1] + d[i - 1][digit + 1]) % 1000000000;
			}
		}
	}
	int sum = 0;
	for (int x : d[n - 1]) {
		sum = (sum + x) % 1000000000;
	}

	printf("%d\n", sum);

	return 0;
}