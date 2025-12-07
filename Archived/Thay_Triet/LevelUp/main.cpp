#include <bits/stdc++.h>
#define lim 1010
#define ii pair<int,int>
#define fi first
#define se second
#define ll long long
#define lli pair<ll,int>
#define ill pair<int,ll>
using namespace std;

vector <ii> a[lim];
int e[lim], h[lim];
vector <ii> dij[lim];
bool visit[lim];
ll dist[lim];
int aa,b,m,n;

void bfs(int s, int x, int t){
    memset(visit,false,sizeof(visit));
    priority_queue <ii> pq;
    pq.push({x,s});
    while (!pq.empty()){
        int d = pq.top().fi;
        int u = pq.top().se;
        pq.pop();
        //cout << u <<" " << d << endl;
        if (visit[u]) continue;
        visit[u] = true;
        if (u!=s) dij[s].push_back({u,t});

        for (auto in:a[u]){
            int v = in.fi;
            int dv = in.se;
            //cout<<"!"<<v<<endl;
            if (d>=dv){
                pq.push({d-dv,v});
            }
        }
    }
}

void dijkstra(int s){
    for (int i=1;i<=n;i++) dist[i]=1e18;
    memset(visit,false,sizeof(visit));
    dist[s] = 0;
    priority_queue <lli,vector<lli>,greater<lli>> pq;
    pq.push({0,s});
    while(!pq.empty()){
        ll du = pq.top().fi;
        int u = pq.top().se;
        pq.pop();
        if (visit[u]) continue;
        visit[u] = true;

        for (auto in:dij[u]){
            int v = in.fi;
            int dv = in.se;
            if (dist[v]>du+dv){
                dist[v] = du+dv;
                pq.push({dist[v],v});
            }
        }
    }
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    cin >> n >> m >> aa >> b;
    while (m--){
        int x,y,z;
        cin >> x >> y >> z;
        a[x].push_back(make_pair(y,z));
        a[y].push_back(make_pair(x,z));
    }
    for (int i=1; i<=n; i++){
        //cout << "meow" << endl;
        int x,y;
        cin >> x >> y;
        bfs(i,x,y);
    }
    dijkstra(aa);
    cout << dist[b];
    return 0;
}
