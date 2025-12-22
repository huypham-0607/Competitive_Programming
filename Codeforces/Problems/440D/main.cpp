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
const int N = 410;
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
vector<int> a[N];
vector<vector<vector<int>>> dp;
vector<vector<int>> sz;

void DFS(int u, int p){

    for (auto in:a[u]){
        int v = in.fi;
        int id = in.se;
        if (v==p) continue;
        DFS(v,u);
        dp[u][0].push_back()

        for (int r)

    }

}

/*Solution*/
void solve(){
    cin >> n >> k;
    for (int i=1; i<n; i++){
        int u,v;
        cin >> u >> v;
        a[u].push_back({v,i});
        a[v].push_back({u,i});
    }
    dp.resize(n+1);
    sz.resize(n+1);
    for (int i=1; i<=n; i++){
        dp[i].resize(k+1);
        sz[i].resize(k+1);
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
