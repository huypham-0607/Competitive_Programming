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

const int N = 2e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

namespace Comb {
    using ll = long long;

    const int MD = 1e9+7;
    const int N = 2e5;
    const int LG = 30;

    int invFac[N+1];
    int fac[N+1];

    int binPow(int a, int b){
        ll res = 1;
        for (int lg = LG-1; lg>=0; lg--){
            res = res*res%MD;
            if ((1LL<<lg)&b) res = res*a%MD;
        }
        return res;
    }

    int invMod(int x, int MD){
        return binPow(x,MD-2);
    }

    int nCk(int n, int k){
        return 1LL*fac[n]*invFac[k]%MD*invFac[n-k]%MD;
    }

    struct Init {
        Init() {
            fac[0] = 1;
            invFac[0] = 1;
            for (int i = 1; i <= N; i++){
                fac[i] = (1LL*fac[i-1]*i%MD);
                invFac[i] = invMod(fac[i],MD);
            }
        }
    } _init;
}

struct LazySegmentTree{
    struct Node{
        int a,b,c,d;
        Node(){
            a = 1;
            b = 0;
            c = 0;
            d = 1;
        }

        int getVal(int x) {
            return (a*x + b)%MD*Comb::invMod(c*x + d, MD)%MD;
        }
    };

    int n;
    vector<pair<Node&, Node>> hist;
    vector<Node> IT;

    Node applyOp(Node n1, Node n2) {
        Node res;

        res.a = ((n1.a*n2.a)%MD + (n1.c*n2.b)%MD)%MD;
        res.b = ((n1.b*n2.a)%MD + (n1.d*n2.b)%MD)%MD;
        res.c = ((n1.a*n2.c)%MD + (n1.c*n2.d)%MD)%MD;
        res.d = ((n1.b*n2.c)%MD + (n1.d*n2.d)%MD)%MD;

        return res;
    }

    void init(int _n) {
        n = _n;
        IT.resize(n*4+10, Node());
        build(1,1,n);
    }

    void build(int idx, int l, int r){
        if (l==r) {
            IT[idx] = Node();
            return;
        }

        int mid = (l+r)/2;
        build(idx*2,l,mid);;
        build(idx*2+1,mid+1,r);
    }

    void iterate(int idx, int l, int r){
        if (l==r) {
            cout << "idx: " << idx << " " << l << " " << r << endl;
            cout << IT[idx].a << " " << IT[idx].b << " " << IT[idx].c << " " << IT[idx].d << endl;
            return;
        }
        cout << "idx: " << idx << " " << l << " " << r << endl;
        cout << IT[idx].a << " " << IT[idx].b << " " << IT[idx].c << " " << IT[idx].d << endl;
        int mid = (l+r)/2;
        iterate(idx*2,l,mid);;
        iterate(idx*2+1,mid+1,r);
    }

    void update(int idx, int l, int r, int x, int y, Node val){
        if (y < l || r < x) return;
        if (x <= l && r <= y){
            hist.push_back({IT[idx],IT[idx]});
            IT[idx] = applyOp(IT[idx], val);
            return;
        }

        int mid = (l+r)/2;
        update(idx*2,l,mid,x,y,val);
        update(idx*2+1,mid+1,r,x,y,val);
    }

    Node getNode(int idx, int l, int r, int x){
        if (x < l || r < x) return Node();
        if (l == r){
            return IT[idx];
        }

        int mid = (l+r)/2; 
        Node res = applyOp(getNode(idx*2,l,mid,x),getNode(idx*2+1,mid+1,r,x));
        res = applyOp(res, IT[idx]);
        return res;
    }

    int getVer() {
        return hist.size();
    }

    void rollback(int ver) {
        while (hist.size() > ver) {
            hist.back().fi = hist.back().se;
            hist.pop_back();
        }
    }

} IT;

int n,q;
vector<int> adj[N];
int timedfs = 0;
int depth[N];
int ccnt[N];
int tin[N], tout[N];
int w[N], dp[N];
int pref[N], val[N], prefval[N];

