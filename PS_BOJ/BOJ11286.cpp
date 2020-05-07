/*
절댓값 힙
*/

#include <iostream>
#include <queue>
#include <cmath>
#define endl '\n'
using namespace std;

int N;

bool IsPriorThan(int a, int b) {
	if (abs(a) > abs(b))
		return true;
	else if (abs(a) < abs(b))
		return false;
	else
		if (a > b)
			return false;
		else
			return true;
}/*sort함수와 달리 이렇게 선언하면 안되나보다; 함수포인터가 아니라 별도의 struct 내부에 () 연산자오버로딩으로 해야할듯
그리고 추가적으로, sort의 경우 오름차순으로 하기 위해서는 return a<b; 하면 되는데 priority queue에서는 return a>b; 해주어야 함에 주의!
즉, 우선순위 큐에서는 좌항이 우선시되기 위해서는 해당 경우에서 true를 해줘야한다*/

struct cmp {//착각했다. 절댓값 다르면 절댓값 큰 것 우선, 절댓값 같으면 실제값 작은 것 우선으로 이해했는데 둘 다 작은 것 우선이었다.
	public:
		/*bool IsPriorThan(int a, int b) {
			if (abs(a) > abs(b))
				return true;
			else if (abs(a) < abs(b))
				return false;
			else
				if (a > b)
					return false;
				else
					return true;
		}*/
		bool operator() (const int& a, const int& b) {
			if (abs(a) > abs(b))
				return false;
			else if (abs(a) < abs(b))
				return true;
			else
				if (a < b)
					return false;
				else
					return true;
		}
};

struct mycmp2 {//착각했다. 절댓값 다르면 절댓값 큰 것 우선, 절댓값 같으면 실제값 작은 것 우선으로 이해했는데 둘 다 작은 것 우선이었다.
	//public://기본이 public이다. 구조체는. class가 private이고.
	/*bool IsPriorThan(int a, int b) {
		if (abs(a) > abs(b))
			return true;
		else if (abs(a) < abs(b))
			return false;
		else
			if (a > b)
				return false;
			else
				return true;
	}*/
	bool operator() (const int& a, const int& b) {
		if (abs(a) > abs(b))
			return true;
		else if (abs(a) < abs(b))
			return false;
		else
			if (a <= b)//등호 붙여보았다. 등호가 문제군. 등호를 붙여야만 한다.
				return false;
			else
				return true;
	}
};

struct cmp2 {
	bool operator()(const int& a, const int& b) {//priority_queue 종특을 유념해야한다. true가 출력되면 후자를, false가 출력되면 전자를 우선시한다. 그러니까 보통은 비교함수를 IsPriorThan으로 짜고 true false를 보는데, 우선순위큐는 IsMinorThan 으로 취급해야한다.
		if (abs(a) == abs(b))//절댓값같으면 작은게 우선이다. 그런데 priority_queue 비교함수 종특상 반대로 뱉어야한다.
			return a > b;
		return abs(a) > abs(b);//즉 스왑하는 기준이 true일때다. 불필요한 swap을 하지 않기 위해서는, 동일할 때 false를 반환하도록 해야하므로 등호는 필요없다. 오히려 등호붙이면 오류뜬다.
	}
};


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<int, vector<int>, mycmp2> pq;

	cin >> N;
	while (N--) {
		int tmp;
		cin >> tmp;
		if (tmp == 0) {
			if (pq.empty())
				cout << 0 << endl;
			else {
				cout << pq.top() << endl;
				pq.pop();
			}
		}
		else {
			pq.push(tmp);
		}
	}

	return 0;
}