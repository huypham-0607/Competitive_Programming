/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define int long long
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
int n,q;
vector<int> adj[N];
int val[N];

void DFS(int u, int p){
    for (auto v:adj[u]){
        if (v==p) continue;
        val[v]+=val[u];
        DFS(v,u);
    }
}

/*Solution*/
void solve(){
    cin >> n >> q;
    for (int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i=1; i<=q; i++){
        int u,w; cin >> u >> w;
        val[u]+=w;
    }
    DFS(1,0);
    for (int i=1; i<=n; i++){
        cout << val[i] << " ";
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
