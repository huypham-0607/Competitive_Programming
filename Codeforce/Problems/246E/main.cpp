/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n,q;
vector<string> nen;
string a[N];
int val[N];
vector<int> adj[N];
vector<pii> tmp[N],query[N];
vector<int> lst;
int parent[N],sz[N],depth[N];
int vis[N];
int res[N];
map<int,int> cnt[N];
int ans[N];

void DFS(int u, int p){
    sz[u] = 1;

    for (auto in:tmp[u]){
        int w,id; tie(id,w) = in;
        int pos = depth[u]-w;
        if (pos < 0) continue;
        query[lst[pos]].push_back({depth[u],id});
    }

    lst.push_back(u);
    for (auto v:adj[u]){
        if (v==p) continue;
        depth[v] = depth[u]+1;
        DFS(v,u);
        sz[u]+=sz[v];
    }
    lst.pop_back();
}

void Add(int u, int p, int x, int heavy){
    cnt[depth[u]][val[u]] += x;
    if (cnt[depth[u]][val[u]] == 0){
        cnt[depth[u]].erase(val[u]);
    }


    for (auto v:adj[u]){
        if (v==p || v==heavy) continue;
        Add(v,u,x,heavy);
    }
}

void Sack(int u, int p, int keep){
    vis[u] = true;

    int heavy = 0;
    for (auto v:adj[u]){
        if (v==p) continue;
        if (!heavy || sz[heavy]<sz[v]) heavy = v;
    }

    for (auto v:adj[u]){
        if (v==p || v==heavy) continue;
        Sack(v,u,0);
    }

    if (heavy) Sack(heavy,u,1);

    Add(u,p,1,heavy);

    for (auto in:query[u]){
        int w,id; tie(w,id) = in;
        ans[id] = cnt[w].size();
    }

    if (!keep) Add(u,p,-1,0);
}

/*Solution*/
void solve(){
    cin >> n;
    for (int u=1; u<=n; u++){
        int v; cin >> a[u] >> v;
        parent[u] = v;
        nen.push_back(a[u]);
        if (v==0) continue;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    sort(all(nen));
    for (int i=1; i<=n; i++){
        val[i] = lower_bound(all(nen),a[i]) - nen.begin()+1;
    }
    nen.resize(unique(all(nen)) - nen.begin());

    for (int i=1; i<=n; i++){
        if (parent[i] == 0){
            DFS(i,0);
        }
    }

    cin >> q;
    for (int i=1; i<=q; i++){
        int u,w; cin >> u >> w;
        query[u].push_back({depth[u]+w,i});
    }

    for (int i=1; i<=n; i++){
        if (parent[i] == 0){
            Sack(i,0,0);
        }
    }

    for (int i=1; i<=q; i++){
        cout << ans[i] << endl;
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
