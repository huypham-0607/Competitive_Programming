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
const int N = 3e5+10;
const int INF = 1e9+7;
const int LG = 19;
const long long LLINF = 1e18+3;

/*Global Variables*/
int n,k;
vector<int> adj[N];
bool isShop[N];
int dist[N];
int fav[N];
int f[N], g[N];

void dfs(int u, int p=0){
    f[u] = INF;
    if (isShop[u]) f[u] = 0;
    for (auto v:adj[u]){
        if (v==p) continue;
        dfs(v,u);
        f[u] = min(f[u],f[v]+1);
    }
}

void reroot(int u, int p=0){
    if (!p) g[u] = INF;
    pii mn = {INF,INF};
    int cur = g[u]+1;
    if (isShop[u]) cur = min(cur,1);
    for (auto v:adj[u]){
        if (v==p) continue;
        if (f[v]<mn.fi){
            mn.se = mn.fi;
            mn.fi = f[v];
        }
        else if (f[v] < mn.se){
            mn.se = f[v];
        }
    }
    for (auto v:adj[u]){
        if (v==p) continue;
        if (f[v] == mn.fi){
            g[v] = min(cur,mn.se+2);
        }
        else{
            g[v] = min(cur,mn.fi+2);
        }
        reroot(v,u);
    }
}

//LCA
int up[LG][N];
int depth[N];

void dfsLCA(int u, int p=0){
    depth[u] = depth[p]+1;
    up[0][u] = p;
    for (int lg=1; lg<LG; lg++){
        int v = up[lg-1][u];
        up[lg][u] = up[lg-1][v];
    }
    for (auto v:adj[u]){
        if (v==p) continue;
        dfsLCA(v,u);
    }
}

int binLift(int u, int x){
    for (int lg=0; lg<LG; lg++){
        if ((1<<lg)&x) u = up[lg][u];
    }
    return u;
}

int getDist(int u, int v){
    int res = 0;
    if (depth[u]>depth[v]) swap(u,v);
    res+=depth[v] - depth[u];
    v = binLift(v,depth[v]-depth[u]);
    if (u==v) return res;
    for (int lg=LG-1; lg>=0; lg--){
        if (up[lg][u]!=up[lg][v]){
            u = up[lg][u];
            v = up[lg][v];
            res+=(1<<lg)*2;
        }
    }
    return res+2;
}

//Centroid
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

vector<int> bar;
vector<pii> clist;
int aux[N];
int suf[N];
int ans[N];

int BIT[N];

void update(int idx, int val){
    ++idx;
    while (idx<=n+1){
        BIT[idx]+=val;
        idx+=(idx&(-idx));
    }
}

int getPoint(int idx){
    ++idx;
    int res = 0;
    while (idx>0){
        res+=BIT[idx];
        idx-=(idx&(-idx));
    }
    return res;
}

int getVal(int l, int r){
    return (getPoint(r)-getPoint(l-1));
}

void cdfs(int u, int p, int depth){
    int val = dist[u]-depth;
    if (val>=0){
        update(val,1);
    }
    clist.push_back({u,depth});
    for (auto v:adj[u]){
        if (vis[v] || v==p) continue;
        cdfs(v,u,depth+1);
    }
}

void buildCentroid(int u){
    findSize(u);
    int c = findCentroid(u,sz[u]);
    vis[c] = true;

    if (dist[c]>=0){
        update(dist[c],1);
    }
    clist.push_back({c,0});
    bar.push_back(clist.size());
    int maxdepth = 0;
    for (auto v:adj[c]){
        if (vis[v]) continue;
        cdfs(v,c,1);
        bar.push_back(clist.size());
    }

    int idx = 0;
    for (auto lim:bar){
        int preidx = idx;
        for (; idx<lim; idx++){
            int u = clist[idx].fi;
            int w = clist[idx].se;
            if (dist[u]-w>=0){
                update(dist[u]-w,-1);
            }
        }

        idx = preidx;
        for (; idx<lim; idx++){
            int u = clist[idx].fi;
            int w = clist[idx].se;
            ans[u]+=getVal(w,n);
        }

        idx = preidx;
        for (; idx<lim; idx++){
            int u = clist[idx].fi;
            int w = clist[idx].se;
            if (dist[u]-w>=0){
                update(dist[u]-w,1);
            };
        }
    }
    for (auto [u,w]:clist){
        if (dist[u]-w>=0){
            update(dist[u]-w,-1);
        }
    }
    bar.clear();
    clist.clear();

    for (auto v:adj[c]){
        if (vis[v]) continue;
        buildCentroid(v);
    }
}

/*Solution*/
void solve(){
    cin >> n >> k;
    for (int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i=1; i<=k; i++){
        int x; cin >> x;
        isShop[x] = true;
    }
    dfsLCA(1);
    dfs(1);
    reroot(1);
    for (int i=1; i<=n; i++){
        int x,w; cin >> x >> w;
        fav[i] = x;
        dist[i] = min(getDist(i,x)-w-1,min(f[i],g[i]));
    }

    buildCentroid(1);

    for (int i=1; i<=n; i++){
        if (dist[i]>=0) ++ans[i];
        cout << ans[i] << " ";
    }
}

/*Driver Code*/
signed main(){
//    cin.tie(0) -> sync_with_stdio(0);
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
