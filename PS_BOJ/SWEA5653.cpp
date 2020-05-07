/*
줄기세포배양
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
	int power;//생명력
	int age;
	int time;
	bool IsActive = false; bool IsDead = false;
};

int T;
int N, M, K;
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };
pii field[MAX][MAX];//초기 r, c값에 +300시켜서 유지할 것. 언제(ff) 몇가중치(ss)의 세포에게 점령당했는지를 유지. visit 상위호환.
int nokori = 0;
int nowtime;
deque<saibou> dqs;

/*
BFS로 탐사시작.
살아있는 세포의 수 전수조사돌리지말고 현 인원현황을 cnt 전역변수로 지속유지할 것
*/


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M >> K;
		//memset(field, 0, sizeof(field));//잘 돌아가려나?
		for (int r = 0; r < MAX; r++) {//초기화
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
					std::cout << "최초고정: " << "rr :" << r - plus << " cc:" << c - plus << " pp:" << pow << " aa:" << 0 << " tt:" << 0 << endl;
					field[r][c].ff = 0; field[r][c].ss = pow;
					dqs.push_back(s);
				}
			}
		}

		while (nowtime < K) {
			saibou s = dqs.front();
			int rr = s.r; int cc = s.c; int pp = s.power; int aa = s.age; int tt = s.time; bool IA = s.IsActive; bool ID = s.IsDead;
			dqs.pop_front();
			std::cout << "지금: " << tt << " 뽑은 세포: " << "rr :" << rr - plus << " cc:" << cc - plus << " pp:" << pp << " aa:" << aa << " tt:" << tt << endl;
			if (ID)//뒤진 세포면 번식절대못하므로 거른다
				continue;
			else if (!IA) {//비활성화라면
				aa++;
				if (aa == pp) {//활성화 ㄱㄱ
					aa = 0;
					cout << tt + 1 << " 초에 " << rr - plus << " " << cc - plus << " 를 활성화시킵니다" << endl;
					IA = true;
				}
				//else
					//cout << "나이는 " << aa << " 인데 " << " 생명력은 " << pp << " 라서 아직 활성화 안됨" << endl;
				saibou ikinoktta = { rr,cc,pp,aa,tt + 1,IA,ID };
				dqs.push_back(ikinoktta);
			}
			else {//현 세포가 이미 활성화
				aa++;
				if (aa == 1) {//사실상 활성화 새내기때만 번식가능하다
					for (int i = 0; i < 4; i++) {
						int rrr = rr + dr[i]; int ccc = cc + dc[i];
						if (field[rrr][ccc].ff == -1 || (field[rrr][ccc].ff == tt + 1 && pp > field[rrr][ccc].ss)) {//가려는 곳이 미방문지이거나, 같은 시간에 점령당했는데 지금이 더 생명력 강한 세포임에 한해서 전진이 허용된다.
							cout << "[번짐] " << tt + 1 << " 초에 " << rr - plus << ' ' << cc - plus << " 와 인접한 "<< rrr - plus << " " << ccc - plus << " 로 번집니다" << endl;
							field[rrr][ccc].ff = tt + 1; field[rrr][ccc].ss = pp;
							saibou new_s = { rrr,ccc,pp,0,tt + 1,false,false };
							dqs.push_back(new_s);
							if (tt + 1 > nowtime)
								nowtime = tt + 1;
						}
					}
				}

				if (aa == pp) {//이제 뒤짐
					//cout << rr << " " << cc << " 를 완전히 죽입니다" << endl;
					ID = true;
				}
				else {//안죽었으면 틀딱세포도 큐에 다시 집어넣자
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