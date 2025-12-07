/*Author: KawakiMeido*/
#include "swap.h"
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define int long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define piii pair<int,pii>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 1e5+10;
const int INF = 1e9+7;
const int LG = 19;
const long long LLINF = 1e18+3;

///*TestCases*/
//int test=1;
//void solve();
//void TestCases(bool v){
//    if (v) cin >> test;
//    while(test--) solve();
//}

/*Global Variables*/
int n,m,k;
vector<piii> edge;
int weight[3*N];
int nodecnt[3*N];
int edgecnt[3*N];
bool valid[3*N];
int deg[3*N];

struct Graph{
    vector<vector<int>> adj;
    vector<vector<int>> up;
    vector<int> depth;

    Graph(): adj(3*N,vector<int>()), up(LG,vector<int>(3*N,0)), depth(3*N,0){};

    void DFS(int u, int p){
        depth[u] = depth[p]+1;
        up[0][u] = p;

        for (int lg=1; lg<LG; lg++){
            int v = up[lg-1][u];
            up[lg][u] = up[lg-1][v];
        }

        for (auto v:adj[u]){
            if (v==p) continue;
            DFS(v,u);
        }
    }

    int bin_lift(int u, int w){
        for (int lg=LG-1; lg>=0; lg--){
            int val = (1<<lg);
            if (w >= val){
                w-=val;
                u = up[lg][u];
            }
        }
        return u;
    }

    int get_LCA(int u, int v){
        if (depth[u]>depth[v]) swap(u,v);
        v = bin_lift(v,depth[v] - depth[u]);
        if (u==v) return u;
        for (int lg=LG-1; lg>=0; lg--){
            if (up[lg][u] != up[lg][v]){
                u = up[lg][u];
                v = up[lg][v];
            }
        }
        return up[0][u];
    }
} KRT,Org;

struct DisSetUnion{
    int n;
    vector<int> parent;

    DisSetUnion(): parent(3*N,0){};

    void Init(int _n){
        n = _n;
        for (int i=1; i<=n; i++){
            parent[i] = i;
            nodecnt[i] = 1;
            valid[i] = false;
        }
    }

    int Find(int x){
        return (x==parent[x])? x : parent[x] = Find(parent[x]);
    }

    void Union(int u, int v, int w){
        int x = u;
        int y = v;
        u = Find(u);
        v = Find(v);

        ++deg[x];
        ++deg[y];

        ++n;
        parent[n] = n;
        weight[n] = w;
        edgecnt[n] = 1;
        KRT.adj[n].push_back(u);
        if (u!=v) KRT.adj[n].push_back(v);

        parent[u] = n;
        if (u!=v) parent[v] = n;

        edgecnt[n]+=edgecnt[u];
        nodecnt[n]+=nodecnt[u];
        if (u!=v){
            edgecnt[n] += edgecnt[v];
            nodecnt[n] += nodecnt[v];
        }

        if (deg[x]>2 || deg[y]>2 || valid[u] || valid[v] || edgecnt[n]>=nodecnt[n]){
            valid[n] = true;
        }
    }
} DSU;

int bin_search(int u){
    for (int lg=LG-1; lg>=0; lg--){
        int v = KRT.up[lg][u];
        if (v==0) continue;

        if (!valid[v]) u = v;
    }
    return KRT.up[0][u];
}

void init(signed _n, signed _m, vector<signed> U, vector<signed> V, vector<signed> W){
    n = _n;
    m = _m;
    for (int i=0; i<m; i++){
        edge.push_back({W[i],{U[i]+1,V[i]+1}});
    }

    sort(all(edge));
//    KRT.adj.resize(3*N);
//    Org.adj.resize(N);
//    KRT.up.resize(LG,vector<int>(3*N,0));
//    Org.up.resize(LG,vector<int>(N,0));
//    KRT.depth.resize((3*N,0));
//    Org.depth.resize((N,0));

    DSU.Init(n);

    for (auto in:edge){
        int w = in.fi;
        int u = in.se.fi;
        int v = in.se.se;

        if (DSU.Find(u)!=DSU.Find(v)){
            Org.adj[u].push_back(v);
            Org.adj[v].push_back(u);
        }

        DSU.Union(u,v,w);
    }

    k = DSU.n;

    KRT.DFS(k,0);
    Org.DFS(1,0);

//    cout << n << " " << m << endl;
//    cout << "Org" << endl;
//    for (int i=1; i<=n; i++){
//        cout << i << ": ";
//        for (auto x:Org.adj[i]){
//            cout << x << " ";
//        }
//        cout << endl;
//    }
//
//    cout << "KRT" << endl;
//    for (int i=1; i<=k; i++){
//        cout << i << ": ";
//        for (auto x:KRT.adj[i]){
//            cout << x << " ";
//        }
//        cout << endl;
//    }
//
//    for (int i=1; i<=k; i++){
//        cout << edgecnt[i] << " " << nodecnt[i] << " " << valid[i] << endl;
//    }
}

signed getMinimumFuelCapacity(signed x, signed y){
    ++x; ++y;
    int lca = KRT.get_LCA(x,y);
//    int lca2 = Org.get_LCA(x,y);
//    int cnt = Org.depth[x] + Org.depth[y] - Org.depth[lca2]*2;
//    if (weight[lca]==cnt){
//        int x = KRT.up[0][lca];
//        if (x==0) return -1;
//        else return weight[x];
//    }
//    else return weight[lca];

    if (valid[lca]) return weight[lca];
    else{
        int tmp = bin_search(lca);
        if (tmp==0) return -1;
        else return weight[tmp];
    }
}

//int _n,_m,q;
//vector<signed> U, V, W;

///*Solution*/
//void solve(){
//    cin >> _n >> _m;
//    for (int i=0; i<_m; i++){
//        signed u,v,w; cin >> u >> v >> w;
//        U.push_back(u);
//        V.push_back(v);
//        W.push_back(w);
//    }
//    init((signed)_n,(signed)_m,U,V,W);
//    cin >> q;
//    for (int i=1; i<=q; i++){
//        int x,y; cin >> x >> y;
//        cout << getMinimumFuelCapacity(x,y) << endl;
//    }
//}
//
///*Driver Code*/
//signed main(){
//    freopen("SwappingCities.inp","r",stdin);
//    freopen("SwappingCities.out","w",stdout);
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//
//    TestCases(0);
//
//    return 0;
//}
/*
5 6
0 1 4
0 2 4
1 2 1
1 3 2
1 4 10
2 3 3
3
1 2
2 4
0 1
*/
