/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT ""

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

const int N = 1e6+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,m;

struct DSU{
    int n;
    int sum;
    vector<vector<int>> adj;
    vector<int> parent;
    vector<int> cnt;
    vector<int> val;

    void init(int _n){
        n = _n;
        parent.clear();
        adj.clear();
        cnt.clear();
        val.clear();
        sum = 0;
        parent.resize(n+1,0);
        adj.resize(n+1,vector<int>());
        cnt.resize(n+1,0);
        val.resize(n+1,INF);
        iota(all(parent),0);
    }

    int find(int x){
        return (x == parent[x])? x : parent[x] = find(parent[x]);
    }

    bool isSame(int u, int v){
        return (find(u) == find(v));
    }

    void merge(int u, int v, int eval){
        // cerr << u << " " << v << " " << eval << endl;
        int x = find(u);
        int y = find(v);
        // cerr << x << " " << y << endl;
        // cerr << n << endl;

        ++n;
        parent.push_back(n);
        adj.push_back(vector<int>());
        cnt.push_back(0);
        val.push_back(eval);

        adj[n].push_back(x);
        if (x!=y) adj[n].push_back(y);
        parent[x] = n;
        if (x!=y) parent[y] = n;
    }
    
    void dfs(int u, int cum) {
        val[u] = min(val[u],cum);
        for (auto v:adj[u]) {
            dfs(v,val[u]);
            cnt[u] += cnt[v];
            if (cnt[u]>=2) {
                sum+=val[u]*(cnt[u]/2);
                cnt[u]%=2;
            }
        }
    }
} DSU;

int deg[N];

void solve(){
    cin >> n >> m;
    int ans = 0;
    for (int i=1; i<=n; i++) deg[i] = 0;
    DSU.init(n);

    // cerr << "meow" << endl;
    for (int i=1; i<=m; i++){
        int u,v,w; cin >> u >> v >> w;
        ans += w;
        ++deg[u]; ++deg[v];
        DSU.merge(u,v,w);
    }

    for (int i=1; i<=n; i++) if (deg[i]%2) DSU.cnt[i]++;

    // cerr << "meow" << endl;

    DSU.dfs(n+m, INF);
    cout << DSU.sum+ans << endl;
}

/*Driver Code*/
signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    if (fopen(TEXT".inp","r")){
        freopen(TEXT".inp","r",stdin);
        freopen(TEXT".out","w",stdout);
    }

    int testCount = 1;
   cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

