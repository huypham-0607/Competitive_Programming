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
const int N = 1e6+10;
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
int sz[N],depth[N];
int mx=0;
int res=0;
int cnt[N];
int ans[N];
vector<int> adj[N];

void DFS(int u, int p){
    sz[u] = 1;
    for (auto v:adj[u]){
        if (v==p) continue;
        depth[v] = depth[u] +1;
        DFS(v,u);
        sz[u]+=sz[v];
    }
}

void Add(int u, int p, int val, int heavy){
    for (auto v:adj[u]){
        if (v==p || v==heavy) continue;
        Add(v,u,val,heavy);
    }
    cnt[depth[u]]+=val;
    if (cnt[depth[u]]>=mx){
        mx = cnt[depth[u]];
        res = depth[u];
    }
}

void Sack(int u, int p, bool keep){
    int heavy = 0;
    for (auto v:adj[u]){
        if (v == p) continue;
        if (!heavy || sz[heavy]<sz[v]) heavy = v;
    }

    for (auto v:adj[u]){
        if (v == p || v == heavy) continue;
        Sack(v,u,0);
    }

    if (heavy){
        Sack(heavy,u,1);
    }

    Add(u,p,1,heavy);

    ans[u] = res - depth[u];

    if (!keep){
        Add(u,p,-1,0);
        res = 0;
        mx = 0;
    }
}

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1,0);
    Sack(1,0,1);
    for (int i=1; i<=n; i++){
        cout << ans[i] << endl;
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
