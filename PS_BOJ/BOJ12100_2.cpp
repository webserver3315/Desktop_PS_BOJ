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

/*�� ���� �̵����� ������ ����� �� ������ �� ����!*/
void goup() {/*������ ������� ���ƴٳ���ϴ� ������, u d r l �Լ� ���ÿ� ������ ����, u �Լ� �ϳ��� ��ü���ɷ� �ȹٷ� ������ ���ٸ� ����! ���ÿ� �����ϴٰ� ���ۺ�� �� �׻�������� �ʹ� Ŀ����*/
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
			//�������: rr==0�̰ų� field[rr-1][cc]�� ���ڰ� ��������
			if (rr > 0 && field[rr - 1][cc] == field[r][c] && !isSummed[rr - 1][cc]) {
				field[rr - 1][cc] *= 2;
				isSummed[rr - 1][cc] = true;
				field[r][c] = 0;
			}
			else {
				int tmp = field[r][c];//�������� �ʾ��� ��츦 ���� ���� tmp�� �״�.
				field[r][c] = 0;
				field[rr][cc] = tmp;
			}
			/*printfield();
			cout << endl;*/
		}
	}
}


/*�� ���� �̵����� ������ ����� �� ������ �� ����!*/
void goleft() {/*������ ������� ���ƴٳ���ϴ� ������, u d r l �Լ� ���ÿ� ������ ����, u �Լ� �ϳ��� ��ü���ɷ� �ȹٷ� ������ ���ٸ� ����! ���ÿ� �����ϴٰ� ���ۺ�� �� �׻�������� �ʹ� Ŀ����*/
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
			//�������: rr==0�̰ų� field[rr-1][cc]�� ���ڰ� ��������
			if (cc > 0 && field[rr][cc-1] == field[r][c] && !isSummed[rr][cc-1]) {
				field[rr][cc-1] *= 2;
				isSummed[rr][cc-1] = true;
				field[r][c] = 0;
			}
			else {
				int tmp = field[r][c];//�������� �ʾ��� ��츦 ���� ���� tmp�� �״�.
				field[r][c] = 0;
				field[rr][cc] = tmp;
			}
			/*printfield();
			cout << endl;*/
		}
	}
}


/*�� ���� �̵����� ������ ����� �� ������ �� ����!*/
void godown() {/*������ ������� ���ƴٳ���ϴ� ������, u d r l �Լ� ���ÿ� ������ ����, u �Լ� �ϳ��� ��ü���ɷ� �ȹٷ� ������ ���ٸ� ����! ���ÿ� �����ϴٰ� ���ۺ�� �� �׻�������� �ʹ� Ŀ����*/
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
			//�������: rr==0�̰ų� field[rr-1][cc]�� ���ڰ� ��������
			if (rr <N-1 && field[rr + 1][cc] == field[r][c] && !isSummed[rr + 1][cc]) {
				field[rr + 1][cc] *= 2;
				isSummed[rr + 1][cc] = true;
				field[r][c] = 0;
			}
			else {
				int tmp = field[r][c];//�������� �ʾ��� ��츦 ���� ���� tmp�� �״�.
				field[r][c] = 0;
				field[rr][cc] = tmp;
			}
			/*printfield();
			cout << endl;*/
		}
	}
}


/*�� ���� �̵����� ������ ����� �� ������ �� ����!*/
void goright() {/*������ ������� ���ƴٳ���ϴ� ������, u d r l �Լ� ���ÿ� ������ ����, u �Լ� �ϳ��� ��ü���ɷ� �ȹٷ� ������ ���ٸ� ����! ���ÿ� �����ϴٰ� ���ۺ�� �� �׻�������� �ʹ� Ŀ����*/
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
			//�������: rr==0�̰ų� field[rr-1][cc]�� ���ڰ� ��������
			if (cc < N-1 && field[rr][cc+1] == field[r][c] && !isSummed[rr][cc+1]) {
				field[rr][cc + 1] *= 2;
				isSummed[rr][cc + 1] = true;
				field[r][c] = 0;
			}
			else {
				int tmp = field[r][c];//�������� �ʾ��� ��츦 ���� ���� tmp�� �״�.
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

	int tmpField[MAX][MAX];//����� call by value �����ؼ� ���ڷ� �ް� �ݽ����Լ����� ���������Ϸ��� ���� ����, �׳� �����ϰ� local ������ tmp ���ù迭 ���� ����� ���� �ʱ�ȭ����.
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