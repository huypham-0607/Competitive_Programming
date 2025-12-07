/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define piiii pair<pii,pii>
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
int dist[N][2][2];
vector<pii> a[N];
priority_queue<piiii,vector<piiii>,greater<piiii>> pq;

void Dijkstra(){
    for (int idx=1; idx<=n; idx++){
        dist[idx][0][0] = LLINF;
        dist[idx][1][0] = LLINF;
        dist[idx][0][1] = LLINF;
        dist[idx][1][1] = LLINF;
    }
    dist[1][0][0] = 0;
    pq.push({{0,1},{0,0}});
    while (!pq.empty()){
        int d1 = pq.top().fi.fi;
        int u = pq.top().fi.se;
        int mn = pq.top().se.fi;
        int mx = pq.top().se.se;
        pq.pop();

        if (d1 > dist[u][mn][mx]) continue;

        for (auto in:a[u]){
            int v = in.fi;
            int w = in.se;

            if (dist[v][mn][mx] > dist[u][mn][mx]+w){
                dist[v][mn][mx] = dist[u][mn][mx]+w;
                pq.push({{dist[v][mn][mx],v},{mn,mx}});
            }
            if (!mn && dist[v][mn+1][mx] > dist[u][mn][mx]+2*w){
                dist[v][mn+1][mx] = dist[u][mn][mx]+2*w;
                pq.push({{dist[v][mn+1][mx],v},{mn+1,mx}});
            }
            if (!mx && dist[v][mn][mx+1] > dist[u][mn][mx]){
                dist[v][mn][mx+1] = dist[u][mn][mx];
                pq.push({{dist[v][mn][mx+1],v},{mn,mx+1}});
            }
            if (!mn && !mx && dist[v][mn+1][mx+1] > dist[u][mn][mx]+w){
                dist[v][mn+1][mx+1] = dist[u][mn][mx]+w;
                pq.push({{dist[v][mn+1][mx+1],v},{mn+1,mx+1}});
            }
        }
    }
}

/*Solution*/
void solve(){
    cin >> n >> m;
    for (int i=1; i<=m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        a[u].push_back({v,w});
        a[v].push_back({u,w});
    }
    Dijkstra();
    for (int i=2; i<=n; i++){
        cout << dist[i][1][1] << " ";
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
