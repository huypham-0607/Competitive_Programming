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
// #define int long long

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

mt19937_64 rd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 4000+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e17+3;

//Starts here

int n,k;
int cnt[N];
int val[N];
ll f[N][N];
vector<int> adj[N];

void calcf(int u, int p) {
    cnt[u] = 1;
    for (auto v:adj[u]) {
        if (v==p) continue;
        calcf(v,u);
        cnt[u] += cnt[v];
    }

    // cout << "org: " << u << endl;

    for (int i=1; i<cnt[u]; i++) f[u][i] = -LLINF;
    f[u][0] = 0;
    int sz = 1;
    for (auto v:adj[u]) {
        if (v==p) continue;
        // cout << "vertex: " << v << endl;
        for (int x=sz+cnt[v]-1; x>=0; x--) {
            for (int j=min({x,cnt[v]}); j>=max(0,x-sz); j--) {
                int i = x-j;
                if (i < 0) break;
                // cout << i << " " << j << endl;
                if (j!=cnt[v]) f[u][x] = max(f[u][x], f[v][j] + f[u][i]);
                if (j!=0) f[u][x] = max(f[u][x], f[v][j-1] + f[u][i] + 1LL*(j)*val[v]);
            }
        }
        sz+=cnt[v];
    }
}

ll g[N][N];
int sz[N];
int offset[N];

void calcg(int u, int p, int cum) {
    // cerr << "org: " << u << endl;
    int nxt = 0;
    for (auto v:adj[u]) {
        if (v==p) continue;
        if (!nxt || cnt[nxt] < cnt[v]) {
            nxt = v;
        }
    }

    if (!nxt) return;

    // Calculate g[nxt]
    // cerr << "nxt: " << nxt << endl;
    vector<ll> tmp(sz[u]);
    copy(g[u],g[u]+sz[u],tmp.begin());

    for (auto v:adj[u]) {
        if (v==p || v==nxt) continue;
        for (int x=sz[u]-1; x>=0; x--) {
            for (int j=0; j<=cnt[v]; j++) {
                int i = x-j;
                if (i < 0) break;
                if (j!=cnt[v]) tmp[x] = max(tmp[x], tmp[i] + f[v][j]);
                if (j!=0) tmp[x] = max(tmp[x], tmp[i] + f[v][j-1] + 1LL*(j)*val[v]);
            }
        }
    }
    for (int x=sz[u]-1; x>0; x--) {
        tmp[x] = max(tmp[x], tmp[x-1] + 1LL*val[u]*(x+cum));
    }

    sz[nxt] = min(cnt[nxt],k);
    offset[nxt] = sz[u]-sz[nxt];
    for (int i=0; i<sz[nxt]; i++) g[nxt][i] = -LLINF;
    // g[nxt].resize(sz[nxt],-LLINF);

    for (int i=0; i<sz[nxt]; i++){
        g[nxt][i] = tmp[offset[nxt] + i];
    }
    calcg(nxt,u,cum+offset[nxt]);

    //Calculate g for small child
    // cerr << "Small calc: " << u << endl;
    vector<pair<int,pair<ll&,ll>>> hist;
    vector<ll> ldp;
    vector<ll> rdp;

    // ldp = g[u];
    ldp.resize(sz[u]); copy(g[u],g[u]+sz[u],ldp.begin());
    // rdp = f[nxt];
    rdp.resize(sz[u],-LLINF); copy(f[nxt],f[nxt]+min(sz[u],cnt[nxt]),rdp.begin());
    // rdp.resize(sz[u],-LLINF);
    for (int x=sz[u]-1; x>0; x--) {
        rdp[x] = max(rdp[x], rdp[x-1] + 1LL*val[nxt]*(x));
    }

    for (int idx=adj[u].size()-1; idx>=0; idx--) {
        int v = adj[u][idx];
        if (v==p || v==nxt) continue;
        // cerr << v << endl;
        for (int x=sz[u]-1; x>=0; x--) {
            for (int j=0; j<=cnt[v]; j++) {
                int i = x-j;
                if (i<0) break;
                // cerr << i << " " << j << endl;
                if (j!=cnt[v]) {
                    ll tmpval = rdp[i] + f[v][j];
                    if (rdp[x] < tmpval) {
                        hist.push_back({v,{rdp[x],rdp[x]}});
                        rdp[x] = max(rdp[x], tmpval);
                    }
                }
                // cerr << "passed" << endl;
                if (j!=0) {
                    ll tmpval = rdp[i] + f[v][j-1] + 1LL*(j)*val[v];
                    if (j!=0 && rdp[x] < tmpval) {
                        hist.push_back({v,{rdp[x],rdp[x]}});
                        rdp[x] = max(rdp[x], tmpval);
                    }
                }
                // cerr << "passed" << endl;
            }
        }
    }

    for (auto v:adj[u]) {
        if (v==p || v==nxt) continue;
        while (!hist.empty() && hist.back().fi == v) {
            hist.back().se.fi = hist.back().se.se;
            hist.pop_back();
        }
        
        sz[v] = min(cnt[v],k);
        offset[v] = sz[u]-sz[v];
        for (int i=0; i<sz[v]; i++) g[v][i] = -LLINF;
        // g[v].resize(sz[v],-LLINF);

        for (int x=0; x<sz[v]; x++) {
            for (int j=0; j<=sz[u]; j++) {
                int i = x+offset[v]-j;
                if (i<0) break;
                if (j!=sz[u]) g[v][x] = max(g[v][x], ldp[i] + rdp[j]);
                if (j!=0) g[v][x] = max(g[v][x], ldp[i] + rdp[j-1] + 1LL*val[u]*(i+j+cum));
            }
        }

        calcg(v,u,cum+offset[v]);

        // Need variable fixing
        for (int x=sz[u]-1; x>=0; x--) {
            for (int j=0; j<=cnt[v]; j++) {
                int i = x-j;
                if (i < 0) break;
                if (j!=cnt[v]) ldp[x] = max(ldp[x], ldp[i] + f[v][j]);
                if (j!=0) ldp[x] = max(ldp[x], ldp[i] + f[v][j-1] + 1LL*(j)*val[v]);
            }
        }
    }
}

void solve(){
    cin >> n >> k;
    for (int i=1; i<=n; i++){
        adj[i].clear();
    }
    for (int i=1; i<=n; i++){
        cin >> val[i];
    }
    for (int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (k == 1) {
        for (int i=1; i<=n; i++){
            cout << val[i] << " ";
        }
        cout << endl;
        return;
    }

    calcf(1,0);
    
    // if (k == 4000) {
    //     for (int i=1; i<=n; i++){
    //         cout << cnt[i] << " ";
    //     }
    //     cout << endl;
    //     return;
    // }

    offset[1] = 0;
    sz[1] = min(n,k);
    for (int i=0; i<sz[1]; i++) g[1][i] = -LLINF;
    // g[1].resize(sz[1],-LLINF);
    g[1][0] = 0;



    calcg(1,0,0);

    // for (int i=1; i<=n; i++){
    //     cout << "id: " << i << endl;
    //     for (int idx=0; idx<cnt[i]; idx++) cout << f[i][idx] << " "; cout << endl;
    //     for (int idx=0; idx<sz[i]; idx++) cout << g[i][idx] << " "; cout << endl;
    // }

    for (int i=1; i<=n; i++){
        ll ans = 0;
        for (int idx=0; idx<sz[i]; idx++) {
            ans = max(ans, g[i][idx] + f[i][sz[i]-1-idx] + 1LL*val[i]*k); 
        }
        cout << ans << " ";
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