#include <bits/stdc++.h>
#define ll long long
#define ii pair<long long,long long>
#define fi first
#define se second
#define lim 10010
#define INF 1000000000000000

using namespace std;

ll m,n;
vector<ii> a[lim];
ll dist[lim];
bool visit[lim];

ll prims(ll s){
    priority_queue<ii,vector<ii>,greater<ii>> pq;
    pq.push({0,s});
    for (ll i=1; i<=lim; i++){
        dist[i] = INF;
    }
    ll t=0;
    while (!pq.empty()){
        ll u = pq.top().se;
        ll du = pq.top().fi;

        pq.pop();
        if (visit[u]) continue;
        visit[u] = true;
        t+=du;
        for (auto in:a[u]){
            ll v = in.fi;
            ll dv = in.se;
            if (dv < dist[v]){
                dist[v] = dv;
                pq.push({dv,v});
            }
        }
    }
    return t;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    while (m--){
        ll x,y,z;
        cin >> x >> y >> z;
        a[x].push_back({y,z});
        a[y].push_back({x,z});
    }
    cout << prims(1);
    /*cout << endl;
    for (ll i=1; i<=n; i++){
        for (auto in:a[i]){
            cout << "(" << in.fi << "," << in.se << ") ";
        }
        cout << endl;
    }*/
    return 0;
}
