#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
#define mp(a,b) make_pair(a,b)
#define endl '\n'
#define MAX 101

#define DEBUG 1
#ifdef DEBUG
#define debug(x)  ((void)0)
#else
#define debug(x)  std::cout << "[Debug] " << #x << " is " << x << '\n'
#endif

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
vector<pii> golem_Initial_Info; // Column & ExitDirection
int Score = 0;
#define EAST 0
#define WEST 1
#define SOUTH 2
#define NORTH 3
int matrix[100][100]; // starts from 0th row -> -3th row in Figure
int dr[4] = { 0, 0, 1, -1}; // east west south north
int dc[4] = { 1, -1, 0, 0 };

pii currentLocation;
int currentExitDirection;
int currentGolemIndex;

/**
 * 이거 재귀로도 풀수있어보이는데, 다음에 생각해보자.
*/
// bool recursive_golem(int currR, int currC, int currentGolemIndex, int currentExitDirection){
//     if(isSouthAble()){
//         return recursive_golem(currR+1, currC, currentGolemIndex, currentExitDirection);
//     }else if(isWestAble()){
//         auto result = recursive_golem(currR, currC-1, currentGolemIndex, )
//         if(isSouthAble()){
//         }
//     }else if(isEastAble()){
//         if(isSouthAble()){
//         }
//     }else{
//         return mp(mp(currR, currC), mp(currentGolemIndex, currentExitDirection));
//     }
// }

int Clockwise(int direction){
    if(direction == EAST){
        return SOUTH;
    }else if(direction == WEST){
        return NORTH;
    }else if(direction == SOUTH){
        return WEST;
    }else if(direction == NORTH){
        return EAST;
    }else{
        return -1;
    }
}

int CounterClockwise(int direction){
    if(direction == EAST){
        return NORTH;
    }else if(direction == WEST){
        return SOUTH;
    }else if(direction == SOUTH){
        return EAST;
    }else if(direction == NORTH){
        return WEST;
    }else{
        return -1;
    }
}

bool isInBound(int r, int c){
    if(r>=0 && r<(R+3) && c>=0 && c<C){
        return true;
    }
    return false;
}

bool isSouthAble(pii targetLocation){
    int r = targetLocation.ff;
    int c = targetLocation.ss;
    int rr = r + dr[SOUTH];
    int cc = c + dc[SOUTH];
    if(!isInBound(rr + dr[SOUTH],cc + dc[SOUTH])) return false;
    if(!isInBound(rr + dr[WEST], cc + dc[WEST])) return false;
    if(!isInBound(rr + dr[EAST], cc + dc[EAST])) return false;
    if(
        matrix[rr + dr[SOUTH]][cc + dc[SOUTH]] == 0 &&
        matrix[rr + dr[WEST]][cc + dc[WEST]] == 0 &&
        matrix[rr + dr[EAST]][cc + dc[EAST]] == 0
    ) return true;
    else return false;
}

bool gotoSouth(){
    int r = currentLocation.ff;
    int c = currentLocation.ss;
    int rr = r + dr[SOUTH];
    int cc = c + dc[SOUTH];
    if(isSouthAble(currentLocation)){
        // release before location
        matrix[r + dr[WEST]][c + dc[WEST]] = 0;
        matrix[r + dr[EAST]][c + dc[EAST]] = 0;
        matrix[r + dr[NORTH]][c + dc[NORTH]] = 0;

        // allocate current location
        matrix[rr][cc] = currentGolemIndex;
        matrix[rr + dr[EAST]][cc + dc[EAST]] = currentGolemIndex;
        matrix[rr + dr[WEST]][cc + dc[WEST]] = currentGolemIndex;
        matrix[rr + dr[SOUTH]][cc + dc[SOUTH]] = currentGolemIndex;
        matrix[rr + dr[NORTH]][cc + dc[NORTH]] = currentGolemIndex;
        currentLocation.ff = rr;
        currentLocation.ss = cc;

        // allocate Exit
        matrix[rr + dr[currentExitDirection]][cc + dc[currentExitDirection]] = -1 * currentGolemIndex;
        return true;
    }
    else 
        return false;
}

