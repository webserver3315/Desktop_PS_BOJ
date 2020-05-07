/*
2048
*/

#include <iostream>
#define endl '\n'
#define MAX 21
using namespace std;


int N;
int field[MAX][MAX];
int maxval;

void printfield() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cout << field[r][c] << ' ';
		}
		cout << endl;
	}
}

/*한 번의 이동에서 합쳐진 블록은 또 합쳐질 수 없다!*/
void goup() {/*앞으로 사방으로 돌아다녀야하는 문제는, u d r l 함수 동시에 만들지 말고, u 함수 하나라도 자체테케로 똑바로 조지고 복붙만 하자! 동시에 제작하다간 제작비용 및 항상성유지비용 너무 커진다*/
	bool isSummed[MAX][MAX];
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			isSummed[r][c] = false;
		}
	}

	for (int c = 0; c < N; c++) {
		for (int r = 1; r < N; r++) {
			if (!field[r][c])
				continue;
			int rr = r; int cc = c;
			while (rr > 0 && !field[rr - 1][cc])
				rr--;
			//멈춘시점: rr==0이거나 field[rr-1][cc]에 숫자가 차있을때
			if (rr > 0 && field[rr - 1][cc] == field[r][c] && !isSummed[rr - 1][cc]) {
				field[rr - 1][cc] *= 2;
				isSummed[rr - 1][cc] = true;
				field[r][c] = 0;
			}
			else {
				int tmp = field[r][c];//움직이지 않았을 경우를 위해 따로 tmp를 뒀다.
				field[r][c] = 0;
				field[rr][cc] = tmp;
			}
			/*printfield();
			cout << endl;*/
		}
	}
}


/*한 번의 이동에서 합쳐진 블록은 또 합쳐질 수 없다!*/
void goleft() {/*앞으로 사방으로 돌아다녀야하는 문제는, u d r l 함수 동시에 만들지 말고, u 함수 하나라도 자체테케로 똑바로 조지고 복붙만 하자! 동시에 제작하다간 제작비용 및 항상성유지비용 너무 커진다*/
	bool isSummed[MAX][MAX];
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			isSummed[r][c] = false;
		}
	}

	for (int r = 0; r < N; r++) {
		for (int c = 1; c < N; c++) {
			if (!field[r][c])
				continue;
			int rr = r; int cc = c;
			while (cc > 0 && !field[rr][cc - 1])
				cc--;
			//멈춘시점: rr==0이거나 field[rr-1][cc]에 숫자가 차있을때
			if (cc > 0 && field[rr][cc-1] == field[r][c] && !isSummed[rr][cc-1]) {
				field[rr][cc-1] *= 2;
				isSummed[rr][cc-1] = true;
				field[r][c] = 0;
			}
			else {
				int tmp = field[r][c];//움직이지 않았을 경우를 위해 따로 tmp를 뒀다.
				field[r][c] = 0;
				field[rr][cc] = tmp;
			}
			/*printfield();
			cout << endl;*/
		}
	}
}


/*한 번의 이동에서 합쳐진 블록은 또 합쳐질 수 없다!*/
void godown() {/*앞으로 사방으로 돌아다녀야하는 문제는, u d r l 함수 동시에 만들지 말고, u 함수 하나라도 자체테케로 똑바로 조지고 복붙만 하자! 동시에 제작하다간 제작비용 및 항상성유지비용 너무 커진다*/
	bool isSummed[MAX][MAX];
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			isSummed[r][c] = false;
		}
	}

	for (int c = 0; c < N; c++) {
		for (int r = N-2; r >=0; r--) {
			if (!field[r][c])
				continue;
			int rr = r; int cc = c;
			while (rr < N-1 && !field[rr + 1][cc])
				rr++;
			//멈춘시점: rr==0이거나 field[rr-1][cc]에 숫자가 차있을때
			if (rr <N-1 && field[rr + 1][cc] == field[r][c] && !isSummed[rr + 1][cc]) {
				field[rr + 1][cc] *= 2;
				isSummed[rr + 1][cc] = true;
				field[r][c] = 0;
			}
			else {
				int tmp = field[r][c];//움직이지 않았을 경우를 위해 따로 tmp를 뒀다.
				field[r][c] = 0;
				field[rr][cc] = tmp;
			}
			/*printfield();
			cout << endl;*/
		}
	}
}


/*한 번의 이동에서 합쳐진 블록은 또 합쳐질 수 없다!*/
void goright() {/*앞으로 사방으로 돌아다녀야하는 문제는, u d r l 함수 동시에 만들지 말고, u 함수 하나라도 자체테케로 똑바로 조지고 복붙만 하자! 동시에 제작하다간 제작비용 및 항상성유지비용 너무 커진다*/
	bool isSummed[MAX][MAX];
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			isSummed[r][c] = false;
		}
	}

	for (int r = 0; r < N; r++) {
		for (int c = N-2; c >=0; c--) {
			if (!field[r][c])
				continue;
			int rr = r; int cc = c;
			while (cc < N-1 && !field[rr][cc+1])
				cc++;
			//멈춘시점: rr==0이거나 field[rr-1][cc]에 숫자가 차있을때
			if (cc < N-1 && field[rr][cc+1] == field[r][c] && !isSummed[rr][cc+1]) {
				field[rr][cc + 1] *= 2;
				isSummed[rr][cc + 1] = true;
				field[r][c] = 0;
			}
			else {
				int tmp = field[r][c];//움직이지 않았을 경우를 위해 따로 tmp를 뒀다.
				field[r][c] = 0;
				field[rr][cc] = tmp;
			}
			/*printfield();
			cout << endl;*/
		}
	}
}

void wheretogo(int i) {
	if (i == 1) {
		goup();
	}
	else if (i == 2) {
		godown();
	}
	else if (i == 3) {
		goleft();
	}
	else if (i == 4) {
		goright();
	}
}

void DFS(int depth) {
	if (depth == 5) {
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				if (maxval < field[r][c])
					maxval = field[r][c];
			}
		}
		return;
	}

	int tmpField[MAX][MAX];//힘들게 call by value 응용해서 인자로 받고 콜스택함수별로 변수유지하려고 하지 말고, 그냥 정직하게 local 변수로 tmp 로컬배열 직접 만들고 직접 초기화하자.
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			tmpField[r][c] = field[r][c];
		}
	}

	for (int i = 1; i < 5; i++) {
		wheretogo(i);
		DFS(depth + 1);
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				field[r][c] = tmpField[r][c];
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> field[r][c];
		}
	}

	//goup();
	//goleft();
	//godown();
	//goright();
	//printfield();

	DFS(0);

	cout << maxval << endl;


	return 0;
}