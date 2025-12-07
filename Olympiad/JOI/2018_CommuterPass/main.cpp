#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define piii pair<int,pii>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 1e18;

int n,m,s,t,u,v;
vector<pii> a[maxn];
vector<int> b[maxn];
int dist[maxn],du[maxn],dv[maxn];
bool valid[maxn];
piii dp[maxn];

void dijkstra(int s, int dist[]){
    for (int i=1; i<=n; i++){
        dist[i] = INF;
    }
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    dist[s] = 0;
    pq.push({0,s});
    while (!pq.empty()){
        int u = pq.top().se;
        int d = pq.top().fi;
        pq.pop();

        for (auto in:a[u]){
            int v = in.fi;
            int delta = in.se;
            if (dist[v] > d+delta){
                dist[v] = d+delta;
                pq.push({d+delta,v});
            }
        }
    }
}

void meow(int s){
    priority_queue<pii> pq;
    pq.push({dist[s],s});
    valid[s] = true;
    while (!pq.empty()){
        int u = pq.top().se;
        int d = pq.top().fi;
        pq.pop();

        dp[u].se.fi = min(dp[u].se.fi,du[u]);
        dp[u].se.se = min(dp[u].se.se,dv[u]);
        if (dp[u].fi > dp[u].se.fi + dv[u]){
            dp[u].fi = dp[u].se.fi + dv[u];
        }
        if (dp[u].fi > dp[u].se.se + du[u]){
            dp[u].fi = dp[u].se.se + du[u];
        }
        for (auto in:a[u]){
            int v = in.fi;
            int delta = in.se;
            if (d - delta == dist[v]){
                if (!valid[v]){
                    valid[v] = true;
                    pq.push({d-delta,v});
                }
                dp[v].fi = min(dp[v].fi,dp[u].fi);
                dp[v].se.fi = min(dp[v].se.fi,dp[u].se.fi);
                dp[v].se.se = min(dp[v].se.se,dp[u].se.se);
            }
        }
    }
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    cin >> s >> t;
    cin >> u >> v;
    while (m--){
        int x,y,z;
        cin >> x >> y >> z;
        a[x].push_back({y,z});
        a[y].push_back({x,z});
    }
    dijkstra(s,dist);
    dijkstra(u,du);
    dijkstra(v,dv);
//    for (int i=1; i<=n; i++){
//        cout << dist[i] << " ";
//    }
//    cout << endl;
    for (int i=1; i<=n; i++){
        dp[i] = {INF,{INF,INF}};
    }
    meow(t);
    cout << min(dp[s].fi,du[v]);
    return 0;
}
