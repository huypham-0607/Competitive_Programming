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
vector<int> adj[N];
vector<int> ans;
bool vis[N];
int deg[N];
priority_queue<int,vector<int>,greater<int>> pq;

/*Solution*/
void solve(){
    cin >> n >> m;
    for (int i=1; i<=m; i++){
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
        ans.push_back(u);
        vis[u] = true;
        for (auto v:adj[u]){
            --deg[v];
            if (!deg[v]) pq.push(v);
        }
    }
    if ((int)ans.size()!=n) cout << "IMPOSSIBLE" << endl;
    else{
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
