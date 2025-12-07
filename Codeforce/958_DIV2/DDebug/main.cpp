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
int n;
int val[N];
int dp[N][6];
int dppos[N][6];
vector<int> a[N];

void DFS(int u, int p){
    for (auto v:a[u]){
        if (v==p) continue;
        DFS(v,u);
        for (int i=1; i<=5; i++){
            int mn = LLINF;
            int ps = 0;
            for (int j=1; j<=5; j++){
                if (i==j) continue;
                if (dp[v][j]<mn){
                    dp[v][j] = mn;
                    ps = j;
                }
            }
            dp[u][i]+=mn;
            dppos[u][i] = ps;
        }
    }
    for (int i=1; i<=5; i++){
        dp[u][i]+=val[u]*i;
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
    int mn = LLINF;
    int pos = 0;
    for (int i=1; i<=5; i++){
        if (dp[1][i] < mn){
            mn = dp[1][i];
            pos = i;
        }
    }
    for (int i=1; i<=n; i++){
        cout << i << ": ";
        for (int j=1; j<=5; j++){
            cout << dppos[i][j] << " ";
        }
        cout << endl;
    }
    cout << mn << " " << pos << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
