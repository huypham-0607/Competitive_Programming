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
int n,q;
vector<int> adj[N];

struct SegTree{
    vector<ll> ST,lazy;

    SegTree(){
        ST.resize(4*N);
        lazy.resize(4*N);
    }

    void Propagate(int idx, int l, int r){
        int mid = (l+r)/2;
        ll delta = lazy[idx];
        ST[idx*2]+=delta*(mid-l+1);
        lazy[idx*2]+=delta;
        ST[idx*2+1]+=delta*(r-(mid+1)+1);
        lazy[idx*2+1]+=delta;
        lazy[idx] = 0;
    }

    void Update(int idx, int l, int r, int x, int y, ll val){
        if (y<l || r<x) return;
        if (x<=l && r<=y){
            ST[idx]+=val*(r-l+1);
            lazy[idx]+=val;
            return;
        }

        Propagate(idx,l,r);

        int mid = (l+r)/2;

        Update(idx*2,l,mid,x,y,val);
        Update(idx*2+1,mid+1,r,x,y,val);
        ST[idx] = ST[idx*2]+ST[idx*2+1];
    }

    long long Get(int idx, int l, int r, int x, int y){
        if (y<l || r<x) return 0;
        if (x<=l && r<=y) return ST[idx];

        Propagate(idx,l,r);

        int mid = (l+r)/2;

        return Get(idx*2,l,mid,x,y) + Get(idx*2+1,mid+1,r,x,y);
    }
} ST;

//HLD
int curpos = 0;
int parent[N],sz[N],depth[N];
int root[N],pos[N];
int tin[N],tout[N];

void DFS(int u, int p){
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
    tin[u] = curpos;

    int nxt = 0;
    for (auto v:adj[u]){
        if (v==parent[u]) continue;
        if (!nxt || sz[nxt]<sz[v]) nxt = v;
    }

    if (nxt) HLD(nxt,r);

    for (auto v:adj[u]){
        if (v==parent[u] || v==nxt) continue;
        HLD(v,v);
    }

    tout[u] = curpos;
}

void UpdateSub(int x, int val){
    ST.Update(1,1,n,tin[x],tout[x],val);
}

void UpdatePoint(int x, int val){
    ST.Update(1,1,n,pos[x],pos[x],val);
}

ll Query(int u, int v){
    ll res = 0;
    while (root[u]!=root[v]){
        if (pos[u] > pos[v]){
            res+=ST.Get(1,1,n,pos[root[u]],pos[u]);
            u = parent[root[u]];
        }
        else{
            res+=ST.Get(1,1,n,pos[root[v]],pos[v]);
            v = parent[root[v]];
        }
    }
    if (pos[u] > pos[v]){
        res+=ST.Get(1,1,n,pos[v],pos[u]);
    }
    else{
        res+=ST.Get(1,1,n,pos[u],pos[v]);
    }
    return res;
}

/*Solution*/
void solve(){
    cin >> n >> q;
    for (int i=1; i<n; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(1,0);
    HLD(1,1);

//    for (int i=1; i<=n; i++){
//        cout << root[i] << " " << pos[i] << endl;
//    }

    for (int i=1; i<=q; i++){
        int id,u,v;
        cin >> id >> u >> v;
        if (id == 1){
            UpdateSub(u,v);
        }
        if (id == 2){
            UpdatePoint(u,v);
        }
        if (id == 3){
            cout << Query(u,v) << endl;
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