void dfs(int u, int p) {
    tin[u] = ++timedfs;
    depth[u] = depth[p]+1;

    for (auto v:adj[u]) {
        if (v==p) continue;
        ++ccnt[u];
        dfs(v,u);
    }
    tout[u] = timedfs;

    // cout << "u: " << u << " " << tin[u] << " " << tout[u] << endl;

    // if (ccnt[u] == 0) return;

    // LazySegmentTree::Node eq = LazySegmentTree::Node();

    // eq.a = (depth[u]+1);
    // eq.b = (ccnt[u] - 1 + MD)%MD;
    // eq.c = (-(depth[u]+1) + MD)%MD;
    // eq.d = ((depth[u]+1)*ccnt[u]%MD - ccnt[u] + 1 + MD)%MD;
    // cout << "u " << u << endl;
    // cout << eq.a << " " << eq.b << " " << eq.c << " " << eq.d << endl;

    // IT.update(1,1,n,tin[u], tout[u], eq);
}

void dfsw(int u, int p) {
    w[u] = 1;

    for (auto v:adj[u]) {
        if (v==p) continue;
        dfsw(v,u);
        w[u] = (w[u] + w[v]*Comb::invMod(ccnt[u],MD)%MD)%MD;
    }
}

void dfs3(int u, int p) {
    val[u] = val[p];

    if (u != 1 && ccnt[u] != 0) {
        val[u] = (val[u] + (Comb::invMod(depth[u],MD)*w[u])%MD)%MD;
    }

    for (auto v:adj[u]) {
        if (v==p) continue;
        dfs3(v,u);
    }

}

int rat = 1;
int sum = 0;

void dfsfin(int u, int p) {
    cerr << u << endl;

    cout << u << " " << sum << " " << rat << endl;
    cout << Comb::invMod(rat,MD) << endl;
    dp[u] = Comb::invMod(rat,MD)*sum%MD;

    vector<int> pref(ccnt[u]+2,0);
    vector<int> suf(ccnt[u]+2,0);

    int idx = 0;
    for (auto v:adj[u]) {
        if (v==p) continue;
        ++idx;
        pref[idx] = (val[v] + w[v])%MD;
        suf[idx] = (val[v] + w[v])%MD;
    }

    for (int i=1; i<=ccnt[u]; i++){
        pref[i] = (pref[i] + pref[i-1])%MD;
    }
    for (int i = ccnt[u]; i > 0; i--) {
        suf[i] = (suf[i] + suf[i+1])%MD;
    }

    if (ccnt[u] == 0) return;

    sum = (sum + rat)%MD;
    rat = (rat*Comb::invMod(ccnt[u],MD)%MD);
    idx = 0;
    for (auto v:adj[u]) {
        if (v==p) continue;
        ++idx;
        int cur = (pref[idx-1] + suf[idx+1])%MD*rat%MD;
        sum = (sum + cur)%MD;
        dfsfin(v,u);
        sum = (sum - cur + MD)%MD;
    }
    rat = (rat*ccnt[u])%MD;
    sum = (sum - rat+MD)%MD;
}

void solve(){
    cin >> n >> q;
    
    for (int u=2; u<=n; u++){
        int v; cin >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    IT.init(n);
    depth[0] = -1;
    dfs(1,0);
    dfsw(1,0);
    dfs3(1,0);
    dfsfin(1,0);
    w[1] = 0;

    // for (int i=2; i<=n; i++){
    //     auto eq = IT.getNode(1,1,n,tin[i]);
        
    //     cout << "i: " << i << endl;
    //     cout << eq.a << " " << eq.b << " " << eq.c << " " << eq.d << endl;

    //     dp[i] = eq.getVal(0);
    // }

    // IT.iterate(1,1,n);

    for (int i=1; i<=n; i++){
        cout << dp[i] << " ";
    }
    cout << endl;
    for (int i=1; i<=n; i++){
        cout << w[i] << " ";
    }
    cout << endl;
    for (int i=1; i<=n; i++){
        cout << val[i] << " ";
    }
    cout << endl;

    for (int i=1; i<=q; i++){
        int u,v; cin >> u >> v;
        int res;

        res = (val[u] + w[u] + dp[v])%MD;

        cout << res << endl;
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

