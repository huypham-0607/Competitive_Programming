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
const int N = 3e5+10;
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
int n,timedfs=0,m;
vector<pii> adj[N];
int num[N],low[N];
pii ans[N];

void DFS(int u, int p){
    num[u] = low[u] = ++timedfs;
    for (auto in:adj[u]){
        int v = in.fi;
        int id = in.se;

        if (v==p) continue;
        if (!num[v]){
            DFS(v,u);
            low[u] = min(low[u],low[v]);
            ans[id] = {u,v};
        }
        else{
            if (num[v] < num[u]){
                ans[id] = {u,v};
            }
            low[u] = min(low[u],num[v]);
        }
    }
    if (p!=0 && num[u] == low[u]){
        cout << 0 << endl;
        exit(0);
    }
}

/*Solution*/
void solve(){
    cin >> n >> m;
    for (int i=1; i<=m; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back({v,i});
        adj[v].push_back({u,i});
    }
    DFS(1,0);
//    if (timedfs<n){
//        cout << 0 << endl;
//        return;
//    }
    for (int i=1; i<=m; i++){
        cout << ans[i].fi << " " << ans[i].se << endl;
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
