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
int n;
vector<int> adj[N];

//Seggs


//HLD
map<int,int> chainval;
int curpos = 0;
int parent[N],depth[N],sz[N];
int root[N],pos[N];
int tin[N],tout[N];

void DFS(int u,int p){
    sz[u] = 1;
    for (auto v:adj[u]){
        if (v==p) continue;
        parent[v] = u;
        depth[v] = depth[u]+1;
        DFS(v,u);
        sz[u]+=sz[v];
    }
}

void HLD(int u, int r){
    root[u] = r;
    pos[u] = ++curpos;
    if (u==r) tin[r] = curpos;

    int nxt = 0;
    for (auto v:adj[u]){
        if (v==parent[u]) continue;
        if (!nxt || sz[nxt]<sz[v]) nxt = v;
    }

    if (nxt) HLD(v,r);
    tout[r] = curpos;

    for (auto v:adj[u]){
        if (v==parent[u] || v==nxt) continue;
        HLD(v,v);
    }
}

/*Solution*/
void solve(){
    cin >> n;
    n*=2;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    for (int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(1,0);
    DFS(1,1);

    for (i)
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
