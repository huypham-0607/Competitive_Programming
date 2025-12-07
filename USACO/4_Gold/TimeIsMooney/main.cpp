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
const int N = 1e3+10;
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
int n,m,c;
int a[N];
int dp[N][N];
vector<int> adj[N];

/*Solution*/
void solve(){
    cin >> n >> m >> c;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    while (m--){
        int u,v;
        cin >> u >> v;
        adj[v].push_back(u);
    }
    dp[0][1] = 0;
    for (int i=2; i<=n; i++){
        dp[0][i] = -INF;
    }
    for (int i=1; i<=1000; i++){
        for (int u=1; u<=n; u++){
            dp[i][u] = -INF;
            for (auto v:adj[u]){
                if (dp[i-1][v] != -INF) dp[i][u] = max(dp[i][u],dp[i-1][v]+a[u]);
            }
        }
    }
    int ans = 0;
    for (int i=0; i<=1000; i++){
        ans = max(ans,dp[i][1]-c*i*i);
    }
    cout << ans;
}

/*Driver Code*/
int main(){
    freopen("time.in","r",stdin);
    freopen("time.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
