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
int a[N];
vector<int> adj[N];

struct SegTree{
    int ST[4*N];

    void Build(int idx, int l, int r, int order[N]){
        if (l==r){
            ST[idx] = a[order[l]];
            return;
        }
        int mid = (l+r)/2;
        Build(idx*2,l,mid,order);
        Build(idx*2+1,mid+1,r,order);
        ST[idx] = (ST[idx*2]^ST[idx*2+1]);
    }

    void Update(int idx, int l, int r, int x, int val){
        if (x<l || r<x) return;
        if (l==r){
            ST[idx] = val;
            return;
        }
        int mid = (l+r)/2;
        Update(idx*2,l,mid,x,val);
        Update(idx*2+1,mid+1,r,x,val);
        ST[idx] = (ST[idx*2]^ST[idx*2+1]);
    }

    int Get(int idx, int l, int r, int x, int y){
        if (y<l || r<x) return 0;
        if (x<=l && r<=y) return ST[idx];

        int mid = (l+r)/2;
        return (Get(idx*2,l,mid,x,y)^Get(idx*2+1,mid+1,r,x,y));
    }
};

struct HeavyLightDecompose{
    int curpos = 0;
    int parent[N],sz[N],depth[N];
    int pos[N], root[N];
    int order[N];
    SegTree ST;

    void DFS(int u, int p = -1){
        sz[u] = 1;
        for (int v:adj[u]){
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
        order[pos[u]] = u;

        int nxt = 0;
        for (int v:adj[u]){
            if (v==parent[u]) continue;
            if (!nxt || sz[nxt]<sz[v]) nxt = v;
        }
        if (nxt) HLD(nxt,r);
        for (int v:adj[u]){
            if (v==parent[u] || v==nxt) continue;
            HLD(v,v);
        }
    }

    HeavyLightDecompose(){
        DFS(1);
        HLD(1,1);
        ST.Build(1,1,n,order);
    }

    void Update(int x, int val){
        ST.Update(1,1,n,pos[x],val);
    }

    int Query(int u, int v){
        int res = 0;
        while (root[u]!=root[v]){
            if (depth[root[u]]>depth[root[v]]) swap(u,v);
            res = (res^ST.Get(1,1,n,pos[root[v]],pos[v]));
            v = parent[root[v]];
        }
        if (depth[u]>depth[v]) swap(u,v);
//        cout << u << " " << v << endl;
        res = (res^ST.Get(1,1,n,pos[u],pos[v]));
        return res;
    }
};

/*Solution*/
void solve(){
    cin >> n >> q;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    for (int i=1; i<n; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    HeavyLightDecompose HLD;

    for (int i=1; i<=q; i++){
        int id,x,y; cin >> id >> x >> y;
        if (id == 1){
            HLD.Update(x,y);
        }
        else{
            cout << HLD.Query(x,y) << endl;
        }
    }

//    for (int i=1; i<=n; i++) {cout << HLD.order[i] << " ";} cout << endl;
//    for (int i=1; i<=n; i++) {cout << HLD.depth[i] << " ";} cout << endl;
}

/*Driver Code*/
signed main(){
    freopen("cowland.in","r",stdin);
    freopen("cowland.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
