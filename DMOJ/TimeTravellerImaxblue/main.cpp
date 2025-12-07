/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define int long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define portalThing pair<pii,pair<pii,int>>
#define fi first
#define se second

#define TEXT ""

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*Global Variables*/
int n,m,q,t;
deque<pii> dq[N];
vector<pii> adj[N];
vector<portalThing> portal;

//LCA
const int LG_LCA = 18;

int up[LG_LCA][N];
int dist[LG_LCA][N];
int depth[N];

void dfsLCA(int u, int p=-1, int prew=0){
    if (p==-1) depth[u] = 0;
    else depth[u] = depth[p]+1;
    up[0][u] = p;
    dist[0][u] = prew;
    for (int lg=1; lg<LG_LCA; lg++){
        int v = up[lg-1][u];
        up[lg][u] = up[lg-1][v];
        dist[lg][u] = dist[lg-1][u]+dist[lg-1][v];
    }
    for (auto [v,w]:adj[u]){
        if (v==p) continue;
        dfsLCA(v,u,w);
    }
}

pii binLift(int u, int x){
    int d = 0;
    for (int lg=0; lg<LG_LCA; lg++){
        if ((1<<lg)&x){
            d += dist[lg][u];
            u = up[lg][u];
        }
    }
    return {u,d};
}

int getDist(int u, int v){
    int res = 0;
    if (depth[u]>depth[v]) swap(u,v);
    pii tmp = binLift(v,depth[v]-depth[u]);
    v = tmp.fi;
    res += tmp.se;
    if (u==v) return res;
//    cout << "fuck" << endl;
    for (int lg=LG_LCA-1; lg>=0; lg--){
        if (up[lg][u]!=up[lg][v]){
            res += dist[lg][u];
            res += dist[lg][v];
            u = up[lg][u];
            v = up[lg][v];
        }
    }
    return res + dist[0][u] + dist[0][v];
}

//Centroid
int cpar[N];
int distpar[N];
int sz[N];
int vis[N];

int findSize(int u, int p=0){
    sz[u] = 1;
    for (auto [v,w]:adj[u]){
        if (vis[v] || v==p) continue;
        sz[u] += findSize(v,u);
    }
    return sz[u];
}

int findCentroid(int u, int n, int p=0){
    for (auto [v,w]:adj[u]){
        if (vis[v] || v==p) continue;
        if (sz[v]>n/2) return findCentroid(v,n,u);
    }
    return u;
}


void buildCentroid(int s, int p=-1){
    findSize(s);
    int u = findCentroid(s,sz[s]);
    vis[u] = true;
    cpar[u] = p;
    if (p!=-1){
        distpar[u] = getDist(u,p);
    }

    for (auto [v,w]:adj[u]){
        if (vis[v]) continue;
        buildCentroid(v,u);
    }
}

/*Solution*/
void solve(){
    cin >> n >> m >> q >> t;
    for (int i=1; i<n; i++){
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dfsLCA(0);
    buildCentroid(0,-1);

//    for (int i=0; i<n; i++){
//        cout << cpar[i] << " ";
//    }
//    cout << endl;
//    for (int i=0; i<n; i++){
//        cout << distpar[i] << " ";
//    }
//    cout << endl;

    for (int i=1; i<=m; i++){
        int x,s,e,w; cin >> x >> s >> e >> w;
        portal.push_back({{e,s},{{x,w},i}});
    }
    sort(all(portal),greater<portalThing>());

    int tmp = 0;
    int tmpdist = 0;
    while (tmp!=-1){
        tmpdist=getDist(0,tmp);
        dq[tmp].push_back({t,tmpdist});
        tmp = cpar[tmp];
    }
    for (auto in:portal){
        int e = in.fi.fi;
        int s = in.fi.se;
        int x = in.se.fi.fi;
        int w = in.se.fi.se;
//        int id = in.se.se;

        int u = x;
        int d = 0;
        int mn = LLINF;
        while (u!=-1){
            d = getDist(x,u);
            auto it = lower_bound(all(dq[u]),make_pair(s,0),[&](const pii &x, const pii &y){ return x.fi > y.fi;});
            if (it != dq[u].end()){
                mn = min(mn,d+it->se);
//                cout << u << " " << mn << " " << d << " " << it->se << " " << it->fi << endl;
            }
//            else cout << u << " " << -1 << endl;
            u = cpar[u];
        }
        mn+=w;
        u = x;
        d = 0;
//        cout << id << " " << mn << endl;
        while (u!=-1){
            d = getDist(x,u);
            while (!dq[u].empty() && dq[u].back().se>=mn+d){
                dq[u].pop_back();
            }
            dq[u].push_back({e,mn+d});
            u = cpar[u];
        }
    }

//    for (int i=0; i<n; i++){
//        cout <<
//    }

    for (int i=1; i<=q; i++){
//        cout << "Query " << i << ": " << endl;
        int val,x; cin >> val >> x;
        int u = x;
        int d = 0;
        int ans = LLINF;
        while (u!=-1){
            d = getDist(u,x);
            auto it = lower_bound(all(dq[u]),make_pair(val,0),[&](const pii &x, const pii &y){ return x.fi > y.fi;});
            if (it != dq[u].end()){
                ans = min(ans,d+it->se);
//                cout <<
            }
//            else cout << -1 << endl;
            u = cpar[u];
        }
        if (ans == LLINF) cout << -1 << endl;
        else cout << ans << endl;
    }
//    cout << getDist(2,3) << endl;

//    for (int i=0; i<n; i++){
//        for (int lg=0; lg<3; lg++){
//            cout << dist[lg][i] << " ";
//        }
//        cout << endl;
//    }
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
