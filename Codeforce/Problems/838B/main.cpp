/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT ""

using namespace std;

#define pb push_back
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second

typedef int int2;
#define int long long

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

mt19937_64 rd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const int LG_LCA = 18;
const long long LLINF = 1e18+3;

//Starts here

struct LazySegmentTree{
    struct Node{
        int val;
        Node(){
            val = LLINF;
        }
    };

    int n;
    vector<Node> IT;
    vector<int> lazy;

    void propagate(int idx){
        //Update idx*2
        IT[idx*2].val += lazy[idx];
        lazy[idx*2] += lazy[idx];

        //Update idx*2+1
        IT[idx*2+1].val += lazy[idx];
        lazy[idx*2+1] += lazy[idx];

        //Reset idx
        lazy[idx] = 0;
    }

    Node comb(Node l, Node r){
        if (l.val == INF) return r;
        if (r.val == INF) return l;

        Node i;

        i.val = min(l.val,r.val);

        return i;
    }

    void build(int idx, int l, int r){
        if (l==r){
            IT[idx].val = 0;

            return;
        }

        int mid = (l+r)/2;
        build(idx*2,l,mid);
        build(idx*2+1,mid+1,r);
        IT[idx] = comb(IT[idx*2],IT[idx*2+1]);
    }

    void update(int idx, int l, int r, int x, int y, int val){
        if (y < l || r < x) return;
        if (x <= l && r <= y){
            IT[idx].val += val;
            lazy[idx] += val;
            return;
        }

        propagate(idx);

        int mid = (l+r)/2;
        update(idx*2,l,mid,x,y,val);
        update(idx*2+1,mid+1,r,x,y,val);
        IT[idx] = comb(IT[idx*2],IT[idx*2+1]);
    }

    int getVal(int idx, int l, int r, int x, int y){
        if (y < l || r < x) return INF;
        if (x <= l && r <= y){
            return IT[idx].val;
        }

        propagate(idx);

        int mid = (l+r)/2;
        return min(getVal(idx*2,l,mid,x,y),getVal(idx*2+1,mid+1,r,x,y));

    }

    void init(int _n){
        n = _n;
        IT.resize(n*4+10, Node());
        lazy.resize(n*4+10, 0);
        build(1,1,n);
    }
} IT;

int n,q;
vector<pair<pii,int>> edges;
vector<int> adj[N];
int up[LG_LCA][N];
int depth[N];

void dfsLCA(int u, int p=0){
    depth[u] = depth[p]+1;
    up[0][u] = p;
    for (int lg=1; lg<LG_LCA; lg++){
        int v = up[lg-1][u];
        up[lg][u] = up[lg-1][v];
    }
    for (auto v:adj[u]){
        if (v==p) continue;
        dfsLCA(v,u);
    }
}

int binLift(int u, int x){
    for (int lg=0; lg<LG_LCA; lg++){
        if ((1<<lg)&x) u = up[lg][u];
    }
    return u;
}

int getLCA(int u, int v){
    if (depth[u]>depth[v]) swap(u,v);
    v = binLift(v,depth[v]-depth[u]);
    if (u==v) return u;
    for (int lg=LG_LCA-1; lg>=0; lg--){
        if (up[lg][u]!=up[lg][v]){
            u = up[lg][u];
            v = up[lg][v];
        }
    }
    return up[0][u];
}


int timedfs = 0;
int tin[N],tout[N],backval[N];
void dfsELT(int u, int p){
    tin[u] = ++timedfs;

    for(auto v:adj[u]){
        if (v==p) continue;
        dfsELT(v,u);
    }

    tout[u] = timedfs;
}


void solve(){
    cin >> n >> q;
    edges.push_back({{0,0},0});
    for (int i=1; i<n; i++) {
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back({{u,v},w});
    }
    dfsLCA(1,0);
    dfsELT(1,0);
    for (int i=1; i<n; i++){
        int u,v,w; cin >> u >> v >> w;
        edges.push_back({{u,v},w});
    }
    IT.init(n);
    for (int i=1; i<=2*n-2; i++){
        if (i < n) {
            if (depth[edges[i].fi.fi] < depth[edges[i].fi.se]) swap(edges[i].fi.fi,edges[i].fi.se);
            auto [u,v] = edges[i].fi;
            int w = edges[i].se;
            IT.update(1,1,n,tin[u],n,w);
            IT.update(1,1,n,tout[u]+1,n,-w);
        }
        else {
            auto [u,v] = edges[i].fi;
            int w = edges[i].se;
            IT.update(1,1,n,tin[u],tin[u],w);
            backval[u] = w;
        }
    }

    while (q--){ 
        int id; cin >> id;
        if (id == 1) {
            int i, w; cin >> i >> w;
            auto [u,v] = edges[i].fi;
            int pw = edges[i].se;
            if (i < n) {
                IT.update(1,1,n,tin[u],n,-pw);
                IT.update(1,1,n,tout[u]+1,n,pw);
                IT.update(1,1,n,tin[u],n,w);
                IT.update(1,1,n,tout[u]+1,n,-w);
            }
            else {
                IT.update(1,1,n,tin[u],tin[u],-pw);
                IT.update(1,1,n,tin[u],tin[u],w);
                backval[u] = w;
            }
            edges[i].se = w;
        }
        else {
            int res = LLINF;
            int u,v; cin >> u >> v;
            int lca = getLCA(u,v);
            if (lca == u) {
                res = min(res,IT.getVal(1,1,n,tin[v],tin[v]) - backval[v] - IT.getVal(1,1,n,tin[u],tin[u]) + backval[u]);
            }
            int p0 = IT.getVal(1,1,n,tin[u],tin[u])-backval[u];
            int p1 = IT.getVal(1,1,n,tin[u],tout[u]);
            int p2 = IT.getVal(1,1,n,tin[v],tin[v])-backval[v];
            // cout << p1 << " " << p2 << endl;
            res = min(res,IT.getVal(1,1,n,tin[u],tout[u])-(IT.getVal(1,1,n,tin[u],tin[u])-backval[u])+IT.getVal(1,1,n,tin[v],tin[v])-backval[v]);
            cout << res << endl;
        }
    }
}

/*Driver Code*/
signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    if (fopen(TEXT".inp","r")){
        freopen(TEXT".inp","r",stdin);
        freopen(TEXT".out","w",stdout);
    }

    int testCount = 1;
//    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

