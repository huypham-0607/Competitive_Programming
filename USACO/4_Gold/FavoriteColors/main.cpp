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
int n,m;
vector<int> adj[N];

//DSU
int parent[N];
int child[N];
int vis[N];

void Init(){
    for (int i=1; i<=n; i++){
        parent[i] = i;
        child[i] = 0;
    }
}

int Find(int x){
    return (x == parent[x])? x : parent[x] = Find(parent[x]);
}

bool Same(int u, int v){
    return (Find(u) == Find(v));
}

void Union(int u, int v){
    int x = Find(u);
    int y = Find(v);
    if (x!=y){
        parent[y] = x;
        if (child[x] == 0 || child[y] == 0) child[x] = max(child[x],child[y]);
        else Union(child[x],child[y]);
        child[y] = 0;
        if (child[x]!=0) child[x] = Find(child[x]);
    }
}

/*Solution*/
void solve(){
    cin >> n >> m;
    Init();
    for (int i=1; i<=m; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int u=1; u<=n; u++){
        int x = Find(u);
        for (int i=1; i<(int)adj[u].size(); i++){
            Union(adj[u][i-1],adj[u][i]);
        }
        if (adj[u].size()){
            int y = Find(adj[u][0]);
            if (child[x] == 0) child[x] = y;
            else Union(child[x],y);
            child[x] = Find(child[x]);
        }
//        for (int i=1; i<=n; i++){
//            cout << Find(i) << " ";
//        }
//        cout << endl;
    }
    int cnt = 0;
    for (int i=1; i<=n; i++){
        int x = Find(i);
        if (!vis[x]){
            vis[x] = ++cnt;
        }
        cout << vis[x] << endl;
    }
}

/*Driver Code*/
signed main(){
    freopen("fcolor.in","r",stdin);
    freopen("fcolor.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}

