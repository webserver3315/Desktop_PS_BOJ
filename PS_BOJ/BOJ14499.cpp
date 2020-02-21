/*
주사위 굴리기
*/

#include <iostream>
#define endl '\n'
#define MAX 21
using namespace std;

class dice {
	int side[6] = { 0,0,0,0,0,0 };//3을 더하거나 빼면 맞은 편의 수가 나온다.
	int bottom = 0;//바닥면 인덱스
	int east = 2;//동쪽면 인덱스
	void goeast() {
		if (bottom == 0) {
			if (east == 1) {
				bottom = east;
				east = bottom + 3;
			}
			else if (east == 2) {
				bottom = east;
				east = bottom + 3;
			}
			else if (east == 4) {
				bottom = east;
				east = bottom + 3;
			}
			else if (east == 5) {
				bottom = east;
				east = bottom + 3;
			}
		}
		else if (bottom == 1) {
			if (east == 0) {
				bottom = east;
				east = bottom + 3;
			}
			else if (east == 2) {
				bottom = east;
				east = bottom + 3;
			}
			else if (east == 3) {
				bottom = east;
				east = bottom + 3;
			}
			else if (east == 5) {
				bottom = east;
				east = bottom + 3;
			}
		}
		else if (bottom == 2) {
			if (east == 0) {
				bottom = east;
				east = bottom + 3;
			}
			else if (east == 1) {
				bottom = east;
				east = bottom + 3;
			}
			else if (east == 3) {
				bottom = east;
				east = bottom + 3;
			}
			else if (east == 4) {
				bottom = east;
				east = bottom + 3;
			}
		}
		else if (bottom == 3) {
			if (east == 1) {
				bottom = east;
				east = bottom - 3;
			}
			else if (east == 2) {
				bottom = east;
				east = bottom - 3;
			}
			else if (east == 4) {
				bottom = east;
				east = bottom - 3;
			}
			else if (east == 5) {
				bottom = east;
				east = bottom - 3;
			}
		}
		else if (bottom == 4) {
			if (east == 0) {
				bottom = east;
				east = bottom - 3;
			}
			else if (east == 2) {
				bottom = east;
				east = bottom - 3;
			}
			else if (east == 3) {
				bottom = east;
				east = bottom - 3;
			}
			else if (east == 5) {
				bottom = east;
				east = bottom - 3;
			}
		}
		else if (bottom == 5) {
			if (east == 0) {
				bottom = east;
				east = bottom - 3;
			}
			else if (east == 1) {
				bottom = east;
				east = bottom - 3;
			}
			else if (east == 3) {
				bottom = east;
				east = bottom - 3;
			}
			else if (east == 4) {
				bottom = east;
				east = bottom - 3;
			}
		}
	}
	void gosouth() {
		if (bottom == 0) {
			if (east == 1) {
				bottom = 5;
				east = bottom + 3;
			}
			else if (east == 2) {
				bottom = 1;
				east = bottom + 3;
			}
			else if (east == 4) {
				bottom = east;
				east = bottom + 3;
			}
			else if (east == 5) {
				bottom = east;
				east = bottom + 3;
			}
		}
		else if (bottom == 1) {
			if (east == 0) {
				bottom = east;
				east = bottom + 3;
			}
			else if (east == 2) {
				bottom = east;
				east = bottom + 3;
			}
			else if (east == 3) {
				bottom = east;
				east = bottom + 3;
			}
			else if (east == 5) {
				bottom = east;
				east = bottom + 3;
			}
		}
		else if (bottom == 2) {
			if (east == 0) {
				bottom = east;
				east = bottom + 3;
			}
			else if (east == 1) {
				bottom = east;
				east = bottom + 3;
			}
			else if (east == 3) {
				bottom = east;
				east = bottom + 3;
			}
			else if (east == 4) {
				bottom = east;
				east = bottom + 3;
			}
		}
		else if (bottom == 3) {
			if (east == 1) {
				bottom = east;
				east = bottom - 3;
			}
			else if (east == 2) {
				bottom = east;
				east = bottom - 3;
			}
			else if (east == 4) {
				bottom = east;
				east = bottom - 3;
			}
			else if (east == 5) {
				bottom = east;
				east = bottom - 3;
			}
		}
		else if (bottom == 4) {
			if (east == 0) {
				bottom = east;
				east = bottom - 3;
			}
			else if (east == 2) {
				bottom = east;
				east = bottom - 3;
			}
			else if (east == 3) {
				bottom = east;
				east = bottom - 3;
			}
			else if (east == 5) {
				bottom = east;
				east = bottom - 3;
			}
		}
		else if (bottom == 5) {
			if (east == 0) {
				bottom = east;
				east = bottom - 3;
			}
			else if (east == 1) {
				bottom = east;
				east = bottom - 3;
			}
			else if (east == 3) {
				bottom = east;
				east = bottom - 3;
			}
			else if (east == 4) {
				bottom = east;
				east = bottom - 3;
			}
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);



	return 0;
}