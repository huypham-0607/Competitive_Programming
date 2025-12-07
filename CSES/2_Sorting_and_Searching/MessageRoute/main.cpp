#include <bits/stdc++.h>
#define int long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 1e5 + 10;
const int INF = 1e15;

int n,m;
vector<ii> a[maxn];
vector<int> dist,parent;

int dijkstra(int s, int e){
    priority_queue<ii,vector<ii>,greater<ii>> pq;
    dist.assign(maxn,INF);
    parent.assign(maxn,-1);
    pq.push({1,s});
    dist[s] = 1;
    parent[s] = 0;
    while (!pq.empty()){
        int u = pq.top().se;
        int d = pq.top().fi;
        pq.pop();

        for (auto in:a[u]){
            int v = in.fi;
            int newd = in.se + d;
            if (newd < dist[v]){
                dist[v] = newd;
                parent[v] = u;
                pq.push({newd,v});
            }
        }
    }
    return dist[e];
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    while (m--){
        int x,y;
        cin >> x >> y;
        a[x].push_back({y,1});
        a[y].push_back({x,1});
    }
    int ans = dijkstra(1,n);
    if (ans == INF) cout << "IMPOSSIBLE";
    else{
        cout << ans << endl;
        int u = n;
        stack<int> s;
        while (u!=0){
            s.push(u);
            u = parent[u];
        }
        while (!s.empty()){
            cout << s.top() << " ";
            s.pop();
        }
    }
    return 0;
}
