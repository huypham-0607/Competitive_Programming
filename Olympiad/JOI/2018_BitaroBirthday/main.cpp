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
const int N = 1e5+10;
const int INF = 1e9+7;
const int B = 200;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n,m,q;
vector<int> adj[N];
vector<pii> lstpath[N];
bool blocked[N];
int dist[N];
vector<int> lstidx;

int DP(int e){
    int res = -1;
    dist[e] = 0;
    for (int i=e; i>0; i--){
        if (dist[i] == -1) continue;
        if (!blocked[i]) res = max(res,dist[i]);
        for (auto v:adj[i]){
            dist[v] = max(dist[v],dist[i]+1);
        }
    }
    for (int i=1; i<=e; i++){
        dist[i] = -1;
    }
    return res;
}

int Brute(int e){
    for (auto in:lstpath[e]){
        int d = in.fi, idx = in.se;
        if (!blocked[idx]) return d;
    }
    return -1;
}

/*Solution*/
void solve(){
    cin >> n >> m >> q;
    for (int i=1; i<=m; i++){
        int u,v; cin >> u >> v;
        adj[v].push_back(u);
    }


    for (int i=1; i<=n; i++){
        dist[i] = -1;
    }

    for (int u=1; u<=n; u++){
        lstidx.push_back(u);
        dist[u] = 0;
        for (int v:adj[u]){
            for (auto in: lstpath[v]){
                int d = in.fi,idx = in.se;
                if (dist[idx] == -1){
                    dist[idx] = d+1;
                    lstidx.push_back(idx);
                }
                else{
                    dist[idx] = max(dist[idx],d+1);
                }
            }
        }
        for (auto idx:lstidx){
            lstpath[u].push_back({dist[idx],idx});
            dist[idx] = -1;
        }
        sort(all(lstpath[u]),greater<pii>());
        while (lstpath[u].size()>B) lstpath[u].pop_back();
        lstidx.clear();
    }

    for (int i=1; i<=q; i++){
        int x,e,sz; cin >> e >> sz;
        for (int j=1; j<=sz; j++){
            cin >> x;
            lstidx.push_back(x);
            blocked[x] = true;
        }
        if (sz>=B){
            cout << DP(e) << endl;
        }
        else{
            cout << Brute(e) << endl;
        }
        for (auto idx:lstidx){
            blocked[idx] = false;
        }
        lstidx.clear();
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
