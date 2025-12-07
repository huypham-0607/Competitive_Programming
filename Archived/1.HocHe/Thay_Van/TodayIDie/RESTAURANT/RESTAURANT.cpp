/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "RESTAURANT"

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
int n,m,k,c;
vector<int> adj[N];
bool vis[N];
int in[N];
queue<int> q;

void BFS(){
    while (!q.empty()){
        int u = q.front();
        q.pop();

        for (auto v:adj[u]){
            ++in[v];
            if (!vis[v] && in[v]>=k){
                q.push(v);
                vis[v] = true;
            }
        }
    }
}

/*Solution*/
void solve(){
    cin >> n >> m >> k;
    while (m--){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> c;
    for (int i=1; i<=c; i++){
        int x;
        cin >> x;
        vis[x] = true;
        q.push(x);
    }
    BFS();
    int cnt = 0;
    for (int i=1; i<=n; i++){
        ++cnt;
    }
    cout << cnt << endl;
    for (int i=1; i<=n; i++){
        if (vis[i]) cout << i << " ";
    }
}

/*Driver Code*/
signed main(){
//    freopen(NAME".INP","r",stdin);
//    freopen(NAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}

