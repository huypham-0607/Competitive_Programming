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
const int N = 21;
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
int n,k;
int cost[N][N];
int dp[(1<<20)+10];

/*Solution*/
void solve(){
    int ans = LLINF;
    cin >> n >> k;
    dp[0] = 0;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin >> cost[i][j];
        }
    }
    if (n==k){
        cout << 0;
        return;
    }
    for (int mask=1; mask<(1<<n)-1; mask++){
        dp[mask] = LLINF;
        int cnt = 0;
        for (int lg=0; lg<n; lg++){
            if (mask&(1<<lg)){
                ++cnt;
                for (int lg2=0; lg2<n; lg2++){
                    if (!(mask&(1<<lg2))){
                        dp[mask] = min(dp[mask],dp[mask^(1<<lg)] + cost[lg+1][lg2+1]);
                    }
                }
            }
        }
        if (cnt>=n-k){
            ans = min(ans,dp[mask]);
        }
    }
    cout << ans;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