bool isWestAble(pii targetLocation){
    int r = targetLocation.ff;
    int c = targetLocation.ss;
    int rr = r + dr[WEST];
    int cc = c + dc[WEST];
    if(!isInBound(rr + dr[SOUTH],cc + dc[SOUTH])) return false;
    if(!isInBound(rr + dr[WEST], cc + dc[WEST])) return false;
    if(!isInBound(rr + dr[NORTH], cc + dc[NORTH])) return false;
    if(
        matrix[rr + dr[SOUTH]][cc + dc[SOUTH]] == 0 &&
        matrix[rr + dr[WEST]][cc + dc[WEST]] == 0 &&
        matrix[rr + dr[NORTH]][cc + dc[NORTH]] == 0
    ) return true;
    else return false;
}

bool gotoWest(){
    int r = currentLocation.ff;
    int c = currentLocation.ss;

    int rr = r + dr[WEST];
    int cc = c + dc[WEST];
    if(isWestAble(currentLocation)){
        currentExitDirection = CounterClockwise(currentExitDirection);

        // release before location
        matrix[r + dr[NORTH]][c + dc[NORTH]] = 0;
        matrix[r + dr[EAST]][c + dc[EAST]] = 0;
        matrix[r + dr[SOUTH]][c + dc[SOUTH]] = 0;

        // allocate current location
        matrix[rr][cc] = currentGolemIndex;
        matrix[rr + dr[EAST]][cc + dc[EAST]] = currentGolemIndex;
        matrix[rr + dr[WEST]][cc + dc[WEST]] = currentGolemIndex;
        matrix[rr + dr[SOUTH]][cc + dc[SOUTH]] = currentGolemIndex;
        matrix[rr + dr[NORTH]][cc + dc[NORTH]] = currentGolemIndex;
        currentLocation.ff = rr;
        currentLocation.ss = cc;

        // allocate Exit
        matrix[rr + dr[currentExitDirection]][cc + dc[currentExitDirection]] = -1 * currentGolemIndex;
        return true;
    }
    else 
        return false;
}

bool isEastAble(pii targetLocation){
    int r = targetLocation.ff;
    int c = targetLocation.ss;
    int rr = r + dr[EAST];
    int cc = c + dc[EAST];
    if(!isInBound(rr + dr[SOUTH],cc + dc[SOUTH])) return false;
    if(!isInBound(rr + dr[EAST], cc + dc[EAST])) return false;
    if(!isInBound(rr + dr[NORTH], cc + dc[NORTH])) return false;
    if(
        matrix[rr + dr[SOUTH]][cc + dc[SOUTH]] == 0 &&
        matrix[rr + dr[EAST]][cc + dc[EAST]] == 0 &&
        matrix[rr + dr[NORTH]][cc + dc[NORTH]] == 0
    ){
        return true;
    }
    return false;
}
bool gotoEast(){
    int r = currentLocation.ff;
    int c = currentLocation.ss;
    int rr = r + dr[EAST];
    int cc = c + dc[EAST];
    if(isEastAble(currentLocation)){
        currentExitDirection = Clockwise(currentExitDirection);

        // release before location
        matrix[r + dr[NORTH]][c + dc[NORTH]] = 0;
        matrix[r + dr[WEST]][c + dc[WEST]] = 0;
        matrix[r + dr[SOUTH]][c + dc[SOUTH]] = 0;

        // allocate current location
        matrix[rr][cc] = currentGolemIndex;
        matrix[rr + dr[EAST]][cc + dc[EAST]] = currentGolemIndex;
        matrix[rr + dr[WEST]][cc + dc[WEST]] = currentGolemIndex;
        matrix[rr + dr[SOUTH]][cc + dc[SOUTH]] = currentGolemIndex;
        matrix[rr + dr[NORTH]][cc + dc[NORTH]] = currentGolemIndex;
        currentLocation.ff = rr;
        currentLocation.ss = cc;

        // allocate Exit
        matrix[rr + dr[currentExitDirection]][cc + dc[currentExitDirection]] = -1 * currentGolemIndex;
        return true;
    }
    else 
        return false;
}

