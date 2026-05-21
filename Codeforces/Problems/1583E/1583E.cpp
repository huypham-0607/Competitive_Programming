/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT ""

using namespace std;

#define pb push_back
#define endl "\n"
#define ffor(i, a, b) for(int i = a; i <= (b); ++i)
#define rfor(i, a, b) for(int i = a; i >= (b); --i)
#define frep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = a; i > (b); --i)
#define all(x) (x).begin(),(x).end()
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

const int N = 3e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,m;
vector<int> ad[N],adj[N];
int depth[N];
int parent[N];
int vis[N];

void DFS(int u, int p) {
    depth[u] = depth[p]+1;
    parent[u] = p;
    vis[u] = 1;
    for (auto v:ad[u]) {
        if (vis[v]) continue;
        adj[u].push_back(v);
        adj[v].push_back(u);
        DFS(v,u);
    }
}

int getLCA(int u, int v) {
    if (depth[u] < depth[v]) swap(v,u);

    while (depth[u] > depth[v]) {
        u = parent[u];
    }
    if (u == v) return u;
    
    while (parent[u] != parent[v]) {
        u = parent[u];
        v = parent[v];
    }
    return parent[u];
}

int deg[N];

void solve(){
    cin >> n >> m;
    for (int i=1; i<=m; i++){
        int u,v; cin >> u >> v;
        ad[u].push_back(v);
        ad[v].push_back(u);
    }

    DFS(1,0);

    int q; cin >> q;
    vector<pii> query;
    for (int i=1; i<=q; i++){
        int u,v; cin >> u >> v;
        ++deg[u];
        ++deg[v];
        query.push_back({u,v});
    }

    int lmao = 0;
    
    for (int i=1; i<=n; i++){
        if (deg[i]%2) {
            ++lmao;
        }
    }

    if (lmao) {
        cout << "NO" << endl;
        cout << lmao/2 << endl;
        return;
    }
    cout << "YES" << endl;

    for (auto[u,v]:query) {
        int lca = getLCA(u,v);
        vector<int> pre,suf;
        while (u!=lca) {
            pre.push_back(u);
            u = parent[u];
        }
        while (v!=lca) {
            suf.push_back(v);
            v = parent[v];
        }
        reverse(all(suf));
        cout << pre.size() + suf.size() + 1 << endl;
        for (auto x:pre) cout << x << " ";
        cout << lca << " ";
        for (auto x:suf) cout << x << " ";
        cout << endl;
    }
}

/*Driver Code*/
signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    if (fopen(TEXT".inp","r")){
        freopen(TEXT".inp","r",stdin);
        freopen(TEXT".out","w",stdout);
    }

    int testCount = 1;
//    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

