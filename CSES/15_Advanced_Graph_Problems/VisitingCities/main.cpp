/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
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
vector<pii> adj[N],Kyrie[N],a[N];
int dist[N];
bool vis[N];

void Dijkstra(int s){
    for (int i=1; i<=n; i++) dist[i] = LLINF;
    dist[s] = 0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,s});
    while (!pq.empty()){
        int d = pq.top().fi;
        int u = pq.top().se;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto in:adj[u]){
            int v = in.fi;
            int delta = in.se;

            if (dist[v] > d+delta){
                dist[v] = d+delta;
                pq.push({dist[v],v});
            }
        }
    }
}

void BuildGraph(int s){
    priority_queue<pii> pq;
    pq.push({dist[s],s});
    vis[s] = true;
    while (!pq.empty()){
        int d = pq.top().fi;
        int u = pq.top().se;
        pq.pop();

        for (auto in:Kyrie[u]){
            int v = in.fi;
            int delta = in.se;

            if (d-delta == dist[v]){
                vis[v] = true;
                a[v].push_back({u,delta});
                pq.push({dist[v],v});
            }
        }
    }
}

/*Solution*/
void solve(){
    cin >> n >> m;
    while (m--){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        Kyrie[v].push_back({u,w});
    }
    Dijkstra(1);
    BuildGraph(n);
    for (int i=1; i<=n; i++){
        cout << i << ": ";
        for (auto x:a[i]){
            cout << x.fi << " ";
        }
        cout << endl;
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
