/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#pragma GCC optimize("Ofast")
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
// #define int long long

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

mt19937_64 rd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 1e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n,q;
int a[N];
vector<int> adj[N];

const int LG_LCA = 17;
const int LG = 20;

struct depth_table{
    int sz;
    ll val;
    int pref_bound, suf_bound;
    vector<int> pref;
    vector<int> suf;

    depth_table() {
        val = 0;
        sz = 0;
        pref_bound = INF;
        suf_bound = INF;
    }
    depth_table(bool b) {
        val = 0;
        sz = 0;
        pref.resize(LG);
        suf.resize(LG);
        pref_bound = INF;
        suf_bound = INF;
    }
    depth_table(int x) {
        val = 1;
        sz = 1;
        pref.resize(LG);
        suf.resize(LG);
        pref_bound = INF;
        suf_bound = INF;
        for (int idx=0; idx<LG; idx++){
            pref[idx] = suf[idx] = ((x&(1<<idx))?sz:sz+1);
        }
    }

    void invert() {
        swap(pref,suf);
        swap(pref_bound,suf_bound);
    }
};

void comb(depth_table &l, depth_table &r, depth_table &res) {
    if (l.sz == 0) {
        res = r;
        return;
    }
    if (r.sz == 0) {
        res = l;
        return;
    }

    res.pref.resize(LG);
    res.suf.resize(LG);
    
    vector<int> ele(LG); iota(all(ele),0);
    sort(all(ele),[&](int x, int y) {return l.suf[x] < l.suf[y];});

    ll sum = 0;

    int prev = 1;
    int mn = min(r.sz+1,r.pref_bound);
    int pos = 0;

    while (pos<ele.size()) {
        int x = l.suf[ele[pos]];
        if (x>min(l.sz+1,l.suf_bound)) break;
        int delta = x-prev;
        sum += (ll)delta*(mn-1);

        while (pos < ele.size() && l.suf[ele[pos]] == x){
            mn = min(mn,r.pref[ele[pos]]);
            ++pos;
        }
        prev = x;
    }

    sum += (min(l.sz+1,l.suf_bound) - prev) * (mn-1);

    res.val = l.val + r.val;
    res.val += sum;
    res.sz = l.sz + r.sz;
    res.pref_bound = min(l.pref_bound,l.sz + r.pref_bound);
    res.suf_bound = min(r.sz + l.suf_bound,r.suf_bound);
    for (int idx=0; idx<LG; idx++){
        res.pref[idx] = ((l.pref[idx] == l.sz+1)?r.pref[idx]+l.sz:l.pref[idx]);
        if (l.pref[idx] != l.sz+1 && r.pref[idx] != r.sz+1) res.pref_bound = min(res.pref_bound,r.pref[idx]+l.sz);
    }
    for (int idx=0; idx<LG; idx++){
        res.suf[idx] = ((r.suf[idx] == r.sz+1)?l.suf[idx]+r.sz:r.suf[idx]);
        if (r.suf[idx] != r.sz+1 && l.suf[idx] != l.sz+1) res.suf_bound = min(res.suf_bound,l.suf[idx]+r.sz);
    }
}

int up[LG_LCA][N];
depth_table bit_depth[LG_LCA][N];
int depth[N];

void pbd(depth_table &x) {
    cout << x.val << " " << x.sz << " " << x.pref_bound << " " << x.suf_bound << endl;
    for (int idx=0; idx<x.pref.size(); idx++){
        cout << x.pref[idx] << " ";
    }
    cout << "| ";
    for (int idx=0; idx<x.suf.size(); idx++){
        cout << x.suf[idx] << " ";
    }
    cout << endl;
}

void dfsLCA(int u, int p=0){
    // cerr << u << endl;
    depth[u] = depth[p]+1;
    up[0][u] = p;
    bit_depth[0][u] = depth_table(a[u]);
    for (int lg=1; lg<LG_LCA; lg++){
        int v = up[lg-1][u];
        // cerr << lg << " " << v << endl;
        up[lg][u] = up[lg-1][v];
        if (up[lg-1][u] == 0 && up[lg][u] == 0) continue;
        comb(bit_depth[lg-1][u],bit_depth[lg-1][v],bit_depth[lg][u]);
        // cerr << "passed precomp for iter" << endl;
    }
    for (auto v:adj[u]){
        if (v==p) continue;
        dfsLCA(v,u);
    }
}

int binLift(int u, int x){
    for (int lg=0; lg<LG_LCA; lg++){
        if ((1<<lg)&x) u = up[lg][u];
    }
    return u;
}

int getLCA(int u, int v){
    if (depth[u]>depth[v]) swap(u,v);
    v = binLift(v,depth[v]-depth[u]);
    if (u==v) return u;
    for (int lg=LG_LCA-1; lg>=0; lg--){
        if (up[lg][u]!=up[lg][v]){
            u = up[lg][u];
            v = up[lg][v];
        }
    }
    return up[0][u];
}

depth_table tmp;
void get_bit_depth(int s, int x, depth_table &res) {
    // cout << "gbd: " << s << " " << x << endl;
    res.sz = 0;
    int u = s;
    for (int lg=0; lg<LG_LCA; lg++){
        if ((1<<lg)&x) {
            // cout << "lg: " << lg << u << endl;
            comb(res,bit_depth[lg][u],tmp); swap(tmp,res);
            // pbd(res);
            u = up[lg][u];
        }
    }
}

void solve(){
    cin >> n >> q;
    for (int i=1; i<=n; i++){
        adj[i].clear();
    }
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    for (int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfsLCA(1,0);
    // cerr << "passed lca precomp" << endl;
    // for (int i=1; i<=n; i++){
    //     cout << "i: " << i << endl;
    //     for (int lg=0; lg<LG_LCA; lg++){
    //         cout << bit_depth[lg][i].val << " " << bit_depth[lg][i].sz << " " << bit_depth[lg][i].pref_bound << " " << bit_depth[lg][i].suf_bound << endl;
    //         for (int idx=0; idx<LG; idx++){
    //             cout << bit_depth[lg][i].pref[idx] << " ";
    //         }
    //         cout << "| ";
    //         for (int idx=0; idx<LG; idx++){
    //             cout << bit_depth[lg][i].suf[idx] << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }
    depth_table l(true),r(true),tmp(true);
    while (q--){
        int u,v; cin >> u >> v;
        int lca = getLCA(u,v);
        get_bit_depth(u,depth[u]-depth[lca]+1,l);
        get_bit_depth(v,depth[v]-depth[lca],r);
        r.invert();
        comb(l,r,tmp);

        cout << tmp.val << endl;
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
   cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

