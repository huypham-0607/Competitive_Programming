/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
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
int n,m,k;

/*Solution*/
void solve(){
    cin >> n >> m >> k;
    string s;
    cin >> s;
    int cnt = 0;
    int barrier = 0;
    int ans = 0;
    for (int i=0; i<n; i++){
        if (i<barrier) continue;
        if (s[i] == '0') ++cnt;
        else cnt = 0;
        if (cnt == m){
            ++ans;
            cnt = 0;
            barrier = i+k;
        }
    }
    cout << ans << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
