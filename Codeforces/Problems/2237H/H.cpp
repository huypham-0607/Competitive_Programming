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
const long long LLINF = 1e18+3;

// If pref[idx] > 0
// offset += pref[idx];

struct SegmentTree{
    struct Node{
        int mx,mn,val;
        Node(){
            val = 0;
            mx = -INF;
            mn = -INF;
        }
    };

    int n;
    vector<Node> IT;
    vector<int> lazyAdd;
    vector<int> lazyInc;
    vector<int> lazySet;

    void applySet(int idx, int val, int l, int r) {
        lazyInc[idx] = 0;
        lazyAdd[idx] = 0;
        IT[idx].mn = IT[idx].mx = val;
        IT[idx].val = max(0LL,val)*(r-l+1);
        lazySet[idx] = val;
    }

    void applyInc(int idx, int val, int l, int r) {
        IT[idx].mn += val;
        IT[idx].mx += val;
        lazyInc[idx] += val;
    }

    void applyAdd(int idx, int val, int l, int r) {
        IT[idx].mn += val;
        IT[idx].mx += val;
        IT[idx].val += val*(r-l+1);
        lazyAdd[idx] += val;
    }

    void propagate(int idx, int l, int r){
        if (lazySet[idx] != -INF) {
            int val = lazySet[idx];
            applySet(idx*2,val,l,r);
            applySet(idx*2+1,val,l,r);
            lazySet[idx] = -INF;
        }
        if (lazyInc[idx] != 0) {
            int val = lazyInc[idx];
            applyInc(idx*2,val,l,r);
            applyInc(idx*2+1,val,l,r);
            lazyInc[idx] = 0;
        }
        if(lazyAdd[idx] != 0) {
            int val = lazyAdd[idx];
            applyAdd(idx*2,val,l,r);
            applyAdd(idx*2+1,val,l,r);
            lazyInc[idx] = 0;
        }
    }

    void comb(Node& i, Node& l, Node& r){
        i.val = l.val + r.val;
        i.mx = max(l.mx,r.mx);
        i.mn = min(l.mn,r.mn);
    }

    void init(int _n) {
        n = _n;
        IT.clear(); IT.resize(n*4+10, Node());
        lazySet.clear(); lazySet.resize(n*4+10, 0);
        lazyInc.clear(); lazyInc.resize(n*4+10, 0);
        lazyAdd.clear(); lazyAdd.resize(n*4+10, 0);
        build(1,1,n);
    }

    void build(int idx, int l, int r){
        if (l==r){
            IT[idx].val = 0;
            IT[idx].mx = IT[idx].mn = -INF;
            return;
        }

        int mid = (l+r)/2;
        build(idx*2,l,mid);
        build(idx*2+1,mid+1,r);
        comb(IT[idx],IT[idx*2],IT[idx*2+1]);
    }

    void update(int idx, int l, int r, int x, int y, int val){
        if (y < l || r < x) return;
        if (x <= l && r <= y){
            if (IT[idx].mn >= 0){
                applyAdd(idx,val,l,r);
                return;
            }
            if (IT[idx].mx < -val) {
                applyInc(idx,val,l,r);
                return;
            }
            if (IT[idx].mx == IT[idx].mn) {
                applySet(idx,IT[idx].mx+val,l,r);
                return;
            }
        }

        propagate(idx,l,r);

        int mid = (l+r)/2;
        update(idx*2,l,mid,x,y,val);
        update(idx*2+1,mid+1,r,x,y,val);
        comb(IT[idx],IT[idx*2],IT[idx*2+1]);
    }

    void updateSet(int idx, int l, int r, int x, int val) { 
        if (x < l || r < x) return;
        if (l==r) {
            applySet(idx,val,l,r);
            return;
        }

        propagate(idx,l,r);

        int mid = (l+r)/2;
        updateSet(idx*2,l,mid,x,val);
        updateSet(idx*2+1,mid+1,r,x,val);
        comb(IT[idx],IT[idx*2],IT[idx*2+1]);
    }


