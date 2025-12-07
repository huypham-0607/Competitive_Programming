/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
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
int x;

/*Solution*/
void solve(){
    cin >> x;
    int cnt = 0;
    for (int i=1; i*i<=n; i++){
        if (x%(i*i)) continue;
        int k = x/(i*i);
        if (k<i) break;
        if (!(x%(i*i)) && (x%(i*i*i))) ++cnt;
    }
    cout << cnt;
}

/*Driver Code*/
signed main(){
//    freopen("SOHEDEM.inp","r",stdin);
//    freopen("SOHEDEM.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
