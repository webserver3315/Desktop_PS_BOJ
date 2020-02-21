/*
B
*/

#include <iostream>
#include <set>
#include <map>
#include <deque>
#include <vector>
#include <queue>
#include <array>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <climits>
#define endl '\n'
//#define X first
//#define Y second
//typedef pair <int, int> P;
//P mypair = make_pair(1.2);//권장사항
//pair<int, int> mypair = make_pair(1, 2);//C++11 비지원시 이렇게
//P mypair = { 1,2 };//C++11 이후부터만 가능
//P mypair(1, 2);//생성자이용
//#define mp(x,y) make_pair(x,y)//고인물용

using namespace std;

/*
n종류의 2진스트링이 주어질 때
스트링의 총 1과 0의 수를 유지하자.
그리고, 스트링의 길이를 정리해놓자.
짝수면 1 또는 0을 짝수단위씩 소모해야 하고
홀수면 1 또는 0을 짝수단위씩 소모하면서 추가로 0 또는 1 아무거나 단독으로 소모하면 회문이 완성된다.

최저비용, 즉 가장 짧은 스트링부터 회문으로 만들어나가는게 우선은 그리디의 조건이다.

*/

int Q;

int Solve(int n) {
	int OneKazu = 0; int ZeroKazu = 0;
	vector<string> strings;
	vector<int> sizes;
	int palindrome = 0;

	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		strings.push_back(tmp);
		for (char c : tmp) {
			if (c == '1')
				OneKazu++;
			else if (c == '0')
				ZeroKazu++;
		}
		sizes.push_back(tmp.size());
	}
	sort(sizes.begin(), sizes.end());
	
	for (int sizeFromMin : sizes) {

		int sacrifice = sizeFromMin / 2;
		int sacrifice2 = 1;

		if (sizeFromMin % 2 == 0) {//짝수라면
			while (sacrifice) {
				if (max(OneKazu, ZeroKazu) < 2)//sacrifice 소진시키기 전에 1, 0이 떨어질 경우 여기서 오와리다.
					break;
				bool OneIsOoi = OneKazu > ZeroKazu;
				if (OneIsOoi) {
					OneKazu -= 2;
				}
				else {
					ZeroKazu -= 2;
				}
				sacrifice--;
			}
		}
		else {//홀수라면
			while (sacrifice) {
				if (max(OneKazu, ZeroKazu) < 2)//sacrifice 소진시키기 전에 1, 0이 떨어질 경우 여기서 오와리다.
					break;
				bool OneIsOoi = OneKazu > ZeroKazu;
				if (OneIsOoi) {
					OneKazu -= 2;
				}
				else {
					ZeroKazu -= 2;
				}
				sacrifice--;
			}
			if (sacrifice == 0) {//홀수는 sacrifice를 소진시켜도 한 개의 관문이 더 남아있다.
				bool OneIsOoi = OneKazu > ZeroKazu;
				if (max(OneKazu, ZeroKazu) < 1)//남은 1 소진시키기 전에 1, 0이 떨어질 경우 여기서 오와리다.
					return palindrome;
				if (OneIsOoi) {
					OneKazu--;
				}
				else {
					ZeroKazu--;
				}
			}
		}
		if(sacrifice==0)
			palindrome++;
		else {//소진이면 가망없다.
			return palindrome;
		}
	}

	return palindrome;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int stringNumber;
		cin >> stringNumber;
		int ans = Solve(stringNumber);
		cout << ans << endl;
	}


	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << duration << " sec" << endl;
	return 0;
}