    int getVal(int idx, int l, int r, int x){
        if (x < l || r < x) return -INF;
        if (l==r){
            return IT[idx].mx;
        }

        propagate(idx,l,r);

        int mid = (l+r)/2;
        return max(getVal(idx*2,l,mid,x),getVal(idx*2+1,mid+1,r,x));
    }
    
    int getAns() {
        return IT[1].val;
    }

} IT;

int lol = 0;
int delta[N];
int sing[N],doub[N];
vector<int> cache;

struct LazySegmentTree{
    struct Node{
        int mx,mn;
        Node(){
            mx = 0;
            mn = 0;
        }
    };

    int n;
    vector<Node> IT;
    vector<int> lazy;

    void applySet(int idx, int val) {
        IT[idx].mx = IT[idx].mn = val;
        lazy[idx] = val;
    }

    void propagate(int idx){
        if (lazy[idx] != 0) {
            int val = lazy[idx];
            //Update idx*2
            applySet(idx*2,val);
            //Update idx*2+1
            applySet(idx*2+1,val);
        }
        //Reset idx
        lazy[idx] = 0;
    }

    void comb(Node& i, Node& l, Node& r){
        i.mx = max(l.mx,r.mx);
        i.mn = min(l.mn,r.mn);
    }

    void init(int _n) {
        n = _n;
        IT.clear();
        IT.resize(n*4+10, Node());
        lazy.clear();
        lazy.resize(n*4+10, 0);
        build(1,1,n);
    }

    void build(int idx, int l, int r){
        if (l==r){
            IT[idx].mx = 0;
            IT[idx].mn = 0;
            return;
        }

        int mid = (l+r)/2;
        build(idx*2,l,mid);
        build(idx*2+1,mid+1,r);
        comb(IT[idx],IT[idx*2],IT[idx*2+1]);
    }

    void update(int idx, int l, int r, int x, int y, int val){
        if (y < l || r < x) return;
        if (x <= l && r <= y && IT[idx].mx == IT[idx].mn){
            delta[IT[idx].mx]+=(r-l+1);
            if (IT[idx].mx == 0) lol += (r-l+1);
            if (IT[idx].mx > 0) cache.push_back(IT[idx].mx);
            delta[val]-=(r-l+1);
            if (val > 0) cache.push_back(val);
            applySet(idx,val);
            return;
        }

        propagate(idx);

        int mid = (l+r)/2;
        update(idx*2,l,mid,x,y,val);
        update(idx*2+1,mid+1,r,x,y,val);
        comb(IT[idx],IT[idx*2],IT[idx*2+1]);
    }
} LIT;

int n,m,q;
int s[N];
int is_slime[N];
vector<int> adj[N];

const int LG_LCA = 17;

int up[LG_LCA][N];
int depth[N];

void dfsLCA(int u, int p=0){
    up[0][u] = p;
    for (int lg=1; lg<LG_LCA; lg++){
        int v = up[lg-1][u];
        up[lg][u] = up[lg-1][v];
    }
    for (auto v:adj[u]){
        depth[v] = depth[u]+1;
        if (v==p) continue;
        dfsLCA(v,u);
    }
}

int binLift(int u){
    if (is_slime[u]) return 0;
    int res = 0;
    for (int lg=LG_LCA-1; lg>=0; lg--){
        if (!is_slime[up[lg][u]]) {
            res += (1<<lg);
            u = up[lg][u];
        }
    }
    return res+1;
}

int curpos = 0;
int parent[N], sz[N];
int root[N], pos[N];

void dfsHLD(int u, int p=0){
    sz[u] = 1;
    for (auto v:adj[u]){
        if (v==p) continue;
        parent[v] = u;
        depth[v] = depth[u]+1;
        dfsHLD(v,u);
        sz[u] += sz[v];
    }
}

