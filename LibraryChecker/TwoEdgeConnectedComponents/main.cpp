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
int n,m,timedfs=0;
vector<pii> adj[N];
int num[N],low[N];
bool IsBridge[N];
vector<int> ans[N];
bool vis[N];

//DSU
int parent[N];

void Init(){
    for (int i=0; i<n; i++){
        parent[i] = i;
    }
}

int Find(int x){
    return (x == parent[x])? x : parent[x] = Find(parent[x]);
}

void Union(int u, int v){
    int x = Find(u);
    int y = Find(v);
    if (x!=y){
        parent[y] = x;
    }
}

void DFS(int u, int p){
    num[u] = low[u] = ++timedfs;
    for (auto &in:adj[u]){
        int v,id;
        tie(v,id) = in;

        if (v==p) continue;
        if (!num[v]){
            DFS(v,u);
            low[u] = min(low[u],low[v]);
            if (num[v] == low[v]) IsBridge[id] = true;
        }
        else{
            low[u] = min(low[u],num[v]);
        }
    }
}

void DFS2(int u, int p, int s){
//    cout << s << " " << u  << endl;
    vis[u] = true;
    Union(s,u);
    for (auto in:adj[u]){
        int v,id;
        tie(v,id) = in;

        if (v==p || vis[v]) continue;
        if (IsBridge[id]) continue;
        DFS2(v,u,s);
    }
}

/*Solution*/
void solve(){
    cin >> n >> m;
    Init();
    for (int i=1; i<=m; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back({v,i});
        adj[v].push_back({u,i});
    }
//    cout << endl;
    for (int i=0; i<n; i++){
        if (!num[i]) DFS(i,-1);
    }
    int cnt = 0;
    for (int i=0; i<n; i++){
        if (!vis[i]){
            ++cnt;
            DFS2(i,-1,i);
        }
    }
    for (int i=0; i<n; i++){
        ans[Find(i)].push_back(i);
    }
    cout << cnt << endl;
    for (int i=0; i<n; i++){
        if (ans[i].size()){
//            cout << i << endl;
            cout << ans[i].size() << " ";
            for (auto x:ans[i]){
                cout << x << " ";
            }
            cout << endl;
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
