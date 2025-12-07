/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define int long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 1e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e15+3;

/*Global Variables*/
int n;
vector<int> adj[N];
int pre[N];

struct Node{
    vector<int> val;
    Node(){
        val.resize(4,LLINF);
    }
    int mn(){
        return min({val[0],val[1],val[2],val[3]});
    }
};

Node Comb(Node x, Node y){
    Node res;
    if (x.val[0] == LLINF) return y;
    if (y.val[0] == LLINF) return x;
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            int idx = (i&(1<<1)) + (j&1);
            int val = x.val[i] + y.val[j] + (((i&1)^((j>>1)&1))?1:0);
            res.val[idx] = min(res.val[idx],val);
        }
    }
    return res;
}

struct SegTree{

    int n;
    vector<Node> ST;

    void Build_Rec(int idx, int l, int r){
        if (l==r){
            ST[idx].val[0] = ST[idx].val[3] = 0;
            ST[idx].val[1] = ST[idx].val[2] = INF;
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

    void Update(int idx, int l, int r, int x, pii val){
        if (x<l || r<x) return;
        if (l==r){
            ST[idx].val[0] += val.fi;
            ST[idx].val[3] += val.se;
            return;
        }

        int mid = (l+r)/2;
        Update(idx*2,l,mid,x,val); Update(idx*2+1,mid+1,r,x,val);
        ST[idx] = Comb(ST[idx*2],ST[idx*2+1]);
    }

    Node Get(int idx, int l, int r, int x, int y){
        if (y<l || r<x) return Node();
        if (x<=l && r<=y) return ST[idx];
        int mid = (l+r)/2;
        return Comb(Get(idx*2,l,mid,x,y),Get(idx*2+1,mid+1,r,x,y));
    }
} ST;

//HLD
int curpos = 0;
int parent[N],sz[N],depth[N];
int root[N],pos[N];
int tin[N],tout[N];
vector<pii> residue(N,make_pair(0,0));

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
    if (u==r) tin[r] = curpos;

    int nxt = 0;
    for (auto v:adj[u]){
        if (v==parent[u]) continue;
        if (!nxt || sz[nxt]<sz[v]) nxt = v;
    }

    if (nxt) HLD(nxt,r);
    else tout[r] = curpos;

    for (auto v:adj[u]){
        if (v==parent[u] || v==nxt) continue;
        HLD(v,v);
    }
}


Node CBT(int x){
    while (root[x]!=1){
        Node tmp = ST.Get(1,1,n,tin[root[x]],tout[root[x]]);
        int p = parent[root[x]];
        ST.Update(1,1,n,pos[p],make_pair(-residue[root[x]].fi,-residue[root[x]].se));
        residue[root[x]].fi = min({tmp.val[0],tmp.val[1],tmp.val[2]+1,tmp.val[3]+1});
        residue[root[x]].se = min({tmp.val[0]+1,tmp.val[1]+1,tmp.val[2],tmp.val[3]});
        ST.Update(1,1,n,pos[p],residue[root[x]]);
        x = p;
    }
    return ST.Get(1,1,n,tin[1],tout[1]);
}

int cat(signed x){
    ST.Update(1,1,n,pos[x],make_pair(0,INF));
    Node tmp = CBT(x);

//    cout << tmp.mn() << endl;

    pre[x] = 1;

    return tmp.mn();
}

int dog(signed x){
    ST.Update(1,1,n,pos[x],make_pair(INF,0));
    Node tmp = CBT(x);

//    cout << tmp.mn() << endl;

    pre[x] = 2;

    return tmp.mn();
}

signed neighbor(signed x){
    if (pre[x] == 1){
        ST.Update(1,1,n,pos[x],make_pair(0,-INF));
    }
    if (pre[x] == 2){
        ST.Update(1,1,n,pos[x],make_pair(-INF,0));
    }

    Node tmp = CBT(x);

//    cout << tmp.mn() << endl;

    pre[x] = 0;

    return tmp.mn();
}

void initialize(signed _n, vector<signed> u, vector<signed> v){
    n = _n;
    for (int i=0; i<n-1; i++){
        adj[u[i]].push_back(v[i]);
        adj[v[i]].push_back(u[i]);
    }
    DFS(1,0);
    HLD(1,1);
    ST.Build(n);
}

//int _n,q;
//int u[N],v[N];
//

//void Solve(){
//    cin >> _n;
//    for (int i=0; i<_n-1; i++){
//        cin >> u[i] >> v[i];
//    }
//    initialize(_n,u,v);
//
//    cin >> q;
//    while (q--){
//        int t,x;
//        cin >> t >> x;
//        if (t==1) cout << cat(x) << endl;
//        if (t==2) cout << dog(x) << endl;
//        if (t==3) cout << neighbor(x) << endl;
//    }
//
//}
//

//signed main(){
////    freopen("catsordogs.inp","r",stdin);
////    freopen("catsordogs.out","w",stdout);
////    ios_base::sync_with_stdio(0);
////    cin.tie(0);
//
//    Solve();
//
//    return 0;
//}
