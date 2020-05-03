/*
수묶기
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> positive_list;
vector<int> negative_list;
int n, sum;
int start_idx;/*양수시작인덱스*/

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		if (tmp > 0)
			positive_list.push_back(tmp);
		else
			negative_list.push_back(tmp);
	}
	sort(positive_list.begin(), positive_list.end());
	sort(negative_list.begin(), negative_list.end());

	int ns = (int)negative_list.size();
	int ps = (int)positive_list.size();

	for (int i = 0; i < ns; i++) {
		if (i + 1 < ns) {
			sum += negative_list[i] * negative_list[i+1];
			i++;
		}
		else {
			sum += negative_list[i];
		}
	}

	for (int i = ps-1; i >=0; i--) {
		if (i >= 1) {
			if (positive_list[i] == 1 || positive_list[i - 1] == 1) {
				sum += positive_list[i] + positive_list[i - 1];
				--i;
			}
			else {
				sum += positive_list[i] * positive_list[i - 1];/*연산순서 의도대로 작동하는지 불확실. 안되네. 분리해서 쓰자. 아마 i -- 먼저되고 i, i-1 더한 듯 한데..*/
				--i;
			}
		}
		else {
			sum += positive_list[i];
		}
	}
	cout << sum << endl;
	return 0;
}