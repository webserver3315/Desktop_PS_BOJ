#include <iostream>
#include <algorithm>

using namespace std;

/*
작은수로 1을 겟하면 내가 이긴다.
상대방이 머리가 있다면 작은 수로 1을 주려고 하지는 않을 것이다.
즉, 1을 줄 수 밖에 없게끔 강제해야하는데,
그러기 위해서는 내가 1차이가 나는 두 수를 만들어내면 된다.
즉, 1차이가 나는 두 수를 만드는 순간 내 승리다.

*/

int a, b;

bool CanWin() {
	int bigger = a > b ? a : b;
	int smaller = a < b ? a : b;//a==b일 상황은 애초에 없다. 그랬으면 상대방이 진작에 끝냈겠지.
	
}

int main() {
	while (1) {
		cin >> a >> b;
		if (a == 0 && b == 0)
			break;
	}
	
}