/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#include "crocodile.h"
#define pb push_back
#define endl "\n"
#define ll long long
#define int long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 1e5+10;
const int M = 1e6+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

///*TestCases*/
//int test=1;
//void solve();
//void TestCases(bool v){
//    if (v) cin >> test;
//    while(test--) solve();
//}

/*Global Variables*/
int n,m,k;
vector<pii> adj[N];
vector<int> lst;
vector<pii> dist(N);

void Dijkstra(){
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    for (int i=0; i<n; i++){
        dist[i] = {LLINF,LLINF};
    }

    for (auto x:lst){
        dist[x] = {0,0};
        pq.push({0,x});
    }

    while (!pq.empty()){
        int u = pq.top().se;
        int d = pq.top().fi;
        pq.pop();

        if (d > dist[u].se) continue;

        for (auto in:adj[u]){
            int v = in.fi;
            int delta = in.se;
            if (d+delta < dist[v].fi){
                if (dist[v].fi < dist[v].se){
                    dist[v].se = dist[v].fi;
                    pq.push({dist[v].se,v});
                }
                dist[v].fi = d+delta;
            }
            else if (d+delta < dist[v].se){
                dist[v].se = d+delta;
                pq.push({dist[v].se,v});
            }
        }
    }
}

signed travel_plan(signed _n, signed _m, signed r[][2], signed l[], signed _k, signed p[]){
    n = _n; m = _m; k = _k;
    for (int i=0; i<m; i++){
        int u = r[i][0];
        int v = r[i][1];
        int w = l[i];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    for (int i=0; i<k; i++){
        lst.push_back(p[i]);
    }
    Dijkstra();

    if (dist[0].se == LLINF) return -1;
    else return dist[0].se;

}

//int _n,_m,_k;
//int _edge[M][2];
//int _val[M];
//int _lst[N];
//
///*Solution*/
//void solve(){
//    cin >> _n >> _m;
//    for (int i=0; i<_m; i++){
//        cin >> _edge[i][0] >> _edge[i][1];
//    }
//    for (int i=0; i<_m; i++){
//        cin >> _val[i];
//    }
//    cin >> _k;
//    for (int i=0; i<_k; i++){
//        cin >> _lst[i];
//    }
//    cout << travel_plan(_n,_m,_edge,_val,_k,_lst);
//}
//
///*Driver Code*/
//signed main(){
//    freopen("Crocodile.inp","r",stdin);
//    freopen("Crocodile.out","w",stdout);
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//
//    TestCases(0);
//
//    return 0;
//}
