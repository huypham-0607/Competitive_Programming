/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

#define NAME "1320E"

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
int n,m,k,q;
vector<int> adj[N];
int vis[N];
int s[N];
int cnt = 0;
queue<int> unspread[N];

void DFSSpread(int u, int lvl){
//    cout << u << endl;
    for (auto v:adj[u]){
        if (vis[v]) continue;
        vis[v] = vis[u];
        ++cnt;
        if (lvl+1 == s[vis[u]]) unspread[vis[u]].push(v);
        else DFSSpread(v,lvl+1);
    }
}

void SolveQuery(){
    cnt = 0;
    cin >> k >> m;
//    for (int i=1; i<=n; i++){
//        vis[i] = 0;
//    }
    for (int i=1; i<=k; i++){
        int x; cin >> x >> s[i];
        unspread[i].push(x);
        vis[x] = i;
    }
    cnt = k;
//    int epoch = 0;
    while (cnt!=n){
//        ++epoch;
//        if (epoch>10) break;
        for (int i=1; i<=k; i++){
            int sus = (int) unspread[i].size();
            for (int idx=0; idx<sus; idx++){
//                cout << unspread[i].front() << " " << i << endl;
                DFSSpread(unspread[i].front(),0);
                unspread[i].pop();
            }
        }
    }
//    cout << cnt << " " << epoch << endl;
    for (int i=1; i<=m; i++){
        int x; cin >> x;
        cout << vis[x] << " ";
    }
    cout << endl;
    for (int i=1; i<=k; i++){
        while (!unspread[i].empty()) unspread[i].pop();
    }
    for (int i=1; i<=n; i++){
        vis[i] = 0;
    }
}

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> q;
    for (int i=1; i<=q; i++){
        SolveQuery();
    }
}

/*Driver Code*/
signed main(){
    freopen(NAME".inp","r",stdin);
    freopen(NAME".ans","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
