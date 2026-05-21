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
typedef pair<int, pii> piii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

mt19937_64 rd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 3e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int q,n;
int ans[N];

//DSU
struct DSU{
    int n = 0;
    int sum = 0;
    vector<int> par;
    vector<int> val;
    vector<int> sz;
    vector<pair<int&, int>> hist;
    void init(int _n) {
        n = _n;
        sum = 0;
        par.clear(); val.clear(); sz.clear();
        par.resize(_n+1,0);
        iota(all(par),0);
        val.resize(_n+1,0);
        sz.resize(_n+1,1);
        hist.clear();
    }

    int find(int x) {
        return (par[x] == x) ? x : find(par[x]); 
    }

    void merge(int u, int v){
        u = find(u);
        v = find(v);
        if (sz[v] > sz[u]) swap(u, v);
        if (u != v) {
            int nval = val[u] + val[v] - 1;
            int nsum = sum - val[u]*sz[u] - val[v]*sz[v] + nval*(sz[u]+sz[v]);
            hist.push_back({sum, sum});
            sum = nsum;
            hist.push_back({val[u],val[u]});
            val[u] = nval;
            hist.push_back({sz[u],sz[u]});
            sz[u] += sz[v];
            hist.push_back({par[v],par[v]});
            par[v] = u;
        }
        else {
            int nval = val[u] - 1;
            int nsum = sum - val[u]*sz[u] + nval*(sz[u]);
            hist.push_back({sum, sum});
            sum = nsum;
            hist.push_back({val[u],val[u]});
            val[u] = nval; 
        }
    }

    void addVal(int u) {
        u = find(u);
        int nval = val[u] + 1;
        int nsum = sum - val[u]*sz[u] + nval*sz[u];
        hist.push_back({sum, sum});
        sum = nsum;
        hist.push_back({val[u],val[u]});
        val[u] = nval; 
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

struct SegmentTree {
    int n;
    vector<vector<piii>> query;

    void init(int _n) {
        n = _n;
        query.resize(4*_n+10);
    }

    void add(int idx, int l, int r, int x, int y, piii val) {
        // if (idx == 1) {
        //     cerr << x << " " << y << " " << val.fi << " " << val.se.fi << " " << val.se.se << endl;
        // }
        if (r < x || y < l) return;
        if (x <= l && r <= y) {
            query[idx].push_back(val);
            return;
        }

        int mid = (l+r)/2;
        add(idx*2,l,mid,x,y,val);
        add(idx*2+1,mid+1,r,x,y,val);
    }

    void iterate(int idx, int l, int r) {
        // cout << "idx: " << idx << " " << l << " " << r << endl;
        int ver = DSU.snapshot();
        for (auto [tmp,in]:query[idx]) {
            auto [x,y] = in;
            // cout << tmp << " " << x << " " << y << endl;
            if (y == 0) DSU.addVal(x);
            else DSU.merge(x,y);
        }
        
        if (l==r) {
            ans[l] = DSU.sum;
            DSU.rollback(ver);
            return;
        }

        int mid = (l+r)/2;
        iterate(idx*2,l,mid);
        iterate(idx*2+1,mid+1,r);
        DSU.rollback(ver);
    }
} IT;

set<int> st[N];
map<pair<int,pii>,int> mp;

void solve(){
    cin >> q;
    n = q;

    IT.init(n);
    DSU.init((int)3e5);

    for (int i=1; i<=q; i++) {
        int x,y; cin >> x >> y;
        // cerr << "i: " << i << " " << x << " " << y << endl;
        auto it = st[y].lower_bound(x);
        if (it!=st[y].end() && (*it) == x) {
            auto nit = next(it);

            IT.add(1,1,n,mp[{y,{x,0}}],i-1,{y,{x,0}});
            mp.erase({y,{x,0}});
            if (it!=st[y].begin()) {
                auto pit = prev(it);
                piii key = {y,{(*pit),x}};
                int pos = mp[key];
                mp.erase(key);
                IT.add(1,1,n,pos,i-1,key);
            }
            if (nit!=st[y].end()) {

                piii key = {y,{x,(*nit)}};
                int pos = mp[key];
                mp.erase(key);
                IT.add(1,1,n,pos,i-1,key);
            }
            if (it!=st[y].begin() && nit!=st[y].end()) {
                auto pit = prev(it);
                piii key = {y,{(*pit),(*nit)}};
                mp[key] = i; 
            }
            st[y].erase(x);
        } else {
            if (it!=st[y].end() && it!=st[y].begin()) {
                auto pit = prev(it);
                int r = (*it);
                int l = (*pit);
                piii key = {y,{l,r}};
                int pos = mp[key];
                mp.erase(key);
                IT.add(1,1,n,pos,i-1,key);
            }
            if (it!=st[y].end()) {
                mp[{y,{x,(*it)}}] = i;
            }
            if (it!=st[y].begin()) {
                auto pit = prev(it);
                mp[{y,{(*pit),x}}] = i;
            }
            mp[{y,{x,0}}] = i;
            st[y].insert(x);
        }
    }
    for (auto it = mp.begin(); it!=mp.end(); it++) {
        piii key = it->fi;
        IT.add(1,1,n,it->se,q,key);
    }

    IT.iterate(1,1,n);
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
//    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

