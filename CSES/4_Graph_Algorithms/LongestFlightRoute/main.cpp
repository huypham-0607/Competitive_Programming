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
const int N = 1e5+10;
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
int n,m;
priority_queue<int,vector<int>,greater<int>> pq;
int deg[N];
vector<int> adj[N];
int dp[N];
int trace[N];
vector<int> ans,order;

/*Solution*/
void solve(){
    cin >> n >> m;
    while (m--){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        ++deg[v];
    }
    for (int i=1; i<=n; i++){
        if (!deg[i]) pq.push(i);
    }
    while (!pq.empty()){
        int u = pq.top();
        pq.pop();

        order.push_back(u);
        for (auto v:adj[u]){
            --deg[v];
            if (!deg[v]) pq.push(v);
        }
    }
    memset(dp,-1,sizeof(dp));
    for (int i=n-1; i>=0; i--){
        int u = order[i];
        if (u == n) dp[u] = 1;
        else{
            for (auto v:adj[u]){
                if (dp[v]!=-1){
                    if (dp[v]+1 > dp[u]){
                        dp[u] = dp[v]+1;
                        trace[u] = v;
                    }
                }
            }
        }
    }
    for (int i=1; i<=n; i++){
//        cout << order[i-1] << " " << dp[i] << " " << trace[i] << endl;
    }
    if (dp[1]==-1){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        int u = 1;
        while (u!=0){
            ans.push_back(u);
            u = trace[u];
        }
        cout << ans.size() << endl;
        for (auto x:ans){
            cout << x << " ";
        }
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
