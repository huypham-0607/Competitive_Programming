/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

#define TEXT ""

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const int LG = 18;
const long long LLINF = 1e18+3;

/*Global Variables*/
int n,k;
vector<int> adj[N];
ll ans = 0;

//Centroid

int cpar[N];
int sz[N];
bool vis[N];
int croot;
int cnt[N];
vector<pii> clist;
vector<int> bar;

int getSize(int u, int p=0){
    sz[u] = 1;
    for (int v:adj[u]){
        if (vis[v] || v==p) continue;
        sz[u] += getSize(v,u);
    }
    return sz[u];
}

int getCentroid(int u, int n, int p=0){
    for (int v:adj[u]){
        if (vis[v] || v==p) continue;
        if (sz[v] > n/2) return getCentroid(v,n,u);
    }
    return u;
}

void dfs(int u, int p=0, int depth=0){
    if (depth) clist.push_back({u,depth});
    for (auto v:adj[u]){
        if (vis[v] || v==p) continue;
        dfs(v,u,depth+1);
        if (!depth) bar.push_back(clist.size());
    }
}

int buildCentroid(int u, int p = 0){
    getSize(u);

    int c = getCentroid(u,sz[u]);
    dfs(c);
    int idx = 0;

//    cout << "centroid: " << c << endl;

    for (auto lim:bar){
//        cout << lim << endl;
        int preidx = idx;
        while (idx<lim){
            if (clist[idx].se == k) ++ans;
            if (k-clist[idx].se > 0){
                ans += cnt[k-clist[idx].se];
            }
            ++idx;
        }
        idx = preidx;
        while (idx<lim){
//            cout << clist[c].size() << endl;
//            cout << u << " " << idx << endl;
//            cout << clist[c][idx].se << endl;
            cnt[clist[idx].se]++;
            ++idx;
        }
    }
    for (auto [x,val]:clist) cnt[val]--;

    clist.clear();
    bar.clear();
    cpar[c] = p;
    vis[c] = true;
    for (int v:adj[c]){
        if (vis[v]) continue;
        buildCentroid(v,c);
    }
    return c;
}

/*Solution*/
void solve(){
    cin >> n >> k;
    for (int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    croot = buildCentroid(1);
    // for (int i=1; i<=n; i++){
    //     cout << cpar[i] << " ";
    // }
    // cout << endl;

    // for (int i=1; i<=n; i++){
    //     cout << "i: " << i << " ";
    //     for (auto [x,val]:clist[i]){
    //         cout << "{" << x << "," << val << "} ";
    //     }
    //     cout << endl;
    // }

    cout << ans << endl;

    // cout << getDist(1,3);
}

/*Driver Code*/
signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    // if (fopen(TEXT".inp","r")){
    //     freopen(TEXT".inp","r",stdin);
    //     freopen(TEXT".out","w",stdout);
    // }

    int testCount = 1;
//    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}
