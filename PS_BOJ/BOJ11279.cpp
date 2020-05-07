/*
최대 힙
*/

#include <iostream>
//#include <deque>
#include <queue>
#define endl '\n'
using namespace std;

/*
C에서는 힙 자료구조를 직접 구현했다면,
C++에서는 힙의 구현체인 우선순위큐를 stl에서 지원한다.
우선순위 큐를 쓰자.
*/

/*
stl의 priority queue는 queue 헤더에 있다.(왜 하필 deque가 아니라 queue에; 설마 인덱스로 참조 안되고 clear함수 없고 그렇진않겠지?
없네; 오로지 insert, pop, top, empty, size 뿐이다. 당연한건가싶긴하지만 심지어 front, back도 없다.
front가 아니라 top이라는 점은 유념할만하다.
그야 뭐 애초에 우선순위큐는 이름만 큐이고 내부는 이진트리이니까;

선언은 priority_queue<int, vector<int>, compare<int> > 로 한다.

인자 순서대로 자료형, 구현체, 비교연산자인데
자료형은 말그대로 정수, 실수, 클래스 등이 가능하고
구현체는 default 값은 vector<자료형> 으로 되어있다. 값의 저장방식을 결정한다
비교함수는 말그대로 비교에 사용할 함수를 적는다.
비교함수의 기본값은 less로 루트부터 내림차순이라는 뜻, 즉 최대힙이고(보통 우선순위큐에서 우선순위가 높다는 것은 우선순위값이 크다는걸 의미하니) greater를 쓰면 루트부터 오름차순이라는 뜻이므로 최소힙이다.

예를 들어 priority_queue<int, vector<int>, greater<int>> pq;
이렇게 선언하면 완벽하다.
만일 자료형이 pair라면 늘 그렇듯 첫 인자부터 검색때리고 동일하면 두 번째 인자를 검사한다.
insert, pop에 소요되는 시간은 logN이다.
*/

int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<int, vector<int>, less<int>> pq;

	cin >> N;

	while (N--) {
		int tmp;
		cin >> tmp;
		if (tmp == 0)
			if (pq.empty())
				cout << 0 << endl;
			else {
				cout << pq.top() << endl;
				pq.pop();
			}
		else
			pq.push(tmp);

	}

	return 0;
}