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

const int N = 1e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e15+3;

//Starts here
struct DSU{
    int n;
    vector<int> parent;

    void init(int _n){
        n = _n;
        parent.clear();
        parent.resize(n+1,0);
        for (int i=1; i<=n; i++){
            parent[i] = i;
        }
    }

    int find(int x){
        return (x == parent[x])? x : parent[x] = find(parent[x]);
    }

    bool isSame(int u, int v){
        return (find(u) == find(v));
    }

    void merge(int u, int v){
        int x = find(u);
        int y = find(v);
        if (x!=y){
            parent[y] = x;
        }
    }
}DSU;

int n,m;
vector<pii> adj[N];

const int LG_LCA = 17;

int up[LG_LCA][N];
int udist[LG_LCA][N];
int depth[N];

void dfsLCA(int u, int w, int p=0){
    depth[u] = depth[p]+1;
    up[0][u] = p;
    udist[0][u] = w;
    for (int lg=1; lg<LG_LCA; lg++){
        int v = up[lg-1][u];
        up[lg][u] = up[lg-1][v];
        udist[lg][u] = udist[lg-1][u] + udist[lg-1][v];
    }
    for (auto [v,w]:adj[u]){
        if (v==p) continue;
        dfsLCA(v,w,u);
    }
}

pii binLift(int u, int x){
    int w = 0;
    for (int lg=0; lg<LG_LCA; lg++){
        if ((1<<lg)&x) {
            w += udist[lg][u];
            u = up[lg][u];
        }
    }
    return {u,w};
}

int getDist(int u, int v){
    if (depth[u]>depth[v]) swap(u,v);
    auto in = binLift(v,depth[v]-depth[u]);
    v = in.fi;
    int res = in.se;
    if (u==v) return res;
    for (int lg=LG_LCA-1; lg>=0; lg--){
        if (up[lg][u]!=up[lg][v]){
            res += udist[lg][u];
            res += udist[lg][v];
            u = up[lg][u];
            v = up[lg][v];
        }
    }
    return res + udist[0][u] + udist[0][v];
}

int fw[43][43];

void dijkstra(int n, vector<vector<pii>>& adj){
    ffor(i,1,n){
        ffor(j,1,n){
            if (i==j) fw[i][j] = 0;
            else fw[i][j] = LLINF;
        }
    }
    for (int u=1; u<=n; u++){
        for (auto [v,w]:adj[u]) {
            fw[u][v] = min(fw[u][v],w);
        }
    }

    ffor(k,1,n){
        ffor(i,1,n){
            ffor(j,1,n){
                fw[i][j] = min(fw[i][j],fw[i][k]+fw[k][j]);
            }
        }
    }
}

vector<pair<int,pii>> edges;
int dist[N][43];

void solve(){
    cin >> n >> m;
    DSU.init(n);
    vector<int> src;
    for (int i=1; i<=m; i++){
        int u,v,w; cin >> u >> v >> w;
        if (!DSU.isSame(u,v)) {
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
            DSU.merge(u,v);
        }
        else {
            src.push_back(u);
            src.push_back(v);
            edges.push_back({w,{u,v}});
        }
    }
    dfsLCA(1,0,0);
    sort(all(src));
    src.resize(unique(all(src))-src.begin());

    // for (auto [w,in]:edges) {
    //     cout << in.fi << " " << in.se << endl;
    // }
    // for (auto x:src) {
    //     cout << x << " ";
    // }
    // cout << endl;

    vector<vector<pii>> adj2;
    adj2.resize(src.size()+3);
    for (auto [w,in]:edges) {
        auto [u,v] = in;
        u = lower_bound(all(src),u) - src.begin()+1;
        v = lower_bound(all(src),v) - src.begin()+1;
        adj2[u].push_back({v,w});
        adj2[v].push_back({u,w});
    }
    for (int i=1; i<=src.size(); i++){
        for (int j=1; j<=src.size(); j++){
            if (i==j) continue;
            adj2[i].push_back({j,getDist(src[i-1],src[j-1])});
        }
    }
    dijkstra(src.size(),adj2);
    for (int i=1; i<=n; i++){
        for (int j=1; j<=src.size(); j++){
            dist[i][j] = LLINF;
        }
        for (int k=1; k<=src.size(); k++){
            int w = getDist(i,src[k-1]);
            ffor(j,1,src.size()) {
                dist[i][j] = min(dist[i][j],w + fw[k][j]);
            }
        }

    }

    // for (int i=1; i<=n; i++){
    //     for (int j=1; j<=src.size(); j++){
    //         cout << dist[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int q; cin >> q;
    
    for (int i=1; i<=q; i++){
        int u,v; cin >> u >> v;
        int ans = getDist(u,v);
        for (int mid = 1; mid<=src.size(); mid++) {
            ans = min(ans,dist[u][mid] + dist[v][mid]);
        }
        cout << ans << endl;
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

