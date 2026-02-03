/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT "1000G"

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

const int N = 3e5+10;
const int Q = 4e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,q;

int f[N]; // Maximal value achieve visiting nodes inside subtree w/o counting u; 
int g[N]; // Maximal value achieve visiting nodes outside subtree w/o counting u; 
int a[N];
int curchild[N];
int curchildw[N];
vector<pair<pii,int>> query[N];
vector<pii> adj[N];

void calcf(int u, int p) {
    for (auto [v,w]:adj[u]) {
        if (v==p) continue;
        calcf(v,u);
        int tmp = f[v] + a[v] - 2*w;
        if (tmp>0) f[u]+=tmp;
    }
}

void calcg(int u, int p, int wp) {
    int tmp = g[u];
    for (auto [v,w]:adj[u]) {
        if (v==p) continue;
        tmp = tmp + max(0LL,f[v] + a[v] - 2*w);
    }
    tmp = g[u]+f[u];

    for (auto [v,w]:adj[u]) {
        if (v==p) continue;
        int lmeo = max(0LL,f[v]+a[v]-2*w);
        int tmp2 = tmp-lmeo;
        g[v] = max(0LL,tmp2 + a[u] - 2*w);
        calcg(v,u,w);
    }
}
const int LG_LCA = 19;

int up[LG_LCA][N];
int depth[N];
int ans[Q];

void dfsLCA(int u, int p) {
    depth[u] = depth[p]+1;
    up[0][u] = p;
    for (int lg=1; lg<LG_LCA; lg++){
        int v = up[lg-1][u];
        up[lg][u] = up[lg-1][v];
    }
    for (auto [v,w]:adj[u]){
        if (v==p) continue;
        dfsLCA(v,u);
    }
}

int binLiftNode(int u, int x){
    for (int lg=0; lg<LG_LCA; lg++){
        if ((1<<lg)&x) u = up[lg][u];
    }
    return u;
}

int getLCA(int u, int v){
    if (depth[u]>depth[v]) swap(u,v);
    v = binLiftNode(v,depth[v]-depth[u]);
    if (u==v) return u;
    for (int lg=LG_LCA-1; lg>=0; lg--){
        if (up[lg][u]!=up[lg][v]){
            u = up[lg][u];
            v = up[lg][v];
        }
    }
    return up[0][u];
}

int dist[LG_LCA][N];

int binLiftDist(int u, int x){
    int res = 0;
    int save_u = u;
    for (int lg=0; lg<LG_LCA; lg++){
        if ((1<<lg)&x) {
            if (u!=save_u) {
                res += f[u] - max(0LL,f[curchild[u]] + a[curchild[u]] - 2*curchildw[u]);
            }
            res += dist[lg][u];
            u = up[lg][u];
        }
    }
    return res;
}


void dfs(int u, int p, int wp) {

    dist[0][u] = a[u] - wp;
    for (int lg=1; lg<LG_LCA; lg++){
        int v = up[lg-1][u];
        int tmp = f[v] - max(0LL,f[curchild[v]] + a[curchild[v]] - 2*curchildw[v]);
        dist[lg][u] = dist[lg-1][u] + dist[lg-1][v] + tmp;
    }

    for (auto in:query[u]) {
        int lca = in.fi.se;
        int id = in.se;
        int h = depth[u] - depth[lca];
        ans[id] += binLiftDist(u,h);
        // cerr << u << " " << lca << endl;
        ans[id] -= max(0LL,f[curchild[lca]] + a[curchild[lca]] - 2*curchildw[lca]);
    }

    for (auto [v,w]:adj[u]) {
        if (v==p) continue;
        curchild[u] = v;
        curchildw[u] = w;
        dfs(v,u,w);
    }
}

void solve(){
    cin >> n >> q;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    for (int i=1; i<n; i++){
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    calcf(1,0);
    calcg(1,0,0);
    dfsLCA(1,0);

    // for (int i=1; i<=n; i++){
    //     cout << f[i] << " " << g[i] << endl;
    // }

    for (int i=1; i<=q; i++) {
        int u,v; cin >> u >> v;
        int lca = getLCA(u,v);
        ans[i] += a[lca];
        ans[i] += f[lca];
        if (u!=lca) ans[i] += f[u];
        if (v!=lca) ans[i] += f[v];
        ans[i] += g[lca];
        // cout << lca << endl;
        // cout << f[u] << " " << f[v] << " " << g[lca] << endl;
        if (u!=lca) query[u].push_back({{u,lca},i});
        if (v!=lca) query[v].push_back({{v,lca},i});
    }

    dfs(1,0,0);

    for (int i=1; i<=q; i++){
        cout << ans[i] << endl; 
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

