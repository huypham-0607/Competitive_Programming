/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "COMPATIB"

using namespace std;

/*Constants*/
const int N = 1e6+10;
const int INF = 1e9+7;
const int LG = 22;
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
int dp[(1<<LG)+10];
int a[N];

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n ; i++){
        cin >> a[i];
        dp[a[i]] = a[i];
    }
    for (int lg=0; lg<LG; lg++){
        for (int mask=0; mask<(1<<LG); mask++){
            if ((mask>>lg)&1) dp[mask] = max(dp[mask],dp[mask^(1<<lg)]);
        }
    }
    for (int i=1; i<=n; i++){
        int mask = ((1<<LG)-1)^a[i];
        if (dp[mask]) cout << dp[mask] << " ";
        else cout << -1 << " ";
    }
}

/*Driver Code*/
signed main(){
//    freopen(NAME".inp","r",stdin);
//    freopen(NAME".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
