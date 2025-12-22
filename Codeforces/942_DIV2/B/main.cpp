/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n;

/*Solution*/
void solve(){
    cin >> n;
    string s;
    cin >> s;
    int upcnt = 0;
    for (int i=0; i<(int)s.size(); i++){
        if (s[i] == 'U') ++upcnt;
    }
    if (upcnt%2) cout << "YES" << endl;
    else cout << "NO" << endl;
}

/*Driver Code*/
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
