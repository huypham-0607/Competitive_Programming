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
const long long LLINF = 1e18+3;

/*Global Variables*/
int n,_n,_m;
vector<pii> diag[N];
int nxt[N];
map<pii,int> mp;
vector<int> adj[N];

int sz[N];
bool vis[N];
int ans[N];

int findSize(int u, int p=0){
    sz[u] = 1;
    for (auto v:adj[u]){
        if (vis[v] || v==p) continue;
        sz[u]+=findSize(v,u);
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

void buildCentroid(int u, int p=0, int depth=1){
    findSize(u);

    int c = findCentroid(u,sz[u]);
    vis[c] = true;
    ans[c] = depth;
    for (auto v:adj[c]){
        if (vis[v]) continue;
        buildCentroid(v,c,depth+1);
    }
}

int viscnt = 0;

void testdfs(int u, int p=0){
    ++viscnt;
    for (auto v:adj[u]){
        if (v==p) continue;
        testdfs(v,u);
    }
}

/*Solution*/
void solve(){
    cin >> _n >> _m;
    for (int i=1; i<=_m; i++){
        int u,v; cin >> u >> v;
        if (u<v) swap(u,v);
        diag[u].push_back({u,v});
        nxt[v] = max(nxt[v],u);
    }
    for (int i=1; i<=_n; i++){
        int u = i;
        int v = i%_n+1;
        if (u<v) swap(u,v);
        diag[u].push_back({u,v});
        nxt[v] = max(nxt[v],u);
    }
    int idx = _m+1;
    for (int i=_n; i>0; i--){
        int cur = 0;
        sort(all(diag[i]),greater<pii>());
        for (int tmp=1; tmp<(int)diag[i].size(); tmp++){
            mp[diag[i][tmp-1]] = idx;
            if (cur){
                adj[idx].push_back(cur);
                adj[cur].push_back(idx);
            }
            cur = idx;
            --idx;
        }
        if (i!=_n){
            int sus = mp[make_pair(nxt[i],i)];
            if (cur){
                adj[sus].push_back(cur);
                adj[cur].push_back(sus);
            }
//            cout << diag[i].size() << endl;
            if (i>1) mp[diag[i].back()] = sus;
        }
    }
    n = _m+1;
//    if (_m == 14265){
//        testdfs(1);
//        cout << viscnt << endl;
//        for (int i=1; i<=n; i++){
//            cout << i << ": ";
//            for (auto x:adj[i]){
//                cout << x << " ";
//            }
//            cout << endl;
//        }
//    }

    buildCentroid(1);
    for (int i=1; i<=n; i++){
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
