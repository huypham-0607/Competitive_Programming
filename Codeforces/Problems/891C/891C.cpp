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

const int N = 5e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,m,q;

struct DSU{ 
    int n;
    int parent[N];
    int sz[N];
    int cmp;
    vector<pair<int&,int>> hist;

    void init(int _n) {
        n = _n;
        hist.clear();
        cmp = 0;
        for (int i=1; i<=n; i++){
            parent[i] = i;
            sz[i] = 1;
        }
    }

    int find(int x) {
        return ((x == parent[x]) ? x : find(parent[x]));
    }

    void merge(int u, int v) {
        u = find(u);
        v = find(v);
        if (sz[u] < sz[v]) swap(u,v);

        if (u != v) {
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

int sat[N];
vector<pair<int,pii>> query[N];
int it[N];

void solve(){
    cin >> n >> m;
    vector<pair<int,pii>> edges;
    for (int i=1; i<=m; i++){
        int u,v,w; cin >> u >> v >> w;
        edges.push_back({w,{u,v}});
    }

    DSU.init(n);

    priority_queue<pii,vector<pii>,greater<pii>> pq;
    cin >> q;
    for (int i=1; i<=q; i++){
        int k; cin >> k;
        sat[i] = true;
        it[i] = 0;
        for (int idx=1; idx<=k; idx++) {
            int x; cin >> x;
            query[i].push_back(edges[x-1]);
        }
        sort(all(query[i]));
        pq.push({query[i][0].fi,i});
    }

    sort(all(edges));
    int idx = 0;

    for (int w = 1; w<=N; w++){
        while (!pq.empty() && pq.top().fi == w) {
            int id = pq.top().se;
            pq.pop();

            int prev_cmp = DSU.cmp;
            int ver = DSU.snapshot();
            int cnt = 0;

            // cout << "id: " << id << " " << w << " " << ver << " " << query[id].size() << endl;

            while (it[id] != query[id].size() && query[id][it[id]].fi == w) {
                auto [u,v] = query[id][it[id]].se;
                DSU.merge(u,v);

                // cout << u << " " << v << endl;

                ++cnt;
                it[id]++;
            }

            // cout << "summ: " << prev_cmp << " " << DSU.cmp << " " << cnt << endl;
            if (prev_cmp - DSU.cmp < cnt) sat[id] = 0;

            DSU.rollback(ver);

            if (it[id] != query[id].size()) {
                pq.push({query[id][it[id]].fi,id});
            }
        }

        while (idx!=edges.size() && edges[idx].fi == w) {
            auto [u,v] = edges[idx].se;

            DSU.merge(u,v);
            ++idx;
        }
    }

    for (int i=1; i<=q; i++){
        if (sat[i]) {
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
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

