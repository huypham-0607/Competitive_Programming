/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT "disconnected"

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

const int N = 1e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here
int n,m,q;

vector<int> query[N];

struct DistSetUnion {
    int n;
    vector<int> parent;
    vector<int> sz;
    vector<pair<int&,int>> hist;
    int cmp;

    void init(int _n) {
        n = _n;
        parent.resize(n+1); sz.resize(n+1);
        iota(all(parent),0);
        for (int i=1; i<=n; i++){
            sz[i] = 1;
        }
        hist.clear();
        cmp = n;
    }

    int find(int x) {
        return (x == parent[x]) ? x : find(parent[x]);
    }

    void merge(int u, int v) {
        u = find(u);
        v = find(v);
        if (sz[u] < sz[v]) swap(u,v);

        if (u!=v) {
            hist.push_back({cmp,cmp});
            --cmp;
            hist.push_back({sz[u],sz[u]});
            sz[u] += sz[v];
            hist.push_back({parent[v],parent[v]});
            parent[v] = u;
        }
    }

    int snapshot() {
        return hist.size();
    }

    void rollback(int ver) {
        while (hist.size() > ver) {
            hist.back().fi = hist.back().se;
            hist.pop_back();
        }
    }
} DSU;

vector<pii> edges;
vector<int> IT[4*N];
int ans[N];

void update(int idx, int l, int r, int x, int y, int val) {
    if (y < l || r < x) return;
    if (x <= l && r <= y) {
        IT[idx].push_back(val);
        return;
    }

    int mid = (l+r)/2;
    update(idx*2,l,mid,x,y,val);
    update(idx*2+1,mid+1,r,x,y,val);
}

void dfs(int idx, int l, int r) {
    int ver = DSU.snapshot();
    for (auto x:IT[idx]) {
        DSU.merge(edges[x-1].fi, edges[x-1].se);
    }
    if (l==r) {
        // cout << "l: " << l << endl;
        // cout << DSU.cmp << " " << DSU.snapshot() << endl;
        ans[l] = (DSU.cmp == 1);
        DSU.rollback(ver);
        return;
    }

    int mid = (l+r)/2;
    dfs(idx*2,l,mid);
    dfs(idx*2+1,mid+1,r);
    DSU.rollback(ver);
}

void solve(){
    cin >> n >> m;
    for (int i=1; i<=m; i++){
        int u,v; cin >> u >> v;
        edges.push_back({u,v});
    }
    cin >> q;
    for (int i=1; i<=q; i++){
        int k; cin >> k;
        for (int idx=1; idx<=k; idx++){
            int x; cin >> x;
            query[x].push_back(i);
        }
    }

    for (int idx=1; idx<=m; idx++){
        // cout << "idx: " << idx << endl;
        int prev = 0;
        for (auto x:query[idx]) {
            // cout << x << " ";
            if (prev+1 <= x-1) {
                update(1,1,q,prev+1,x-1,idx);
            }
            prev = x;
        }
        if (prev+1 <= q) {
            update(1,1,q,prev+1,q,idx);
        }
        // cout << endl;
    }

    DSU.init(n);
    dfs(1,1,q);

    for (int i=1; i<=q; i++){
        if (ans[i]) {
            cout << "Connected" << endl;
        }
        else {
            cout << "Disconnected" << endl;
        }
    }
}

/*Driver Code*/
signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    if (fopen(TEXT".in","r")){
        freopen(TEXT".in","r",stdin);
        freopen(TEXT".out","w",stdout);
    }

    int testCount = 1;
//    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

