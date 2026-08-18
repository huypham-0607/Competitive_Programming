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
int par[N];
vector<int> child[N];
int score[N];

struct DSU{
    int n;
    vector<int> parent;
    vector<int> val;
    vector<int> cnt;


    void init(int _n){
        n = _n;
        parent.clear();parent.resize(n+1,0);
        val.clear();val.resize(n+1,0);
        cnt.clear();cnt.resize(n+1,0);

        for (int i=1; i<=n; i++){
            par[i] = i;
            child[i].clear();
            score[i] = 0;
            parent[i] = i;
        }
    }

    int find(int x){
        return (x == parent[x])? x : parent[x] = find(parent[x]);
    }

    bool isSame(int u, int v){
        return (find(u) == find(v));
    }

    void merge(int u, int v, int w){
        u = find(u);
        v = find(v);
        if (u!=v){
            ++n;
            par[n] = n;
            score[n] = 0;
            child[n].clear();
            parent.push_back(n);
            val.push_back(0);
            cnt.push_back(0);

            val[n] = w;
            cnt[n] = cnt[u] + cnt[v];

            score[u] += (val[n] - val[u]) * cnt[u];
            score[v] += (val[n] - val[v]) * cnt[v];

            child[n].push_back(u);
            child[n].push_back(v);
            par[u] = par[v] = n;
            parent[u] = parent[v] = n;
        }
    }
} DSU;


int buffer[N];
int pref[N];
vector<pair<int,pii>> edges;
int n,m,q;
int cand[N];
int ans[N];

void flush(int u) {
    pref[u] += buffer[u];
    for (auto v:child[u]) {
        buffer[v] += buffer[u];
        flush(v);
    }
    buffer[u] = 0;
}

int cur_val = 0;

void load(int u) {
    // cout << "load: " << u << endl;
    buffer[u] -= score[u];
    cur_val -= score[u];
    score[u] = 0;
    if (u!=par[u]) {
        load(par[u]);
    }
}

void solve(){
    cin >> n >> m >> q;
    edges.clear();
    DSU.init(n);
    ffor(i,1,q) {
        int x; cin >> x;
        cand[i] = x;
        DSU.cnt[x] = 1;
    }
    for (int i=1; i<=m; i++){
        int u,v,w; cin >> u >> v >> w;
        edges.push_back({w,{u,v}});
    }
    sort(all(edges));

    for (auto [w,in] : edges){
        // cout << in.fi << " " << in.se << " " << w << endl;
        DSU.merge(in.fi,in.se,w);
    }

    for (int i=1; i<=DSU.n; i++){
        pref[i] = 0;
        cur_val += score[i];
        buffer[i] += score[i];
    }
    flush(DSU.n);

    // cout << cur_val << endl;
    // for (int i=1; i<=DSU.n; i++){
    //     for (auto x:child[i]){
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }
    // for (int i=1; i<=DSU.n; i++){
    //     cout << score[i] << " " << DSU.cnt[i] << " " <<DSU.val[i] << endl; 
    // }
    // cout << endl;
    // for (int i=1; i<=DSU.n; i++){
    //     cout << pref[i] << " ";
    // }
    // cout << endl;
    ffor(i,1,n) ans[i] = 0;
    for (int i=1; i<=q; i++){
        pii mx = {-LLINF,0};
        for (int idx=1; idx<=q; idx++){
            if (make_pair(pref[cand[idx]],cand[idx]) > mx) {
                mx = make_pair(pref[cand[idx]],cand[idx]);
            }
        }

        // cout << mx.fi << " " << mx.se << endl;
        load(mx.se);
        // for (int i=1; i<=DSU.n; i++){
        //     cout << buffer[i] << " ";
        // }
        // cout << endl;
        flush(DSU.n);
        // for (int i=1; i<=DSU.n; i++){
        //     cout << pref[i] << " ";
        // }
        // cout << endl;

        ans[i] = cur_val;
    }
    for (int i=1; i<=n; i++){
        cout << ans[i] << " ";
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

