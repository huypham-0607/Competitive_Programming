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
const int LG = 17;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n,q;
vector<pii> adj[N];
int up[LG][N];
int dist[LG][N];
int depth[N];

void DFS(int u, int p, int w){
    up[0][u] = p;
    dist[0][u] = w;
    depth[u] = depth[p]+1;

    for (auto lg=1; lg<LG; lg++){
        int v = up[lg-1][u];
        up[lg][u] = up[lg-1][v];
        dist[lg][u] = dist[lg-1][u] + dist[lg-1][v];
    }

    for (auto in:adj[u]){
        if (in.fi==p) continue;
        DFS(in.fi,u,in.se);
    }
}

pii Lift(int u, int x){
    int d = 0;
    for (int lg=0; lg<LG; lg++){
        if (x&(1<<lg)){
            d+=dist[lg][u];
            u = up[lg][u];
        }
    }
    return make_pair(u,d);
}

int LCA(int u, int v){
    if (depth[v]>depth[u]) swap(u,v);
    pii in = Lift(u,depth[u]-depth[v]);
    int res = in.se;
    u = in.fi;
    if (u==v) return res;
    for (int lg=LG-1; lg>=0; lg--){
        if (up[lg][u]!=up[lg][v]){
            res+=dist[lg][u];
            res+=dist[lg][v];
            u = up[lg][u];
            v = up[lg][v];
        }
    }
    res+=dist[0][u]+dist[0][v];
    return res;
}

/*Solution*/
void solve(){
    for (int u=1; u<n; u++){
        int v,w;
        cin >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    depth[0] = 0;
    DFS(0,0,0);

    cin >> q;
    while (q--){
        int u,v;
        cin >> u >> v;
        cout << LCA(u,v) << " ";
    }

    for (int i=0; i<=n; i++){
        adj[i].clear();
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tmp = 0;
    cin >> n;
    while (n){
        if (tmp) cout << endl;
        tmp = 1;
        solve();
        cin >> n;
    }
//    TestCases(0);

    return 0;
}
