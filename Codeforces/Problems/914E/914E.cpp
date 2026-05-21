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
const int LG = 20;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

int n;
vector<int> adj[N];
int val[N];
int ans[N];
int dp1[(1<<LG)+10];
int dp2[(1<<LG)+10];

int sz[N];
int vis[N];

int findSize(int u, int p=0){
    sz[u] = 1;
    for (auto v:adj[u]){
        if (vis[v] || v==p) continue;
        sz[u] += findSize(v,u);
    }
    return sz[u];
}

int findCentroid(int u, int n, int p=0){
    for (auto v:adj[u]){
        if (vis[v] || v==p) continue;
        if (sz[v]>n/2) return findCentroid(v,n,u);
    }
    return u;
}

void dfs1(int u, int p, int cen, int pref){
    pref^=val[u];
    ans[cen] += dp1[pref];
    for (int lg = 0; lg < LG; lg++){
        ans[cen] += dp1[pref^(1<<lg)];
    }
    for (auto v:adj[u]){
        if (vis[v] || v==p) continue;
        dfs1(v,u,cen,pref);
    }
}

void dfs1Add(int u, int p, int cen, int pref) {
    pref^=val[u];
    dp1[pref^val[cen]]++;
    for (auto v:adj[u]){
        if (vis[v] || v==p) continue;
        dfs1Add(v,u,cen,pref);
    }
}

void dfs2Add(int u, int p, int cen, int pref) {
    pref^=val[u];
    dp2[pref^val[cen]]++;
    for (auto v:adj[u]){
        if (vis[v] || v==p) continue;
        dfs2Add(v,u,cen,pref);
    }
}

int dfs2(int u, int p, int cen, int pref) {
    pref^=val[u];
    int res = 0;
    res += (dp1[pref] - dp2[pref]);
    for (int lg=0; lg<LG; lg++){
        res += (dp1[pref^(1<<lg)] - dp2[pref^(1<<lg)]);
    }
    for (auto v:adj[u]) {
        if (vis[v] || v==p) continue;
        res += dfs2(v,u,cen,pref);
    }
    ans[u] += res;
    return res;
}

void dfs2Rem(int u, int p, int cen, int pref) {
    pref^=val[u];
    dp2[pref^val[cen]]--;
    for (auto v:adj[u]){
        if (vis[v] || v==p) continue;
        dfs2Rem(v,u,cen,pref);
    }
}

void dfs1Rem(int u, int p, int cen, int pref) {
    pref^=val[u];
    dp1[pref^val[cen]]--;
    for (auto v:adj[u]){
        if (vis[v] || v==p) continue;
        dfs1Rem(v,u,cen,pref);
    }
}

void buildCentroid(int s){
    findSize(s);
    int u = findCentroid(s,sz[s]);
    // cerr << u << endl;
    vis[u] = true;

    dp1[val[u]]++;
    ++ans[u];

    for (auto v:adj[u]){
        if (vis[v]) continue;
        dfs1(v,u,u,0);
        dfs1Add(v,u,u,0);
    }

    for (auto v:adj[u]) {
        if (vis[v]) continue;
        dfs2Add(v,u,u,0);
        dfs2(v,u,u,0);
        dfs2Rem(v,u,u,0);
    }

    for (auto v:adj[u]) {
        if (vis[v]) continue;
        // for (int mask=0; mask<(1<<3); mask++){
        //     cerr << dp1[mask] << " ";
        // }
        // cerr << endl;
        dfs1Rem(v,u,u,0);
    }

    dp1[val[u]]--;

    for (auto v:adj[u]){
        if (vis[v]) continue;
        buildCentroid(v);
    }
}


void solve(){
    cin >> n;
    for (int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);   
    }
    for (int i=1; i<=n; i++){
        char c; cin >> c;
        int shift = c-'a';
        val[i] = (1<<shift);
    }
    // for (int i=1; i<=n; i++){
    //     cerr << val[i] << " ";
    // }
    // cerr << endl;

    buildCentroid(1);

    for (int i=1; i<=n; i++){
        cout << ans[i] << " ";
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

