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

pii Comb(pii x, pii y){
    return make_pair(((x.fi!=-1)? x.fi: y.fi),((y.se!=-1)? y.se:x.se));
}

struct SegTree{
    pii ST[4*N];

    void Build(int idx, int l, int r){
        if (l==r){
            ST[idx] = {-1,-1};
            return;
        }
        int mid = (l+r)/2;
        Build(idx*2,l,mid); Build(idx*2+1,mid+1,r);
        ST[idx] = Comb(ST[idx*2],ST[idx*2+1]);
    }

    void Update(int idx, int l, int r, int x, int val){
        if (x<l || r<x) return;
        if (l==r){
            if (ST[idx].fi == -1){
                ST[idx].fi = ST[idx].se = val;
            }
            else ST[idx].fi = ST[idx].se = -1;
            return;
        }
        int mid = (l+r)/2;
        Update(idx*2,l,mid,x,val); Update(idx*2+1,mid+1,r,x,val);
        ST[idx] = Comb(ST[idx*2],ST[idx*2+1]);
    }

    pii Get(int idx, int l, int r, int x, int y){
        if (y<l || r<x) return make_pair(-1,-1);
        if (x<=l && r<=y) return ST[idx];
        int mid = (l+r)/2;
        return Comb(Get(idx*2,l,mid,x,y),Get(idx*2+1,mid+1,r,x,y));
    }
};

struct HeavyLightDecompose{
    int curpos = 0;
    int parent[N],depth[N],sz[N];
    int root[N],pos[N],lst[N];
    SegTree ST;

    void DFS(int u, int p){
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
        lst[pos[u]] = u;

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

    void Update(int x){
        ST.Update(1,1,n,pos[x],x);
    }

    int Query(int x){
        int u = 1, v = x;
        pii lans = {-1,-1}, rans = {-1,-1};
        while (root[u]!=root[v]){
            if (depth[root[u]] > depth[root[v]]){
                lans = Comb(ST.Get(1,1,n,pos[root[u]],pos[u]),lans);
                u = parent[root[u]];
            }
            else{
                rans = Comb(ST.Get(1,1,n,pos[root[v]],pos[v]),rans);
                v = parent[root[v]];
            }
        }
        if (depth[u]>depth[v]){
            lans = Comb(ST.Get(1,1,n,pos[v],pos[u]),lans);
        }
        else{
            rans = Comb(ST.Get(1,1,n,pos[u],pos[v]),rans);
        }
        if (lans.se!=-1) return lans.se;
        else return rans.fi;
    }
} HLD;

/*Solution*/
void solve(){
    cin >> n >> q;
    for (int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    HLD.DFS(1,0);
    HLD.HLD(1,1);
    HLD.ST.Build(1,1,n);

//    for (int i=1; i<=n; i++){
//        cout << HLD.root[i] << " " << HLD.pos[i] << " " << HLD.parent[i] << endl;
//    }

    for (int i=1; i<=q; i++){
        int id,x; cin >> id >> x;
        if (!id) HLD.Update(x);
        else cout << HLD.Query(x) << endl;
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
