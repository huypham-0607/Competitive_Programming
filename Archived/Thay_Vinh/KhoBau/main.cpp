#include <bits/stdc++.h>
#define inf 1000000000
using namespace std;

vector<pair<int,int> > a[1001];
int delay[1001];

int dijkstra(int s){

    priority_queue <pair<int,int>, greater <pair<int,int> >, vector <int,int> > pq;
    bool mark[n+1];
    int dist[n+1];
    for (int i=2; i<=n; i++){
        dist[i] = inf;
    }
    pq.push({0,s});
    while (!pq.empty()){
        u = pq.top().second;
        pq.pop();
        if (mark[u]) continue;
        if (u==n)
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    while (m--){
        cin >> x >> y >> t;
        a[x].push_back({y,t});
        a[y].push_back({x,y});
    }
    while(k--){
        cin << x << t;
        delay[x] = t;
    }


    return 0;
}
