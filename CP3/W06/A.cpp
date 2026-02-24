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
// #define int long long

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

mt19937_64 rd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 6010;
const int INF = 1e9+7;
const int MD = 998244353;
const long long LLINF = 1e18+3;

//Starts here

int n;
int c[N];
vector<int> adj[N];
int dp[N][N];
int tcolcnt[N];
int ncolcnt[N];
int colcnt[N];
int lcnt[N];
int rcnt[N];
int piv[N];
int sz[N];
int dpcur[N];
int ans;

void dfs(int u, int p, int col) {
    ncolcnt[u] = colcnt[u] = 0;
    if (c[u] != col) ++ncolcnt[u];
    else ++colcnt[u];

    int lb = 0, rb = 0;
    for (auto v:adj[u]) {
        if (v==p) continue;
        dfs(v,u,col);
        colcnt[u] += colcnt[v];
        ncolcnt[u] += ncolcnt[v];
        lb += lcnt[v];
        rb += rcnt[v];
    }

    // cerr << "u: " << u << " " << colcnt[u] << " " << ncolcnt[u] << endl;

    if (c[u] == col) ++rb;
    else ++lb;

    // cerr << lb << " " << rb << endl;
    piv[u] = lb;
    sz[u] = lb + rb + 1;
    for (int i=0; i<sz[u]; i++) {
        dp[u][i] = 0;
        dpcur[i] = 0;
    }
    
    // cerr << piv[u] << " " << sz[u] << endl;

    if (c[u] == col) lb = rb = piv[u]+1;
    else lb = rb = piv[u]-1;
    dp[u][lb] = 1;
    dpcur[lb] = 1;

    for (auto v:adj[u]) {
        if (v==p) continue;

        for (int delta=-lcnt[v]; delta<=rcnt[v]; delta++){
            
            int i = piv[v]+delta;
            for (int j=lb; j<=rb; j++){
                if (j+delta < 0 || j+delta >= sz[u]) continue;
                dpcur[j+delta] = (1LL*dpcur[j+delta] + 1LL*dp[v][i]*dp[u][j])%MD;
            }
        }
        lb = max(0, lb-piv[v]);
        rb = min(sz[u]-1, rb+sz[v]-piv[v]+1);
        for (int i=lb; i<=rb; i++){
            dp[u][i]  = dpcur[i];
        }
    }

    for (int i=piv[u]+1; i<sz[u]; i++){
        ans = (ans+dp[u][i])%MD;
    }

    lcnt[u] = min({piv[u], ncolcnt[u],tcolcnt[col] - colcnt[u]});
    while (lcnt[u] > 0 && dp[u][piv[u] - lcnt[u]] == 0) {
        --lcnt[u];
    }
    rcnt[u] = (sz[u]-piv[u]-1);
    while (rcnt[u] > 0 && dp[u][piv[u] + rcnt[u]] == 0) {
        --rcnt[u];
    }
    // cerr << "cnt: " << u << " " << lcnt[u] << " " << rcnt[u] << endl;
}

void solve(){
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> c[i];
        tcolcnt[c[i]]++;
    }
    for (int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ans = 0;
    for (int i=1; i<=n; i++){
        // cerr << "curcol: " << i << " " << tcolcnt[i] << endl;
        dfs(1,0,i);
    }
    cout << ans << endl;
}

/*Driver Code*/
signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int testCount = 1;
//    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

