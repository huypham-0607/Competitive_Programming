/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define piii pair<int,pii>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 3e5+10;
const int INF = 1e9+7;
const int LG = 20;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n,m,q;
int val[N];
int t[2*N];
vector<piii> edge;
vector<pii> query;
vector<int> adj[2*N];

struct DisSetUnion{
    int n;
    int parent[2*N];

    void Init(int _n, int _q){
        n = _n;
        for (int i=1; i<=n; i++){
            parent[i] = i;
            t[i] = _q+1;
        }
    }

    int Find(int x){
        return (x == parent[x])? x : parent[x] = Find(parent[x]);
    }

    void Union(int u, int v, int x){
        u = Find(u);
        v = Find(v);

        if (u==v) return;

        ++n;
        t[n] = x;
        parent[n] = n;
        parent[u] = parent[v] = parent[n];

        adj[n].push_back(u);
        adj[n].push_back(v);
    }
} DSU;

int timedfs = 0;
int org[N],vis[2*N];
int tin[2*N],tout[2*N];
int up[LG][2*N];

void DFS(int u, int p){
//    cout << u << endl;
    vis[u] = true;
    up[0][u] = p;
    for (int lg=1; lg<LG; lg++){
        int v = up[lg-1][u];
        up[lg][u] = up[lg-1][v];
    }

    tin[u] = timedfs+1;
    if (!(int)adj[u].size()){
        ++timedfs;
        org[timedfs] = u;
    }
    for (auto v:adj[u]){
        DFS(v,u);
    }
    tout[u] = timedfs;
}

int bin_lift(int u, int x){
    for (int lg = LG-1; lg>=0; lg--){
        int v = up[lg][u];
        if (t[v]>x) u = v;
    }
    return u;
}

struct SegTree{
    int n;
    pii ST[4*N];

    void Build(int idx, int l, int r){
        if (l==r){
            ST[idx] = {val[org[l]],l};
            return;
        }
        int mid = (l+r)/2;
        Build(idx*2,l,mid);
        Build(idx*2+1,mid+1,r);
        ST[idx] = max(ST[idx*2],ST[idx*2+1]);
    }

    pii Get(int idx, int l, int r, int x, int y){
        if (r<x || y<l) return make_pair(0,0);
        if (x<=l && r<=y) return ST[idx];
        int mid = (l+r)/2;
        return max(Get(idx*2,l,mid,x,y),Get(idx*2+1,mid+1,r,x,y));
    }

    void Update(int idx, int l, int r, int x){
        if (r < x || x < l) return;
        if (l==r){
            ST[idx] = {0,0};
            return;
        }
        int mid = (l+r)/2;
        Update(idx*2,l,mid,x);
        Update(idx*2+1,mid+1,r,x);
        ST[idx] = max(ST[idx*2],ST[idx*2+1]);
    }
} ST;

/*Solution*/
void solve(){
    cin >> n >> m >> q;
    for (int i=1; i<=n; i++){
        cin >> val[i];
    }
    for (int i=1; i<=m; i++){
        int u,v; cin >> u >> v;
        edge.push_back({q+1,{u,v}});
    }
    for (int i=1; i<=q; i++){
        int id; cin >> id;
        if (id == 1){
            int u; cin >> u;
            query.push_back({u,i});
        }
        else{
            int x; cin >> x;
            edge[x-1].fi = i;
        }
    }

    DSU.Init(n,q);

    sort(all(edge),greater<piii>());

    for (auto in:edge){
        int u = DSU.Find(in.se.fi);
        int v = DSU.Find(in.se.se);

        if (u!=v){
            DSU.Union(u,v,in.fi);
        }
    }

//    for (int i=1; i<=DSU.n; i++){
//        cout << i << ": ";
//        for (auto x:adj[i]){
//            cout << x << " ";
//        }
//        cout << endl;
//    }

    for (int i=DSU.n; i>0; i--){
        if (!vis[i]) DFS(i,0);
    }

    ST.Build(1,1,n);

    for (auto in:query){
        int u = in.fi;
        int x = in.se;
        int v = bin_lift(u,x);
        pii res = ST.Get(1,1,n,tin[v],tout[v]);
        cout << res.fi << endl;
        ST.Update(1,1,n,res.se);
    }
}

/*Driver Code*/
signed main(){
//    freopen("1416D.inp","r",stdin);
//    freopen("1416D.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
