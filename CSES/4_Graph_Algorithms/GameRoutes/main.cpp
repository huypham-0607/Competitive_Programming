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
int n,m;
vector<int> adj[N],order;
int deg[N];
int dp[N];
priority_queue<int,vector<int>,greater<int>> pq;

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
    for (int i=n-1; i>=0; i--){
        int u = order[i];

        if (u==n) dp[u] = 1;
        else{
            for (auto v:adj[u]){
                dp[u] = (dp[u]+dp[v])%INF;
            }
        }
    }
    cout << dp[1] << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
