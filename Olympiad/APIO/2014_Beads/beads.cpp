/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define int long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e15+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n;
vector<pii> tmp[N];
int f[N][2], g[N][2];
vector<pii> adj[N];

void DFS_f(int u, int p, int w){
    int res = 0;
    tmp[u].push_back({-LLINF,0});
    tmp[u].push_back({-LLINF,0});
    for (auto in:adj[u]){
        int v,val; tie(v,val) = in;
        if (v==p) continue;
        DFS_f(v,u,val);
        res+=f[v][1];
        tmp[u].push_back({f[v][0] - f[v][1] + val,v});
    }
    sort(all(tmp[u]),greater<pii>());
    f[u][0] = f[u][1] = res;
    f[u][1] = max(f[u][1],res+tmp[u][0].fi+w);
}

void DFS_g(int u, int p, int w){
    for (auto in:adj[u]){
        int v,val; tie(v,val) = in;
        if (v==p) continue;
        g[v][0] = f[u][0] - f[v][1] + g[u][1];
        int idx = 0;
        if (f[v][0] - f[v][1] + val == tmp[u][idx].fi) ++idx;
        if (g[u][0] - g[u][1] + w > tmp[u][idx].fi){
            g[v][1] = max(g[v][0],g[v][0] + (g[u][0] - g[u][1] + w) + val);
        }
        else g[v][1] = max(g[v][0],g[v][0] + tmp[u][idx].fi + val);
        DFS_g (v,u,val);
    }
}

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<n; i++){
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    DFS_f(1,0,0);
    g[1][0] = -LLINF;
    DFS_g(1,0,0);
    int mx = 0;
    for (int i=1; i<=n; i++){
        mx = max(mx,f[i][0] + g[i][1]);
    }
    cout << mx << endl;
//    for (int i=1; i<=n; i++){
//        cout << f[i][0] << " " << f[i][1] << " " << g[i][0] << " " << g[i][1] << endl;
//    }
}

/*Driver Code*/
signed main(){
//    freopen("beads.inp","r",stdin);
//    freopen("beads.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
