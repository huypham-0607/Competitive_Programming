/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT "G"

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
const int MD = 998244353;
const long long LLINF = 1e18+3;

// Standard Combinatoric Template
namespace Comb {
    using ll = long long;

    const int MD = 998244353;
    const int N = 3e5;
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

int n,k;
vector<int> adj[N];

const int LG_LCA = 19;

int up[LG_LCA][N];
int depth[N];
int sz[N];

vector<int> queryIn[N],queryOut[N];
vector<pii> query[N];
int qIn[N],qOut[N];
int high[N];
int dpIn[N],dpOut[N];
int cnt[N],cntv[N];

// Standard LCA
void dfsLCA(int u, int p=0){
    depth[u] = depth[p]+1;
    sz[u] = 1;
    up[0][u] = p;
    for (int lg=1; lg<LG_LCA; lg++){
        int v = up[lg-1][u];
        up[lg][u] = up[lg-1][v];
    }
    for (auto v:adj[u]){
        if (v==p) continue;
        dfsLCA(v,u);
        sz[u] += sz[v];
    }
}

// Standard Bin Lift
int binLift(int u, int x){
    for (int lg=0; lg<LG_LCA; lg++){
        if ((1<<lg)&x) u = up[lg][u];
    }
    return u;
}

// Standard LCA
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

/*
    Sack:
    Allows us to calculate and query cnt[u][d]: number of node v inside subtree u with depth[v] = d
    (depth[v] is depth of v relative to tree root (1 in this case))

    Calculates in offline manner, with total complexity of O(n*log(n))
*/
void addSack(int u, int p, int val, int heavy) {
    //Sack
    cnt[depth[u]]+=val;

    for (auto v:adj[u]) {
        if (v==p || v==heavy) continue;
        addSack(v,u,val,heavy);
    }
}

void sack(int u, int p, int keep){
    cout << "Sack: " <<  u << endl;
    int heavy = 0;
    for (auto v:adj[u]) {
        if (v==p) continue;
        if (sz[v] > sz[heavy]) heavy = v;
    }

    for (auto v:adj[u]) {
        if (v==p || v==heavy) continue;
        sack(v,u,0);
    }

    if (heavy) sack(heavy,u,1);

    addSack(u,p,1,heavy);

    for (auto [d,id]:query[u]) {
        if (id == 1) {
            // Number of ways to transition from dp[d+1] to dp[d] (redundant lol)
            dpIn[d] = dpOut[d+1];
            // Number of valid starting node
            cntv[d] = cnt[d];
        }
        else {
            if (cnt[d] == 1) {
                // If cnt[d] == 1, theres only 1 choice for transition
                dpOut[d] =  dpIn[d];
            }
            else {
                /*
                    Lets call dp[d] number of ways to form valid FDS path up to all nodes with depth >= d
                    Case 1: Choosing 2 valid starting node:
                        cntv[d] * (cntv[d]-1)) * fac[cnt[d]-2] * dp[d+1]
                    Case 2: Choosing 1 starting node and 1 non-starting node:
                        (cnt[d]-cntv[d]) * cntv[d] * fac[cnt[d]-2] * dp[d+1]
                */
                dpOut[d] = (cntv[d]*(cntv[d]-1)%MD
                            *Comb::fac[cnt[d]-2]%MD
                            *dpIn[d]%MD
                            + (cnt[d]-cntv[d])*cntv[d]%MD
                            *Comb::fac[cnt[d]-2]%MD
                            *dpIn[d]%MD)%MD;
            }
        }
    }

    if (!keep) addSack(u,p,-1,0);
}

void solve(){
    cin >> n >> k;

    for (int i=0; i<=n; i++){
        dpIn[i] = 0;
        dpOut[i] = 0;
        adj[i].clear();
        query[i].clear();
        high[i] = 0;
        qIn[i] = 0;
        qOut[i] = 0;
        cnt[i] = 0;
        cntv[i] = 0;
    }

    for (int u=2; u<=n; u++){
        int v; cin >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    depth[0] = -1;
    dfsLCA(1,0);

    /*
        Calculate mxdepth: max(depth[u]) over all u
        also calculate high[d]: LCA of all node u where depth[u] = d
    */

    int mxdepth = 0;
    for (int i=1; i<=n; i++){
        cout << depth[i] << " ";
        mxdepth = max(mxdepth,depth[i]);
        if (high[depth[i]] == 0) high[depth[i]] = i;
        else {
            high[depth[i]] = getLCA(high[depth[i]],i);
        }
    }
    cout << endl;

    /*
        Checking if maximum distance between any pair of node with same depth d exceed k
    */
    for (int i=1; i<=n; i++){
        int delta = depth[i] - depth[high[depth[i]]];
        // cout << delta << " " << depth[i] << " " << k << endl;
        if (depth[i] > k || delta*2 > k) {
            cout << 0 << endl;
            return;
        }
    }

    
    dpIn[mxdepth] = 1;

    /*
        qIn[d]: Highest node any node u with depth[u] = d can reach if we are transitioning
        from depth[u] to depth[u]-1 in our First-Depth-Search sequence
        qOut[d]: 
    */
    for (int i=1; i<=n; i++){
        if (depth[i] == mxdepth) cntv[mxdepth]++;
        int deltaIn = k/2 + k%2;
        int deltaOut = k/2;
        
        qIn[depth[i]] = binLift(i,deltaIn);
        qOut[depth[i]] = binLift(i,deltaOut);

        if (qIn[depth[i]] == 0) qIn[depth[i]] = 1;
        if (qOut[depth[i]] == 0) qOut[depth[i]] = 1;
    }

    /*
        Pushing Queries into our Sack query table.
    */
    for (int d=mxdepth; d>=0; d--){
        int deltaIn = k/2 + k%2;
        int deltaOut = k/2;
        
        if (d != 0) {
            query[qIn[d]].push_back({d-1,1});
        }
        query[qOut[d]].push_back({d,0});
    }

    /*
        Sort decreasing depth (Since we want to query highest depth first)
    */
    for (int i=1; i<=n; i++){
        sort(all(query[i]),greater<pii>());
    }

    for (int i=1; i<=n; i++){
        cout << "Node: " << i << endl;
        for (auto [d,id]:query[i]) {
            cout << "{" << d << "," << id << "} ";
        }
        cout << endl;
    }
    sack(1,0,0);

    for (int i=0; i<=mxdepth; i++){
        cout << dpIn[i] << " " << dpOut[i] << " " << cntv[i] << endl;
    }
    cout << dpOut[0] << endl;
    // cout << "meow" << endl;
}

/*Driver Code*/
signed main(){
    // cin.tie(0) -> sync_with_stdio(0);
    if (fopen(TEXT".inp","r")){
        freopen(TEXT".inp","r",stdin);
        freopen(TEXT".out","w",stdout);
    }

    int testCount = 1;
   cin >> testCount;
    while (testCount--){
        cout << "New Test" << endl;
        solve();
    }

    return 0;
}

