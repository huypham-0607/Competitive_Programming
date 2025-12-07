/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "TWOTREE"

using namespace std;

/*Constants*/
const int N = 3e5+10;
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
int ans[N];
pii range[N];
vector<pii> query[N];
vector<vector<int>> adj1,adj2;

//BIT
struct Fenwick{
    vector<int> BIT;
    int n;

    void Init(int _n){
        n = _n;
        BIT.resize(n+10);
    }

    void Update(int idx, int val){
        while (idx<=n){
            BIT[idx]+=val;
            idx+=(idx&(-idx));
        }
    }

    int GetPoint(int idx){
        int res = 0;
        while (idx>0){
            res+=BIT[idx];
            idx-=(idx&(-idx));
        }
        return res;
    }

    int Get(int l, int r){
        return GetPoint(r) - GetPoint(l-1);
    }
}BIT;

//HLD
struct HeavyLightDecomposition{
    int n;
    int curpos;
    vector<int> parent,depth,sz;
    vector<int> root,pos;
    Fenwick BIT;

    void DFSHLD(int u, int p, vector<vector<int>>& adj){
        sz[u] = 1;
        for (auto v:adj[u]){
            if (v==p) continue;
            parent[v] = u;
            depth[v] = depth[u]+1;
            DFSHLD(v,u,adj);
            sz[u] += sz[v];
        }
    }

    void HLD(int u, int r, vector<vector<int>> &adj){
        pos[u] = ++curpos;
        root[u] = r;

        int nxt = 0;
        for (auto v:adj[u]){
            if (v == parent[u]) continue;
            if (!nxt || sz[nxt]<sz[v]) nxt = v;
        }

        if (nxt) HLD(nxt,r,adj);

        for (auto v:adj[u]){
            if (v == nxt || v == parent[u]) continue;
            HLD(v,v,adj);
        }
    }

    HeavyLightDecomposition(int _n, vector<vector<int>>& adj){
        n = _n;
        BIT.Init(n);
        curpos = 0;
        parent.resize(n+10,0);
        depth.resize(n+10,0);
        sz.resize(n+10,0);
        pos.resize(n+10,0);
        root.resize(n+10,0);
        DFSHLD(1,0,adj);
        HLD(1,1,adj);
    }

    int GetLCA(int u, int v){
        while (root[u]!=root[v]){
            if (depth[root[u]]>depth[root[v]]) swap(u,v);
            v = parent[root[v]];
        }
        if (depth[u]>depth[v]) swap(u,v);
        return u;
    }

    void Update(int u, int val){
        BIT.Update(pos[u],val);
    }

    int GetSum(int u, int v){
        int res = 0;
        while (root[u]!=root[v]){
            if (depth[root[u]]>depth[root[v]]){
                res+=BIT.Get(pos[root[u]],pos[u]);
                u = parent[root[u]];
            }
            else{
                res+=BIT.Get(pos[root[v]],pos[v]);
                v = parent[root[v]];
            }
//            cerr << u << " " << v << endl;
        }
        if (depth[u]>depth[v]){
            res+=BIT.Get(pos[v],pos[u]);
        }
        else{
            res+=BIT.Get(pos[u],pos[v]);
        }
        return res;
    }

};

void DFS(int u, int p, vector<vector<int>>& adj, HeavyLightDecomposition& HLD){
    HLD.Update(u,1);
    for (auto in:query[u]){
        int id = in.fi;
        int sus = in.se;
        ans[id]+=sus*HLD.GetSum(range[id].fi,range[id].se);
    }
    for (auto v:adj[u]){
        if (v==p) continue;
        DFS(v,u,adj,HLD);
    }
    HLD.Update(u,-1);
}

/*Solution*/
void solve(){
    cin >> n >> q;
    BIT.Init(n);
    adj1.resize(n+5);
    adj2.resize(n+5);
    for (int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        adj1[u].push_back(v);
        adj1[v].push_back(u);
    }
    for (int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        adj2[u].push_back(v);
        adj2[v].push_back(u);
    }
    HeavyLightDecomposition HLD1(n,adj1),HLD2(n,adj2);
    for (int id=1; id<=q; id++){
        int u1,v1,u2,v2;
        cin >> u1 >> v1 >> u2 >> v2;
        range[id] = {u2,v2};
        int LCA = HLD1.GetLCA(u1,v1);
        query[u1].push_back({id,1});
        query[v1].push_back({id,1});
        query[LCA].push_back({id,-1});
        query[HLD1.parent[LCA]].push_back({id,-1});
    }
//    for (int i=1; i<=n; i++){cout << HLD1.pos[i] << " ";} cout << endl;
//    for (int i=1; i<=n; i++){cout << HLD2.pos[i] << " ";} cout << endl;
    DFS(1,0,adj1,HLD2);
    for (int i=1; i<=n; i++){
        cout << ans[i] << endl;
    }
}

/*Driver Code*/
signed main(){
    freopen(NAME".inp","r",stdin);
    freopen(NAME".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
