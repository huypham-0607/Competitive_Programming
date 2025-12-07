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
const int N = 5e5+10;
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
int a[N],dp[N];

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    dp[0] = 0;
    for (int i=1; i<=n; i++){
        dp[i] = INF;
        if (i-1>=0) dp[i] = min(dp[i],dp[i-1]+a[i]);
        if (i-2>=0) dp[i] = min(dp[i],dp[i-2]+a[i]);
        if (i-3>=0) dp[i] = min(dp[i],dp[i-3]+a[i]);
    }
    cout << min({dp[n],dp[n-1],dp[n-2]});
}

/*Driver Code*/
signed main(){
    freopen("XOASO.INP","r",stdin);
    freopen("XOASO.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