void buildHLD(int u, int r){
    pos[u] = ++curpos;
    root[u] = r;

    int nxt = 0;

    for (auto v:adj[u]){
        if (v==parent[u]) continue;
        if (!nxt || sz[v]>sz[nxt]) nxt = v;
    }

    if (nxt){
        buildHLD(nxt,r);
    }

    for (auto v:adj[u]){
        if (v==parent[u] || v==nxt) continue;
        buildHLD(v,v);
    }
}

int is_updated[N];

void clear_cache(int q) {

    for (auto x:cache){
        // cerr << x << endl;
        if (!is_updated[x]) {
            if (delta[x]!=0){
                IT.update(1,1,n,x,q,delta[x]);
                delta[x] = 0;
            }
            is_updated[x] = 1;
        }
    }
    for (auto x:cache) is_updated[x] = 0;
    cache.clear();
}

void updateHLD(int u, int v, int val){

    while (root[u]!=root[v]){
        if (depth[v] > depth[u]) swap(v,u);
        int r = root[u];
        
        // IT update from pos[r] to pos[u]
        LIT.update(1,1,n,pos[r],pos[u],val);

        u = parent[r];
    }
    if (depth[v] > depth[u]) {
        // IT update from pos[u] to pos[v]
        LIT.update(1,1,n,pos[u],pos[v],val);
    }
    else {
        // IT update from pos[v] to pos[u]
        LIT.update(1,1,n,pos[v],pos[u],val);
    }
}

void print_tree(int q) {
    for (int i=1; i<=q; i++){
        cerr << IT.getVal(1,1,n,i) << " ";
    }
    cerr << endl;
}

void solve(){
    cin >> n >> m >> q;
    cache.clear();
    lol = 0;
    curpos = 0;
    for (int i=0; i<=n; i++){
        sz[i] = 0;
        root[i] = 0;
        parent[i] = 0;
        depth[i] = 0;
        is_updated[i] = 0;
        adj[i].clear();
        is_slime[i] = 0;
        sing[i] = 0;
        doub[i] = 0;
    }
    is_slime[0] = 1;


    for (int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ffor(i,1,m) {
        cin >> s[i];
        is_slime[s[i]] = 1;
    }
    // cerr << s[1] << endl;
    dfsLCA(s[1]);
    dfsHLD(s[1]);
    buildHLD(s[1],s[1]);

    LIT.init(n);
    IT.init(n);
    for (int i=1; i<=m; i++){
        LIT.update(1,1,n,pos[s[i]],pos[s[i]],1);
    }
    lol-=m;

    int x; cin >> x;
    delta[1] += binLift(x);
    cerr << x << " " << binLift(x) << endl;
    cache.push_back(1);
    int y = x;
    if (!is_slime[y]) {
        for (int lg=LG_LCA-1; lg>=0; lg--){
            if (!is_slime[up[lg][y]]) y = up[lg][y];
        }
        updateHLD(x,y,1);
    }
    cerr << "delta: " << delta[1] << endl;
    IT.updateSet(1,1,n,1,delta[1]); delta[1] = 0;

    clear_cache(1);

    int ans = lol+IT.getAns();
    cout << ans << " ";

    cerr << "ans: " << ans << " " << lol <<  endl;
    print_tree(1);

    int prev = x;
    for (int i=2; i<=q; i++){
        int p; cin >> p;
        int x = (p-1+ans)%n+1;

        delta[i] += binLift(x);
        cerr << x << " " << binLift(x) << endl;
        cache.push_back(i);
        // cerr << "passed bin lift" << endl;
        updateHLD(prev,x,i);
        // cerr << "passed hld" << endl;
        int pref = IT.getVal(1,1,n,i-1);
        cerr << "delta: " << pref+delta[i] << endl;
        IT.updateSet(1,1,n,i,pref+delta[i]); delta[i] = 0;
        clear_cache(i);

        ans = lol+IT.getAns();
        cout << ans << " ";
        prev = x;

        cerr << "ans: " << x << " " << ans << " " << lol << " " << IT.getAns() << endl;
        print_tree(i);
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

