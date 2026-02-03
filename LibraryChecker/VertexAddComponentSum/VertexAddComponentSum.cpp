/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT "VACS"

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
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

struct DSU {
    int n;
    vector<int> parent;
    vector<int> sum;
    vector<int> size;
    vector<pair<int&, int>> history;

    void init (int _n) {
        n = _n;
        parent.resize(n);
        sum.resize(n,0);
        size.resize(n,1);

        iota(all(parent),0);
    }

    int find(int x) {
        return (x==parent[x])? x : find(parent[x]);
    }

    void merge(int x, int y) {
        int u = find(x);
        int v = find(y);
        // cerr << u << " " << v << endl;
        if (size[u] < size[v]) swap(u,v);

        if (u!=v) {
            history.push_back({parent[v],parent[v]});
            history.push_back({sum[u],sum[u]});
            history.push_back({size[u],size[u]});

            size[u] += size[v];
            sum[u] += sum[v];
            parent[v] = parent[u];
        }
    }

    void add(int x, int val) {
        int u = find(x);
        history.push_back({sum[u],sum[u]});
        sum[u]+=val;
    }

    int snapshot() {
        return history.size();
    }

    void roll_back(int ver) {
        while (history.size() > ver) {
            history.back().fi = history.back().se;
            history.pop_back();
        }
    }
} dsu;

int n,q;
int ans[N];

struct LazySegmentTree{
    int n;
    vector<vector<pair<int,pii>>> query;

    LazySegmentTree(int _n) {
        n = _n;
        query.resize(n*4+10);
    }

    void addQuery(int idx, int l, int r, int x, int y, pair<int,pii> val){
        // cerr << l << " " << r << " " << x << " " << y << endl;
        if (y < l || r < x) return;
        if (x <= l && r <= y){
            query[idx].push_back(val);
            return;
        }

        int mid = (l+r)/2;
        addQuery(idx*2,l,mid,x,y,val);
        addQuery(idx*2+1,mid+1,r,x,y,val);
    }

    void dfs(int idx, int l, int r) {
        // cerr << idx << " " << l << " " << r << endl;
        int ver = dsu.snapshot();
        for (auto in:query[idx]) {
            int id = in.fi;
            auto [x,y] = in.se;

            if (id == 0) {
                dsu.merge(x,y);
            }
            if (id == 1) {
                dsu.add(x,y);
            }
        }
        for (auto in:query[idx]) {
            int id = in.fi;
            auto [x,y] = in.se;

            if (id == 2) {
                int u = dsu.find(x);
                ans[y] = dsu.sum[u];
            }
        }
        if (l<r) {
            int mid = (l+r)/2;
            dfs(idx*2,l,mid);
            dfs(idx*2+1,mid+1,r);
        }

        dsu.roll_back(ver);
    }
};


void solve(){
    cin >> n >> q;
    dsu.init(n);
    for (int i=0; i<n; i++){
        int x; cin >> x;
        dsu.add(i,x);
    }

    LazySegmentTree IT(q);

    int ansCnt = 0;

    map<pii,int> mp;
    for (int i=1; i<=q; i++){
        int id,x,y; cin >> id;
        if (id == 0) {
            cin >> x >> y;
            if (x>y) swap(x,y);
            mp[make_pair(x,y)] = i;
        }
        if (id == 1) {
            cin >> x >> y;
            if (x>y) swap(x,y);
            int prev = mp[make_pair(x,y)];
            mp.erase(make_pair(x,y));
            // cerr << prev << " " << i-1 << " " << x << " " << y << endl;
            IT.addQuery(1,1,q,prev,i-1,make_pair(0,make_pair(x,y)));
        }
        if (id == 2) {
            cin >> x >> y;
            // cerr << i << " " << q << endl;
            IT.addQuery(1,1,q,i,q,make_pair(1,make_pair(x,y)));
        }
        if (id == 3) {
            cin >> x;
            IT.addQuery(1,1,q,i,i,make_pair(2,make_pair(x,ansCnt)));
            ++ansCnt;
        }
    }
    for (auto it = mp.begin(); it!=mp.end(); it++){
        auto edge = it->fi;
        int prev = it->se;
        IT.addQuery(1,1,q,prev,q,make_pair(0,edge));
    }
    IT.dfs(1,1,q);

    for (int i=0; i<ansCnt; i++){
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

