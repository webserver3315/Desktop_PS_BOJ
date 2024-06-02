#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
#define mp(a,b) make_pair(a,b)
#define endl '\n'
#define MAX 101
#define int long long
using namespace std;

/**
 * https://www.codetree.ai/training-field/frequent-problems/problems/magical-forest-exploration/description?page=1&pageSize=20&tier=1%2C15
*/


/**
 * 해결step
 * 1. 골렘 낙하 알고리즘 구현
 *      1. matrix의 기본값은 뭘로 할것인지 -> let 0x00
 *      2. 골렘의 기본값은 뭘로 할것인지 -> 1, 2, 3, ...
 *      3. 골렘의 탈출구는 뭘로 할것인지 -> -1, -2, -3, ...
 *      4. 골렘의 탈출구방향은 어떻게 유지할것인지 -> golemExit[NUM_OF_ANGELS] 로 유지
 * 2. 요정 탈출시 기대가능한 최대점수값 알고리즘 구현
 *      1. 현재 거쳐갈 수 있는 모든 골렘의 종류를 구하고
 *      2. 그 골렘의 min(Row) 값을 점수로써 출력
*/


int R, C, K;
vector<pii> golem_Initial_Location;
int Score = 0;

int dropGolem(int golemName){
    return 0;
}

signed main(){   
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
    cin >> R >> C >> K;
    for(int golemName=1; golemName <= K; golemName++){
        int r, c;
        cin >> r >> c;
        golem_Initial_Location.push_back()
    }

    vector<string> msg {
        "Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"
    };    
    for (const string& word : msg)   {
        cout << word << " ";   
    }   
    cout << endl;
}
