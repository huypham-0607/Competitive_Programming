/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define int long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define piii pair<int,pii>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 1e4+10;
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
int n,m,t;
int a[N],dist[N],cnt[N],deg[N],parent[N],tdist[N];
vector<pii> adj[N];


void Dijkstra(int s){
    priority_queue<piii,vector<piii>,greater<piii>> pq;
    for (int i=1; i<=n; i++){
        dist[i] = LLINF;
        parent[i] = 0;
    }
    dist[s] = 0;
    pq.push({0,{-1,s}});
    while (!pq.empty()){
        int u = pq.top().se.se;
        int p = pq.top().se.fi;
        int d = pq.top().fi;
        pq.pop();

//        cout << u << " " << p << " " << d << endl;

        if (parent[u]) continue;
        parent[u] = p;
        if (p!=-1) ++deg[p];

        for (auto in:adj[u]){
            int v = in.fi;
            int w = in.se;

            if (d+w<=dist[v]){
                dist[v] = d+w;
                pq.push({d+w,{u,v}});
            }
        }
    }
}

/*Solution*/
void solve(){
    cin >> n >> m >> t;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        cnt[i] = a[i];
    }
    while (m--){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    Dijkstra(1);
    queue<int> q;
    int tcost = 0;
    for (int i=1; i<=n; i++){
        tcost+=cnt[i]*dist[i];
        if (!deg[i]) q.push(i);
    }
    while (!q.empty()){
        int u = q.front();
        q.pop();
        tdist[u] = dist[u]*cnt[u];
        if (parent[u]!=-1){
            cnt[parent[u]]+=cnt[u];
            --deg[parent[u]];
            if (!deg[parent[u]]) q.push(parent[u]);
        }
    }
    int red = 0;
    for (int i=1; i<=n; i++){
//        cout << tdist[i] << " " << parent[i] << endl;
        red = max(red,tdist[i] - t*cnt[i]);
    }
//    cout << endl;
    cout << red << endl;
}

/*Driver Code*/
signed main(){
    freopen("shortcut.in","r",stdin);
    freopen("shortcut.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}

