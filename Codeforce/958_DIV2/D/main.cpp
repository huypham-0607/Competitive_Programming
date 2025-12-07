/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int unsigned long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 3e5+10;
const int INF = 1e9+7;
const long long LLINF = 2e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n;
int val[N];
vector<int> a[N];
int dp[N][3];
int pos[N];

void DFS(int u, int p){
    dp[u][1] = dp[u][2] = LLINF;
    pos[u] = 0;
    int m = 2;
    int org = 0;
    for (auto v:a[u]){
        if (v==p) continue;
        DFS(v,u);
        ++m;
        org+=dp[v][1];
    }
    if (m==1){
        dp[u][1] = val[u];
        dp[u][2] = val[u]*2;
        pos[u] = 1;
        return;
    }
    vector<int> res;
    res.resize(m+1);
    for (auto v:a[u]){
        if (v==p) continue;
        if (pos[v]<=m){
            res[pos[v]]+=dp[v][2]-dp[v][1];
        }
    }
    for (int i=1; i<=m; i++){
        res[i]+=org+val[u]*i;
        if (res[i]<dp[u][1]){
            dp[u][2] = dp[u][1];
            dp[u][1] = res[i];
            pos[u] = i;
        }
        else if (res[i]<dp[u][2]){
            dp[u][2] = res[i];
        }
    }
}

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> val[i];
    }
    for (int i=1; i<n; i++){
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    DFS(1,0);
    cout << dp[1][1] << endl;

//    for (int i=1; i<=n; i++){
//        cout << i << " ";
//        for (int j=1; j<=2; j++){
//            cout << dp[i][j] << " ";
//        }
//        cout << pos[i] << endl;
//    }

    for (int i=1; i<=n; i++){
        a[i].clear();
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
