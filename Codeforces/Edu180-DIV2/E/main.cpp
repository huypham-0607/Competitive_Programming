/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#include <windows.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 5e5;
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
int q;
int dp[N+10];

/*Solution*/
void solve(){
    for (int i=1; i<=N; i++){
        dp[i] = INF;
    }
    dp[1] = 1;
    for (int i=1; i<=N; i++){
        if (i+2<=N){
            dp[i+2] = min(dp[i+2],dp[i]+1);
        }
        for (int j=1; j<i; j++){
            int idx = i*(j+2);
            if (idx>N) break;
            dp[idx] = min(dp[idx],dp[i] + dp[j]);

        }
    }

    cin >> q;
    for (int i=1; i<=q; i++){
        int x; cin >> x;
        if (dp[x] == INF) cout << -1 << endl;
        else cout << dp[x] << endl;
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
