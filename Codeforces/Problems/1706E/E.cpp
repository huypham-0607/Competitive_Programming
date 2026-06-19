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

const int N = 2e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,m,q,k;
vector<int> adj[N];
int val[N];

struct DSU{
    int n;
    vector<int> parent;

    void init(int _n){
        n = _n;
        parent.resize(n+1,0);
        for (int i=1; i<=n; i++){
            parent[i] = i;
            val[i] = i;
        }
    }

    int find(int x){
        return (x == parent[x])? x : parent[x] = find(parent[x]);
    }

    bool isSame(int u, int v){
        return (find(u) == find(v));
    }

    void merge(int u, int v, int id){
        int x = find(u);
        int y = find(v);
        if (x!=y){
            ++n;
            parent.push_back(n);
            val[n] = k+id;
            adj[n].push_back(x);
            adj[n].push_back(y);
            parent[x] = n;
            parent[y] = n;
        }
    }
} DSU;

int timedfs = 0;
int tin[N], tout[N];
int order[2*N];


void DFS(int u, int p) {
    order[++timedfs] = u;
    tin[u] = timedfs;
    for (auto v:adj[u]) {
        if (v==p) continue;
        DFS(v,u);
        order[++timedfs] = u;
    }
    tout[u] = timedfs;
}

const int LG_LCA = 19;
int st[LG_LCA][2*N];
int st2[LG_LCA][N];
void solve(){
    cin >> k >> m >> q;
    timedfs = 0;
    for (int i=1; i<=2*k-1; i++){
        adj[i].clear();
    }
    DSU.init(k);
    for (int i=1; i<=m; i++){
        int u,v; cin >> u >> v;
        DSU.merge(u,v,i);
    }

    n = 2*k-1;
    DFS(n,0);
    for (int i=timedfs; i>0; i--){
        st[0][i] = order[i];
        for (int lg=1; lg<LG_LCA; lg++){
            int j = i + (1<<(lg-1));
            // cout << i << " " << j << " " << lg << " " << st[lg-1][i] << " " << st[lg-1][j] << endl;
            st[lg][i] = ((j>timedfs)?st[lg-1][i]:max(st[lg-1][i],st[lg-1][j]));
            // cout << st[lg][i] << endl;
        } 
    }

    // for (int i=1; i<=timedfs; i++){
    //     cout << order[i] << " ";
    // }
    // cout << endl;

    for (int i=n; i>0; i--){
        st2[0][i] = i;
        for (int lg=1; lg<LG_LCA; lg++){
            int j = i+(1<<(lg-1));
            if (j>n) {
                st2[lg][i] = st2[lg-1][i];
            }
            else {
                int u = st2[lg-1][i];
                int v = st2[lg-1][j];
                int x = tin[u];
                int y = tout[v];
                if (x>y) swap(x,y);
                int delta = y-x+1;
                int msb = 63-__builtin_clzll(delta);
                int ans = max(st[msb][x],st[msb][y-(1<<msb)+1]);
                st2[lg][i] = ans;
            }
        }
    }

    // for (int lg=0; lg<4; lg++){
    //     for (int i=1; i<=timedfs; i++){
    //         cout << st[lg][i] << " "; 
    //     }
    //     cout << endl;
    // }

    for (int idx=1; idx<=q; idx++){
        int l,r; cin >> l >> r;
        int d = (r-l+1);
        int msb = 63-__builtin_clzll(d);
        int u = st2[msb][l];
        int v = st2[msb][r-(1<<msb)+1];
        // cout << msb << " " << u << " " << v << endl;

        int x = tin[u];
        int y = tout[v];
        if (x>y) swap(x,y);
        int delta = y-x+1;
        msb = 63-__builtin_clzll(delta);
        int ans = max(st[msb][x],st[msb][y-(1<<msb)+1]);
        cout << max(0LL,val[ans]-k) << " ";
    }
    cout << endl;
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

