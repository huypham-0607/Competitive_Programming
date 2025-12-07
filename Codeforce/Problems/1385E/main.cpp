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
int deg[N];
vector<pii> query;
int pos[N];
priority_queue<int,vector<int>,greater<int>> pq;

/*Solution*/
void solve(){
    cin >> n >> m;
    query.clear();
    while (!pq.empty()) pq.pop();
    for (int i=1; i<=n; i++){
        adj[i].clear();
        pos[i] = 0;
        deg[i] = 0;
    }
    for (int i=1; i<=m; i++){
        int idx,u,v;
        cin >> idx >> u >> v;
        if (idx){
            adj[u].push_back(v);
            ++deg[v];
        }
        else query.push_back({u,v});
    }
    for (int i=1; i<=n; i++){
        if (!deg[i]) pq.push(i);
    }
    int cnt = 0;
    while (!pq.empty()){
        int u = pq.top();
        pq.pop();

        pos[u] = ++cnt;
        for (auto v:adj[u]){
            --deg[v];
            if (!deg[v]) pq.push(v);
        }
    }
    if (cnt!=n){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
        for (int i=1; i<=n; i++){
            for (auto j:adj[i]){
                cout << i << " " << j << endl;
            }
        }
        for (auto in:query){
            int u = in.fi;
            int v = in.se;

            if (pos[u]>pos[v]){
                cout << v << " " << u << endl;
            }
            else cout << u << " " << v << endl;
        }
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
