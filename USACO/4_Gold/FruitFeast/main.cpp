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
int t,a,b;
bool dp1[5000010],dp2[5000010];

/*Solution*/
void solve(){
    cin >> t >> a >> b;
    dp1[0] = 1;
    dp2[0] = 1;
    for (int i=1; i<=t; i++){
        if (i-a>=0) dp1[i] = (dp1[i]||dp1[i-a]);
        if (i-b>=0) dp1[i] = (dp1[i]||dp1[i-b]);
        dp2[i/2] = (dp2[i/2]||dp1[i]);
    }
    int ans = 0;
    for (int i=1; i<=t; i++){
        if (i-a>=0) dp2[i] = (dp2[i]||dp2[i-a]);
        if (i-b>=0) dp2[i] = (dp2[i]||dp2[i-b]);
        if (dp2[i]) ans = i;
    }
    cout << ans;
}

/*Driver Code*/
signed main(){
    freopen("feast.in","r",stdin);
    freopen("feast.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
