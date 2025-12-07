/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 1010;
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
int n,m,k,t;
bool check[N],vis[N];
vector<vector<pii>> a(N);
vector<vector<pii>> adj(N);

//Dijkstra
void dijkstra(int s,vector<int> &dist, vector<vector<pii>> a){
    for (int i=1; i<=n; i++){
        dist[i] = INF;
    }
    dist[s] = 0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,s});
    while (!pq.empty()){
        int d1 = pq.top().fi;
        int u = pq.top().se;
        pq.pop();

        if (dist[u]<d1) continue;

        for (auto in:a[u]){
            int d2 = in.se;
            int v = in.fi;

            if (dist[v] > d1+d2){
                dist[v] = d1+d2;
                pq.push({dist[v],v});
            }
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
    a.resize(N);
    adj.resize(N);
    int u,v,c;
    while (m--){
        cin >> u >> v >> c;
        a[u].push_back({v,c});
        a[v].push_back({u,c});
    }
    vector<int> dist(n+10,INF);
    for (int i=1; i<n; i++){
        if (check[i] || i==1){
            dijkstra(i,dist,a);
//            for (int i=1; i<=n; i++){
//                cout << dist[i] << " ";
//            }
//            cout << endl;
            vis[i] = true;
            for (int j=1; j<=n; j++){
                if ((check[j] || j==1 || j==n) && i!=j && !vis[j]){
                    if (dist[j] > k) continue;
                    if (j==n){
                        adj[i].push_back({j,dist[j]});
                        continue;
                    }
                    int d = dist[j];
                    d+=t;
                    adj[i].push_back({j,d});
                    if (i!=1) adj[j].push_back({i,d});
                }
            }
        }
    }
    dijkstra(1,dist,adj);
    if (dist[n] == INF) cout << -1 << endl;
    else cout << dist[n] << endl;
//    for (int i=1; i<=n; i++){
//        for (auto in:adj[i]){
//            cout << "{" << in.fi << "," << in.se << "} ";
//        }
//        cout << endl;
//    }
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
