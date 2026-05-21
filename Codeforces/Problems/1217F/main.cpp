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
typedef pair<pii, pii> piiii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

mt19937_64 rd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,m,k;
vector<pii> nen;

pii prev_edge(pii e) {
    e.fi = (e.fi-2+n)%n+1;
    e.se = (e.se-2+n)%n+1;
    if (e.fi > e.se) swap(e.fi,e.se);
    return e;
}

pii next_edge(pii e) {
    e.fi = (e.fi%n)+1;
    e.se = (e.se%n)+1;
    if (e.fi > e.se) swap(e.fi,e.se);
    return e;
}

int getidx(pii e) {
    int pos = lower_bound(all(nen),e) - nen.begin() + 1;
    return pos;
}

struct upt{
    int pos,eid,pid,state;
    
    upt(int a=0, int b=0, int c=0, int d=0) {
        pos = a;
        eid = b;
        pid = c;
        state = d;
    }

    bool operator <(const upt &other) {
        return (pos < other.pos);
    }
};

struct cmp {
    bool operator()(const upt& p1, const upt& p2) const {
        return p1.pos > p2.pos; 
    }
};


priority_queue<upt,vector<upt>,cmp> pq;

struct DSU{
    int n = 0;
    vector<int> par;
    vector<int> sz;
    vector<pair<int&, int>> hist;
    void init(int _n) {
        n = _n;
        par.clear(); sz.clear();
        par.resize(_n+1,0);
        iota(all(par),0);
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
            hist.push_back({sz[u],sz[u]});
            sz[u] += sz[v];
            hist.push_back({par[v],par[v]});
            par[v] = u;
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

int last = 0;
int pq_idx = 0;

map<pii,int> mp;

vector<pair<int,pii>> edges;
pii ask[N];
int pre[2*N];
vector<int> ans;
vector<pii> pts[2*N];

struct SegmentTree {
    int n;
    vector<vector<pii>> query;

    void init(int _n) {
        n = _n;
        query.resize(4*_n+10);
    }

    void add(int idx, int l, int r, int x, int y, pii val) {
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
        int ver = DSU.snapshot();
        for (auto [u,v]:query[idx]) {
            DSU.merge(u,v);
        }
        
        if (l==r) {
            if (ask[l].fi != 0) {
                if (last == 1) {
                    ask[l] = next_edge(ask[l]);
                }
                int u = DSU.find(ask[l].fi);
                int v = DSU.find(ask[l].se);

                if (u==v) {
                    last = 1;
                }
                else last = 0;
                ans.push_back(last);
            }

            while (!pq.empty() && pq.top().pos <= l) {
                auto [pos,eid,pid,state] = pq.top();
                pq.pop();

                if (pid+1 == pts[eid].size()) continue;

                ++pid;
                int l = pts[eid][pid].fi;
                int r = (pid+1 == pts[eid].size()) ? m : pts[eid][pid+1].fi-1;


                if (pts[eid][pid].se == last) state = (state^1);
                if (state == 1) {
                    add(1,1,m,l,r,nen[eid-1]);
                }

                upt tmp = {r,eid,pid,state};
                pq.push(tmp);
            }

            DSU.rollback(ver);
            return;
        }

        int mid = (l+r)/2;
        iterate(idx*2,l,mid);
        iterate(idx*2+1,mid+1,r);
        DSU.rollback(ver);
    }
} IT;



void solve(){
    cin >> n >> m;

    for (int i=1; i<=m; i++){
        int id; cin >> id;
        pii e; cin >> e.fi >> e.se;
        if (e.fi > e.se) swap(e.fi,e.se);
        if (id == 2) {
            ask[i] = e;
            continue;
        }
        edges.push_back({i,e});

        nen.push_back(e);
        nen.push_back(next_edge(e));
    }

    sort(all(nen));
    nen.resize(unique(all(nen))-nen.begin());
    k = nen.size();

    for (int i=1; i<=k; i++){
        pre[i] = 1;
        pts[i].push_back({0,0});
    }

    for (int i=0; i<edges.size(); i++) {
        auto [pos,e] = edges[i];
        pts[getidx(e)].push_back({pos,0});
        e = next_edge(e);
        pts[getidx(e)].push_back({pos,1});
    }

    for (int i=1; i<=k; i++){
        if (pts[i].size() == 1) {
            pq.push({m,i,0,0});
        }
        else {
            pq.push({pts[i][1].fi-1,i,0,0});
        }
    }

    DSU.init(n);
    IT.init(m);

    while (!pq.empty() && pq.top().pos <= 0) {
        auto [pos,eid,pid,state] = pq.top();
        pq.pop();

        if (pid+1 == pts[eid].size()) continue;

        ++pid;
        int l = pts[eid][pid].fi;
        int r = (pid+1 == pts[eid].size()) ? m : pts[eid][pid+1].fi-1;


        if (pts[eid][pid].se == last) state = (state^1);
        if (state == 1) {
            IT.add(1,1,m,l,r,nen[eid-1]);
        }

        upt tmp = {r,eid,pid,state};
        pq.push(tmp);
    }

    IT.iterate(1,1,m);

    for (int i=0; i<ans.size(); i++){
        cout << ans[i];
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

