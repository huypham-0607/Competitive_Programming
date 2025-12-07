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
const int N = 5e5+10;
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
int a[N];
int sz[N],depth[N];
vector<int> adj[N];
vector<pii> query[N];
bool ans[N];
int state[N];
int cnt[N][26];

void DFS(int u, int p){
    sz[u] = 1;
    for (auto v:adj[u]){
        if (v==p) continue;
        depth[v] = depth[u]+1;
        DFS(v,u);
        sz[u]+=sz[v];
    }
}

void Add(int u, int p, int val, int big){
    cnt[depth[u]][a[u]]+=val;
    if (cnt[depth[u]][a[u]]%2) state[depth[u]]++;
    else state[depth[u]]--;
    for (auto v:adj[u]){
        if (v==p || v==big) continue;
        Add(v,u,val,big);
    }
}

void Sack(int u, int p, bool keep){
    int big = 0;
    for (auto v:adj[u]){
        if (v==p) continue;
        if (!big || sz[big]<sz[v]) big = v;
    }

    for (auto v:adj[u]){
        if (v==p || v==big) continue;
        Sack(v,u,0);
    }

    if (big) Sack(big,u,1);
    Add(u,p,1,big);

    for (auto in:query[u]){
        int id,d; tie(id,d) = in;
        if (state[d]>1) ans[id] = 0;
        else ans[id] = 1;
    }

    if (!keep) Add(u,p,-1,0);
}

/*Solution*/
void solve(){
    cin >> n >> q;
    for (int u=2; u<=n; u++){
        int v; cin >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i=1; i<=n; i++){
        char c; cin >> c;
        a[i] = c-'a';
    }

    for (int i=1; i<=q; i++){
        int v,d;
        cin >> v >> d;
        query[v].push_back({i,d});
    }

    depth[1] = 1;
    DFS(1,0);
    Sack(1,0,1);

    for (int i=1; i<=q; i++){
        if (ans[i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}

