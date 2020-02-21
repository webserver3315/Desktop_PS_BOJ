/*
텀 프로젝트

1이 2를 지목하면 같은 그룹이 되고, 2가 3을 지목하고 3이 1을 지목하는 식으로, 사이클이 형성되면 그룹이 된다.
만일 자기자신을 선택하면 홀로 그룹이 된다
학생의 수는 10만 이하이다.
테스트케이스 또한 복수번 주어진다.
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
#include <cstring>
#include <ctime>
#include <climits>
using namespace std;
#define endl '\n'
//#define ff first
//#define ss second
//typedef std::pair <int, int> pii;
//#define mp(x,y) make_pair(x,y)
//P mypair = make_pair(1.2);//권장사항
//pair<int, int> mypair = make_pair(1, 2);//C++11 비지원시 이렇게
//P mypair = { 1,2 };//C++11 이후부터만 가능
//P mypair(1, 2);//생성자이용

/*어느 프로젝트 팀에도 속하지 않는 학생들의 수를 계산하는 프로그램을 작성하라

*/

int T, N;
int arr[100005];//-1이라면 이미 그룹에 들어간 학생이므로 조사할 필요가 없다는 뜻. 한 학생이 복수의 그룹에 가입하는 것은 불가능하다.
bool visited[100005];
int inssacnt;

void clearvisit() {
	memset(visited, false, N);
}

void printall() {
	cout << endl;
	cout << "arr" << endl;
	for (int i = 1; i <= N; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
	cout << "visited" << endl;;
	for (int i = 1; i <= N; i++) {
		cout << visited[i] << ' ';
	}
	cout << endl;
	cout << "inssacnt" << endl;
	cout << inssacnt << endl;
}

void IsCycle(int n) {/*만일 이미 그룹에 소속된 학생이면 함수 터트린다.
					최초선정된 학생을 시발점으로 지정한 후, 방문표시를 찍는다
					방문표시확인 후 최초학생이 가리키는 학생으로 가며 이를 넥스트라고 한다
					방문표시확인 후 넥스트가 가리키는 학생으로 가며 이를 넥스트라고 한다. 만일 넥스트가 -1을 가리킨다면 터트린다.
					방문표시확인 후 넥스트가 가리키는 학생으로 가며 이를 넥스트라고 한다. 만일 넥스트가 -1을 가리킨다면 터트린다.
					방문표시확인 후 넥스트가 가리키는 학생으로 가며 이를 넥스트라고 한다. 만일 넥스트가 -1을 가리킨다면 터트린다.
					...
					언젠가는 방문표시확인이 걸릴 것이다
					이 때, 넥스트로부터 순환이다.
					넥스트로부터 가능한 한 순환된 모든 학생이 가리키는 값을 -1 찍는다
					*/
	if (arr[n] == -1) {
		cout << n << "은 취급안한다" << endl;
		return;
	}
	//printall();
	int next = n;
	while (!visited[arr[next]]) {
		if (arr[next] == -1)
			return;
		visited[next] = true;
		cout << next << " 에서 얘가 가리키던 " << arr[next] << " 으로 이동" << endl;
		next = arr[next];
	}
	cout << next << " 에서 터짐" << endl;
	//어디에서 터졌든, 그것은 사이클이다.
	int next = n;
	while (visited[arr[next]]) {
		visited[next] = false;
		/*cout << next << " 에서 얘가 가리키던 " << arr[next] << " 으로 이동" << endl;*/
		next = arr[next];
		arr[next] = -1;
	}


	/*while (visited[arr[next]]) {
		visited[next] = false;
		if (arr[next] != -1) {
			inssacnt++;
			cout << next << "은 확실히 그룹에 속하므로 -1을 새긴다" << endl;
			arr[next] == -1;
		}
		next = arr[next];
	}*/
	
	clearvisit();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> arr[i];
		}
		for (int i = 1; i <= N; i++) {
			IsCycle(i);
		}
		cout << inssacnt << endl;
	}


	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << ctime_duration << " ms" << endl;
	return 0;
}