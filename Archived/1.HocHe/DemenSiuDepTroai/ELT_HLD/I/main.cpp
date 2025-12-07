/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int MD = 998244353;
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

//SEGGS
struct Node{
    int a[2],b[2];

    Node(int _a = 1, int _b = 0){
        a[0] = a[1] = _a;
        b[0] = b[1] = _b;
    }

    int GetFor(int x){
        return ((a[0]*x)%MD+b[0])%MD;
    }

    int GetRev(int x){
        return ((a[1]*x)%MD+b[1])%MD;
    }
};

Node Comb(Node u, Node v){
    Node res;
    res.a[0] = (u.a[0]*v.a[0])%MD;
    res.a[1] = (v.a[1]*u.a[1])%MD;
    res.b[0] = ((u.b[0]*v.a[0])%MD+v.b[0])%MD;
    res.b[1] = ((v.b[1]*u.a[1])%MD+u.b[1])%MD;
    return res;
}

Node ST[N*2];

void BuildST(){
    for (int i=n-1; i>0; --i) ST[i] = Comb(ST[i<<1],ST[i<<1|1]);
}

void UpdateST(int x, Node v){
    for (ST[x+=n] = v; x>>=1; ) ST[x] = Comb(ST[x<<1],ST[x<<1|1]);
}

Node GetST(int l, int r){
    Node resl(1,0), resr(1,0);
    for (l+=n, r+=n; l<r; l>>=1, r>>=1){
        if (l&1) resl = Comb(resl,ST[l++]);
        if (r&1) resr = Comb(ST[--r],resr);
    }
    return Comb(resl,resr);
}

//HLD

Node val[N];
vector<int> adj[N];
int sz[N], parent[N], depth[N];
int CCur=1, timedfs=-1;
int CID[N],CHead[N];
int pos[N];

void DFS(int u, int p){
    parent[u] = p;
    depth[u] = depth[p]+1;
    sz[u] = 1;

    for (auto v:adj[u]){
        if (v==p) continue;
        DFS(v,u);
        sz[u]+=sz[v];
    }
}

void GetHLD(int u, int p){
    if (!CHead[CCur]) CHead[CCur] = u;
    CID[u] = CCur;
    pos[u] = ++timedfs;
    ST[pos[u]+n] = val[u];

    int nxt = 0;
    for (auto v:adj[u]){
        if (v==p) continue;
        if (sz[v]>sz[nxt]) nxt = v;
    }

    if (nxt) GetHLD(nxt,u);
    for (auto v:adj[u]){
        if (v==p || v==nxt) continue;
        ++CCur;
        GetHLD(v,u);
    }
}

int Query(int u, int v, int x){
    Node resl, resr;
    while (CID[u]!=CID[v]){
        if (CID[u]>CID[v]){
//            cout << u << " " << CHead[CID[u]] << endl;
            resl = Comb(GetST(pos[CHead[CID[u]]],pos[u]+1),resl);
            u = parent[CHead[CID[u]]];
        }
        else{
//            cout << v << " " << CHead[CID[v]] << endl;
            resr = Comb(GetST(pos[CHead[CID[v]]],pos[v]+1),resr);
            v = parent[CHead[CID[v]]];
        }
    }
    if (depth[u]>depth[v]) resl = Comb(GetST(pos[v],pos[u]+1),resl);
    else resr = Comb(GetST(pos[u],pos[v]+1),resr);
//    cout << u << " " << v << endl;
    return resr.GetFor(resl.GetRev(x));
}

/*Solution*/
void solve(){
    cin >> n >> q;
    for (int i=1; i<=n; i++){
        cin >> val[i].a[0] >> val[i].b[0];
        val[i].a[1] = val[i].a[0];
        val[i].b[1] = val[i].b[0];
    }
    for (int i=1; i<n; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1,0);
    GetHLD(1,0);
    BuildST();
//    cout << endl;
//    for (int i=1; i<=n; i++){
//        cout << i << " " << pos[i] << " " << CID[i] << endl;
//    }
//    cout << endl;
    while (q--){
        int id,x,y,z;
        cin >> id >> x >> y >> z;
        if (!id){
            Node tmp(y,z);
            UpdateST(pos[x],tmp);
        }
        else{
            cout << Query(x,y,z) << endl;
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
