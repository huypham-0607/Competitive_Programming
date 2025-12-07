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
const int N = 20;
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
int cst[N][N];
int dp[(1<<16)+10][N];

/*Solution*/
void solve(){
    cin >> n;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> cst[i][j];
        }
    }
    for (int i=0; i<n; i++){
        dp[(1<<i)][i] = 0;
    }
    for (int mask=1; mask<(1<<n); mask++){
        if (__builtin_popcount(mask) == 1) continue;
        for (int i=0; i<n; i++){
            if (!(mask&(1<<i))) continue;
            dp[mask][i] = INF;
            for (int j=0; j<n; j++){
                if (i==j) continue;
                if ((mask&(1<<j))){
                    dp[mask][i] = min(dp[mask][i],dp[mask^(1<<i)][j]+cst[j][i]);
                }
            }
        }
    }
    int ans = INF;
    for (int i=0; i<n; i++){
        ans = min(ans,dp[(1<<n)-1][i]);
    }
    cout << ans << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
