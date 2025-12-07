#include <bits/stdc++.h>
#define ii pair<int,int>
#define iii pair<ii,int>
#define fi first
#define se second
#define lim 10010
#define INF 1e9
using namespace std;

vector <iii> a[lim];
int height[lim];
int dist[lim];
int n,m,k,s,e;

void dijkstra(int s,int h){
    priority_queue <iii,vector<iii>,greater<iii>> pq;
    for (int i=1; i<=n; i++){
        dist[i] = INF;
    }
    pq.push({{0,h},s});
    dist[s] = 0;
    while (!pq.empty()){
        int du = pq.top().fi.fi;
        int hu = pq.top().fi.se;
        int u = pq.top().se;

        pq.pop();

        for (auto in:a[u]){
            int v = in.se;
            int dv = in.fi.fi;
            int req = in.fi.se;
            if (hu > req && hu-req>height[v] && dv+du < dist[v]){
                dist[v] = du+dv;
                pq.push({{dist[v],hu-req},v});
            }
        }
    }
}

int main()
{
    freopen("TRIP.INP","r",stdin);
    freopen("TRIP.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k >> n >> m;
    while (m--){
        int u,v,t,h;
        cin >> u >> v >> t >> h;
        a[u].push_back({{t,h},v});
        a[v].push_back({{t,h},u});
    }
    cin >> s >> e;

    priority_queue <ii,vector<ii>,greater<ii>> pq;
    for (int i=1; i<=n; i++){
        height[i] = INF;
    }
    pq.push({0,e});
    height[e] = 0;
    while (!pq.empty()){
        int hu = pq.top().fi;
        int u = pq.top().se;

        pq.pop();

        for (auto in:a[u]){
            int v = in.se;
            int hv = in.fi.se;
            if (hv+hu < height[v]){
                height[v] = hu+hv;
                pq.push({height[v],v});
            }
        }
    }

    /*for (int i=1; i<=n; i++){
        cout << height[i] << " ";
    }*/
    dijkstra(s,k);
    cout << endl;
    if (dist[e] == INF) cout << -1;
    else cout << dist[e];
    return 0;
}
