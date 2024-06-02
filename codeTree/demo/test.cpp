#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
#define mp(a,b) make_pair(a,b)
#define endl '\n'
#define MAX 101
#define int long long
using namespace std;

signed main(){   
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
    vector<string> msg {
        "Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"
    };    
    for (const string& word : msg)   {
        cout << word << " ";   
    }   
    cout << endl;
}
