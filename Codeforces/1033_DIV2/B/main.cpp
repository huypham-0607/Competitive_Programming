/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define int long long
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
int n,s;

/*Solution*/
void solve(){
    cin >> n >> s;
    int cnt = 0;
    for (int i=1; i<=n; i++){
        int dx,dy,x,y; cin >> dx >> dy >> x >> y;
        if (x-y == 0 && dx*dy > 0){
            ++cnt;
            continue;
        }
        if (x+y == s && dx*dy < 0){
            ++cnt;
            continue;
        }
    }
    cout << cnt << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
