/*Author: KawakiMeido*/

//HLD + ST with non-commutative function
//Segment Tree: Finding suffix ending at u with the highest sum.
//Init all node val as -1
//Query 1: Increment node u by 1
//Query 2: Revert all changes made in subtree u, decrement node u by value of suffix with the highest sum ending at u
//Query 3: Finding suffix with highest sum ending at u, if it's -1, node u is white, otherwise node u is black.

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
    if (x.fi == -INF) return y;
    if (y.fi == -INF) return x;
    return make_pair(max(y.fi,x.fi+y.se),x.se+y.se);
}

struct SegTree{
    vector<pii> ST;
    set<int> st;

    void Build_Rec(int idx, int l, int r){
        if (l==r){
            ST[idx] = {-1,-1};
            return;
        }
        int mid = (l+r)/2;
        Build_Rec(idx*2,l,mid); Build_Rec(idx*2+1,mid+1,r);
        ST[idx] = Comb(ST[idx*2],ST[idx*2+1]);
    }

    void Build(int _n){
        ST.resize(_n*4+10);
        Build_Rec(1,1,_n);
    }

    void Update_Rec(int idx, int l, int r, int x, int val){
        if (x<l || r<x) return;
        if (l==r){
            ST[idx].fi+=val;
            ST[idx].se+=val;
            return;
        }
        int mid = (l+r)/2;
        Update_Rec(idx*2,l,mid,x,val); Update_Rec(idx*2+1,mid+1,r,x,val);
        ST[idx] = Comb(ST[idx*2],ST[idx*2+1]);
    }

    void Reset_Rec(int idx, int l, int r, int x){
        if (x<l || r<x) return;
        if (l==r){
            ST[idx].fi = ST[idx].se = -1;
            return;
        }
        int mid = (l+r)/2;
        Reset_Rec(idx*2,l,mid,x); Reset_Rec(idx*2+1,mid+1,r,x);
        ST[idx] = Comb(ST[idx*2],ST[idx*2+1]);
    }

    pii Get_Rec(int idx, int l, int r, int x, int y){
        if (y<l || r<x) return make_pair(-INF,-INF);
        if (x<=l && r<=y) return ST[idx];
        int mid = (l+r)/2;
        return Comb(Get_Rec(idx*2,l,mid,x,y),Get_Rec(idx*2+1,mid+1,r,x,y));
    }

    void Reset(int l, int r){
        auto it = st.lower_bound(l);
        while (it!=st.end() && *it<=r){
            Reset_Rec(1,1,n,*it);
            st.erase(it);
            it = st.lower_bound(l);
        }
    }
    void Update(int x, int val){
        Update_Rec(1,1,n,x,val);
        st.insert(x);
    }
    pii Get(int x, int y){
        return Get_Rec(1,1,n,x,y);
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

pii GetVal(int u){
    pii res = {-INF,-INF};
    while (root[u]!=1){
        res = Comb(ST.Get(pos[root[u]],pos[u]),res);
        u = parent[root[u]];
    }
    res = Comb(ST.Get(pos[1],pos[u]),res);
    return res;
}

void Query1(int u){
    ST.Update(pos[u],1);
}

void Query2(int u){
    ST.Reset(tin[u],tout[u]);
    pii tmp = GetVal(u);
    ST.Update(pos[u],-1-tmp.fi);
}

void Query3(int u){
    pii tmp = GetVal(u);
//    cout << tmp.fi << endl;
    if (tmp.fi == -1){
        cout << "white" << endl;
    }
    else cout << "black" << endl;
}

/*Solution*/
void solve(){
    cin >> n >> q;
    for (int u=2; u<=n; u++){
        int v; cin >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ST.Build(n);
    DFS(1,0);
    HLD(1,1);

//    for (int i=1; i<=n; i++){
//        cout << root[i] << " " << pos[i] << endl;
//    }

    for (int i=1; i<=q; i++){
        int id,u; cin >> id >> u;
        if (id == 1) Query1(u);
        if (id == 2) Query2(u);
        if (id == 3) Query3(u);
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
