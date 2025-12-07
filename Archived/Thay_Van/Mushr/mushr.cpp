#include <bits/stdc++.h>
#define ll long long
#define ii pair<ll,ll>
#define fi first
#define se second
#define INF 1000000000000000
using namespace std;

ll s1,s2,s3,n,m;
vector<ll> a[40010];
vector<ll> v1(40010,INF),v2(40010,INF),v3(40010,INF);


void dijkstra(ll s, vector<ll>& dist, ll val){
    dist[s] = 0;
    priority_queue<ii,vector<ii>,greater<ii>> pq;
    pq.push({0,s});
    while (!pq.empty()){
        ll u = pq.top().se;
        ll du = pq.top().fi;
        pq.pop();

        for (auto v:a[u]){
            if (du+val < dist[v]){
                dist[v] = du + val;
                pq.push({du+val,v});
            }
        }
    }
}


int main(){
    freopen("mushr.inp","r",stdin);
    freopen("mushr.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s1 >> s2 >> s3 >> n >> m;
    while (m--){
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dijkstra(1,v1,s1);
    dijkstra(2,v2,s2);
    dijkstra(n,v3,s3);

    /*for (int i=1; i<=n; i++){
        cout << v1[i] << " ";
    }
    cout << endl;

    for (int i=1; i<=n; i++){
        cout << v2[i] << " ";
    }
    cout << endl;

    for (int i=1; i<=n; i++){
        cout << v3[i] << " ";
    }
    cout << endl;*/
    ll mn = INF;
    for (int i=1; i<=n; i++){
        mn = min(mn,v1[i]+v2[i]+v3[i]);
    }
    cout << mn;
    return 0;
}
