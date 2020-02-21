/*
A
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

/*고장난 키보드는 반드시 중복입력. 고장안난키보드는 그냥입력.
string의 처음부터 끝까지 조사하는데, 만일 동일한 글자가 홀수번 반복된다면(1번도 포함) 그 글자는 map에 넣는다.


*/

int T;


/*전진만 한다. 
1번 인덱스부터 시작하며, 자신 직전항과 비교한다.
자신 직전항과 동일하면 KurikaesiCount를 증가
다르면 증가 이후 터트린다.

좀 더 구체적으로 짜자.
일단 크기가 1인지부터 조사한다. 1이면 그냥 그거 출력하고 터트린다.
만일 크기가 2 이상이라면, 이전항과 끝까지 조사를 반복하게 된다.
만일, 이전항과 동일하다면: 반복카운트 ++ // 아니다. 무조건 앞뒤 둘다 비교해야만 한다. // 아니다. 글자가 바뀔때마다 insert 판단하는 식으로 한다면 상관없다.
끝항이거나, 다르다면: 반복카운트++하고 반복카운트 참조. 만일 홀수번 반복된 상황이면insert, 같다면 다음으로
*/
void solve(string answer) {
	if (answer.size() == 1) {
		cout << answer << endl;
		return;
	}
	//answer.push_back('E');
	set<char> Kakusin;
	char Kioku = answer.front();
	int KurikaesiCount = 1;
	for (int idx = 1; idx <= answer.size();idx++) {//왜 에러가 안뜨지? idx==answer.size() 인데 answer[idx]로 참조하면 불가능한 참조라는 오류가 떠야 하잖아? 아, 아예 정의되지 않은 케이스라 오류조차 뜨지 않는건가;
		char c = answer[idx];//아, 에러가 안뜬다. 왜냐하면, size와 동일한 idx를 참조하는 경우 \0이 성공적으로 c에 저장되기 때문이다. 정상적인 연산으로 취급한다. 그러나, 조금 더 수정해서 \0 의 범위까지 벗어나 완전히 string의 관할구역에서 벗어나버리면 그 땐 컴파일러수준에서 경고 및 에러를 때려버리고 프로그램을 터트린다.
		if (c != Kioku) {
			//KurikaesiCount++;
			if (KurikaesiCount % 2) {
				Kakusin.insert(Kioku);
				//cout << Kioku << " 는 홀수번 반복되었으므로 삽입" << endl;
			}
			Kioku = c;
			KurikaesiCount = 1;
		}
		else {
			KurikaesiCount++;
		}
	}
	/*if (answer.back() != Kioku) {
		if (KurikaesiCount % 2)
			Kakusin.insert(c);
		KurikaesiCount = 1;
		Kioku = c;
	}*/
	for (char c : Kakusin) {
		cout << c;
	}
	cout << endl;
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> T;
	for (int i = 0; i < T; i++) {
		string answer;
		cin >> answer;
		solve(answer);
	}


	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << duration << " sec" << endl;
	return 0;
}