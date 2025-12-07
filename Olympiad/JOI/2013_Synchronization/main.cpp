/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pib pair<int,bool>
#define piib pair<pii,bool>
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
int n,m,q;
vector<pii> adj[N];
bool state[N];
int residue[N];
pii edge[N];

piib Comb(piib x, piib y){
    if (x.fi.fi == -INF) return y;
    if (y.fi.fi == -INF) return x;

    return make_pair( make_pair(((y.se)? x.fi.fi : y.fi.fi), ((y.se)? x.fi.se: y.fi.se)) ,(x.se&&y.se));
}

struct SegTree{
    int n;
    vector<piib> ST;

    void Build_Rec(int idx, int l, int r){
        if (l==r){
            ST[idx] = {{1,l},false};
            return;
        }
        int mid = (l+r)/2;
        Build_Rec(idx*2,l,mid); Build_Rec(idx*2+1,mid+1,r);
        ST[idx] = Comb(ST[idx*2],ST[idx*2+1]);
    }

    void Build(int _n){
        n = _n;
        ST.resize(4*n+10);
        Build_Rec(1,1,n);
    }

    void UpdateState(int idx, int l, int r, int x, bool val){
        if (x<l || r<x) return;
        if (l==r){
            ST[idx].se = val;
            return;
        }
        int mid = (l+r)/2;
        UpdateState(idx*2,l,mid,x,val); UpdateState(idx*2+1,mid+1,r,x,val);
        ST[idx] = Comb(ST[idx*2],ST[idx*2+1]);
    }

    void UpdateVal(int idx, int l, int r, int x, int val){
        if (x<l || r<x) return;
        if (l==r){
            ST[idx].fi.fi = val;
            return;
        }
        int mid = (l+r)/2;
        UpdateVal(idx*2,l,mid,x,val); UpdateVal(idx*2+1,mid+1,r,x,val);
        ST[idx] = Comb(ST[idx*2],ST[idx*2+1]);
    }

    piib Get(int idx, int l, int r, int x, int y){
        if (y<l || r<x) return make_pair(make_pair(-INF,0),0);
        if (x<=l && r<=y) return ST[idx];
        int mid = (l+r)/2;
        return Comb(Get(idx*2,l,mid,x,y),Get(idx*2+1,mid+1,r,x,y));
    }
} ST;

//HLD
int curpos = 0;
int parent[N],sz[N],depth[N];
int root[N],pos[N];

void DFS(int u, int p, int id){
    edge[id] = {u,p};
    sz[u] = 1;
    for (auto &in:adj[u]){
        int v,vid; tie(v,vid) = in;
        if (v==p) continue;
        parent[v] = u;
        depth[v] = depth[u]+1;
        DFS(v,u,vid);
        sz[u]+=sz[v];
    }
}

void HLD(int u, int r){
    root[u] = r;
    pos[u] = ++curpos;

    int nxt = 0;
    for (auto &in:adj[u]){
        int v = in.fi;
        if (v==parent[u]) continue;
        if (!nxt || sz[nxt]<sz[v]) nxt = v;
    }
    if (nxt) HLD(nxt,r);
    for (auto &in:adj[u]){
        int v = in.fi;
        if (v==parent[u] || v==nxt) continue;
        HLD(v,v);
    }
}

piib Query(int u){
    piib res = {{-INF,0},0};
    while (root[u]!=1){
        res = Comb(ST.Get(1,1,n,pos[root[u]],pos[u]),res);
        u = parent[root[u]];
    }
    res = Comb(ST.Get(1,1,n,pos[1],pos[u]),res);
    return res;
}

void Update(int id){
    if (!state[id]){
        piib res1 = Query(edge[id].fi);
        piib res2 = Query(edge[id].se);
        int val = res1.fi.fi+res2.fi.fi-residue[id];
        ST.UpdateState(1,1,n,pos[edge[id].fi],true);
        ST.UpdateVal(1,1,n,res2.fi.se,val);
    }
    else{
        piib res1 = Query(edge[id].fi);
        int val = res1.fi.fi;
        ST.UpdateState(1,1,n,pos[edge[id].fi],false);
        ST.UpdateVal(1,1,n,pos[edge[id].fi],val);
        residue[id] = val;
    }
    state[id] = !state[id];
}

/*Solution*/
void solve(){
    cin >> n >> m >> q;
    for (int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back({v,i});
        adj[v].push_back({u,i});
    }
    ST.Build(n);
    DFS(1,0,0);
    HLD(1,1);
    for (int i=1; i<=m; i++){
        int x; cin >> x;
        Update(x);
    }
    for (int i=1; i<=q; i++){
        int x; cin >> x;
        piib res = Query(x);
        cout << res.fi.fi << endl;
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
