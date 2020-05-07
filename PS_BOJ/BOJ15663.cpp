/*
N과M 9
중복이 허용되는 인풋이 주어질 때, 수열을 출력하라
*/

#include <iostream>
#include <string>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <vector>
#include <array>
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

int N, M;
bool visited[10];
vector<int> mystack;
set<vector<int>> mukashi;
vector<int> kouhou;

/*
M<=N임에 유의해야하고,
1 1 1 1 을 입력받았고 4자리를 출력해야한다면 1 1 1 1을 출력해야 한다.
똑같은 원리로, 1 1 3 4 를 입력받았고 4자리를 출력해야한다면 1 1 3 4를 출력해야 한다.
고로, 이 문제에서는 중복 거르겠다고 set을 쓰면 안된다. 중복원소도 결국 쓰이는 케이스가 있다.

1 7 9 9를 입력한다면, 2개씩 뽑는다고 했을 때 9 9 가 반드시 들어가야 한다.
어? 그런데 2 4 4 에서 1개씩만 뽑는다면 4는 1개밖에 안나오는데... 4로 케이스가 2개 나오는게 아니라...
아, 케이스가 unique 해야지 원소가 unique 한지는 상관이 없구나. 실제로 9 9가 여러번 나온건 아니니 말 되네. 기준은 unique 한 케이스의 경우 전부 나열하는 것이다.
그렇다면, 케이스를 set에 넣고 일일이 find 여부를 따지는 게 맞지 않을까. find 되면 거르고, find 안되면 해당 케이스를 넣는다.

재귀로 풀 수 있으려나. 일단 naive 한 것으로는 set 과 find 를 사용하는 것이 먼저 떠오르긴 한다.

아, 재귀로 푼다면
그냥 일반적으로 풀되,
이전 출력값과 현재 출력값이 같다면 거르는 식으로 진행 가능한 부분 아닌가?
이전 출력값은 어디에 따로 저장해놓을 필요도 없고, 나름 킹리적이군.

현재 벡터와 아까의 벡터(==mystack) 를 비교하는데 == 연산자를 사용한다면, 제1기준=양벡터의 size, 제2기준: 각각의 원소
또한, 벡터에서 = 연산자가 대입이 가능한가? 가능하다면, 깊은복사로 가능한가 아니면 포인터 주소만 얕은복사하는가? >>> 깊은복사다. copies all the element from x into the container 라고 레퍼에 되어있다.

반례: 1 1 2 2
아, 안되겠다. 일단 set 써서 풀기로 하자.
*/

void Permutation3(int depth) {
	if (depth == M) {
		if (mukashi.find(mystack) != mukashi.end())
			return;
		mukashi.insert(mystack);
		for (int tmp : mystack)
			cout << tmp << ' ';
		cout << endl;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (visited[i])
			continue;
		visited[i] = true;
		mystack.push_back(kouhou[i]);
		Permutation3(depth + 1);
		mystack.pop_back();
		visited[i] = false;
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		kouhou.push_back(tmp);
	}
	sort(kouhou.begin(), kouhou.end());

	Permutation3(0);


	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << duration << " sec" << endl;
	return 0;
}

/*후기
input은 중복가능이지만 output은 중복불가라 일단 난 set을 바로 써서 풀었는데
사실 한 번에 고정된 수가 아닌 M개의 수를 뽑을 수 있기에 set 에 넣어 일일이 중복검사를 하는 것은 비효율적일 것이다.

2번풀이를 보면, 재귀되는 자함수마다 for문 당 같은 value 는 유일하게 호출되게끔 하면 굳이 set을 쓰지 않고도 중복output을 막을 수 있다.
*/