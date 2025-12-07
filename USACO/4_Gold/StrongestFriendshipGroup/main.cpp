/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

#define NAME ""

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
int n,cnt,m;
bool vis[N];
int deg[N];
priority_queue<pii,vector<pii>,greater<pii>> pq;
vector<int> adj[N];
stack<pii> order;

//DSU;
int parent[N];
int sz[N];

void Init(){
    for (int i=1; i<=n; i++){
        parent[i] = i;
        sz[i] = 1;
    }
}

int Find(int x){
    return (x == parent[x])? x : parent[x] = Find(parent[x]);
}

void Union(int u, int v){
    int x = Find(u);
    int y = Find(v);
    if (x!=y){
        sz[x]+=sz[y];
        parent[y] = x;
    }
}

/*Solution*/
void solve(){
    cin >> n >> m;
    Init();
    while (m--){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i=1; i<=n; i++){
        deg[i] = adj[i].size();
        pq.push({deg[i],i});
    }
    int ans = 0;
    for (int i=1; i<=n; i++){
        while (!pq.empty()){
            int val = pq.top().fi;
            int u = pq.top().se;
            pq.pop();

            if (val > deg[u]) continue;

            order.push({u,deg[u]});

            for (auto v:adj[u]){
                if (deg[v]==0) continue;

                --deg[v];

                pq.push({deg[v],v});
            }
            deg[u] = 0;
        }
    }
    while (!order.empty()){
        int u = order.top().fi;
        int val = order.top().se;

        order.pop();

        vis[u] = true;
        for (auto v:adj[u]){
            if (vis[v]){
                Union(u,v);
            }
        }

        ans = max(ans,val*sz[Find(u)]);
    }
    cout << ans << endl;
}

/*Driver Code*/
signed main(){
//    freopen(NAME".in","r",stdin);
//    freopen(NAME".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
