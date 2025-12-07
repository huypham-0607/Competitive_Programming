#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "SHIP"

using namespace std;

const int N = 2e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

int n,q;
vector<int> adj[N];
int val[N];
pii query[N];

void Init(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> val[i];
    }
    for (int i=1; i<n; i++){
         int u,v; cin >> u >> v;
         adj[u].push_back(v);
         adj[v].push_back(u);
    }
    cin >> q;
    for (int i=1; i<=q; i++){
        int u,v; cin >> u >> v;
        query[i] = {u,v};
    }
}

namespace Sub5{
    bool CheckSub(){
        return true;
    }

    //SegmentTree

    struct SegTree{
        vector<int> ST;
        int n;

        void Build_Rec(int idx, int l, int r, int elt[]){
            if (l==r){
                ST[idx] = val[elt[l]];
                return;
            }
            int mid = (l+r)/2;
            Build_Rec(idx*2,l,mid,elt); Build_Rec(idx*2+1,mid+1,r,elt);
            ST[idx] = max(ST[idx*2],ST[idx*2+1]);
        }

        void Build(int _n, int elt[]){
            n = _n;
            ST.resize(n*4+10);

            Build_Rec(1,1,n,elt);
        }

        int Get_Rec(int idx, int l, int r, int x, int y){
            if (r<x || y<l) return 0;
            if (x<=l && r<=y) return ST[idx];
            int mid = (l+r)/2;
            return max(Get_Rec(idx*2,l,mid,x,y),Get_Rec(idx*2+1,mid+1,r,x,y));
        }

        int Get(int l, int r){
            return Get_Rec(1,1,n,l,r);
        }
    }ST;

    //HLD
    int curpos = 0;
    int parent[N], sz[N], depth[N];
    int root[N], pos[N];
    int elt[N];

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
        elt[curpos] = u;

        int nxt = 0;
        for (auto v:adj[u]){
            if (v==parent[u]) continue;
            if (!nxt || sz[nxt]<sz[v])  nxt = v;
        }

        if (nxt) HLD(nxt,r);

        for (auto v:adj[u]){
            if (v==parent[u] || v==nxt) continue;
            HLD(v,v);
        }
    }

    int GetQval(int u, int v){
        int lval=0, rval = 0;
        while (root[u]!=root[v]){
            if (depth[root[u]]>depth[root[v]]){
                lval = max(lval,ST.Get(pos[root[u]],pos[u]));
                u = parent[root[u]];
            }
            else{
                rval = max(rval,ST.Get(pos[root[v]],pos[v]));
                v = parent[root[v]];
            }
        }
        if (depth[u]>depth[v]){
            lval = max(lval,ST.Get(pos[v],pos[u]));
        }
        else{
            rval = max(rval,ST.Get(pos[u],pos[v]));
        }
        return max(lval,rval);
    }

    ll qval[N];
    ll dp[N];

    void SolveSub(){
        DFS(1,1);
        HLD(1,1);
        ST.Build(n,elt);

//        for (int i=1; i<=n; i++){
//            cout << root[i] << endl;
//        }

        for (int i=1; i<=q; i++){
            qval[i] = GetQval(query[i].fi,query[i].se);
        }

        for (int i=1; i<=n; i++){
            dp[i] = -1;
        }
        dp[1] = 0;

        for (int i=1; i<=q; i++){
            int u = query[i].fi;
            int v = query[i].se;

            if (dp[u] == -1) continue;
            dp[v] = max(dp[v],dp[u]+qval[i]);
//            for (int i=1; i<=n; i++){
//                cout << dp[i] << " ";
//            }
//            cout << endl;
        }

        ll ans = 0;
        for (int i=1; i<=n; i++){
            ans = max(ans,dp[i]);
        }

        cout << ans << endl;
    }
}

signed main(){
    freopen(NAME ".inp","r",stdin);
    freopen(NAME ".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Init();
    if (Sub5::CheckSub()) return Sub5::SolveSub(),0;

    return 0;
}

