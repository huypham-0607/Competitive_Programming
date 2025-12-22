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
const int LG = 17;

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
vector<int> adj[N];
int up[LG][N];
int depth[N];

void DFS(int u, int p=0){
    depth[u] = depth[p]+1;
    up[0][u] = p;
    for (int lg=1; lg<LG; lg++){
        int v = up[lg-1][u];
        up[lg][u] = up[lg-1][v];
    }
    for (auto v:adj[u]){
        if (v==p) continue;
        DFS(v,u);
    }
}

int binLift(int u, int d){
    for (int lg=LG-1; lg>=0; lg--){
        if ((1<<lg)&d) u = up[lg][u];
    }
    return u;
}

int getDist(int u, int v){
    int dist = 0;
    if (depth[u] > depth[v]) swap(u,v);
    dist+=depth[v] - depth[u];
    v = binLift(v,depth[v] - depth[u]);
//    cout << dist << endl;
    if (u==v) return dist;
    for (int lg=LG-1; lg>=0; lg--){
        if (up[lg][u]!=up[lg][v]){
            u = up[lg][u];
            v = up[lg][v];
            dist+=(1<<lg)*2;
        }
    }
    dist+=2;
    return dist;
}

//Centroid

int cpar[N], sz[N];
bool vis[N];

int findSize(int u, int p=0){
    if (vis[u]) return 0;
    sz[u] = 1;
    for (auto v:adj[u]){
        if (v==p) continue;
        sz[u]+=findSize(v,u);
    }

    return sz[u];
}

int findCentroid(int u, int n, int p=0){
    for (auto v:adj[u]){
        if (v==p) continue;
        if (!vis[v] && sz[v]>n/2) return findCentroid(v,n,u);
    }
    return u;
}

void initCentroid(int u=1, int p = 0){
    findSize(u);

    int c = findCentroid(u,sz[u]);
    cpar[c] = p;
    vis[c] = true;

    for (auto v:adj[c]){
        if (!vis[v]){
            initCentroid(v,c);
        }
    }
}

int ans[N];

/*Solution*/
void solve(){
    cin >> n >> q;
    for (int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i=1; i<=n; i++){
        ans[i] = INF;
    }

    DFS(1);
    initCentroid();

    int u = 1;
    while (u){
        ans[u] = min(ans[u],getDist(u,1));
        u = cpar[u];
    }

//    for (int i=1; i<=n; i++){
//        cout << cpar[i] << " ";
//    }
//    cout << endl;
//
//    for (int i=1; i<=n; i++){
//        cout << ans[i] << " ";
//    }
//    cout << endl;

    for (int i=1; i<=q; i++){
        int id,x; cin >> id >> x;
        if (id==1){
            int u = x;
            while (u){
                ans[u] = min(ans[u],getDist(u,x));
                u = cpar[u];
            }
//            for (int i=1; i<=n; i++){
//                cout << ans[i] << " ";
//            }
//            cout << endl;
        }
        else{
            int res = INF;
            int u = x;
            while (u){
                res = min(res,ans[u] + getDist(u,x));
                u = cpar[u];
            }
            cout << res << endl;
        }
    }

}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
