/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define piii pair<int,pii>
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
int n;
int dist[N][2];
int check[N];

void dijkstra(){
    for (int i=1; i<=n; i++){
        dist[i][0] = INF;
        dist[i][1] = INF;
    }
    dist[1][0] = 0;
    priority_queue<piii,vector<piii>,greater<piii>> pq;
    pq.push({0,1});
    while (!pq.empty()){
        int u = pq.top().se.fi;
        int state = pq.top().se.se;
        int d1 = pq.top().fi;

        for (int i=1; i<=n; i++){

        }

    }
}

/*Solution*/
void solve(){
    cin >> n >> m >> k >> t;
    for (int i=1; i<=n; i++){
        int x;
        cin >> x;
        check[i] = (x==1);
    }
    while (m--){
        int u,v,c;
        cin >> u >> v >> c;
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
    }
    dijkstra();

}

/*Driver Code*/
signed main(){
    freopen("TOUR.inp","r",stdin);
    freopen("TOUR.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
