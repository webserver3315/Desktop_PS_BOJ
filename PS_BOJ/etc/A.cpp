/*
	2048 게임
*/

#include <iostream>
#include <cstdio>
using namespace std;

int Jijyo_kazu[12];/*2의 0승부터 11승까지 갯수를 유지*/
int q, n

int my_sqrt(int input) {
	switch (input) {
	case 1:
		return 0;
	case 2:
		return 1;
	case 4:
		return 2;
	case 8:
		return 3;
	case 16:
		return 4;
	case 32:
		return 5;
	case 64:
		return 6;
	case 128:
		return 7;
	case 256:
		return 8;
	case 512:
		return 9;
	case 1024:
		return 10;
	case 2048:
		return 11;
	}
	return -1;
}

int main() {
	cin >> q;
	while (q--) {/* --q해도 되려나? */
		scanf("%d", &n);
		while (n--) {
			int tmp;
			scanf("%d", &tmp);
			++Jijyo_kazu[my_sqrt(tmp)];
		}
		int now = 0;
		for (int i = 11; i >= 0; i--) {
			while()
		}
	}
}