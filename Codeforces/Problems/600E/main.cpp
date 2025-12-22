/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 1e5+10;
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
int n;
vector<int> adj[N];
int sz[N];
int col[N];
int cnt[N];
int res = 0;
int mx = 0;
int ans[N];
int big[N];

void DFS(int u, int p){
    assert(u!=0);
    sz[u] = 1;
    for (auto v:adj[u]){
        if (v==p) continue;
        DFS(v,u);
        sz[u]+=sz[v];
    }
}

void Add(int u, int p, int val){
    assert(u!=0);
    cnt[col[u]]+=val;
    if (cnt[col[u]] > mx){
        res = 0;
        mx = cnt[col[u]];
    }
    if (cnt[col[u]] == mx) res+=col[u];
    for (auto v:adj[u]){
        if (v==p || big[v]) continue;
        Add(v,u,val);
    }
}

void Guni(int u, int p, bool keep){
    assert(u!=0);
    int nxt = 0;
    for (auto v:adj[u]){
        if (v==p) continue;
        if (!nxt || sz[nxt] < sz[v]) nxt = v;
    }
    for (auto v:adj[u]){
        if (v==p || v==nxt) continue;
        Guni(v,u,0);
    }
    if (nxt){
        Guni(nxt,u,1), big[nxt] = 1;
    }
    Add(u,p,1);
    ans[u] = res;
//    cout << u << ": ";
//    for (int i=1; i<=n; i++){
//        cout << cnt[i] << " ";
//    }
//    cout << endl;
//    for (int i=1; i<=n; i++){
//        cout << big[i] << " ";
//    }
//    cout << endl;
    if (nxt){
        big[nxt] = 0;
    }
    if (!keep){
        Add(u,p,-1);
        mx = 0;
        res = 0;
    }
}

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> col[i];
    }
    for (int i=1; i<n; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1,0);
    Guni(1,0,0);
    for (int i=1; i<=n; i++){
        cout << ans[i] << " ";
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}

