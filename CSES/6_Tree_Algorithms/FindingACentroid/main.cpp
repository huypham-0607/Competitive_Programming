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
int n;
vector<int> adj[N];
int sz[N];

int centroid = 0;

void DFS(int u, int p = 0){
    sz[u] = 1;
    bool check = true;
    for (auto v:adj[u]){
        if (v==p) continue;
        DFS(v,u);
        sz[u] += sz[v];
        if (sz[v]>n/2) check = false;
    }
    if (!centroid && check && n-(sz[u])<=n/2) centroid = u;
//    cout << u << " " << check << " " << n-(sz[u]) << endl;
}

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(1,0);

    cout << centroid << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
