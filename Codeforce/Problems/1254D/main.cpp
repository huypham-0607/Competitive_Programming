/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const int MD = 998244353;
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

int bin_pow(int a, int b){
    int res = 1;
    for (int lg=30; lg>=0; lg--){
        res = (res*res)%MD;
        if (b&(1<<lg)) res = (res*a)%MD;
    }
    return res;
}

struct FWRange{
    int BIT[N];

//    FWRange(int _n): n(_n){};

    void UpdatePoint(int idx, int val){
        while (idx<=n){
            BIT[idx] = (MD+BIT[idx]+val)%MD;
            idx+=(idx&(-idx));
        }
    }

    void Update(int l, int r, int val){
        UpdatePoint(l,val);
        UpdatePoint(r+1,-val);
    }

    int Get(int idx){
        int res = 0;
        while (idx>0){
            res = (MD+res+BIT[idx])%MD;
            idx-=(idx&(-idx));
        }
        return res;
    }
};

struct FWPoint{
    int BIT[N];

    void Update(int idx, int val){
        while (idx<=n){
            BIT[idx] = (MD+BIT[idx]+val)%MD;
            idx+=(idx&(-idx));
        }
    }

    int GetPoint(int idx){
        int res = 0;
        while (idx>0){
            res = (MD+res+BIT[idx])%MD;
            idx-=(idx&(-idx));
        }
        return res;
    }

    int Get(int l, int r){
        return (MD+GetPoint(r)-GetPoint(l-1))%MD;
    }
};

struct Isekai{
    int timedfs = 0;
    int parent[N], sz[N],depth[N];
    int pos[N],root[N];
    int tin[N],tout[N];
    int changecost[N],sum[N];
    int curcost[N];
    int heavy[N];
    FWRange BITout;
    FWPoint BITin;

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
        pos[u] = ++timedfs;
        root[u] = r;
        tin[u] = timedfs;

        int nxt = 0;
        for (int v:adj[u]){
            if (v==parent[u]) continue;
            if (!nxt || sz[nxt]<sz[v]) nxt = v;
        }

        heavy[u] = sz[nxt];
        curcost[u] = sz[nxt];
        if (nxt) HLD(nxt,r);

        for (int v:adj[u]){
            if (v==nxt || v==parent[u]) continue;
            changecost[v] = sz[nxt]-sz[v];
            HLD(v,v);
        }
        tout[u] = timedfs;
    }

    Isekai(){
        DFS(1,0);
        HLD(1,1);
//        for (int i=1; i<=n; i++){
//            cout << curcost[i] << " " << changecost[i] << endl;
//        }
//        cout << endl;
    }

    void Update(int x, int val){
        BITout.Update(1,tin[x]-1, (val*sz[x])%MD ); BITout.Update(tout[x]+1,n, (val*sz[x])%MD );
        BITin.Update(pos[x],(val*(n-heavy[x]))%MD );
        sum[x] = (sum[x]+val)%MD;
    }

    int Query(int u){
        int res = (sum[u]*curcost[u])%MD;
        res = (res+BITout.Get(pos[u]))%MD;

        while (root[u]!=1){
            res = (res+BITin.Get(pos[root[u]],pos[u]))%MD;
            res = (res + (changecost[root[u]]*sum[parent[root[u]]])%MD )%MD;
            u = parent[root[u]];
        }
        res = (res + BITin.Get(pos[1],pos[u]))%MD;
        return res;
    }
};

/*Solution*/
void solve(){
    cin >> n >> q;
    int inv_mod = bin_pow(n,MD-2);
    for (int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Isekai HLD;
    for (int i=1; i<=q; i++){
        int id,x,val;
        cin >> id;
        if (id == 1){
            cin >> x >> val;
            HLD.Update(x,val);
        }
        else{
            cin >> x;
            val = HLD.Query(x);
            cout << (val*inv_mod)%MD << endl;
        }
    }
//    cout << endl;
//    HLD.BITin.Update(1,1000);
//    cout << HLD.BITin.Get(1,5) << endl;
//    HLD.BITout.Update(1,5,1000);
//    cout << HLD.BITout.Get(1) << endl;
}

/*Driver Code*/
signed main(){
//    freopen("1254D.inp","r",stdin);
//    freopen("1254D.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