bool firstTry(){
    if(isSouthAble(currentLocation)){
        gotoSouth();
        return true;
    }
    else 
        return false;
}

bool secondTry(){
    if(isWestAble(currentLocation) && isSouthAble(mp(currentLocation.ff + dr[WEST], currentLocation.ss + dc[WEST]))){
        gotoWest();
        gotoSouth();
        return true;
    }
    else
        return false;
}

bool thirdTry(){
    if(isEastAble(currentLocation) && isSouthAble(mp(currentLocation.ff + dr[EAST], currentLocation.ss + dc[EAST]))){
        gotoEast();
        gotoSouth();
        return true;
    }
    else
        return false;
}

bool enterFailed(){
    int r = currentLocation.ff;
    int c = currentLocation.ss;
    int rr = r + dr[NORTH];
    int cc = c + dc[NORTH];
    if(rr < 3) return true;
    else return false;
}

int getScore(){
    int maximumRow = 0;
    set<int> ableGolems; // 이동가능한 골렘 인덱스 종류
    ableGolems.insert(currentGolemIndex);
    int er = currentLocation.ff + dr[currentExitDirection]; // exit location
    int ec = currentLocation.ss + dc[currentExitDirection]; // exit location
    while(1){
        for(int i=0; i<4; i++){ // TODO: 알고리즘 채워넣을것. 지금은 부족함.
            int err = er + dr[i];
            int ecc = ec + dc[i];
            int newGolem = matrix[err][ecc]>0 ? matrix[err][ecc] : -1 * matrix[err][ecc];
            if(newGolem == 0) continue;
            else ableGolems.insert(newGolem);
        }
    }
    for(auto ableGolem : ableGolems){
        for(int r=3; r<100; r++){
            for(int c=0; c<100; c++){
                if(maximumRow > r || matrix[r][c] == ableGolem || (-1 * matrix[r][c]) == ableGolem){
                    maximumRow = r;
                }
            }
        }
    }
    return maximumRow-2;
}

void cleanAll(){
    for(int r=0; r<100; r++){
        for(int c=0;c<100;c++){
            matrix[r][c] = 0;
        }
    }
}

int startSim(int startColumn, int startExitDirection){
    currentLocation         = mp(1, startColumn);
    currentExitDirection    = startExitDirection;
    while(1){
        if(firstTry()){
            continue;
        }
        else if(secondTry()){
            continue;
        }
        else if(thirdTry()){
            continue;
        }
        else{
            if(enterFailed()){
                cleanAll();
            }else{
                Score += getScore();
            }
            break;
        }
    }
}

int dropGolem(int targetGolemIndex){
    int startColumn         = golem_Initial_Info[targetGolemIndex].ff;
    int startExitDirection  = golem_Initial_Info[targetGolemIndex].ss;
    currentGolemIndex = targetGolemIndex;
    startSim(startColumn, startExitDirection);
    
    return 0;
}

int printMatrix(){
    for(int r=0; r<73; r++){
        for(int c=0;c<73;c++){
            cout<<matrix[r][c]<<"\t";
        }
        cout<<endl;
    }
}

signed main(){   
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
    cin >> R >> C >> K;
    golem_Initial_Info.push_back(mp(-1, -1)); // invalid
    for(int golemIndex=1; golemIndex <= K; golemIndex++){
        int c, d;
        cin >> c >> d;
        c -= 1;
        if(d == 0){
            d = NORTH;
        }else if(d == 1){
            d = EAST;
        }else if(d == 2){
            d = SOUTH;
        }else if(d == 3){
            d = WEST;
        }
        golem_Initial_Info.push_back(mp(c, d));
        dropGolem(golemIndex);
        #ifdef DEBUG
        cout<<Score<<endl;
        // printMatrix();
        #endif
    }
    cout << Score << endl;
}
