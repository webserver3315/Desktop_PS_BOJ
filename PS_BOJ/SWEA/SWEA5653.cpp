/*
�ٱ⼼�����
*/

#include <iostream>
#include <deque>
#include <utility>
#include <cstring>
#define endl '\n'
#define MAX (int)653
#define plus (int)300
#define ff first
#define ss second
#define mp(aa,b) make_pair(aa,b)
using namespace std;

typedef pair<int, int> pii;

struct saibou {
	int r; int c;
	int power;//�����
	int age;
	int time;
	bool IsActive = false; bool IsDead = false;
};

int T;
int N, M, K;
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };
pii field[MAX][MAX];//�ʱ� r, c���� +300���Ѽ� ������ ��. ����(ff) ���ġ(ss)�� �������� ���ɴ��ߴ����� ����. visit ����ȣȯ.
int nokori = 0;
int nowtime;
deque<saibou> dqs;

/*
BFS�� Ž�����.
����ִ� ������ �� �������絹�������� �� �ο���Ȳ�� cnt ���������� ���������� ��
*/


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M >> K;
		//memset(field, 0, sizeof(field));//�� ���ư�����?
		for (int r = 0; r < MAX; r++) {//�ʱ�ȭ
			for (int c = 0; c < MAX; c++) {
				field[r][c].ff = -1; field[r][c].ss = 0;
			}
		}
		dqs.clear();
		nokori = 0; nowtime = 0;

		for (int r = 1 + plus; r <= N + plus; r++) {
			for (int c = 1 + plus; c <= M + plus; c++) {
				int pow;
				cin >> pow;
				if (pow != 0) {
					nokori++;
					saibou s = { r,c,pow,0,0,false,false };
					std::cout << "���ʰ���: " << "rr :" << r - plus << " cc:" << c - plus << " pp:" << pow << " aa:" << 0 << " tt:" << 0 << endl;
					field[r][c].ff = 0; field[r][c].ss = pow;
					dqs.push_back(s);
				}
			}
		}

		while (nowtime < K) {
			saibou s = dqs.front();
			int rr = s.r; int cc = s.c; int pp = s.power; int aa = s.age; int tt = s.time; bool IA = s.IsActive; bool ID = s.IsDead;
			dqs.pop_front();
			std::cout << "����: " << tt << " ���� ����: " << "rr :" << rr - plus << " cc:" << cc - plus << " pp:" << pp << " aa:" << aa << " tt:" << tt << endl;
			if (ID)//���� ������ ����������ϹǷ� �Ÿ���
				continue;
			else if (!IA) {//��Ȱ��ȭ���
				aa++;
				if (aa == pp) {//Ȱ��ȭ ����
					aa = 0;
					cout << tt + 1 << " �ʿ� " << rr - plus << " " << cc - plus << " �� Ȱ��ȭ��ŵ�ϴ�" << endl;
					IA = true;
				}
				//else
					//cout << "���̴� " << aa << " �ε� " << " ������� " << pp << " �� ���� Ȱ��ȭ �ȵ�" << endl;
				saibou ikinoktta = { rr,cc,pp,aa,tt + 1,IA,ID };
				dqs.push_back(ikinoktta);
			}
			else {//�� ������ �̹� Ȱ��ȭ
				aa++;
				if (aa == 1) {//��ǻ� Ȱ��ȭ �����⶧�� ���İ����ϴ�
					for (int i = 0; i < 4; i++) {
						int rrr = rr + dr[i]; int ccc = cc + dc[i];
						if (field[rrr][ccc].ff == -1 || (field[rrr][ccc].ff == tt + 1 && pp > field[rrr][ccc].ss)) {//������ ���� �̹湮���̰ų�, ���� �ð��� ���ɴ��ߴµ� ������ �� ����� ���� �����ӿ� ���ؼ� ������ ���ȴ�.
							cout << "[����] " << tt + 1 << " �ʿ� " << rr - plus << ' ' << cc - plus << " �� ������ "<< rrr - plus << " " << ccc - plus << " �� �����ϴ�" << endl;
							field[rrr][ccc].ff = tt + 1; field[rrr][ccc].ss = pp;
							saibou new_s = { rrr,ccc,pp,0,tt + 1,false,false };
							dqs.push_back(new_s);
							if (tt + 1 > nowtime)
								nowtime = tt + 1;
						}
					}
				}

				if (aa == pp) {//���� ����
					//cout << rr << " " << cc << " �� ������ ���Դϴ�" << endl;
					ID = true;
				}
				else {//���׾����� Ʋ�������� ť�� �ٽ� �������
					saibou ikinoktta = { rr,cc,pp,aa,tt + 1,IA,ID };
					dqs.push_back(ikinoktta);
				}
			}
		}

		/*for (int r = 0; r < MAX; r++) {
			for (int c = 0; c < MAX; c++) {
				cout << field[r][c].ss << ' ';
			}
			cout << endl;
		}*/

		cout << "#" << t << ' ' << dqs.size() << endl;

	}

	return 0;
}